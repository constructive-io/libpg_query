#include <pg_query.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bool check_depth(const char *name, const char *open, int depth,
						bool nested, bool expect_error)
{
	const char prefix[] = "SELECT ";
	size_t open_len = strlen(open);
	char *query = malloc(sizeof(prefix) + depth * (open_len + nested) + 1);
	if (query == NULL)
	{
		fprintf(stderr, "FAIL %s: could not allocate query\n", name);
		return false;
	}

	char *p = query;
	memcpy(p, prefix, sizeof(prefix) - 1);
	p += sizeof(prefix) - 1;
	for (int i = 0; i < depth; i++)
	{
		memcpy(p, open, open_len);
		p += open_len;
	}
	*p++ = '1';
	if (nested)
	{
		memset(p, ')', depth);
		p += depth;
	}
	*p = '\0';

	PgQueryParseResult result = pg_query_parse(query);
	const char *error = result.error ? result.error->message : NULL;
	bool ok = expect_error ? error && strcmp(error, "stack depth limit exceeded") == 0
						   : result.error == NULL && result.parse_tree != NULL;
	if (ok)
		printf("PASS %s: %s\n", name, expect_error ? error : "parsed successfully");
	else
		fprintf(stderr, "FAIL %s: expected %s, got %s\n", name,
				expect_error ? "stack depth limit exceeded" : "a parse tree",
				error ? error : result.parse_tree ? "a parse tree" : "no parse tree");

	pg_query_free_parse_result(result);
	free(query);
	return ok;
}

int main(void)
{
	int status = EXIT_SUCCESS;
	if (!check_depth("2000 chained terms", "1+", 1999, false, false))
		status = EXIT_FAILURE;
	if (!check_depth("1000 nested subqueries", "(SELECT ", 1000, true, false))
		status = EXIT_FAILURE;
	if (!check_depth("2000 nested function calls", "f(", 2000, true, false))
		status = EXIT_FAILURE;
	if (!check_depth("100000 chained terms", "1+", 99999, false, true))
		status = EXIT_FAILURE;
	return status;
}
