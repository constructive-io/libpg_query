#ifndef PG_QUERY_JSON_PLPGSQL_H
#define PG_QUERY_JSON_PLPGSQL_H

#include "postgres.h"
#include "plpgsql.h"

char* plpgsqlToJSON(PLpgSQL_function* func);

/*
 * ALIAS declarations (e.g. "arg ALIAS FOR $1") only exist in the PL/pgSQL
 * compiler's namespace, which is popped before the function struct is dumped.
 * The grammar records them here during compile so plpgsqlToJSON can emit them.
 */
void pg_query_plpgsql_reset_aliases(void);
void pg_query_plpgsql_record_alias(int itemno, const char *name, int lineno);
int pg_query_plpgsql_alias_count(void);
const char* pg_query_plpgsql_alias_name(int i);
int pg_query_plpgsql_alias_varno(int i);
int pg_query_plpgsql_alias_lineno(int i);

#endif
