case T_Alias:
  // Intentionally ignoring for fingerprinting
  break;
case T_RangeVar:
  _fingerprintString(ctx, "RangeVar");
  _fingerprintCall((FingerprintFunc) _fingerprintRangeVar, ctx, obj, parent, field_name, depth);
  break;
case T_TableFunc:
  _fingerprintString(ctx, "TableFunc");
  _fingerprintCall((FingerprintFunc) _fingerprintTableFunc, ctx, obj, parent, field_name, depth);
  break;
case T_IntoClause:
  _fingerprintString(ctx, "IntoClause");
  _fingerprintCall((FingerprintFunc) _fingerprintIntoClause, ctx, obj, parent, field_name, depth);
  break;
case T_Var:
  _fingerprintString(ctx, "Var");
  _fingerprintCall((FingerprintFunc) _fingerprintVar, ctx, obj, parent, field_name, depth);
  break;
case T_Const:
  _fingerprintString(ctx, "Const");
  _fingerprintCall((FingerprintFunc) _fingerprintConst, ctx, obj, parent, field_name, depth);
  break;
case T_Param:
  _fingerprintString(ctx, "Param");
  _fingerprintCall((FingerprintFunc) _fingerprintParam, ctx, obj, parent, field_name, depth);
  break;
case T_Aggref:
  _fingerprintString(ctx, "Aggref");
  _fingerprintCall((FingerprintFunc) _fingerprintAggref, ctx, obj, parent, field_name, depth);
  break;
case T_GroupingFunc:
  _fingerprintString(ctx, "GroupingFunc");
  _fingerprintCall((FingerprintFunc) _fingerprintGroupingFunc, ctx, obj, parent, field_name, depth);
  break;
case T_WindowFunc:
  _fingerprintString(ctx, "WindowFunc");
  _fingerprintCall((FingerprintFunc) _fingerprintWindowFunc, ctx, obj, parent, field_name, depth);
  break;
case T_WindowFuncRunCondition:
  _fingerprintString(ctx, "WindowFuncRunCondition");
  _fingerprintCall((FingerprintFunc) _fingerprintWindowFuncRunCondition, ctx, obj, parent, field_name, depth);
  break;
case T_MergeSupportFunc:
  _fingerprintString(ctx, "MergeSupportFunc");
  _fingerprintCall((FingerprintFunc) _fingerprintMergeSupportFunc, ctx, obj, parent, field_name, depth);
  break;
case T_SubscriptingRef:
  _fingerprintString(ctx, "SubscriptingRef");
  _fingerprintCall((FingerprintFunc) _fingerprintSubscriptingRef, ctx, obj, parent, field_name, depth);
  break;
case T_FuncExpr:
  _fingerprintString(ctx, "FuncExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintFuncExpr, ctx, obj, parent, field_name, depth);
  break;
case T_NamedArgExpr:
  _fingerprintString(ctx, "NamedArgExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintNamedArgExpr, ctx, obj, parent, field_name, depth);
  break;
case T_OpExpr:
  _fingerprintString(ctx, "OpExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintOpExpr, ctx, obj, parent, field_name, depth);
  break;
case T_ScalarArrayOpExpr:
  _fingerprintString(ctx, "ScalarArrayOpExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintScalarArrayOpExpr, ctx, obj, parent, field_name, depth);
  break;
case T_BoolExpr:
  _fingerprintString(ctx, "BoolExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintBoolExpr, ctx, obj, parent, field_name, depth);
  break;
case T_SubLink:
  _fingerprintString(ctx, "SubLink");
  _fingerprintCall((FingerprintFunc) _fingerprintSubLink, ctx, obj, parent, field_name, depth);
  break;
case T_SubPlan:
  _fingerprintString(ctx, "SubPlan");
  _fingerprintCall((FingerprintFunc) _fingerprintSubPlan, ctx, obj, parent, field_name, depth);
  break;
case T_AlternativeSubPlan:
  _fingerprintString(ctx, "AlternativeSubPlan");
  _fingerprintCall((FingerprintFunc) _fingerprintAlternativeSubPlan, ctx, obj, parent, field_name, depth);
  break;
case T_FieldSelect:
  _fingerprintString(ctx, "FieldSelect");
  _fingerprintCall((FingerprintFunc) _fingerprintFieldSelect, ctx, obj, parent, field_name, depth);
  break;
case T_FieldStore:
  _fingerprintString(ctx, "FieldStore");
  _fingerprintCall((FingerprintFunc) _fingerprintFieldStore, ctx, obj, parent, field_name, depth);
  break;
case T_RelabelType:
  _fingerprintString(ctx, "RelabelType");
  _fingerprintCall((FingerprintFunc) _fingerprintRelabelType, ctx, obj, parent, field_name, depth);
  break;
case T_CoerceViaIO:
  _fingerprintString(ctx, "CoerceViaIO");
  _fingerprintCall((FingerprintFunc) _fingerprintCoerceViaIO, ctx, obj, parent, field_name, depth);
  break;
case T_ArrayCoerceExpr:
  _fingerprintString(ctx, "ArrayCoerceExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintArrayCoerceExpr, ctx, obj, parent, field_name, depth);
  break;
case T_ConvertRowtypeExpr:
  _fingerprintString(ctx, "ConvertRowtypeExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintConvertRowtypeExpr, ctx, obj, parent, field_name, depth);
  break;
case T_CollateExpr:
  _fingerprintString(ctx, "CollateExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintCollateExpr, ctx, obj, parent, field_name, depth);
  break;
case T_CaseExpr:
  _fingerprintString(ctx, "CaseExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintCaseExpr, ctx, obj, parent, field_name, depth);
  break;
case T_CaseWhen:
  _fingerprintString(ctx, "CaseWhen");
  _fingerprintCall((FingerprintFunc) _fingerprintCaseWhen, ctx, obj, parent, field_name, depth);
  break;
case T_CaseTestExpr:
  _fingerprintString(ctx, "CaseTestExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintCaseTestExpr, ctx, obj, parent, field_name, depth);
  break;
case T_ArrayExpr:
  _fingerprintString(ctx, "ArrayExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintArrayExpr, ctx, obj, parent, field_name, depth);
  break;
case T_RowExpr:
  _fingerprintString(ctx, "RowExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintRowExpr, ctx, obj, parent, field_name, depth);
  break;
case T_RowCompareExpr:
  _fingerprintString(ctx, "RowCompareExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintRowCompareExpr, ctx, obj, parent, field_name, depth);
  break;
case T_CoalesceExpr:
  _fingerprintString(ctx, "CoalesceExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintCoalesceExpr, ctx, obj, parent, field_name, depth);
  break;
case T_MinMaxExpr:
  _fingerprintString(ctx, "MinMaxExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintMinMaxExpr, ctx, obj, parent, field_name, depth);
  break;
case T_SQLValueFunction:
  _fingerprintString(ctx, "SQLValueFunction");
  _fingerprintCall((FingerprintFunc) _fingerprintSQLValueFunction, ctx, obj, parent, field_name, depth);
  break;
case T_XmlExpr:
  _fingerprintString(ctx, "XmlExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintXmlExpr, ctx, obj, parent, field_name, depth);
  break;
case T_JsonFormat:
  _fingerprintString(ctx, "JsonFormat");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonFormat, ctx, obj, parent, field_name, depth);
  break;
case T_JsonReturning:
  _fingerprintString(ctx, "JsonReturning");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonReturning, ctx, obj, parent, field_name, depth);
  break;
case T_JsonValueExpr:
  _fingerprintString(ctx, "JsonValueExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonValueExpr, ctx, obj, parent, field_name, depth);
  break;
case T_JsonConstructorExpr:
  _fingerprintString(ctx, "JsonConstructorExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonConstructorExpr, ctx, obj, parent, field_name, depth);
  break;
case T_JsonIsPredicate:
  _fingerprintString(ctx, "JsonIsPredicate");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonIsPredicate, ctx, obj, parent, field_name, depth);
  break;
case T_JsonBehavior:
  _fingerprintString(ctx, "JsonBehavior");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonBehavior, ctx, obj, parent, field_name, depth);
  break;
case T_JsonExpr:
  _fingerprintString(ctx, "JsonExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonExpr, ctx, obj, parent, field_name, depth);
  break;
case T_JsonTablePath:
  _fingerprintString(ctx, "JsonTablePath");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonTablePath, ctx, obj, parent, field_name, depth);
  break;
case T_JsonTablePathScan:
  _fingerprintString(ctx, "JsonTablePathScan");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonTablePathScan, ctx, obj, parent, field_name, depth);
  break;
case T_JsonTableSiblingJoin:
  _fingerprintString(ctx, "JsonTableSiblingJoin");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonTableSiblingJoin, ctx, obj, parent, field_name, depth);
  break;
case T_NullTest:
  _fingerprintString(ctx, "NullTest");
  _fingerprintCall((FingerprintFunc) _fingerprintNullTest, ctx, obj, parent, field_name, depth);
  break;
case T_BooleanTest:
  _fingerprintString(ctx, "BooleanTest");
  _fingerprintCall((FingerprintFunc) _fingerprintBooleanTest, ctx, obj, parent, field_name, depth);
  break;
case T_MergeAction:
  _fingerprintString(ctx, "MergeAction");
  _fingerprintCall((FingerprintFunc) _fingerprintMergeAction, ctx, obj, parent, field_name, depth);
  break;
case T_CoerceToDomain:
  _fingerprintString(ctx, "CoerceToDomain");
  _fingerprintCall((FingerprintFunc) _fingerprintCoerceToDomain, ctx, obj, parent, field_name, depth);
  break;
case T_CoerceToDomainValue:
  _fingerprintString(ctx, "CoerceToDomainValue");
  _fingerprintCall((FingerprintFunc) _fingerprintCoerceToDomainValue, ctx, obj, parent, field_name, depth);
  break;
case T_SetToDefault:
  // Intentionally ignoring for fingerprinting
  break;
case T_CurrentOfExpr:
  _fingerprintString(ctx, "CurrentOfExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintCurrentOfExpr, ctx, obj, parent, field_name, depth);
  break;
case T_NextValueExpr:
  _fingerprintString(ctx, "NextValueExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintNextValueExpr, ctx, obj, parent, field_name, depth);
  break;
case T_InferenceElem:
  _fingerprintString(ctx, "InferenceElem");
  _fingerprintCall((FingerprintFunc) _fingerprintInferenceElem, ctx, obj, parent, field_name, depth);
  break;
case T_ReturningExpr:
  _fingerprintString(ctx, "ReturningExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintReturningExpr, ctx, obj, parent, field_name, depth);
  break;
case T_TargetEntry:
  _fingerprintString(ctx, "TargetEntry");
  _fingerprintCall((FingerprintFunc) _fingerprintTargetEntry, ctx, obj, parent, field_name, depth);
  break;
case T_RangeTblRef:
  _fingerprintString(ctx, "RangeTblRef");
  _fingerprintCall((FingerprintFunc) _fingerprintRangeTblRef, ctx, obj, parent, field_name, depth);
  break;
case T_JoinExpr:
  _fingerprintString(ctx, "JoinExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintJoinExpr, ctx, obj, parent, field_name, depth);
  break;
case T_FromExpr:
  _fingerprintString(ctx, "FromExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintFromExpr, ctx, obj, parent, field_name, depth);
  break;
case T_OnConflictExpr:
  _fingerprintString(ctx, "OnConflictExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintOnConflictExpr, ctx, obj, parent, field_name, depth);
  break;
case T_Query:
  _fingerprintString(ctx, "Query");
  _fingerprintCall((FingerprintFunc) _fingerprintQuery, ctx, obj, parent, field_name, depth);
  break;
case T_TypeName:
  _fingerprintString(ctx, "TypeName");
  _fingerprintCall((FingerprintFunc) _fingerprintTypeName, ctx, obj, parent, field_name, depth);
  break;
case T_ColumnRef:
  _fingerprintString(ctx, "ColumnRef");
  _fingerprintCall((FingerprintFunc) _fingerprintColumnRef, ctx, obj, parent, field_name, depth);
  break;
case T_ParamRef:
  // Intentionally ignoring for fingerprinting
  break;
case T_A_Expr:
  _fingerprintString(ctx, "A_Expr");
  _fingerprintCall((FingerprintFunc) _fingerprintA_Expr, ctx, obj, parent, field_name, depth);
  break;
case T_TypeCast:
  if (!IsA(castNode(TypeCast, (void*) obj)->arg, A_Const) && !IsA(castNode(TypeCast, (void*) obj)->arg, ParamRef))
  {
  _fingerprintString(ctx, "TypeCast");
  _fingerprintCall((FingerprintFunc) _fingerprintTypeCast, ctx, obj, parent, field_name, depth);
  }
  break;
case T_CollateClause:
  _fingerprintString(ctx, "CollateClause");
  _fingerprintCall((FingerprintFunc) _fingerprintCollateClause, ctx, obj, parent, field_name, depth);
  break;
case T_RoleSpec:
  _fingerprintString(ctx, "RoleSpec");
  _fingerprintCall((FingerprintFunc) _fingerprintRoleSpec, ctx, obj, parent, field_name, depth);
  break;
case T_FuncCall:
  _fingerprintString(ctx, "FuncCall");
  _fingerprintCall((FingerprintFunc) _fingerprintFuncCall, ctx, obj, parent, field_name, depth);
  break;
case T_A_Star:
  _fingerprintString(ctx, "A_Star");
  _fingerprintCall((FingerprintFunc) _fingerprintA_Star, ctx, obj, parent, field_name, depth);
  break;
case T_A_Indices:
  _fingerprintString(ctx, "A_Indices");
  _fingerprintCall((FingerprintFunc) _fingerprintA_Indices, ctx, obj, parent, field_name, depth);
  break;
case T_A_Indirection:
  _fingerprintString(ctx, "A_Indirection");
  _fingerprintCall((FingerprintFunc) _fingerprintA_Indirection, ctx, obj, parent, field_name, depth);
  break;
case T_A_ArrayExpr:
  _fingerprintString(ctx, "A_ArrayExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintA_ArrayExpr, ctx, obj, parent, field_name, depth);
  break;
case T_ResTarget:
  _fingerprintString(ctx, "ResTarget");
  _fingerprintCall((FingerprintFunc) _fingerprintResTarget, ctx, obj, parent, field_name, depth);
  break;
case T_MultiAssignRef:
  _fingerprintString(ctx, "MultiAssignRef");
  _fingerprintCall((FingerprintFunc) _fingerprintMultiAssignRef, ctx, obj, parent, field_name, depth);
  break;
case T_SortBy:
  _fingerprintString(ctx, "SortBy");
  _fingerprintCall((FingerprintFunc) _fingerprintSortBy, ctx, obj, parent, field_name, depth);
  break;
case T_WindowDef:
  _fingerprintString(ctx, "WindowDef");
  _fingerprintCall((FingerprintFunc) _fingerprintWindowDef, ctx, obj, parent, field_name, depth);
  break;
case T_RangeSubselect:
  _fingerprintString(ctx, "RangeSubselect");
  _fingerprintCall((FingerprintFunc) _fingerprintRangeSubselect, ctx, obj, parent, field_name, depth);
  break;
case T_RangeFunction:
  _fingerprintString(ctx, "RangeFunction");
  _fingerprintCall((FingerprintFunc) _fingerprintRangeFunction, ctx, obj, parent, field_name, depth);
  break;
case T_RangeTableFunc:
  _fingerprintString(ctx, "RangeTableFunc");
  _fingerprintCall((FingerprintFunc) _fingerprintRangeTableFunc, ctx, obj, parent, field_name, depth);
  break;
case T_RangeTableFuncCol:
  _fingerprintString(ctx, "RangeTableFuncCol");
  _fingerprintCall((FingerprintFunc) _fingerprintRangeTableFuncCol, ctx, obj, parent, field_name, depth);
  break;
case T_RangeTableSample:
  _fingerprintString(ctx, "RangeTableSample");
  _fingerprintCall((FingerprintFunc) _fingerprintRangeTableSample, ctx, obj, parent, field_name, depth);
  break;
case T_ColumnDef:
  _fingerprintString(ctx, "ColumnDef");
  _fingerprintCall((FingerprintFunc) _fingerprintColumnDef, ctx, obj, parent, field_name, depth);
  break;
case T_TableLikeClause:
  _fingerprintString(ctx, "TableLikeClause");
  _fingerprintCall((FingerprintFunc) _fingerprintTableLikeClause, ctx, obj, parent, field_name, depth);
  break;
case T_IndexElem:
  _fingerprintString(ctx, "IndexElem");
  _fingerprintCall((FingerprintFunc) _fingerprintIndexElem, ctx, obj, parent, field_name, depth);
  break;
case T_DefElem:
  _fingerprintString(ctx, "DefElem");
  _fingerprintCall((FingerprintFunc) _fingerprintDefElem, ctx, obj, parent, field_name, depth);
  break;
case T_LockingClause:
  _fingerprintString(ctx, "LockingClause");
  _fingerprintCall((FingerprintFunc) _fingerprintLockingClause, ctx, obj, parent, field_name, depth);
  break;
case T_XmlSerialize:
  _fingerprintString(ctx, "XmlSerialize");
  _fingerprintCall((FingerprintFunc) _fingerprintXmlSerialize, ctx, obj, parent, field_name, depth);
  break;
case T_PartitionElem:
  _fingerprintString(ctx, "PartitionElem");
  _fingerprintCall((FingerprintFunc) _fingerprintPartitionElem, ctx, obj, parent, field_name, depth);
  break;
case T_PartitionSpec:
  _fingerprintString(ctx, "PartitionSpec");
  _fingerprintCall((FingerprintFunc) _fingerprintPartitionSpec, ctx, obj, parent, field_name, depth);
  break;
case T_PartitionBoundSpec:
  _fingerprintString(ctx, "PartitionBoundSpec");
  _fingerprintCall((FingerprintFunc) _fingerprintPartitionBoundSpec, ctx, obj, parent, field_name, depth);
  break;
case T_PartitionRangeDatum:
  _fingerprintString(ctx, "PartitionRangeDatum");
  _fingerprintCall((FingerprintFunc) _fingerprintPartitionRangeDatum, ctx, obj, parent, field_name, depth);
  break;
case T_PartitionCmd:
  _fingerprintString(ctx, "PartitionCmd");
  _fingerprintCall((FingerprintFunc) _fingerprintPartitionCmd, ctx, obj, parent, field_name, depth);
  break;
case T_RangeTblEntry:
  _fingerprintString(ctx, "RangeTblEntry");
  _fingerprintCall((FingerprintFunc) _fingerprintRangeTblEntry, ctx, obj, parent, field_name, depth);
  break;
case T_RTEPermissionInfo:
  _fingerprintString(ctx, "RTEPermissionInfo");
  _fingerprintCall((FingerprintFunc) _fingerprintRTEPermissionInfo, ctx, obj, parent, field_name, depth);
  break;
case T_RangeTblFunction:
  _fingerprintString(ctx, "RangeTblFunction");
  _fingerprintCall((FingerprintFunc) _fingerprintRangeTblFunction, ctx, obj, parent, field_name, depth);
  break;
case T_TableSampleClause:
  _fingerprintString(ctx, "TableSampleClause");
  _fingerprintCall((FingerprintFunc) _fingerprintTableSampleClause, ctx, obj, parent, field_name, depth);
  break;
case T_WithCheckOption:
  _fingerprintString(ctx, "WithCheckOption");
  _fingerprintCall((FingerprintFunc) _fingerprintWithCheckOption, ctx, obj, parent, field_name, depth);
  break;
case T_SortGroupClause:
  _fingerprintString(ctx, "SortGroupClause");
  _fingerprintCall((FingerprintFunc) _fingerprintSortGroupClause, ctx, obj, parent, field_name, depth);
  break;
case T_GroupingSet:
  _fingerprintString(ctx, "GroupingSet");
  _fingerprintCall((FingerprintFunc) _fingerprintGroupingSet, ctx, obj, parent, field_name, depth);
  break;
case T_WindowClause:
  _fingerprintString(ctx, "WindowClause");
  _fingerprintCall((FingerprintFunc) _fingerprintWindowClause, ctx, obj, parent, field_name, depth);
  break;
case T_RowMarkClause:
  _fingerprintString(ctx, "RowMarkClause");
  _fingerprintCall((FingerprintFunc) _fingerprintRowMarkClause, ctx, obj, parent, field_name, depth);
  break;
case T_WithClause:
  _fingerprintString(ctx, "WithClause");
  _fingerprintCall((FingerprintFunc) _fingerprintWithClause, ctx, obj, parent, field_name, depth);
  break;
case T_InferClause:
  _fingerprintString(ctx, "InferClause");
  _fingerprintCall((FingerprintFunc) _fingerprintInferClause, ctx, obj, parent, field_name, depth);
  break;
case T_OnConflictClause:
  _fingerprintString(ctx, "OnConflictClause");
  _fingerprintCall((FingerprintFunc) _fingerprintOnConflictClause, ctx, obj, parent, field_name, depth);
  break;
case T_CTESearchClause:
  _fingerprintString(ctx, "CTESearchClause");
  _fingerprintCall((FingerprintFunc) _fingerprintCTESearchClause, ctx, obj, parent, field_name, depth);
  break;
case T_CTECycleClause:
  _fingerprintString(ctx, "CTECycleClause");
  _fingerprintCall((FingerprintFunc) _fingerprintCTECycleClause, ctx, obj, parent, field_name, depth);
  break;
case T_CommonTableExpr:
  _fingerprintString(ctx, "CommonTableExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintCommonTableExpr, ctx, obj, parent, field_name, depth);
  break;
case T_MergeWhenClause:
  _fingerprintString(ctx, "MergeWhenClause");
  _fingerprintCall((FingerprintFunc) _fingerprintMergeWhenClause, ctx, obj, parent, field_name, depth);
  break;
case T_ReturningOption:
  _fingerprintString(ctx, "ReturningOption");
  _fingerprintCall((FingerprintFunc) _fingerprintReturningOption, ctx, obj, parent, field_name, depth);
  break;
case T_ReturningClause:
  _fingerprintString(ctx, "ReturningClause");
  _fingerprintCall((FingerprintFunc) _fingerprintReturningClause, ctx, obj, parent, field_name, depth);
  break;
case T_TriggerTransition:
  _fingerprintString(ctx, "TriggerTransition");
  _fingerprintCall((FingerprintFunc) _fingerprintTriggerTransition, ctx, obj, parent, field_name, depth);
  break;
case T_JsonOutput:
  _fingerprintString(ctx, "JsonOutput");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonOutput, ctx, obj, parent, field_name, depth);
  break;
case T_JsonArgument:
  _fingerprintString(ctx, "JsonArgument");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonArgument, ctx, obj, parent, field_name, depth);
  break;
case T_JsonFuncExpr:
  _fingerprintString(ctx, "JsonFuncExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonFuncExpr, ctx, obj, parent, field_name, depth);
  break;
case T_JsonTablePathSpec:
  _fingerprintString(ctx, "JsonTablePathSpec");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonTablePathSpec, ctx, obj, parent, field_name, depth);
  break;
case T_JsonTable:
  _fingerprintString(ctx, "JsonTable");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonTable, ctx, obj, parent, field_name, depth);
  break;
case T_JsonTableColumn:
  _fingerprintString(ctx, "JsonTableColumn");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonTableColumn, ctx, obj, parent, field_name, depth);
  break;
case T_JsonKeyValue:
  _fingerprintString(ctx, "JsonKeyValue");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonKeyValue, ctx, obj, parent, field_name, depth);
  break;
case T_JsonParseExpr:
  _fingerprintString(ctx, "JsonParseExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonParseExpr, ctx, obj, parent, field_name, depth);
  break;
case T_JsonScalarExpr:
  _fingerprintString(ctx, "JsonScalarExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonScalarExpr, ctx, obj, parent, field_name, depth);
  break;
case T_JsonSerializeExpr:
  _fingerprintString(ctx, "JsonSerializeExpr");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonSerializeExpr, ctx, obj, parent, field_name, depth);
  break;
case T_JsonObjectConstructor:
  _fingerprintString(ctx, "JsonObjectConstructor");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonObjectConstructor, ctx, obj, parent, field_name, depth);
  break;
case T_JsonArrayConstructor:
  _fingerprintString(ctx, "JsonArrayConstructor");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonArrayConstructor, ctx, obj, parent, field_name, depth);
  break;
case T_JsonArrayQueryConstructor:
  _fingerprintString(ctx, "JsonArrayQueryConstructor");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonArrayQueryConstructor, ctx, obj, parent, field_name, depth);
  break;
case T_JsonAggConstructor:
  _fingerprintString(ctx, "JsonAggConstructor");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonAggConstructor, ctx, obj, parent, field_name, depth);
  break;
case T_JsonObjectAgg:
  _fingerprintString(ctx, "JsonObjectAgg");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonObjectAgg, ctx, obj, parent, field_name, depth);
  break;
case T_JsonArrayAgg:
  _fingerprintString(ctx, "JsonArrayAgg");
  _fingerprintCall((FingerprintFunc) _fingerprintJsonArrayAgg, ctx, obj, parent, field_name, depth);
  break;
case T_RawStmt:
  _fingerprintString(ctx, "RawStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintRawStmt, ctx, obj, parent, field_name, depth);
  break;
case T_InsertStmt:
  _fingerprintString(ctx, "InsertStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintInsertStmt, ctx, obj, parent, field_name, depth);
  break;
case T_DeleteStmt:
  _fingerprintString(ctx, "DeleteStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintDeleteStmt, ctx, obj, parent, field_name, depth);
  break;
case T_UpdateStmt:
  _fingerprintString(ctx, "UpdateStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintUpdateStmt, ctx, obj, parent, field_name, depth);
  break;
case T_MergeStmt:
  _fingerprintString(ctx, "MergeStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintMergeStmt, ctx, obj, parent, field_name, depth);
  break;
case T_SelectStmt:
  _fingerprintString(ctx, "SelectStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintSelectStmt, ctx, obj, parent, field_name, depth);
  break;
case T_SetOperationStmt:
  _fingerprintString(ctx, "SetOperationStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintSetOperationStmt, ctx, obj, parent, field_name, depth);
  break;
case T_ReturnStmt:
  _fingerprintString(ctx, "ReturnStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintReturnStmt, ctx, obj, parent, field_name, depth);
  break;
case T_PLAssignStmt:
  _fingerprintString(ctx, "PLAssignStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintPLAssignStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreateSchemaStmt:
  _fingerprintString(ctx, "CreateSchemaStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateSchemaStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterTableStmt:
  _fingerprintString(ctx, "AlterTableStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterTableStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterTableCmd:
  _fingerprintString(ctx, "AlterTableCmd");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterTableCmd, ctx, obj, parent, field_name, depth);
  break;
case T_ATAlterConstraint:
  _fingerprintString(ctx, "ATAlterConstraint");
  _fingerprintCall((FingerprintFunc) _fingerprintATAlterConstraint, ctx, obj, parent, field_name, depth);
  break;
case T_ReplicaIdentityStmt:
  _fingerprintString(ctx, "ReplicaIdentityStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintReplicaIdentityStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterCollationStmt:
  _fingerprintString(ctx, "AlterCollationStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterCollationStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterDomainStmt:
  _fingerprintString(ctx, "AlterDomainStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterDomainStmt, ctx, obj, parent, field_name, depth);
  break;
case T_GrantStmt:
  _fingerprintString(ctx, "GrantStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintGrantStmt, ctx, obj, parent, field_name, depth);
  break;
case T_ObjectWithArgs:
  _fingerprintString(ctx, "ObjectWithArgs");
  _fingerprintCall((FingerprintFunc) _fingerprintObjectWithArgs, ctx, obj, parent, field_name, depth);
  break;
case T_AccessPriv:
  _fingerprintString(ctx, "AccessPriv");
  _fingerprintCall((FingerprintFunc) _fingerprintAccessPriv, ctx, obj, parent, field_name, depth);
  break;
case T_GrantRoleStmt:
  _fingerprintString(ctx, "GrantRoleStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintGrantRoleStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterDefaultPrivilegesStmt:
  _fingerprintString(ctx, "AlterDefaultPrivilegesStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterDefaultPrivilegesStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CopyStmt:
  _fingerprintString(ctx, "CopyStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCopyStmt, ctx, obj, parent, field_name, depth);
  break;
case T_VariableSetStmt:
  _fingerprintString(ctx, "VariableSetStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintVariableSetStmt, ctx, obj, parent, field_name, depth);
  break;
case T_VariableShowStmt:
  _fingerprintString(ctx, "VariableShowStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintVariableShowStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreateStmt:
  _fingerprintString(ctx, "CreateStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateStmt, ctx, obj, parent, field_name, depth);
  break;
case T_Constraint:
  _fingerprintString(ctx, "Constraint");
  _fingerprintCall((FingerprintFunc) _fingerprintConstraint, ctx, obj, parent, field_name, depth);
  break;
case T_CreateTableSpaceStmt:
  _fingerprintString(ctx, "CreateTableSpaceStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateTableSpaceStmt, ctx, obj, parent, field_name, depth);
  break;
case T_DropTableSpaceStmt:
  _fingerprintString(ctx, "DropTableSpaceStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintDropTableSpaceStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterTableSpaceOptionsStmt:
  _fingerprintString(ctx, "AlterTableSpaceOptionsStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterTableSpaceOptionsStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterTableMoveAllStmt:
  _fingerprintString(ctx, "AlterTableMoveAllStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterTableMoveAllStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreateExtensionStmt:
  _fingerprintString(ctx, "CreateExtensionStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateExtensionStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterExtensionStmt:
  _fingerprintString(ctx, "AlterExtensionStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterExtensionStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterExtensionContentsStmt:
  _fingerprintString(ctx, "AlterExtensionContentsStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterExtensionContentsStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreateFdwStmt:
  _fingerprintString(ctx, "CreateFdwStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateFdwStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterFdwStmt:
  _fingerprintString(ctx, "AlterFdwStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterFdwStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreateForeignServerStmt:
  _fingerprintString(ctx, "CreateForeignServerStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateForeignServerStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterForeignServerStmt:
  _fingerprintString(ctx, "AlterForeignServerStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterForeignServerStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreateForeignTableStmt:
  _fingerprintString(ctx, "CreateForeignTableStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateForeignTableStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreateUserMappingStmt:
  _fingerprintString(ctx, "CreateUserMappingStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateUserMappingStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterUserMappingStmt:
  _fingerprintString(ctx, "AlterUserMappingStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterUserMappingStmt, ctx, obj, parent, field_name, depth);
  break;
case T_DropUserMappingStmt:
  _fingerprintString(ctx, "DropUserMappingStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintDropUserMappingStmt, ctx, obj, parent, field_name, depth);
  break;
case T_ImportForeignSchemaStmt:
  _fingerprintString(ctx, "ImportForeignSchemaStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintImportForeignSchemaStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreatePolicyStmt:
  _fingerprintString(ctx, "CreatePolicyStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreatePolicyStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterPolicyStmt:
  _fingerprintString(ctx, "AlterPolicyStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterPolicyStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreateAmStmt:
  _fingerprintString(ctx, "CreateAmStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateAmStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreateTrigStmt:
  _fingerprintString(ctx, "CreateTrigStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateTrigStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreateEventTrigStmt:
  _fingerprintString(ctx, "CreateEventTrigStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateEventTrigStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterEventTrigStmt:
  _fingerprintString(ctx, "AlterEventTrigStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterEventTrigStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreatePLangStmt:
  _fingerprintString(ctx, "CreatePLangStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreatePLangStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreateRoleStmt:
  _fingerprintString(ctx, "CreateRoleStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateRoleStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterRoleStmt:
  _fingerprintString(ctx, "AlterRoleStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterRoleStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterRoleSetStmt:
  _fingerprintString(ctx, "AlterRoleSetStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterRoleSetStmt, ctx, obj, parent, field_name, depth);
  break;
case T_DropRoleStmt:
  _fingerprintString(ctx, "DropRoleStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintDropRoleStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreateSeqStmt:
  _fingerprintString(ctx, "CreateSeqStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateSeqStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterSeqStmt:
  _fingerprintString(ctx, "AlterSeqStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterSeqStmt, ctx, obj, parent, field_name, depth);
  break;
case T_DefineStmt:
  _fingerprintString(ctx, "DefineStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintDefineStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreateDomainStmt:
  _fingerprintString(ctx, "CreateDomainStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateDomainStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreateOpClassStmt:
  _fingerprintString(ctx, "CreateOpClassStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateOpClassStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreateOpClassItem:
  _fingerprintString(ctx, "CreateOpClassItem");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateOpClassItem, ctx, obj, parent, field_name, depth);
  break;
case T_CreateOpFamilyStmt:
  _fingerprintString(ctx, "CreateOpFamilyStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateOpFamilyStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterOpFamilyStmt:
  _fingerprintString(ctx, "AlterOpFamilyStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterOpFamilyStmt, ctx, obj, parent, field_name, depth);
  break;
case T_DropStmt:
  _fingerprintString(ctx, "DropStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintDropStmt, ctx, obj, parent, field_name, depth);
  break;
case T_TruncateStmt:
  _fingerprintString(ctx, "TruncateStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintTruncateStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CommentStmt:
  _fingerprintString(ctx, "CommentStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCommentStmt, ctx, obj, parent, field_name, depth);
  break;
case T_SecLabelStmt:
  _fingerprintString(ctx, "SecLabelStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintSecLabelStmt, ctx, obj, parent, field_name, depth);
  break;
case T_DeclareCursorStmt:
  _fingerprintString(ctx, "DeclareCursorStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintDeclareCursorStmt, ctx, obj, parent, field_name, depth);
  break;
case T_ClosePortalStmt:
  _fingerprintString(ctx, "ClosePortalStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintClosePortalStmt, ctx, obj, parent, field_name, depth);
  break;
case T_FetchStmt:
  _fingerprintString(ctx, "FetchStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintFetchStmt, ctx, obj, parent, field_name, depth);
  break;
case T_IndexStmt:
  _fingerprintString(ctx, "IndexStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintIndexStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreateStatsStmt:
  _fingerprintString(ctx, "CreateStatsStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateStatsStmt, ctx, obj, parent, field_name, depth);
  break;
case T_StatsElem:
  _fingerprintString(ctx, "StatsElem");
  _fingerprintCall((FingerprintFunc) _fingerprintStatsElem, ctx, obj, parent, field_name, depth);
  break;
case T_AlterStatsStmt:
  _fingerprintString(ctx, "AlterStatsStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterStatsStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreateFunctionStmt:
  _fingerprintString(ctx, "CreateFunctionStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateFunctionStmt, ctx, obj, parent, field_name, depth);
  break;
case T_FunctionParameter:
  _fingerprintString(ctx, "FunctionParameter");
  _fingerprintCall((FingerprintFunc) _fingerprintFunctionParameter, ctx, obj, parent, field_name, depth);
  break;
case T_AlterFunctionStmt:
  _fingerprintString(ctx, "AlterFunctionStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterFunctionStmt, ctx, obj, parent, field_name, depth);
  break;
case T_DoStmt:
  _fingerprintString(ctx, "DoStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintDoStmt, ctx, obj, parent, field_name, depth);
  break;
case T_InlineCodeBlock:
  _fingerprintString(ctx, "InlineCodeBlock");
  _fingerprintCall((FingerprintFunc) _fingerprintInlineCodeBlock, ctx, obj, parent, field_name, depth);
  break;
case T_CallStmt:
  _fingerprintString(ctx, "CallStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCallStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CallContext:
  _fingerprintString(ctx, "CallContext");
  _fingerprintCall((FingerprintFunc) _fingerprintCallContext, ctx, obj, parent, field_name, depth);
  break;
case T_RenameStmt:
  _fingerprintString(ctx, "RenameStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintRenameStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterObjectDependsStmt:
  _fingerprintString(ctx, "AlterObjectDependsStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterObjectDependsStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterObjectSchemaStmt:
  _fingerprintString(ctx, "AlterObjectSchemaStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterObjectSchemaStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterOwnerStmt:
  _fingerprintString(ctx, "AlterOwnerStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterOwnerStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterOperatorStmt:
  _fingerprintString(ctx, "AlterOperatorStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterOperatorStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterTypeStmt:
  _fingerprintString(ctx, "AlterTypeStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterTypeStmt, ctx, obj, parent, field_name, depth);
  break;
case T_RuleStmt:
  _fingerprintString(ctx, "RuleStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintRuleStmt, ctx, obj, parent, field_name, depth);
  break;
case T_NotifyStmt:
  _fingerprintString(ctx, "NotifyStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintNotifyStmt, ctx, obj, parent, field_name, depth);
  break;
case T_ListenStmt:
  _fingerprintString(ctx, "ListenStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintListenStmt, ctx, obj, parent, field_name, depth);
  break;
case T_UnlistenStmt:
  _fingerprintString(ctx, "UnlistenStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintUnlistenStmt, ctx, obj, parent, field_name, depth);
  break;
case T_TransactionStmt:
  _fingerprintString(ctx, "TransactionStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintTransactionStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CompositeTypeStmt:
  _fingerprintString(ctx, "CompositeTypeStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCompositeTypeStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreateEnumStmt:
  _fingerprintString(ctx, "CreateEnumStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateEnumStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreateRangeStmt:
  _fingerprintString(ctx, "CreateRangeStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateRangeStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterEnumStmt:
  _fingerprintString(ctx, "AlterEnumStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterEnumStmt, ctx, obj, parent, field_name, depth);
  break;
case T_ViewStmt:
  _fingerprintString(ctx, "ViewStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintViewStmt, ctx, obj, parent, field_name, depth);
  break;
case T_LoadStmt:
  _fingerprintString(ctx, "LoadStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintLoadStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreatedbStmt:
  _fingerprintString(ctx, "CreatedbStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreatedbStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterDatabaseStmt:
  _fingerprintString(ctx, "AlterDatabaseStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterDatabaseStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterDatabaseRefreshCollStmt:
  _fingerprintString(ctx, "AlterDatabaseRefreshCollStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterDatabaseRefreshCollStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterDatabaseSetStmt:
  _fingerprintString(ctx, "AlterDatabaseSetStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterDatabaseSetStmt, ctx, obj, parent, field_name, depth);
  break;
case T_DropdbStmt:
  _fingerprintString(ctx, "DropdbStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintDropdbStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterSystemStmt:
  _fingerprintString(ctx, "AlterSystemStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterSystemStmt, ctx, obj, parent, field_name, depth);
  break;
case T_ClusterStmt:
  _fingerprintString(ctx, "ClusterStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintClusterStmt, ctx, obj, parent, field_name, depth);
  break;
case T_VacuumStmt:
  _fingerprintString(ctx, "VacuumStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintVacuumStmt, ctx, obj, parent, field_name, depth);
  break;
case T_VacuumRelation:
  _fingerprintString(ctx, "VacuumRelation");
  _fingerprintCall((FingerprintFunc) _fingerprintVacuumRelation, ctx, obj, parent, field_name, depth);
  break;
case T_ExplainStmt:
  _fingerprintString(ctx, "ExplainStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintExplainStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreateTableAsStmt:
  _fingerprintString(ctx, "CreateTableAsStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateTableAsStmt, ctx, obj, parent, field_name, depth);
  break;
case T_RefreshMatViewStmt:
  _fingerprintString(ctx, "RefreshMatViewStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintRefreshMatViewStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CheckPointStmt:
  _fingerprintString(ctx, "CheckPointStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCheckPointStmt, ctx, obj, parent, field_name, depth);
  break;
case T_DiscardStmt:
  _fingerprintString(ctx, "DiscardStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintDiscardStmt, ctx, obj, parent, field_name, depth);
  break;
case T_LockStmt:
  _fingerprintString(ctx, "LockStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintLockStmt, ctx, obj, parent, field_name, depth);
  break;
case T_ConstraintsSetStmt:
  _fingerprintString(ctx, "ConstraintsSetStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintConstraintsSetStmt, ctx, obj, parent, field_name, depth);
  break;
case T_ReindexStmt:
  _fingerprintString(ctx, "ReindexStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintReindexStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreateConversionStmt:
  _fingerprintString(ctx, "CreateConversionStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateConversionStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreateCastStmt:
  _fingerprintString(ctx, "CreateCastStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateCastStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreateTransformStmt:
  _fingerprintString(ctx, "CreateTransformStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateTransformStmt, ctx, obj, parent, field_name, depth);
  break;
case T_PrepareStmt:
  _fingerprintString(ctx, "PrepareStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintPrepareStmt, ctx, obj, parent, field_name, depth);
  break;
case T_ExecuteStmt:
  _fingerprintString(ctx, "ExecuteStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintExecuteStmt, ctx, obj, parent, field_name, depth);
  break;
case T_DeallocateStmt:
  _fingerprintString(ctx, "DeallocateStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintDeallocateStmt, ctx, obj, parent, field_name, depth);
  break;
case T_DropOwnedStmt:
  _fingerprintString(ctx, "DropOwnedStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintDropOwnedStmt, ctx, obj, parent, field_name, depth);
  break;
case T_ReassignOwnedStmt:
  _fingerprintString(ctx, "ReassignOwnedStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintReassignOwnedStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterTSDictionaryStmt:
  _fingerprintString(ctx, "AlterTSDictionaryStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterTSDictionaryStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterTSConfigurationStmt:
  _fingerprintString(ctx, "AlterTSConfigurationStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterTSConfigurationStmt, ctx, obj, parent, field_name, depth);
  break;
case T_PublicationTable:
  _fingerprintString(ctx, "PublicationTable");
  _fingerprintCall((FingerprintFunc) _fingerprintPublicationTable, ctx, obj, parent, field_name, depth);
  break;
case T_PublicationObjSpec:
  _fingerprintString(ctx, "PublicationObjSpec");
  _fingerprintCall((FingerprintFunc) _fingerprintPublicationObjSpec, ctx, obj, parent, field_name, depth);
  break;
case T_CreatePublicationStmt:
  _fingerprintString(ctx, "CreatePublicationStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreatePublicationStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterPublicationStmt:
  _fingerprintString(ctx, "AlterPublicationStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterPublicationStmt, ctx, obj, parent, field_name, depth);
  break;
case T_CreateSubscriptionStmt:
  _fingerprintString(ctx, "CreateSubscriptionStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintCreateSubscriptionStmt, ctx, obj, parent, field_name, depth);
  break;
case T_AlterSubscriptionStmt:
  _fingerprintString(ctx, "AlterSubscriptionStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintAlterSubscriptionStmt, ctx, obj, parent, field_name, depth);
  break;
case T_DropSubscriptionStmt:
  _fingerprintString(ctx, "DropSubscriptionStmt");
  _fingerprintCall((FingerprintFunc) _fingerprintDropSubscriptionStmt, ctx, obj, parent, field_name, depth);
  break;
