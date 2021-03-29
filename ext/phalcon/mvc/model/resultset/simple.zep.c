
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


/**
 * Phalcon\Mvc\Model\Resultset\Simple
 *
 * Simple resultsets only contains a complete objects
 * This class builds every complete object as it is required
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Resultset_Simple) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Resultset, Simple, phalcon, mvc_model_resultset_simple, phalcon_mvc_model_resultset_ce, phalcon_mvc_model_resultset_simple_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_resultset_simple_ce, SL("_model"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_model_resultset_simple_ce, SL("_columnMap"), ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalcon_mvc_model_resultset_simple_ce, SL("_keepSnapshots"), 0, ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Resultset\Simple constructor
 *
 * @param array columnMap
 * @param \Phalcon\Mvc\ModelInterface|Phalcon\Mvc\Model\Row model
 * @param \Phalcon\Db\Result\Pdo|null result
 * @param \Phalcon\Cache\BackendInterface cache
 * @param boolean keepSnapshots
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *columnMap, columnMap_sub, *model, model_sub, *result, result_sub, *cache = NULL, cache_sub, *keepSnapshots = NULL, keepSnapshots_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&result_sub);
	ZVAL_UNDEF(&cache_sub);
	ZVAL_UNDEF(&keepSnapshots_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 5)
		Z_PARAM_ZVAL(columnMap)
		Z_PARAM_ZVAL(model)
		Z_PARAM_ZVAL(result)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(cache, phalcon_cache_backendinterface_ce)
		Z_PARAM_ZVAL(keepSnapshots)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &columnMap, &model, &result, &cache, &keepSnapshots);

	if (!cache) {
		cache = &cache_sub;
		cache = &__$null;
	}
	if (!keepSnapshots) {
		keepSnapshots = &keepSnapshots_sub;
		keepSnapshots = &__$null;
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("_model"), model);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_columnMap"), columnMap);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_keepSnapshots"), keepSnapshots);
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_resultset_simple_ce, getThis(), "__construct", &_0, 0, result, cache);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns current row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, current) {

	zend_class_entry *_5$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, __$false, row, hydrateMode, columnMap, activeRow, modelName, _0$$6, _2$$6, _3$$6, _4$$6, _1$$7, _7$$9, _8$$9, _9$$9;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&hydrateMode);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&activeRow);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&_0$$6);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_1$$7);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&activeRow);
	zephir_read_property(&activeRow, this_ptr, ZEND_STRL("_activeRow"), PH_NOISY_CC);
	if (Z_TYPE_P(&activeRow) != IS_NULL) {
		RETURN_CCTOR(&activeRow);
	}
	ZEPHIR_OBS_VAR(&row);
	zephir_read_property(&row, this_ptr, ZEND_STRL("_row"), PH_NOISY_CC);
	if (Z_TYPE_P(&row) != IS_ARRAY) {
		if (0) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("_activeRow"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("_activeRow"), &__$false);
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(&hydrateMode);
	zephir_read_property(&hydrateMode, this_ptr, ZEND_STRL("_hydrateMode"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&columnMap);
	zephir_read_property(&columnMap, this_ptr, ZEND_STRL("_columnMap"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_LONG(&hydrateMode, 0)) {
			if (ZEPHIR_GLOBAL(orm).late_state_binding) {
				ZEPHIR_OBS_VAR(&_0$$6);
				zephir_read_property(&_0$$6, this_ptr, ZEND_STRL("_model"), PH_NOISY_CC);
				if (zephir_instance_of_ev(&_0$$6, phalcon_mvc_model_ce)) {
					zephir_read_property(&_1$$7, this_ptr, ZEND_STRL("_model"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_VAR(&modelName);
					zephir_get_class(&modelName, &_1$$7, 0);
				} else {
					ZEPHIR_INIT_NVAR(&modelName);
					ZVAL_STRING(&modelName, "Phalcon\\Mvc\\Model");
				}
				zephir_read_property(&_2$$6, this_ptr, ZEND_STRL("_model"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_3$$6, this_ptr, ZEND_STRL("_keepSnapshots"), PH_NOISY_CC | PH_READONLY);
				ZVAL_LONG(&_4$$6, 0);
				_5$$6 = zephir_fetch_class(&modelName);
				ZEPHIR_CALL_CE_STATIC(&activeRow, _5$$6, "cloneresultmap", NULL, 0, &_2$$6, &row, &columnMap, &_4$$6, &_3$$6);
				zephir_check_call_status();
			} else {
				zephir_read_property(&_7$$9, this_ptr, ZEND_STRL("_model"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_8$$9, this_ptr, ZEND_STRL("_keepSnapshots"), PH_NOISY_CC | PH_READONLY);
				ZVAL_LONG(&_9$$9, 0);
				ZEPHIR_CALL_CE_STATIC(&activeRow, phalcon_mvc_model_ce, "cloneresultmap", &_6, 0, &_7$$9, &row, &columnMap, &_9$$9, &_8$$9);
				zephir_check_call_status();
			}
			break;
		}
		ZEPHIR_CALL_CE_STATIC(&activeRow, phalcon_mvc_model_ce, "cloneresultmaphydrate", &_10, 0, &row, &columnMap, &hydrateMode);
		zephir_check_call_status();
		break;
	} while(0);

	zephir_update_property_zval(this_ptr, ZEND_STRL("_activeRow"), &activeRow);
	RETURN_CCTOR(&activeRow);

}

/**
 * Returns a complete resultset as an array, if the resultset has a big number of rows
 * it could consume more memory than currently it does. Export the resultset to an array
 * couldn't be faster with a large number of records
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, toArray) {

	zend_string *_6$$8, *_19$$17;
	zend_ulong _5$$8, _18$$17;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *renameColumns_param = NULL, __$null, result, records, record, renamed, renamedKey, key, value, renamedRecords, columnMap, _0$$3, *_1$$7, _2$$7, *_3$$8, _4$$8, _7$$10, _8$$10, _10$$12, _11$$12, _12$$14, _13$$14, _14$$16, _15$$16, *_16$$17, _17$$17, _20$$19, _21$$19, _22$$21, _23$$21, _24$$23, _25$$23, _26$$25, _27$$25;
	zend_bool renameColumns;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&renamed);
	ZVAL_UNDEF(&renamedKey);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&renamedRecords);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$16);
	ZVAL_UNDEF(&_15$$16);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_20$$19);
	ZVAL_UNDEF(&_21$$19);
	ZVAL_UNDEF(&_22$$21);
	ZVAL_UNDEF(&_23$$21);
	ZVAL_UNDEF(&_24$$23);
	ZVAL_UNDEF(&_25$$23);
	ZVAL_UNDEF(&_26$$25);
	ZVAL_UNDEF(&_27$$25);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(renameColumns)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &renameColumns_param);

	if (!renameColumns_param) {
		renameColumns = 1;
	} else {
		renameColumns = zephir_get_boolval(renameColumns_param);
	}


	ZEPHIR_OBS_VAR(&records);
	zephir_read_property(&records, this_ptr, ZEND_STRL("_rows"), PH_NOISY_CC);
	if (Z_TYPE_P(&records) != IS_ARRAY) {
		ZEPHIR_OBS_VAR(&result);
		zephir_read_property(&result, this_ptr, ZEND_STRL("_result"), PH_NOISY_CC);
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("_row"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0$$3) != IS_NULL) {
			ZEPHIR_CALL_METHOD(NULL, &result, "execute", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&records, &result, "fetchall", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("_row"), &__$null);
		zephir_update_property_zval(this_ptr, ZEND_STRL("_rows"), &records);
	}
	if (renameColumns) {
		ZEPHIR_OBS_VAR(&columnMap);
		zephir_read_property(&columnMap, this_ptr, ZEND_STRL("_columnMap"), PH_NOISY_CC);
		if (Z_TYPE_P(&columnMap) != IS_ARRAY) {
			RETURN_CCTOR(&records);
		}
		ZEPHIR_INIT_VAR(&renamedRecords);
		array_init(&renamedRecords);
		if (Z_TYPE_P(&records) == IS_ARRAY) {
			zephir_is_iterable(&records, 0, "phalcon/mvc/model/resultset/simple.zep", 217);
			if (Z_TYPE_P(&records) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&records), _1$$7)
				{
					ZEPHIR_INIT_NVAR(&record);
					ZVAL_COPY(&record, _1$$7);
					ZEPHIR_INIT_NVAR(&renamed);
					array_init(&renamed);
					zephir_is_iterable(&record, 0, "phalcon/mvc/model/resultset/simple.zep", 215);
					if (Z_TYPE_P(&record) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&record), _5$$8, _6$$8, _3$$8)
						{
							ZEPHIR_INIT_NVAR(&key);
							if (_6$$8 != NULL) { 
								ZVAL_STR_COPY(&key, _6$$8);
							} else {
								ZVAL_LONG(&key, _5$$8);
							}
							ZEPHIR_INIT_NVAR(&value);
							ZVAL_COPY(&value, _3$$8);
							ZEPHIR_OBS_NVAR(&renamedKey);
							if (!(zephir_array_isset_fetch(&renamedKey, &columnMap, &key, 0))) {
								ZEPHIR_INIT_NVAR(&_7$$10);
								object_init_ex(&_7$$10, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_NVAR(&_8$$10);
								ZEPHIR_CONCAT_SVS(&_8$$10, "Column '", &key, "' is not part of the column map");
								ZEPHIR_CALL_METHOD(NULL, &_7$$10, "__construct", &_9, 4, &_8$$10);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_7$$10, "phalcon/mvc/model/resultset/simple.zep", 199);
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (Z_TYPE_P(&renamedKey) == IS_ARRAY) {
								ZEPHIR_OBS_NVAR(&renamedKey);
								if (!(zephir_array_isset_long_fetch(&renamedKey, &renamedKey, 0, 0))) {
									ZEPHIR_INIT_NVAR(&_10$$12);
									object_init_ex(&_10$$12, phalcon_mvc_model_exception_ce);
									ZEPHIR_INIT_NVAR(&_11$$12);
									ZEPHIR_CONCAT_SVS(&_11$$12, "Column '", &key, "' is not part of the column map");
									ZEPHIR_CALL_METHOD(NULL, &_10$$12, "__construct", &_9, 4, &_11$$12);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_10$$12, "phalcon/mvc/model/resultset/simple.zep", 205);
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
							zephir_array_update_zval(&renamed, &renamedKey, &value, PH_COPY | PH_SEPARATE);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &record, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_4$$8, &record, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_4$$8)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&key, &record, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&value, &record, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_OBS_NVAR(&renamedKey);
								if (!(zephir_array_isset_fetch(&renamedKey, &columnMap, &key, 0))) {
									ZEPHIR_INIT_NVAR(&_12$$14);
									object_init_ex(&_12$$14, phalcon_mvc_model_exception_ce);
									ZEPHIR_INIT_NVAR(&_13$$14);
									ZEPHIR_CONCAT_SVS(&_13$$14, "Column '", &key, "' is not part of the column map");
									ZEPHIR_CALL_METHOD(NULL, &_12$$14, "__construct", &_9, 4, &_13$$14);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_12$$14, "phalcon/mvc/model/resultset/simple.zep", 199);
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (Z_TYPE_P(&renamedKey) == IS_ARRAY) {
									ZEPHIR_OBS_NVAR(&renamedKey);
									if (!(zephir_array_isset_long_fetch(&renamedKey, &renamedKey, 0, 0))) {
										ZEPHIR_INIT_NVAR(&_14$$16);
										object_init_ex(&_14$$16, phalcon_mvc_model_exception_ce);
										ZEPHIR_INIT_NVAR(&_15$$16);
										ZEPHIR_CONCAT_SVS(&_15$$16, "Column '", &key, "' is not part of the column map");
										ZEPHIR_CALL_METHOD(NULL, &_14$$16, "__construct", &_9, 4, &_15$$16);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_14$$16, "phalcon/mvc/model/resultset/simple.zep", 205);
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
								zephir_array_update_zval(&renamed, &renamedKey, &value, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(NULL, &record, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&value);
					ZEPHIR_INIT_NVAR(&key);
					zephir_array_append(&renamedRecords, &renamed, PH_SEPARATE, "phalcon/mvc/model/resultset/simple.zep", 215);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &records, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_2$$7, &records, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_2$$7)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&record, &records, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&renamed);
						array_init(&renamed);
						zephir_is_iterable(&record, 0, "phalcon/mvc/model/resultset/simple.zep", 215);
						if (Z_TYPE_P(&record) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&record), _18$$17, _19$$17, _16$$17)
							{
								ZEPHIR_INIT_NVAR(&key);
								if (_19$$17 != NULL) { 
									ZVAL_STR_COPY(&key, _19$$17);
								} else {
									ZVAL_LONG(&key, _18$$17);
								}
								ZEPHIR_INIT_NVAR(&value);
								ZVAL_COPY(&value, _16$$17);
								ZEPHIR_OBS_NVAR(&renamedKey);
								if (!(zephir_array_isset_fetch(&renamedKey, &columnMap, &key, 0))) {
									ZEPHIR_INIT_NVAR(&_20$$19);
									object_init_ex(&_20$$19, phalcon_mvc_model_exception_ce);
									ZEPHIR_INIT_NVAR(&_21$$19);
									ZEPHIR_CONCAT_SVS(&_21$$19, "Column '", &key, "' is not part of the column map");
									ZEPHIR_CALL_METHOD(NULL, &_20$$19, "__construct", &_9, 4, &_21$$19);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_20$$19, "phalcon/mvc/model/resultset/simple.zep", 199);
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (Z_TYPE_P(&renamedKey) == IS_ARRAY) {
									ZEPHIR_OBS_NVAR(&renamedKey);
									if (!(zephir_array_isset_long_fetch(&renamedKey, &renamedKey, 0, 0))) {
										ZEPHIR_INIT_NVAR(&_22$$21);
										object_init_ex(&_22$$21, phalcon_mvc_model_exception_ce);
										ZEPHIR_INIT_NVAR(&_23$$21);
										ZEPHIR_CONCAT_SVS(&_23$$21, "Column '", &key, "' is not part of the column map");
										ZEPHIR_CALL_METHOD(NULL, &_22$$21, "__construct", &_9, 4, &_23$$21);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_22$$21, "phalcon/mvc/model/resultset/simple.zep", 205);
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
								zephir_array_update_zval(&renamed, &renamedKey, &value, PH_COPY | PH_SEPARATE);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &record, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_17$$17, &record, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_17$$17)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&key, &record, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&value, &record, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_OBS_NVAR(&renamedKey);
									if (!(zephir_array_isset_fetch(&renamedKey, &columnMap, &key, 0))) {
										ZEPHIR_INIT_NVAR(&_24$$23);
										object_init_ex(&_24$$23, phalcon_mvc_model_exception_ce);
										ZEPHIR_INIT_NVAR(&_25$$23);
										ZEPHIR_CONCAT_SVS(&_25$$23, "Column '", &key, "' is not part of the column map");
										ZEPHIR_CALL_METHOD(NULL, &_24$$23, "__construct", &_9, 4, &_25$$23);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_24$$23, "phalcon/mvc/model/resultset/simple.zep", 199);
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (Z_TYPE_P(&renamedKey) == IS_ARRAY) {
										ZEPHIR_OBS_NVAR(&renamedKey);
										if (!(zephir_array_isset_long_fetch(&renamedKey, &renamedKey, 0, 0))) {
											ZEPHIR_INIT_NVAR(&_26$$25);
											object_init_ex(&_26$$25, phalcon_mvc_model_exception_ce);
											ZEPHIR_INIT_NVAR(&_27$$25);
											ZEPHIR_CONCAT_SVS(&_27$$25, "Column '", &key, "' is not part of the column map");
											ZEPHIR_CALL_METHOD(NULL, &_26$$25, "__construct", &_9, 4, &_27$$25);
											zephir_check_call_status();
											zephir_throw_exception_debug(&_26$$25, "phalcon/mvc/model/resultset/simple.zep", 205);
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
									zephir_array_update_zval(&renamed, &renamedKey, &value, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(NULL, &record, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&value);
						ZEPHIR_INIT_NVAR(&key);
						zephir_array_append(&renamedRecords, &renamed, PH_SEPARATE, "phalcon/mvc/model/resultset/simple.zep", 215);
					ZEPHIR_CALL_METHOD(NULL, &records, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&record);
		}
		RETURN_CCTOR(&renamedRecords);
	}
	RETURN_CCTOR(&records);

}

/**
 * Serializing a resultset will dump all related rows into a big array
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, serialize) {

	zval _1, _2, _3;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 6, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("_model"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("model"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("_cache"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("cache"), &_1, PH_COPY | PH_SEPARATE);
	ZVAL_BOOL(&_3, 0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "toarray", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("rows"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("_columnMap"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("columnMap"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("_hydrateMode"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("hydrateMode"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("_keepSnapshots"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("keepSnapshots"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 54, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserializing a resultset will allow to only works on the rows present in the saved state
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, unserialize) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, resultset, keepSnapshots, _0, _1, _2, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&resultset);
	ZVAL_UNDEF(&keepSnapshots);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_CALL_FUNCTION(&resultset, "unserialize", NULL, 55, data);
	zephir_check_call_status();
	if (Z_TYPE_P(&resultset) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data", "phalcon/mvc/model/resultset/simple.zep", 252);
		return;
	}
	zephir_array_fetch_string(&_0, &resultset, SL("model"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/simple.zep", 255);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_model"), &_0);
	zephir_array_fetch_string(&_1, &resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/simple.zep", 256);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_rows"), &_1);
	zephir_array_fetch_string(&_2, &resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/simple.zep", 257);
	ZEPHIR_INIT_ZVAL_NREF(_3);
	ZVAL_LONG(&_3, zephir_fast_count_int(&_2));
	zephir_update_property_zval(this_ptr, ZEND_STRL("_count"), &_3);
	zephir_array_fetch_string(&_4, &resultset, SL("cache"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/simple.zep", 258);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_cache"), &_4);
	zephir_array_fetch_string(&_5, &resultset, SL("columnMap"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/simple.zep", 259);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_columnMap"), &_5);
	zephir_array_fetch_string(&_6, &resultset, SL("hydrateMode"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/simple.zep", 260);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_hydrateMode"), &_6);
	if (zephir_array_isset_string_fetch(&keepSnapshots, &resultset, SL("keepSnapshots"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_keepSnapshots"), &keepSnapshots);
	}
	ZEPHIR_MM_RESTORE();

}

