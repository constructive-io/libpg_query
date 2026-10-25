#include <pg_query.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "scan_tests.c"

#include "protobuf/pg_query.pb-c.h"

#if defined(__linux__) && !defined(USE_VALGRIND)
#include <sys/resource.h>
#include <unistd.h>

/* Scanning under a tight address-space limit must report "out of memory"
 * instead of writing tokens through a NULL pointer. */
static bool test_scan_out_of_memory(void)
{
  const char *stmt = "SELECT 1;\n";
  const size_t repeat = 2000000;
  size_t len = strlen(stmt);
  char *input = malloc(len * repeat + 1);
  long pages = 0;
  FILE *statm;
  struct rlimit old_limit;
  struct rlimit limit;
  PgQueryScanResult result;
  bool ok;
  size_t i;

  for (i = 0; i < repeat; i++)
    memcpy(input + i * len, stmt, len);
  input[len * repeat] = '\0';

  statm = fopen("/proc/self/statm", "r");
  if (statm == NULL || fscanf(statm, "%ld", &pages) != 1) {
    printf("INVALID result for out of memory scan: cannot read /proc/self/statm\n");
    free(input);
    return false;
  }
  fclose(statm);

  getrlimit(RLIMIT_AS, &old_limit);
  limit = old_limit;
  limit.rlim_cur = (rlim_t) pages * sysconf(_SC_PAGESIZE) + 128 * 1024 * 1024;
  setrlimit(RLIMIT_AS, &limit);
  result = pg_query_scan(input);
  setrlimit(RLIMIT_AS, &old_limit);

  ok = result.error != NULL && strcmp(result.error->message, "out of memory") == 0;
  if (ok) {
    printf(".");
  } else {
    printf("INVALID result for out of memory scan: %s\n", result.error ? result.error->message : "no error");
  }

  pg_query_free_scan_result(result);
  free(input);
  return ok;
}
#endif

int main() {
  size_t i;
  size_t j;
  bool ret_code = 0;
  PgQuery__ScanResult *scan_result;
  PgQuery__ScanToken *scan_token;
  const ProtobufCEnumValue *token_kind;
  const ProtobufCEnumValue *keyword_kind;
  PgQueryScanResult result;

  // tests contains pairs of strings
  assert(testsCount % 2 == 0);

  for (i = 0; i < testsCount * 2; i += 2) {
    char buffer[1024];
    buffer[0] = '\0';

    result = pg_query_scan(tests[i]);

    if (result.error) {
      ret_code = -1;
      printf("%s\n", result.error->message);
    } else {
      scan_result = pg_query__scan_result__unpack(NULL, result.pbuf.len, (void*) result.pbuf.data);

      for (j = 0; j < scan_result->n_tokens; j++) {
        char buffer2[1024];
        scan_token = scan_result->tokens[j];
        token_kind = protobuf_c_enum_descriptor_get_value(&pg_query__token__descriptor, scan_token->token);
        keyword_kind = protobuf_c_enum_descriptor_get_value(&pg_query__keyword_kind__descriptor, scan_token->keyword_kind);
        if (token_kind == NULL) {
          ret_code = -1;
          printf("INVALID result for \"%s\": scan_result token %zu token_kind == NULL\n", tests[i], j);
          break;
        }
        sprintf(buffer2, "%.*s = %s, %s\n", scan_token->end - scan_token->start, &(tests[i][scan_token->start]), token_kind->name, keyword_kind->name);
        strcat(buffer, buffer2);
      }

      pg_query__scan_result__free_unpacked(scan_result, NULL);

      if (strcmp(buffer, tests[i + 1]) == 0) {
        printf(".");
      } else {
        ret_code = -1;
        printf("INVALID result for \"%s\"\nexpected:\n%s\nactual:\n%s\n", tests[i], tests[i + 1], buffer);
      }
    }

    pg_query_free_scan_result(result);
  }

#if defined(__linux__) && !defined(USE_VALGRIND)
  if (!test_scan_out_of_memory())
    ret_code = -1;
#endif

  printf("\n");

  pg_query_exit();

  return ret_code;
}
