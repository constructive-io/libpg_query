#include <pg_query.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* prefix, open repeated depth times, body, close repeated depth times, suffix */
static char *nested_query(const char *prefix, const char *open, const char *body,
						  const char *close, const char *suffix, int depth)
{
	char *query = malloc(strlen(prefix) + depth * (strlen(open) + strlen(close)) +
						 strlen(body) + strlen(suffix) + 1);
	if (query == NULL)
	{
		fprintf(stderr, "FAIL: could not allocate query\n");
		exit(EXIT_FAILURE);
	}

	char *p = stpcpy(query, prefix);
	for (int i = 0; i < depth; i++)
		p = stpcpy(p, open);
	p = stpcpy(p, body);
	for (int i = 0; i < depth; i++)
		p = stpcpy(p, close);
	strcpy(p, suffix);
	return query;
}

static bool check_result(const char *name, const PgQueryError *error, bool has_tree,
						 bool expect_error)
{
	const char *expected = expect_error ? "stack depth limit exceeded" : "a parse tree";
	const char *got = error ? error->message : has_tree ? "a parse tree" : "no parse tree";
	bool ok = strcmp(expected, got) == 0;
	if (ok)
		printf("PASS %s: %s\n", name, got);
	else
		fprintf(stderr, "FAIL %s: expected %s, got %s\n", name, expected, got);
	return ok;
}

/* e.g. "SELECT " "f(" ... "1" ... ")" */
static bool check_depth(const char *name, const char *open, const char *close, int depth,
						bool expect_error)
{
	char *query = nested_query("SELECT ", open, "1", close, "", depth);
	PgQueryParseResult result = pg_query_parse(query);
	bool ok = check_result(name, result.error, result.parse_tree != NULL, expect_error);

	pg_query_free_parse_result(result);
	free(query);
	return ok;
}

/* e.g. "IF true THEN " ... "NULL;" ... " END IF;" in a function body */
static bool check_plpgsql_depth(const char *name, const char *open, const char *body,
								const char *close, int depth)
{
	char *query = nested_query("CREATE FUNCTION f() RETURNS void LANGUAGE plpgsql AS $$ BEGIN ",
							   open, body, close, " END $$", depth);
	PgQueryPlpgsqlParseResult result = pg_query_parse_plpgsql(query);
	bool ok = check_result(name, result.error, result.plpgsql_funcs != NULL, false);

	pg_query_free_plpgsql_parse_result(result);
	free(query);
	return ok;
}

/*
 * Without arguments, run with the WebAssembly stack libpg-query-node links
 * (32MB). With "overflow", run with a 1MB stack, small enough that the stack
 * depth check fires before the host engine's native stack runs out.
 */
int main(int argc, char **argv)
{
	bool ok = true;
	if (argc > 1 && strcmp(argv[1], "overflow") == 0)
		return check_depth("100000 chained terms", "1+", "", 99999, true) ? EXIT_SUCCESS : EXIT_FAILURE;

	ok &= check_depth("2000 chained terms", "1+", "", 1999, false);
	ok &= check_depth("1000 nested subqueries", "(SELECT ", ")", 1000, false);
	ok &= check_depth("2000 nested function calls", "f(", ")", 2000, false);
	ok &= check_plpgsql_depth("1000 nested IF blocks", "IF true THEN ", "NULL;", " END IF;", 1000);
	ok &= check_plpgsql_depth("3000 nested BEGIN blocks", "BEGIN ", "NULL;", " END;", 3000);
	return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
