/*
 * Regression tests for pg_query_parse_plpgsql() in PG 18.
 *
 * These tests verify that the PL/pgSQL JSON serialization produces valid,
 * complete output for various function patterns.
 *
 * On the unpatched 18-latest branch, several of these tests FAIL:
 *
 *   - Trigger functions produce malformed JSON (invalid JSON.parse)
 *   - Schema-qualified types return "Not implemented" error
 *   - RETURN <variable> loses the return target entirely (no expr, no retvarno)
 *
 * All of these work correctly on 17-latest.
 */

#include <pg_query.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static int tests_run = 0;
static int tests_passed = 0;
static int tests_failed = 0;

/*
 * Minimal JSON validation: check that every '{' has a matching '}'.
 * Returns true if braces are balanced and non-negative throughout.
 */
static bool
json_braces_balanced(const char *json)
{
	int depth = 0;
	for (const char *p = json; *p; p++)
	{
		if (*p == '{') depth++;
		else if (*p == '}') depth--;
		if (depth < 0) return false;
	}
	return depth == 0;
}

/*
 * Check that a string is valid-ish JSON by verifying it starts with '[' or '{'
 * and has balanced braces. (Not a full JSON parser, but catches the known
 * malformed output patterns.)
 */
static bool
looks_like_json(const char *s)
{
	if (!s || s[0] == '\0') return false;
	/* The known Bug 2 returns "Not implemented ..." which is not JSON */
	if (s[0] != '[' && s[0] != '{') return false;
	return json_braces_balanced(s);
}

typedef struct {
	const char *name;
	const char *sql;
	bool        expect_success;     /* expect parsing to succeed */
	bool        expect_valid_json;  /* expect JSON output to be valid */
	const char *must_contain;       /* string that must appear in output */
	const char *must_not_contain;   /* string that must NOT appear */
} TestCase;

static void
run_test(TestCase *tc)
{
	PgQueryPlpgsqlParseResult result;

	tests_run++;
	printf("  TEST %d: %s ... ", tests_run, tc->name);

	result = pg_query_parse_plpgsql(tc->sql);

	if (result.error)
	{
		if (!tc->expect_success)
		{
			printf("PASS (expected error)\n");
			tests_passed++;
		}
		else
		{
			printf("FAIL (unexpected error: %.80s)\n", result.error->message);
			tests_failed++;
		}
		pg_query_free_plpgsql_parse_result(result);
		return;
	}

	/* Parsing succeeded but we expected failure */
	if (!tc->expect_success)
	{
		printf("FAIL (expected error, but got success)\n");
		tests_failed++;
		pg_query_free_plpgsql_parse_result(result);
		return;
	}

	/* Check JSON validity */
	if (tc->expect_valid_json && !looks_like_json(result.plpgsql_funcs))
	{
		printf("FAIL (invalid JSON output)\n");
		printf("         got: %.200s...\n", result.plpgsql_funcs);
		tests_failed++;
		pg_query_free_plpgsql_parse_result(result);
		return;
	}

	/* Check required content */
	if (tc->must_contain && !strstr(result.plpgsql_funcs, tc->must_contain))
	{
		printf("FAIL (missing: \"%s\")\n", tc->must_contain);
		printf("         got: %s\n", result.plpgsql_funcs);
		tests_failed++;
		pg_query_free_plpgsql_parse_result(result);
		return;
	}

	/* Check content that must NOT appear */
	if (tc->must_not_contain && strstr(result.plpgsql_funcs, tc->must_not_contain))
	{
		printf("FAIL (unexpected content: \"%s\")\n", tc->must_not_contain);
		tests_failed++;
		pg_query_free_plpgsql_parse_result(result);
		return;
	}

	printf("PASS\n");
	tests_passed++;
	pg_query_free_plpgsql_parse_result(result);
}

int main()
{
	printf("\n=== PL/pgSQL Parse Regression Tests ===\n\n");

	/*
	 * ---------------------------------------------------------------
	 * Bug 1: Trigger functions produce malformed JSON.
	 *
	 * PLPGSQL_DTYPE_PROMISE datums (tg_name, tg_when, etc.) are not
	 * handled in dump_function(), producing empty {} entries with
	 * mismatched braces — resulting in invalid JSON.
	 *
	 * In PG 17, trigger datums are serialized correctly.
	 * In PG 18 (broken), the JSON output fails JSON.parse().
	 * ---------------------------------------------------------------
	 */
	printf("Bug 1: Trigger function JSON serialization\n");

	TestCase trigger_simple = {
		.name = "simple trigger produces valid JSON",
		.sql =
			"CREATE FUNCTION audit_trigger() RETURNS trigger LANGUAGE plpgsql AS $$\n"
			"BEGIN\n"
			"  NEW.updated_at := now();\n"
			"  RETURN NEW;\n"
			"END;\n"
			"$$",
		.expect_success = true,
		.expect_valid_json = true,
		.must_contain = "PLpgSQL_stmt_return",
		.must_not_contain = NULL,
	};
	run_test(&trigger_simple);

	TestCase trigger_old_new = {
		.name = "trigger with OLD and NEW produces valid JSON",
		.sql =
			"CREATE FUNCTION version_trigger() RETURNS trigger LANGUAGE plpgsql AS $$\n"
			"BEGIN\n"
			"  NEW.version := OLD.version + 1;\n"
			"  NEW.updated_at := now();\n"
			"  RETURN NEW;\n"
			"END;\n"
			"$$",
		.expect_success = true,
		.expect_valid_json = true,
		.must_contain = "PLpgSQL_recfield",
		.must_not_contain = NULL,
	};
	run_test(&trigger_old_new);

	TestCase trigger_declare = {
		.name = "trigger with DECLARE produces valid JSON",
		.sql =
			"CREATE FUNCTION log_trigger() RETURNS trigger LANGUAGE plpgsql AS $$\n"
			"DECLARE\n"
			"  v_old jsonb;\n"
			"BEGIN\n"
			"  v_old := to_jsonb(OLD);\n"
			"  RETURN NEW;\n"
			"END;\n"
			"$$",
		.expect_success = true,
		.expect_valid_json = true,
		.must_contain = "\"refname\":\"v_old\"",
		.must_not_contain = NULL,
	};
	run_test(&trigger_declare);

	/*
	 * ---------------------------------------------------------------
	 * Bug 2: Schema-qualified types fail with "Not implemented".
	 *
	 * LookupExplicitNamespace() only supports pg_catalog and public,
	 * but PG 18's reworked compilation now calls it for DECLARE types.
	 *
	 * In PG 17, schema-qualified types parse successfully.
	 * In PG 18 (broken), returns an error string instead of JSON.
	 * ---------------------------------------------------------------
	 */
	printf("\nBug 2: Schema-qualified type declarations\n");

	TestCase schema_quoted = {
		.name = "quoted schema type parses successfully",
		.sql =
			"CREATE FUNCTION test_func() RETURNS void LANGUAGE plpgsql AS $$\n"
			"DECLARE\n"
			"    v_user \"my_schema\".users;\n"
			"BEGIN\n"
			"    RETURN;\n"
			"END;\n"
			"$$",
		.expect_success = true,
		.expect_valid_json = true,
		.must_contain = "\"refname\":\"v_user\"",
		.must_not_contain = NULL,
	};
	run_test(&schema_quoted);

	TestCase schema_unquoted = {
		.name = "unquoted schema type parses successfully",
		.sql =
			"CREATE FUNCTION test_func2() RETURNS void LANGUAGE plpgsql AS $$\n"
			"DECLARE\n"
			"    v_item app.items;\n"
			"BEGIN\n"
			"    RETURN;\n"
			"END;\n"
			"$$",
		.expect_success = true,
		.expect_valid_json = true,
		.must_contain = "\"refname\":\"v_item\"",
		.must_not_contain = NULL,
	};
	run_test(&schema_unquoted);

	TestCase schema_multiple = {
		.name = "multiple schema-qualified types parse successfully",
		.sql =
			"CREATE FUNCTION test_func3() RETURNS void LANGUAGE plpgsql AS $$\n"
			"DECLARE\n"
			"    v_user \"my_schema\".users;\n"
			"    v_order billing.orders;\n"
			"    v_name pg_catalog.text;\n"
			"BEGIN\n"
			"    RETURN;\n"
			"END;\n"
			"$$",
		.expect_success = true,
		.expect_valid_json = true,
		.must_contain = "\"refname\":\"v_name\"",
		.must_not_contain = NULL,
	};
	run_test(&schema_multiple);

	/*
	 * ---------------------------------------------------------------
	 * Bug 3: RETURN <variable> loses the return target.
	 *
	 * When the return expression is a simple variable reference, PG 18's
	 * compiler sets retvarno instead of expr. But dump_return() has
	 * retvarno commented out, so the return statement has NO target at
	 * all — neither expr nor retvarno.
	 *
	 * In PG 17, RETURN v produces: {"expr":{"PLpgSQL_expr":{"query":"v"}}}
	 * In PG 18 (broken), RETURN v produces: {"lineno":4} (no return info)
	 *
	 * The test checks that the return statement contains EITHER "expr"
	 * or "retvarno" — on PG 17 it has expr, on a fixed PG 18 it has
	 * retvarno. On the broken PG 18 it has neither, which fails.
	 * ---------------------------------------------------------------
	 */
	printf("\nBug 3: RETURN <variable> serialization\n");

	/*
	 * Helper note: we can't use must_contain for an OR check, so we
	 * use a dedicated test that checks for the absence of both "expr"
	 * and "retvarno" in the return statement context. We check that
	 * the PLpgSQL_stmt_return node is NOT followed by just "lineno"
	 * and closing brace — it must have additional fields.
	 *
	 * Simpler approach: check that the return statement body is NOT
	 * just {"PLpgSQL_stmt_return":{"lineno":N}} — it should have more.
	 * We do this by checking that "PLpgSQL_stmt_return" appears, and
	 * also that either "expr" or "retvarno" appears somewhere in the
	 * PLpgSQL_stmt_return context.
	 *
	 * Since the return statement is always in the body array, the
	 * simplest check is: if the output contains PLpgSQL_stmt_return,
	 * does it also contain "query" (from expr) or "retvarno"?
	 */

	TestCase return_declared_var = {
		.name = "RETURN declared variable preserves return target",
		.sql =
			"CREATE FUNCTION get_value() RETURNS int LANGUAGE plpgsql AS $$\n"
			"DECLARE v int := 42;\n"
			"BEGIN\n"
			"    RETURN v;\n"
			"END;\n"
			"$$",
		.expect_success = true,
		.expect_valid_json = true,
		/* In PG 17: has "expr" with "query":"v". In fixed PG 18: has "retvarno".
		 * In broken PG 18: has neither. We check for "parseMode" which appears
		 * in expr, or "retvarno". Since PG 17 always has expr, we check for
		 * the stmt_return containing more than just lineno. The string
		 * "stmt_return\":{\"lineno\":" followed by "}}" means nothing else
		 * is in the return. Instead, let's check for either keyword. */
		.must_contain = NULL,  /* checked manually below */
		.must_not_contain = NULL,
	};
	/* Don't use run_test for this one — we need custom OR logic */
	{
		PgQueryPlpgsqlParseResult result;
		tests_run++;
		printf("  TEST %d: %s ... ", tests_run, return_declared_var.name);
		result = pg_query_parse_plpgsql(return_declared_var.sql);
		if (result.error) {
			printf("FAIL (error: %s)\n", result.error->message);
			tests_failed++;
		} else if (!looks_like_json(result.plpgsql_funcs)) {
			printf("FAIL (invalid JSON)\n");
			tests_failed++;
		} else if (!strstr(result.plpgsql_funcs, "retvarno") &&
		           !strstr(result.plpgsql_funcs, "\"query\":\"v\"")) {
			printf("FAIL (RETURN has no target — missing both expr and retvarno)\n");
			printf("         got: %s\n", result.plpgsql_funcs);
			tests_failed++;
		} else {
			printf("PASS\n");
			tests_passed++;
		}
		pg_query_free_plpgsql_parse_result(result);
	}

	TestCase return_param = {
		.name = "RETURN parameter preserves return target",
		.sql =
			"CREATE FUNCTION identity(x int) RETURNS int LANGUAGE plpgsql AS $$\n"
			"BEGIN\n"
			"    RETURN x;\n"
			"END;\n"
			"$$",
	};
	{
		PgQueryPlpgsqlParseResult result;
		tests_run++;
		printf("  TEST %d: %s ... ", tests_run, return_param.name);
		result = pg_query_parse_plpgsql(return_param.sql);
		if (result.error) {
			printf("FAIL (error: %s)\n", result.error->message);
			tests_failed++;
		} else if (!looks_like_json(result.plpgsql_funcs)) {
			printf("FAIL (invalid JSON)\n");
			tests_failed++;
		} else if (!strstr(result.plpgsql_funcs, "retvarno") &&
		           !strstr(result.plpgsql_funcs, "\"query\":\"x\"")) {
			printf("FAIL (RETURN has no target — missing both expr and retvarno)\n");
			printf("         got: %s\n", result.plpgsql_funcs);
			tests_failed++;
		} else {
			printf("PASS\n");
			tests_passed++;
		}
		pg_query_free_plpgsql_parse_result(result);
	}

	TestCase return_expr = {
		.name = "RETURN expression still has expr (control)",
		.sql =
			"CREATE FUNCTION add_one(x int) RETURNS int LANGUAGE plpgsql AS $$\n"
			"BEGIN\n"
			"    RETURN x + 1;\n"
			"END;\n"
			"$$",
		.expect_success = true,
		.expect_valid_json = true,
		.must_contain = "\"query\":\"x + 1\"",
		.must_not_contain = NULL,
	};
	run_test(&return_expr);

	TestCase return_literal = {
		.name = "RETURN literal still has expr (control)",
		.sql =
			"CREATE FUNCTION get_42() RETURNS int LANGUAGE plpgsql AS $$\n"
			"BEGIN\n"
			"    RETURN 42;\n"
			"END;\n"
			"$$",
		.expect_success = true,
		.expect_valid_json = true,
		.must_contain = "\"query\":\"42\"",
		.must_not_contain = NULL,
	};
	run_test(&return_literal);

	/*
	 * ---------------------------------------------------------------
	 * Control group: patterns that work in both PG 17 and PG 18.
	 * These should always pass.
	 * ---------------------------------------------------------------
	 */
	printf("\nControl: patterns that should work in both versions\n");

	TestCase ctrl_simple = {
		.name = "simple function with expression return",
		.sql =
			"CREATE FUNCTION add(a int, b int) RETURNS int LANGUAGE plpgsql AS $$\n"
			"BEGIN\n"
			"    RETURN a + b;\n"
			"END;\n"
			"$$",
		.expect_success = true,
		.expect_valid_json = true,
		.must_contain = "\"query\":\"a + b\"",
		.must_not_contain = NULL,
	};
	run_test(&ctrl_simple);

	TestCase ctrl_literal = {
		.name = "function with RETURN literal",
		.sql =
			"CREATE FUNCTION hello() RETURNS text LANGUAGE plpgsql AS $$\n"
			"BEGIN\n"
			"    RETURN 'hello world';\n"
			"END;\n"
			"$$",
		.expect_success = true,
		.expect_valid_json = true,
		.must_contain = "PLpgSQL_stmt_return",
		.must_not_contain = NULL,
	};
	run_test(&ctrl_literal);

	TestCase ctrl_select_into = {
		.name = "function with SELECT INTO",
		.sql =
			"CREATE FUNCTION count_users() RETURNS int LANGUAGE plpgsql AS $$\n"
			"DECLARE n int;\n"
			"BEGIN\n"
			"    SELECT count(*) INTO n FROM users;\n"
			"    RETURN n;\n"
			"END;\n"
			"$$",
		.expect_success = true,
		.expect_valid_json = true,
		.must_contain = "\"into\":true",
		.must_not_contain = NULL,
	};
	run_test(&ctrl_select_into);

	/* Summary */
	printf("\n=== Results: %d passed, %d failed, %d total ===\n\n",
		   tests_passed, tests_failed, tests_run);

	pg_query_exit();

	return (tests_failed > 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}
