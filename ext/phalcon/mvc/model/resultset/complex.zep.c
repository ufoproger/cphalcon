
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
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * Phalcon\Mvc\Model\Resultset\Complex
 *
 * Complex resultsets may include complete objects and scalar values.
 * This class builds every complex row as it is required
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Resultset_Complex) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Resultset, Complex, phalcon, mvc_model_resultset_complex, phalcon_mvc_model_resultset_ce, phalcon_mvc_model_resultset_complex_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_resultset_complex_ce, SL("_columnTypes"), ZEND_ACC_PROTECTED);

	/**
	 * Unserialised result-set hydrated all rows already. unserialise() sets _disableHydration to true
	 */
	zend_declare_property_bool(phalcon_mvc_model_resultset_complex_ce, SL("_disableHydration"), 0, ZEND_ACC_PROTECTED);

	zend_class_implements(phalcon_mvc_model_resultset_complex_ce, 1, phalcon_mvc_model_resultsetinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Resultset\Complex constructor
 *
 * @param array columnTypes
 * @param \Phalcon\Db\ResultInterface result
 * @param \Phalcon\Cache\BackendInterface cache
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *columnTypes, columnTypes_sub, *result = NULL, result_sub, *cache = NULL, cache_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columnTypes_sub);
	ZVAL_UNDEF(&result_sub);
	ZVAL_UNDEF(&cache_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(columnTypes)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(result, phalcon_db_resultinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(cache, phalcon_cache_backendinterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &columnTypes, &result, &cache);

	if (!result) {
		result = &result_sub;
		result = &__$null;
	}
	if (!cache) {
		cache = &cache_sub;
		cache = &__$null;
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("_columnTypes"), columnTypes);
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_resultset_complex_ce, getThis(), "__construct", &_0, 0, result, cache);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns current row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, current) {

	zend_class_entry *_14$$16, *_29$$36;
	zend_string *_5;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_15 = NULL, *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, dirtyState = 0;
	zval __$true, __$false, row, hydrateMode, eager, alias, activeRow, type, column, columnValue, value, attribute, source, attributes, columnMap, rowModel, keepSnapshots, sqlAlias, modelName, _0, _1, *_2, _3, *_6$$11, _7$$11, _8$$12, _9$$13, _10$$16, _12$$16, _13$$16, _11$$17, _16$$19, _17$$19, _19$$25, _20$$25, *_21$$31, _22$$31, _23$$32, _24$$33, _25$$36, _27$$36, _28$$36, _26$$37, _30$$39, _31$$39, _32$$45, _33$$45;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&hydrateMode);
	ZVAL_UNDEF(&eager);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&activeRow);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&columnValue);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&rowModel);
	ZVAL_UNDEF(&keepSnapshots);
	ZVAL_UNDEF(&sqlAlias);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_9$$13);
	ZVAL_UNDEF(&_10$$16);
	ZVAL_UNDEF(&_12$$16);
	ZVAL_UNDEF(&_13$$16);
	ZVAL_UNDEF(&_11$$17);
	ZVAL_UNDEF(&_16$$19);
	ZVAL_UNDEF(&_17$$19);
	ZVAL_UNDEF(&_19$$25);
	ZVAL_UNDEF(&_20$$25);
	ZVAL_UNDEF(&_22$$31);
	ZVAL_UNDEF(&_23$$32);
	ZVAL_UNDEF(&_24$$33);
	ZVAL_UNDEF(&_25$$36);
	ZVAL_UNDEF(&_27$$36);
	ZVAL_UNDEF(&_28$$36);
	ZVAL_UNDEF(&_26$$37);
	ZVAL_UNDEF(&_30$$39);
	ZVAL_UNDEF(&_31$$39);
	ZVAL_UNDEF(&_32$$45);
	ZVAL_UNDEF(&_33$$45);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&activeRow);
	zephir_read_property(&activeRow, this_ptr, ZEND_STRL("_activeRow"), PH_NOISY_CC);
	if (Z_TYPE_P(&activeRow) != IS_NULL) {
		RETURN_CCTOR(&activeRow);
	}
	ZEPHIR_OBS_VAR(&row);
	zephir_read_property(&row, this_ptr, ZEND_STRL("_row"), PH_NOISY_CC);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("_disableHydration"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_activeRow"), &row);
		RETURN_CCTOR(&row);
	}
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
	do {
		if (ZEPHIR_IS_LONG(&hydrateMode, 0)) {
			ZEPHIR_INIT_NVAR(&activeRow);
			object_init_ex(&activeRow, phalcon_mvc_model_row_ce);
			if (zephir_has_constructor(&activeRow)) {
				ZEPHIR_CALL_METHOD(NULL, &activeRow, "__construct", NULL, 0);
				zephir_check_call_status();
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&hydrateMode, 1)) {
			ZEPHIR_INIT_NVAR(&activeRow);
			array_init(&activeRow);
			break;
		}
		ZEPHIR_INIT_NVAR(&activeRow);
		object_init(&activeRow);
		break;
	} while(0);

	dirtyState = 0;
	zephir_read_property(&_1, this_ptr, ZEND_STRL("_columnTypes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_1, 0, "phalcon/mvc/model/resultset/complex.zep", 246);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_1), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&alias);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&alias, _5);
			} else {
				ZVAL_LONG(&alias, _4);
			}
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _2);
			if (Z_TYPE_P(&column) != IS_ARRAY) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Column type is corrupt", "phalcon/mvc/model/resultset/complex.zep", 133);
				return;
			}
			ZEPHIR_OBS_NVAR(&type);
			zephir_array_fetch_string(&type, &column, SL("type"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 136);
			if (ZEPHIR_IS_STRING(&type, "object")) {
				ZEPHIR_OBS_NVAR(&source);
				zephir_array_fetch_string(&source, &column, SL("column"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 142);
				ZEPHIR_OBS_NVAR(&attributes);
				zephir_array_fetch_string(&attributes, &column, SL("attributes"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 143);
				ZEPHIR_OBS_NVAR(&columnMap);
				zephir_array_fetch_string(&columnMap, &column, SL("columnMap"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 144);
				ZEPHIR_INIT_NVAR(&rowModel);
				array_init(&rowModel);
				zephir_is_iterable(&attributes, 0, "phalcon/mvc/model/resultset/complex.zep", 162);
				if (Z_TYPE_P(&attributes) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _6$$11)
					{
						ZEPHIR_INIT_NVAR(&attribute);
						ZVAL_COPY(&attribute, _6$$11);
						ZEPHIR_OBS_NVAR(&columnValue);
						ZEPHIR_INIT_NVAR(&_8$$12);
						ZEPHIR_CONCAT_SVSV(&_8$$12, "_", &source, "_", &attribute);
						zephir_array_fetch(&columnValue, &row, &_8$$12, PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 155);
						zephir_array_update_zval(&rowModel, &attribute, &columnValue, PH_COPY | PH_SEPARATE);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_7$$11, &attributes, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_7$$11)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_OBS_NVAR(&columnValue);
							ZEPHIR_INIT_NVAR(&_9$$13);
							ZEPHIR_CONCAT_SVSV(&_9$$13, "_", &source, "_", &attribute);
							zephir_array_fetch(&columnValue, &row, &_9$$13, PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 155);
							zephir_array_update_zval(&rowModel, &attribute, &columnValue, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&attribute);
				do {
					if (ZEPHIR_IS_LONG(&hydrateMode, 0)) {
						ZEPHIR_OBS_NVAR(&keepSnapshots);
						if (!(zephir_array_isset_string_fetch(&keepSnapshots, &column, SL("keepSnapshots"), 0))) {
							ZEPHIR_INIT_NVAR(&keepSnapshots);
							ZVAL_BOOL(&keepSnapshots, 0);
						}
						if (ZEPHIR_GLOBAL(orm).late_state_binding) {
							ZEPHIR_OBS_NVAR(&_10$$16);
							zephir_array_fetch_string(&_10$$16, &column, SL("instance"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 173);
							if (zephir_instance_of_ev(&_10$$16, phalcon_mvc_model_ce)) {
								zephir_array_fetch_string(&_11$$17, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 174);
								ZEPHIR_INIT_NVAR(&modelName);
								zephir_get_class(&modelName, &_11$$17, 0);
							} else {
								ZEPHIR_INIT_NVAR(&modelName);
								ZVAL_STRING(&modelName, "Phalcon\\Mvc\\Model");
							}
							zephir_array_fetch_string(&_12$$16, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 180);
							ZVAL_LONG(&_13$$16, dirtyState);
							_14$$16 = zephir_fetch_class(&modelName);
							ZEPHIR_CALL_CE_STATIC(&value, _14$$16, "cloneresultmap", NULL, 0, &_12$$16, &rowModel, &columnMap, &_13$$16, &keepSnapshots);
							zephir_check_call_status();
						} else {
							zephir_array_fetch_string(&_16$$19, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 188);
							ZVAL_LONG(&_17$$19, dirtyState);
							ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmap", &_15, 0, &_16$$19, &rowModel, &columnMap, &_17$$19, &keepSnapshots);
							zephir_check_call_status();
						}
						break;
					}
					ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmaphydrate", &_18, 0, &rowModel, &columnMap, &hydrateMode);
					zephir_check_call_status();
					break;
				} while(0);

				ZEPHIR_OBS_NVAR(&attribute);
				zephir_array_fetch_string(&attribute, &column, SL("balias"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 202);
			} else {
				ZEPHIR_OBS_NVAR(&sqlAlias);
				if (zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0)) {
					ZEPHIR_OBS_NVAR(&value);
					zephir_array_fetch(&value, &row, &sqlAlias, PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 210);
				} else {
					ZEPHIR_OBS_NVAR(&value);
					zephir_array_isset_fetch(&value, &row, &alias, 0);
				}
				if (zephir_array_isset_string(&column, SL("balias"))) {
					ZEPHIR_CPY_WRT(&attribute, &alias);
				} else {
					ZEPHIR_INIT_NVAR(&_19$$25);
					ZVAL_STRING(&_19$$25, "_");
					ZEPHIR_INIT_NVAR(&_20$$25);
					ZVAL_STRING(&_20$$25, "");
					ZEPHIR_INIT_NVAR(&attribute);
					zephir_fast_str_replace(&attribute, &_19$$25, &_20$$25, &alias);
				}
			}
			if (!(zephir_array_isset_string_fetch(&eager, &column, SL("eager"), 1))) {
				do {
					if (ZEPHIR_IS_LONG(&hydrateMode, 1)) {
						zephir_array_update_zval(&activeRow, &attribute, &value, PH_COPY | PH_SEPARATE);
						break;
					}
					zephir_update_property_zval_zval(&activeRow, &attribute, &value);
					break;
				} while(0);

			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_1, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &_1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&alias, &_1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&column, &_1, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&column) != IS_ARRAY) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Column type is corrupt", "phalcon/mvc/model/resultset/complex.zep", 133);
					return;
				}
				ZEPHIR_OBS_NVAR(&type);
				zephir_array_fetch_string(&type, &column, SL("type"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 136);
				if (ZEPHIR_IS_STRING(&type, "object")) {
					ZEPHIR_OBS_NVAR(&source);
					zephir_array_fetch_string(&source, &column, SL("column"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 142);
					ZEPHIR_OBS_NVAR(&attributes);
					zephir_array_fetch_string(&attributes, &column, SL("attributes"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 143);
					ZEPHIR_OBS_NVAR(&columnMap);
					zephir_array_fetch_string(&columnMap, &column, SL("columnMap"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 144);
					ZEPHIR_INIT_NVAR(&rowModel);
					array_init(&rowModel);
					zephir_is_iterable(&attributes, 0, "phalcon/mvc/model/resultset/complex.zep", 162);
					if (Z_TYPE_P(&attributes) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _21$$31)
						{
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _21$$31);
							ZEPHIR_OBS_NVAR(&columnValue);
							ZEPHIR_INIT_NVAR(&_23$$32);
							ZEPHIR_CONCAT_SVSV(&_23$$32, "_", &source, "_", &attribute);
							zephir_array_fetch(&columnValue, &row, &_23$$32, PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 155);
							zephir_array_update_zval(&rowModel, &attribute, &columnValue, PH_COPY | PH_SEPARATE);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_22$$31, &attributes, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_22$$31)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_OBS_NVAR(&columnValue);
								ZEPHIR_INIT_NVAR(&_24$$33);
								ZEPHIR_CONCAT_SVSV(&_24$$33, "_", &source, "_", &attribute);
								zephir_array_fetch(&columnValue, &row, &_24$$33, PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 155);
								zephir_array_update_zval(&rowModel, &attribute, &columnValue, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&attribute);
					do {
						if (ZEPHIR_IS_LONG(&hydrateMode, 0)) {
							ZEPHIR_OBS_NVAR(&keepSnapshots);
							if (!(zephir_array_isset_string_fetch(&keepSnapshots, &column, SL("keepSnapshots"), 0))) {
								ZEPHIR_INIT_NVAR(&keepSnapshots);
								ZVAL_BOOL(&keepSnapshots, 0);
							}
							if (ZEPHIR_GLOBAL(orm).late_state_binding) {
								ZEPHIR_OBS_NVAR(&_25$$36);
								zephir_array_fetch_string(&_25$$36, &column, SL("instance"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 173);
								if (zephir_instance_of_ev(&_25$$36, phalcon_mvc_model_ce)) {
									zephir_array_fetch_string(&_26$$37, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 174);
									ZEPHIR_INIT_NVAR(&modelName);
									zephir_get_class(&modelName, &_26$$37, 0);
								} else {
									ZEPHIR_INIT_NVAR(&modelName);
									ZVAL_STRING(&modelName, "Phalcon\\Mvc\\Model");
								}
								zephir_array_fetch_string(&_27$$36, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 180);
								ZVAL_LONG(&_28$$36, dirtyState);
								_29$$36 = zephir_fetch_class(&modelName);
								ZEPHIR_CALL_CE_STATIC(&value, _29$$36, "cloneresultmap", NULL, 0, &_27$$36, &rowModel, &columnMap, &_28$$36, &keepSnapshots);
								zephir_check_call_status();
							} else {
								zephir_array_fetch_string(&_30$$39, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 188);
								ZVAL_LONG(&_31$$39, dirtyState);
								ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmap", &_15, 0, &_30$$39, &rowModel, &columnMap, &_31$$39, &keepSnapshots);
								zephir_check_call_status();
							}
							break;
						}
						ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmaphydrate", &_18, 0, &rowModel, &columnMap, &hydrateMode);
						zephir_check_call_status();
						break;
					} while(0);

					ZEPHIR_OBS_NVAR(&attribute);
					zephir_array_fetch_string(&attribute, &column, SL("balias"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 202);
				} else {
					ZEPHIR_OBS_NVAR(&sqlAlias);
					if (zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0)) {
						ZEPHIR_OBS_NVAR(&value);
						zephir_array_fetch(&value, &row, &sqlAlias, PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 210);
					} else {
						ZEPHIR_OBS_NVAR(&value);
						zephir_array_isset_fetch(&value, &row, &alias, 0);
					}
					if (zephir_array_isset_string(&column, SL("balias"))) {
						ZEPHIR_CPY_WRT(&attribute, &alias);
					} else {
						ZEPHIR_INIT_NVAR(&_32$$45);
						ZVAL_STRING(&_32$$45, "_");
						ZEPHIR_INIT_NVAR(&_33$$45);
						ZVAL_STRING(&_33$$45, "");
						ZEPHIR_INIT_NVAR(&attribute);
						zephir_fast_str_replace(&attribute, &_32$$45, &_33$$45, &alias);
					}
				}
				ZEPHIR_OBS_NVAR(&eager);
				if (!(zephir_array_isset_string_fetch(&eager, &column, SL("eager"), 0))) {
					do {
						if (ZEPHIR_IS_LONG(&hydrateMode, 1)) {
							zephir_array_update_zval(&activeRow, &attribute, &value, PH_COPY | PH_SEPARATE);
							break;
						}
						zephir_update_property_zval_zval(&activeRow, &attribute, &value);
						break;
					} while(0);

				}
			ZEPHIR_CALL_METHOD(NULL, &_1, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	ZEPHIR_INIT_NVAR(&alias);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_activeRow"), &activeRow);
	RETURN_CCTOR(&activeRow);

}

/**
 * Returns a complete resultset as an array, if the resultset has a big number of rows
 * it could consume more memory than currently it does.
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, toArray) {

	zval records, current, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&current);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&records);
	array_init(&records);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL, 66);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid", &_1, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_0))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&current, this_ptr, "current", &_2, 307);
		zephir_check_call_status();
		zephir_array_append(&records, &current, PH_SEPARATE, "phalcon/mvc/model/resultset/complex.zep", 263);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "next", &_3, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&records);

}

/**
 * Serializing a resultset will dump all related rows into a big array
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, serialize) {

	zval _0;
	zval records, cache, columnTypes, hydrateMode, serialized;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&columnTypes);
	ZVAL_UNDEF(&hydrateMode);
	ZVAL_UNDEF(&serialized);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&records, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&cache);
	zephir_read_property(&cache, this_ptr, ZEND_STRL("_cache"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&columnTypes);
	zephir_read_property(&columnTypes, this_ptr, ZEND_STRL("_columnTypes"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&hydrateMode);
	zephir_read_property(&hydrateMode, this_ptr, ZEND_STRL("_hydrateMode"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	zephir_array_update_string(&_0, SL("cache"), &cache, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("rows"), &records, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("columnTypes"), &columnTypes, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("hydrateMode"), &hydrateMode, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&serialized, "serialize", NULL, 54, &_0);
	zephir_check_call_status();
	RETURN_CCTOR(&serialized);

}

/**
 * Unserializing a resultset will allow to only works on the rows present in the saved state
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, unserialize) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, __$true, __$false, resultset, _0, _1, _2, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&resultset);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_disableHydration"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_disableHydration"), &__$false);
	}
	ZEPHIR_CALL_FUNCTION(&resultset, "unserialize", NULL, 55, data);
	zephir_check_call_status();
	if (Z_TYPE_P(&resultset) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data", "phalcon/mvc/model/resultset/complex.zep", 310);
		return;
	}
	zephir_array_fetch_string(&_0, &resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 313);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_rows"), &_0);
	zephir_array_fetch_string(&_1, &resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 314);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, zephir_fast_count_int(&_1));
	zephir_update_property_zval(this_ptr, ZEND_STRL("_count"), &_2);
	zephir_array_fetch_string(&_3, &resultset, SL("cache"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 315);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_cache"), &_3);
	zephir_array_fetch_string(&_4, &resultset, SL("columnTypes"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 316);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_columnTypes"), &_4);
	zephir_array_fetch_string(&_5, &resultset, SL("hydrateMode"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 317);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_hydrateMode"), &_5);
	ZEPHIR_MM_RESTORE();

}

