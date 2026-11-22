#ifndef PG_QUERY_JSON_PLPGSQL_H
#define PG_QUERY_JSON_PLPGSQL_H

#include "postgres.h"
#include "plpgsql.h"

typedef struct PgQueryPlpgsqlAlias
{
	int varno;
	char *name;
	int lineno;
} PgQueryPlpgsqlAlias;

typedef struct PgQueryPlpgsqlAliases
{
	PgQueryPlpgsqlAlias *items;
	int count;
	int capacity;
} PgQueryPlpgsqlAliases;

void pg_query_plpgsql_set_aliases(PgQueryPlpgsqlAliases *aliases);
void pg_query_plpgsql_record_alias(int itemno, const char *name, int lineno);
char* plpgsqlToJSON(PLpgSQL_function *func, const PgQueryPlpgsqlAliases *aliases);

#endif
