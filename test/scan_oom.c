#include "pg_query.h"
#include "../src/pg_query_internal.h"
#include "protobuf/pg_query.upb.h"

#include <stdio.h>
#include <string.h>

enum { NO_FAILURE, ARENA, MESSAGE, TOKEN, SERIALIZE, OUTPUT };
static int failure;
static int token_calls;

static int fail_once(int point)
{
  if (failure != point)
    return 0;
  failure = NO_FAILURE;
  return 1;
}

static upb_Arena *test_arena_new(void)
{
  return fail_once(ARENA) ? NULL : upb_Arena_New();
}

static pg_query_ScanResult *test_result_new(upb_Arena *arena)
{
  return fail_once(MESSAGE) ? NULL : pg_query_ScanResult_new(arena);
}

static pg_query_ScanToken *test_add_token(pg_query_ScanResult *result, upb_Arena *arena)
{
  if (++token_calls == 2 && fail_once(TOKEN))
    return NULL;
  return pg_query_ScanResult_add_tokens(result, arena);
}

static char *test_serialize(const pg_query_ScanResult *result, upb_Arena *arena, size_t *len)
{
  return fail_once(SERIALIZE) ? NULL : pg_query_ScanResult_serialize(result, arena, len);
}

static void *test_malloc(size_t size)
{
  return fail_once(OUTPUT) ? NULL : malloc(size);
}

/* Inject failures only in the scan translation unit, not in error reporting. */
#define upb_Arena_New test_arena_new
#define pg_query_ScanResult_new test_result_new
#define pg_query_ScanResult_add_tokens test_add_token
#define pg_query_ScanResult_serialize test_serialize
#define malloc test_malloc
#include "../src/pg_query_scan.c"
#undef malloc

int main(void)
{
  int failed = 0;

  for (int point = ARENA; point <= OUTPUT; point++)
  {
    PgQueryScanResult result;
    const char *message = point == SERIALIZE ?
      "could not serialize scan result to protobuf" : "out of memory";

    failure = point;
    token_calls = 0;
    result = pg_query_scan("SELECT 1;");
    if (failure != NO_FAILURE || result.error == NULL ||
        strcmp(result.error->message, message) != 0 ||
        result.pbuf.data != NULL || result.pbuf.len != 0)
    {
      printf("INVALID scan allocation failure %d\n", point);
      failed = 1;
    }
    pg_query_free_scan_result(result);
  }

  failure = OUTPUT;
  PgQueryScanTokensResult tokens = pg_query_scan_tokens("SELECT 1;");
  if (failure != NO_FAILURE || tokens.error == NULL ||
      strcmp(tokens.error->message, "out of memory") != 0 ||
      tokens.tokens != NULL || tokens.n_tokens != 0)
  {
    printf("INVALID scan_tokens allocation failure\n");
    failed = 1;
  }
  pg_query_free_scan_tokens_result(tokens);

  const char *inputs[] = {"SELECT 1;", "", "SELECT 'unterminated"};
  for (int i = 0; i < 3; i++)
  {
    PgQueryScanResult result = pg_query_scan(inputs[i]);
    if ((result.error != NULL) != (i == 2) ||
        (i != 2 && (result.pbuf.data == NULL || result.pbuf.len == 0)))
    {
      printf("INVALID scan recovery case %d\n", i);
      failed = 1;
    }
    pg_query_free_scan_result(result);
  }

  pg_query_exit();
  if (!failed)
    printf("scan OOM: 6 injected failures and 3 recovery cases passed\n");
  return failed;
}
