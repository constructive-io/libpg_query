#include <pg_query.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* With pg_query_set_stack_limit() configured, input nested deeper than the
 * limit must come back as a "stack depth limit exceeded" error. Before these
 * paths were wrapped in PG_TRY, the error had no handler, so it was promoted
 * to FATAL and the whole process exited. */

#define STACK_LIMIT (16 * 1024)

static char *repeat_into(char *out, const char *s, size_t n)
{
  size_t len = strlen(s);
  size_t i;

  for (i = 0; i < n; i++, out += len)
    memcpy(out, s, len);
  *out = '\0';
  return out;
}

static char *deep_expression(size_t depth)
{
  char *sql = malloc(strlen("SELECT 1") + depth * 2 + 1);
  repeat_into(stpcpy(sql, "SELECT 1"), "+1", depth);
  return sql;
}

static char *deep_plpgsql(size_t depth)
{
  const char *head = "CREATE FUNCTION f() RETURNS void LANGUAGE plpgsql AS $$ BEGIN ";
  const char *tail = "END $$;";
  char *sql = malloc(strlen(head) + depth * (strlen("IF true THEN ") + strlen("END IF; ")) + strlen("NULL; ") + strlen(tail) + 1);
  char *p = stpcpy(sql, head);

  p = repeat_into(p, "IF true THEN ", depth);
  p = stpcpy(p, "NULL; ");
  p = repeat_into(p, "END IF; ", depth);
  strcpy(p, tail);
  return sql;
}

static bool expect_stack_error(const char *name, PgQueryError *error)
{
  if (error != NULL && strstr(error->message, "stack depth limit exceeded") != NULL) {
    printf(".");
    return true;
  }
  printf("INVALID result for %s: %s\n", name, error ? error->message : "no error");
  return false;
}

static bool test_fingerprint(void)
{
  char *sql = deep_expression(3000);
  PgQueryFingerprintResult result;
  bool ok;

  /* Fingerprinting stops at 100 nodes deep, so it needs a tighter limit */
  pg_query_set_stack_limit(4 * 1024);
  result = pg_query_fingerprint(sql);
  ok = expect_stack_error("deep fingerprint", result.error);
  pg_query_free_fingerprint_result(result);
  free(sql);
  return ok;
}

static bool test_parse_protobuf(void)
{
  char *sql = deep_expression(3000);
  PgQueryProtobufParseResult result;
  bool ok;

  pg_query_set_stack_limit(STACK_LIMIT);
  result = pg_query_parse_protobuf(sql);
  ok = expect_stack_error("deep protobuf parse", result.error);
  pg_query_free_protobuf_parse_result(result);
  free(sql);
  return ok;
}

static bool test_parse_plpgsql(void)
{
  char *sql = deep_plpgsql(2000);
  PgQueryPlpgsqlParseResult result;
  bool ok;

  pg_query_set_stack_limit(STACK_LIMIT);
  result = pg_query_parse_plpgsql(sql);
  ok = expect_stack_error("deep plpgsql parse", result.error);
  pg_query_free_plpgsql_parse_result(result);
  free(sql);
  return ok;
}

int main(int argc, char **argv)
{
  const char *only = argc > 1 ? argv[1] : NULL;
  int ret_code = 0;

  if ((!only || strcmp(only, "fingerprint") == 0) && !test_fingerprint())
    ret_code = 1;
  if ((!only || strcmp(only, "protobuf") == 0) && !test_parse_protobuf())
    ret_code = 1;
  if ((!only || strcmp(only, "plpgsql") == 0) && !test_parse_plpgsql())
    ret_code = 1;

  printf("\n");
  pg_query_exit();
  return ret_code;
}
