
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


/**
 * Phalcon\Mvc\Model\MetaData\Session
 *
 * Stores model meta-data in session. Data will erased when the session finishes.
 * Meta-data are permanent while the session is active.
 *
 * You can query the meta-data by printing $_SESSION['$PMM$']
 *
 *<code>
 * $metaData = new \Phalcon\Mvc\Model\Metadata\Session(
 *     [
 *        "prefix" => "my-app-id",
 *     ]
 * );
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Session) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Session, phalcon, mvc_model_metadata_session, phalcon_mvc_model_metadata_ce, phalcon_mvc_model_metadata_session_method_entry, 0);

	zend_declare_property_string(phalcon_mvc_model_metadata_session_ce, SL("_prefix"), "", ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\MetaData\Session constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, __construct) {

	zval *options = NULL, options_sub, __$null, prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&prefix);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(options)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(0, 1, &options);

	if (!options) {
		options = &options_sub;
		options = &__$null;
	}


	if (Z_TYPE_P(options) == IS_ARRAY) {
		if (zephir_array_isset_string_fetch(&prefix, options, SL("prefix"), 1)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("_prefix"), &prefix);
		}
	}

}

/**
 * Reads meta-data from $_SESSION
 *
 * @param string key
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, read) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, _SESSION, metaData, _0, _1, _2;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_SESSION);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	zephir_read_property(&_1, this_ptr, ZEND_STRL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SV(&_2, "$PMM$", &_1);
	zephir_array_fetch(&_0, &_SESSION, &_2, PH_READONLY, "phalcon/mvc/model/metadata/session.zep", 71);
	if (zephir_array_isset_fetch(&metaData, &_0, &key, 1)) {
		RETURN_CTOR(&metaData);
	}
	RETURN_MM_NULL();

}

/**
 * Writes the meta-data to $_SESSION
 *
 * @param string key
 * @param array data
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, write) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, *data, data_sub, _SESSION, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_SESSION);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	zephir_fetch_params(1, 2, 0, &key_param, &data);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "$PMM$", &_0);
	zephir_array_update_multi(&_SESSION, data, SL("zz"), 2, &_1, &key);
	ZEPHIR_MM_RESTORE();

}

