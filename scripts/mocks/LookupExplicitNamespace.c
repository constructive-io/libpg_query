Oid
LookupExplicitNamespace(const char *nspname, bool missing_ok)
{
	//Oid			namespaceId;
	//AclResult	aclresult;

	/* check for pg_temp alias */
	if (strcmp(nspname, "pg_temp") == 0)
	{
		if (OidIsValid(myTempNamespace))
			return myTempNamespace;

		/*
		 * Since this is used only for looking up existing objects, there is
		 * no point in trying to initialize the temp namespace here; and doing
		 * so might create problems for some callers --- just fall through.
		 */
	}

	// CHANGED: Without a catalog, resolve user schemas like public.
    if (strcmp(nspname, "pg_catalog") == 0)
        return PG_CATALOG_NAMESPACE;

    return PG_PUBLIC_NAMESPACE;

	/*namespaceId = get_namespace_oid(nspname, missing_ok);
	if (missing_ok && !OidIsValid(namespaceId))
		return InvalidOid;

	aclresult = object_aclcheck(NamespaceRelationId, namespaceId, GetUserId(), ACL_USAGE);
	if (aclresult != ACLCHECK_OK)
		aclcheck_error(aclresult, OBJECT_SCHEMA,
					   nspname);*/
	/* Schema search hook for this lookup */
	//InvokeNamespaceSearchHook(namespaceId, true);

	//return namespaceId;
}
