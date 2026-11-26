#include <pg_query.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *nested_query(const char *prefix, const char *open, const char *body,
						  const char *close, const char *suffix, int depth)
{
	char *query = malloc(strlen(prefix) + depth * (strlen(open) + strlen(close)) +
						 strlen(body) + strlen(suffix) + 1);
	if (query == NULL)
	{
		fprintf(stderr, "could not allocate query\n");
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

static bool check_parse(const char *name, const PgQueryError *error, bool has_tree,
						bool expect_error)
{
	const char *expected = expect_error ? "stack depth limit exceeded" : "a parse tree";
	const char *actual = error ? error->message : has_tree ? "a parse tree" : "no parse tree";
	bool ok = strcmp(expected, actual) == 0;

	fprintf(ok ? stdout : stderr, "%s %s: expected %s, got %s\n",
			ok ? "PASS" : "FAIL", name, expected, actual);
	return ok;
}

static bool check_sql_depth(int terms, bool expect_error)
{
	char *query = nested_query("SELECT 1", "+1", "", "", "", terms - 1);
	PgQueryParseResult result = pg_query_parse(query);
	char name[64];
	snprintf(name, sizeof(name), "parse %d chained terms", terms);
	bool ok = check_parse(name, result.error, result.parse_tree != NULL, expect_error);

	pg_query_free_parse_result(result);
	free(query);
	return ok;
}

static bool check_plpgsql_depth(void)
{
	char *query = nested_query("CREATE FUNCTION f() RETURNS void LANGUAGE plpgsql AS $$ BEGIN ",
							   "IF true THEN ", "NULL;", " END IF;", " END $$", 1000);
	PgQueryPlpgsqlParseResult result = pg_query_parse_plpgsql(query);
	bool ok = check_parse("parse 1000 nested PL/pgSQL IF blocks", result.error,
						  result.plpgsql_funcs != NULL, false);

	pg_query_free_plpgsql_parse_result(result);
	free(query);
	return ok;
}

int main(int argc, char **argv)
{
	/* Run with a 1 MiB linked stack for overflow, 32 MiB otherwise. */
	bool ok;
	if (argc > 1 && strcmp(argv[1], "overflow") == 0)
		ok = check_sql_depth(100000, true);
	else
	{
		ok = check_sql_depth(2000, false);
		ok &= check_plpgsql_depth();
	}

	pg_query_exit();
	return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
