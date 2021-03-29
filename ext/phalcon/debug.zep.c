
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/time.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * Phalcon\Debug
 *
 * Provides debug capabilities to Phalcon applications
 */
ZEPHIR_INIT_CLASS(Phalcon_Debug) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Debug, phalcon, debug, phalcon_debug_method_entry, 0);

	zend_declare_property_string(phalcon_debug_ce, SL("_uri"), "//static.phalconphp.com/www/debug/3.0.x/", ZEND_ACC_PUBLIC);

	zend_declare_property_string(phalcon_debug_ce, SL("_theme"), "default", ZEND_ACC_PUBLIC);

	zend_declare_property_bool(phalcon_debug_ce, SL("_hideDocumentRoot"), 0, ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalcon_debug_ce, SL("_showBackTrace"), 1, ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalcon_debug_ce, SL("_showFiles"), 1, ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalcon_debug_ce, SL("_showFileFragment"), 0, ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_debug_ce, SL("_data"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_debug_ce, SL("_isActive"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);

	return SUCCESS;

}

/**
 * Change the base URI for static resources
 */
PHP_METHOD(Phalcon_Debug, setUri) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *uri_param = NULL;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	if (UNEXPECTED(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(&uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_EMPTY_STRING(&uri);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("_uri"), &uri);
	RETURN_THIS();

}

/**
 * Sets if files the exception's backtrace must be showed
 */
PHP_METHOD(Phalcon_Debug, setShowBackTrace) {

	zval *showBackTrace_param = NULL, __$true, __$false;
	zend_bool showBackTrace;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(showBackTrace)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &showBackTrace_param);

	showBackTrace = zephir_get_boolval(showBackTrace_param);


	if (showBackTrace) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_showBackTrace"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_showBackTrace"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Set if files part of the backtrace must be shown in the output
 */
PHP_METHOD(Phalcon_Debug, setShowFiles) {

	zval *showFiles_param = NULL, __$true, __$false;
	zend_bool showFiles;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(showFiles)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &showFiles_param);

	showFiles = zephir_get_boolval(showFiles_param);


	if (showFiles) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_showFiles"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_showFiles"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Sets if files must be completely opened and showed in the output
 * or just the fragment related to the exception
 */
PHP_METHOD(Phalcon_Debug, setShowFileFragment) {

	zval *showFileFragment_param = NULL, __$true, __$false;
	zend_bool showFileFragment;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(showFileFragment)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &showFileFragment_param);

	showFileFragment = zephir_get_boolval(showFileFragment_param);


	if (showFileFragment) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_showFileFragment"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_showFileFragment"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Listen for uncaught exceptions and unsilent notices or warnings
 */
PHP_METHOD(Phalcon_Debug, listen) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exceptions_param = NULL, *lowSeverity_param = NULL;
	zend_bool exceptions, lowSeverity;
	zval *this_ptr = getThis();

#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(exceptions)
		Z_PARAM_BOOL(lowSeverity)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &exceptions_param, &lowSeverity_param);

	if (!exceptions_param) {
		exceptions = 1;
	} else {
		exceptions = zephir_get_boolval(exceptions_param);
	}
	if (!lowSeverity_param) {
		lowSeverity = 0;
	} else {
		lowSeverity = zephir_get_boolval(lowSeverity_param);
	}


	if (exceptions) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "listenexceptions", NULL, 0);
		zephir_check_call_status();
	}
	if (lowSeverity) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "listenlowseverity", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Listen for uncaught exceptions
 */
PHP_METHOD(Phalcon_Debug, listenExceptions) {

	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "onUncaughtException");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 147, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Listen for unsilent notices or warnings
 */
PHP_METHOD(Phalcon_Debug, listenLowSeverity) {

	zval _1;
	zval _0, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "onUncaughtLowSeverity");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 148, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	zephir_array_fast_append(&_2, this_ptr);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "onUncaughtException");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 147, &_2);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Halts the request showing a backtrace
 */
PHP_METHOD(Phalcon_Debug, halt) {

	zval *this_ptr = getThis();



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_exception_ce, "Halted request", "phalcon/debug.zep", 120);
	return;

}

/**
 * Adds a variable to the debug output
 */
PHP_METHOD(Phalcon_Debug, debugVar) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key;
	zval *varz, varz_sub, *key_param = NULL, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&varz_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(varz)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(key)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &varz, &key_param);

	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_STRING(&key, "");
	} else {
		zephir_get_strval(&key, key_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	zephir_array_fast_append(&_0, varz);
	ZEPHIR_CALL_FUNCTION(&_1, "debug_backtrace", NULL, 149);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_time(&_2);
	zephir_array_fast_append(&_0, &_2);
	zephir_update_property_array_append(this_ptr, SL("_data"), &_0);
	RETURN_THIS();

}

/**
 * Clears are variables added previously
 */
PHP_METHOD(Phalcon_Debug, clearVars) {

	zval __$null;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);



	zephir_update_property_zval(this_ptr, ZEND_STRL("_data"), &__$null);
	RETURN_THISW();

}

/**
 * Escapes a string with htmlentities
 */
PHP_METHOD(Phalcon_Debug, _escapeString) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	if (Z_TYPE_P(value) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "\n");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "\\n");
		zephir_fast_str_replace(&_0$$3, &_1$$3, &_2$$3, value);
		ZVAL_LONG(&_3$$3, 2);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "utf-8");
		ZEPHIR_RETURN_CALL_FUNCTION("htmlentities", NULL, 150, &_0$$3, &_3$$3, &_4$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

/**
 * Produces a recursive representation of an array
 */
PHP_METHOD(Phalcon_Debug, _getArrayDump) {

	zend_string *_4;
	zend_ulong _3;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *argument_param = NULL, *n = NULL, n_sub, numberArguments, dump, varDump, k, v, *_1, _2, _6$$8, _7$$8, _9$$9, _10$$5, _11$$15, _12$$15, _13$$16, _14$$12;
	zval argument;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&n_sub);
	ZVAL_UNDEF(&numberArguments);
	ZVAL_UNDEF(&dump);
	ZVAL_UNDEF(&varDump);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$15);
	ZVAL_UNDEF(&_12$$15);
	ZVAL_UNDEF(&_13$$16);
	ZVAL_UNDEF(&_14$$12);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(argument)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(n)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &argument_param, &n);

	ZEPHIR_OBS_COPY_OR_DUP(&argument, argument_param);
	if (!n) {
		n = &n_sub;
		ZEPHIR_INIT_VAR(n);
		ZVAL_LONG(n, 0);
	}


	ZEPHIR_INIT_VAR(&numberArguments);
	ZVAL_LONG(&numberArguments, zephir_fast_count_int(&argument));
	_0 = ZEPHIR_GE_LONG(n, 3);
	if (!(_0)) {
		_0 = ZEPHIR_IS_LONG(&numberArguments, 0);
	}
	if (_0) {
		RETURN_MM_NULL();
	}
	if (ZEPHIR_GE_LONG(&numberArguments, 10)) {
		RETURN_CCTOR(&numberArguments);
	}
	ZEPHIR_INIT_VAR(&dump);
	array_init(&dump);
	zephir_is_iterable(&argument, 0, "phalcon/debug.zep", 189);
	if (Z_TYPE_P(&argument) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&argument), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&k, _4);
			} else {
				ZVAL_LONG(&k, _3);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _1);
			if (ZEPHIR_IS_STRING(&v, "")) {
				ZEPHIR_INIT_NVAR(&varDump);
				ZVAL_STRING(&varDump, "(empty string)");
			} else if (zephir_is_scalar(&v)) {
				ZEPHIR_CALL_METHOD(&varDump, this_ptr, "_escapestring", &_5, 0, &v);
				zephir_check_call_status();
			} else if (Z_TYPE_P(&v) == IS_ARRAY) {
				ZVAL_LONG(&_7$$8, (zephir_get_numberval(n) + 1));
				ZEPHIR_CALL_METHOD(&_6$$8, this_ptr, "_getarraydump", &_8, 151, &v, &_7$$8);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&varDump);
				ZEPHIR_CONCAT_SVS(&varDump, "Array(", &_6$$8, ")");
			} else if (Z_TYPE_P(&v) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(&_9$$9);
				zephir_get_class(&_9$$9, &v, 0);
				ZEPHIR_INIT_NVAR(&varDump);
				ZEPHIR_CONCAT_SVS(&varDump, "Object(", &_9$$9, ")");
			} else if (Z_TYPE_P(&v) == IS_NULL) {
				ZEPHIR_INIT_NVAR(&varDump);
				ZVAL_STRING(&varDump, "null");
			} else {
				ZEPHIR_CPY_WRT(&varDump, &v);
			}
			ZEPHIR_INIT_NVAR(&_10$$5);
			ZEPHIR_CONCAT_SVSV(&_10$$5, "[", &k, "] =&gt; ", &varDump);
			zephir_array_append(&dump, &_10$$5, PH_SEPARATE, "phalcon/debug.zep", 186);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &argument, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &argument, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&k, &argument, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&v, &argument, "current", NULL, 0);
			zephir_check_call_status();
				if (ZEPHIR_IS_STRING(&v, "")) {
					ZEPHIR_INIT_NVAR(&varDump);
					ZVAL_STRING(&varDump, "(empty string)");
				} else if (zephir_is_scalar(&v)) {
					ZEPHIR_CALL_METHOD(&varDump, this_ptr, "_escapestring", &_5, 0, &v);
					zephir_check_call_status();
				} else if (Z_TYPE_P(&v) == IS_ARRAY) {
					ZVAL_LONG(&_12$$15, (zephir_get_numberval(n) + 1));
					ZEPHIR_CALL_METHOD(&_11$$15, this_ptr, "_getarraydump", &_8, 151, &v, &_12$$15);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&varDump);
					ZEPHIR_CONCAT_SVS(&varDump, "Array(", &_11$$15, ")");
				} else if (Z_TYPE_P(&v) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_13$$16);
					zephir_get_class(&_13$$16, &v, 0);
					ZEPHIR_INIT_NVAR(&varDump);
					ZEPHIR_CONCAT_SVS(&varDump, "Object(", &_13$$16, ")");
				} else if (Z_TYPE_P(&v) == IS_NULL) {
					ZEPHIR_INIT_NVAR(&varDump);
					ZVAL_STRING(&varDump, "null");
				} else {
					ZEPHIR_CPY_WRT(&varDump, &v);
				}
				ZEPHIR_INIT_NVAR(&_14$$12);
				ZEPHIR_CONCAT_SVSV(&_14$$12, "[", &k, "] =&gt; ", &varDump);
				zephir_array_append(&dump, &_14$$12, PH_SEPARATE, "phalcon/debug.zep", 186);
			ZEPHIR_CALL_METHOD(NULL, &argument, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_fast_join_str(return_value, SL(", "), &dump);
	RETURN_MM();

}

/**
 * Produces an string representation of a variable
 */
PHP_METHOD(Phalcon_Debug, _getVarDump) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *variable, variable_sub, className, dumpedObject, _0$$9, _1$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&dumpedObject);
	ZVAL_UNDEF(&_0$$9);
	ZVAL_UNDEF(&_1$$11);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(variable)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &variable);



	if (zephir_is_scalar(variable)) {
		if (((Z_TYPE_P(variable) == IS_TRUE || Z_TYPE_P(variable) == IS_FALSE) == 1)) {
			if (zephir_is_true(variable)) {
				RETURN_MM_STRING("true");
			} else {
				RETURN_MM_STRING("false");
			}
		}
		if (Z_TYPE_P(variable) == IS_STRING) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_escapestring", NULL, 0, variable);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETVAL_ZVAL(variable, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&className);
		zephir_get_class(&className, variable, 0);
		if ((zephir_method_exists_ex(variable, ZEND_STRL("dump")) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&dumpedObject, variable, "dump", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_0$$9, this_ptr, "_getarraydump", NULL, 0, &dumpedObject);
			zephir_check_call_status();
			ZEPHIR_CONCAT_SVSVS(return_value, "Object(", &className, ": ", &_0$$9, ")");
			RETURN_MM();
		} else {
			ZEPHIR_CONCAT_SVS(return_value, "Object(", &className, ")");
			RETURN_MM();
		}
	}
	if (Z_TYPE_P(variable) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_1$$11, this_ptr, "_getarraydump", NULL, 151, variable);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVS(return_value, "Array(", &_1$$11, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		RETURN_MM_STRING("null");
	}
	zephir_gettype(return_value, variable);
	RETURN_MM();

}

/**
 * Returns the major framework's version
 *
 * @deprecated Will be removed in 4.0.0
 * @see Phalcon\Version::getPart()
 */
PHP_METHOD(Phalcon_Debug, getMajorVersion) {

	zval parts, _0, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_version_ce, "get", &_1, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode_str(&parts, SL(" "), &_0, LONG_MAX);
	zephir_array_fetch_long(&_2, &parts, 0, PH_NOISY | PH_READONLY, "phalcon/debug.zep", 281);
	RETURN_CTOR(&_2);

}

/**
 * Generates a link to the current version documentation
 */
PHP_METHOD(Phalcon_Debug, getVersion) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$false, link, _0, _2, _3, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_5 = NULL, *_6 = NULL;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&link);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&link);
	zephir_create_array(&link, 4, 0);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_version_ce, "getpart", &_1, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SVS(&_3, "https://docs.phalconphp.com/en/", &_0, ".0.0/");
	zephir_array_update_string(&link, SL("action"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_CE_STATIC(&_4, phalcon_version_ce, "get", &_5, 0);
	zephir_check_call_status();
	zephir_array_update_string(&link, SL("text"), &_4, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&link, SL("local"), &__$false, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&link, SL("target"), SL("_new"));
	ZEPHIR_CALL_CE_STATIC(&_4, phalcon_tag_ce, "linkto", &_6, 0, &link);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<div class='version'>Phalcon Framework ", &_4, "</div>");
	RETURN_MM();

}

/**
 * Returns the css sources
 */
PHP_METHOD(Phalcon_Debug, getCssSources) {

	zval uri, sources, _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&sources);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	zephir_read_property(&uri, this_ptr, ZEND_STRL("_uri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&sources);
	ZEPHIR_CONCAT_SVS(&sources, "<link href=\"", &uri, "bower_components/jquery-ui/themes/ui-lightness/jquery-ui.min.css\" type=\"text/css\" rel=\"stylesheet\" />");
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVS(&_0, "<link href=\"", &uri, "bower_components/jquery-ui/themes/ui-lightness/theme.css\" type=\"text/css\" rel=\"stylesheet\" />");
	zephir_concat_self(&sources, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "<link href=\"", &uri, "themes/default/style.css\" type=\"text/css\" rel=\"stylesheet\" />");
	zephir_concat_self(&sources, &_1);
	RETURN_CCTOR(&sources);

}

/**
 * Returns the javascript sources
 */
PHP_METHOD(Phalcon_Debug, getJsSources) {

	zval uri, sources, _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&sources);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&uri, this_ptr, ZEND_STRL("_uri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&sources);
	ZEPHIR_CONCAT_SVS(&sources, "<script type=\"text/javascript\" src=\"", &uri, "bower_components/jquery/dist/jquery.min.js\"></script>");
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVS(&_0, "<script type=\"text/javascript\" src=\"", &uri, "bower_components/jquery-ui/jquery-ui.min.js\"></script>");
	zephir_concat_self(&sources, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "<script type=\"text/javascript\" src=\"", &uri, "bower_components/jquery.scrollTo/jquery.scrollTo.min.js\"></script>");
	zephir_concat_self(&sources, &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVS(&_2, "<script type=\"text/javascript\" src=\"", &uri, "prettify/prettify.js\"></script>");
	zephir_concat_self(&sources, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SVS(&_3, "<script type=\"text/javascript\" src=\"", &uri, "pretty.js\"></script>");
	zephir_concat_self(&sources, &_3);
	RETURN_CCTOR(&sources);

}

/**
 * Shows a backtrace item
 */
PHP_METHOD(Phalcon_Debug, showTraceItem) {

	zend_bool _40$$25;
	zval _1, _28$$17;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_21 = NULL, *_47 = NULL;
	zval trace;
	zval *n_param = NULL, *trace_param = NULL, className, prepareInternalClass, preparedFunctionName, html, classReflection, prepareUriClass, functionName, functionReflection, traceArgs, arguments, argument, filez, line, showFiles, lines, numberLines, showFileFragment, firstLine, lastLine, linePosition, currentLine, classNameWithLink, functionNameWithLink, _0, _17, _2$$3, _3$$3, _4$$3, _5$$3, _12$$3, _13$$3, _6$$4, _7$$4, _8$$5, _9$$6, _10$$6, _11$$6, _14$$10, _15$$11, _16$$11, *_18$$14, _19$$14, _25$$14, _26$$14, _20$$15, _22$$15, _23$$16, _24$$16, _27$$17, _29$$17, _30$$19, _31$$24, _32$$27, _33$$27, _34$$27, _35$$27, _36$$27, _37$$28, _38$$28, _39$$28, _41$$30, _42$$30, _43$$30, _44$$30, _45$$30, _46$$30;
	zend_long n, ZEPHIR_LAST_CALL_STATUS, i = 0, beforeLine$$19, afterLine$$19;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&prepareInternalClass);
	ZVAL_UNDEF(&preparedFunctionName);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&classReflection);
	ZVAL_UNDEF(&prepareUriClass);
	ZVAL_UNDEF(&functionName);
	ZVAL_UNDEF(&functionReflection);
	ZVAL_UNDEF(&traceArgs);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&filez);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&showFiles);
	ZVAL_UNDEF(&lines);
	ZVAL_UNDEF(&numberLines);
	ZVAL_UNDEF(&showFileFragment);
	ZVAL_UNDEF(&firstLine);
	ZVAL_UNDEF(&lastLine);
	ZVAL_UNDEF(&linePosition);
	ZVAL_UNDEF(&currentLine);
	ZVAL_UNDEF(&classNameWithLink);
	ZVAL_UNDEF(&functionNameWithLink);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_29$$17);
	ZVAL_UNDEF(&_30$$19);
	ZVAL_UNDEF(&_31$$24);
	ZVAL_UNDEF(&_32$$27);
	ZVAL_UNDEF(&_33$$27);
	ZVAL_UNDEF(&_34$$27);
	ZVAL_UNDEF(&_35$$27);
	ZVAL_UNDEF(&_36$$27);
	ZVAL_UNDEF(&_37$$28);
	ZVAL_UNDEF(&_38$$28);
	ZVAL_UNDEF(&_39$$28);
	ZVAL_UNDEF(&_41$$30);
	ZVAL_UNDEF(&_42$$30);
	ZVAL_UNDEF(&_43$$30);
	ZVAL_UNDEF(&_44$$30);
	ZVAL_UNDEF(&_45$$30);
	ZVAL_UNDEF(&_46$$30);
	ZVAL_UNDEF(&trace);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_28$$17);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_ARRAY(trace)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &n_param, &trace_param);

	n = zephir_get_intval(n_param);
	ZEPHIR_OBS_COPY_OR_DUP(&trace, trace_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, n);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "<tr><td align=\"right\" valign=\"top\" class=\"error-number\">#", &_0, "</td><td>");
	ZEPHIR_CPY_WRT(&html, &_1);
	ZEPHIR_OBS_VAR(&className);
	if (zephir_array_isset_string_fetch(&className, &trace, SL("class"), 0)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "/^Phalcon/");
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "/^Phalcon/");
		zephir_preg_match(&_4$$3, &_5$$3, &className, &_2$$3, 0, 0 , 0 );
		if (zephir_is_true(&_4$$3)) {
			ZEPHIR_INIT_VAR(&_6$$4);
			ZVAL_STRING(&_6$$4, "\\");
			ZEPHIR_INIT_VAR(&_7$$4);
			ZVAL_STRING(&_7$$4, "/");
			ZEPHIR_INIT_VAR(&prepareUriClass);
			zephir_fast_str_replace(&prepareUriClass, &_6$$4, &_7$$4, &className);
			ZEPHIR_INIT_VAR(&classNameWithLink);
			ZEPHIR_CONCAT_SVSVS(&classNameWithLink, "<a target=\"_new\" href=\"//api.phalconphp.com/class/", &prepareUriClass, ".html\">", &className, "</a>");
		} else {
			ZEPHIR_INIT_VAR(&classReflection);
			object_init_ex(&classReflection, zephir_get_internal_ce(SL("reflectionclass")));
			ZEPHIR_CALL_METHOD(NULL, &classReflection, "__construct", NULL, 80, &className);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_8$$5, &classReflection, "isinternal", NULL, 152);
			zephir_check_call_status();
			if (zephir_is_true(&_8$$5)) {
				ZEPHIR_INIT_VAR(&_9$$6);
				zephir_fast_strtolower(&_9$$6, &className);
				ZEPHIR_INIT_VAR(&_10$$6);
				ZVAL_STRING(&_10$$6, "_");
				ZEPHIR_INIT_VAR(&_11$$6);
				ZVAL_STRING(&_11$$6, "-");
				ZEPHIR_INIT_VAR(&prepareInternalClass);
				zephir_fast_str_replace(&prepareInternalClass, &_10$$6, &_11$$6, &_9$$6);
				ZEPHIR_INIT_NVAR(&classNameWithLink);
				ZEPHIR_CONCAT_SVSVS(&classNameWithLink, "<a target=\"_new\" href=\"http://php.net/manual/en/class.", &prepareInternalClass, ".php\">", &className, "</a>");
			} else {
				ZEPHIR_CPY_WRT(&classNameWithLink, &className);
			}
		}
		ZEPHIR_INIT_VAR(&_12$$3);
		ZEPHIR_CONCAT_SVS(&_12$$3, "<span class=\"error-class\">", &classNameWithLink, "</span>");
		zephir_concat_self(&html, &_12$$3);
		zephir_array_fetch_string(&_13$$3, &trace, SL("type"), PH_NOISY | PH_READONLY, "phalcon/debug.zep", 388);
		zephir_concat_self(&html, &_13$$3);
	}
	ZEPHIR_OBS_VAR(&functionName);
	zephir_array_fetch_string(&functionName, &trace, SL("function"), PH_NOISY, "phalcon/debug.zep", 394);
	if (zephir_array_isset_string(&trace, SL("class"))) {
		ZEPHIR_CPY_WRT(&functionNameWithLink, &functionName);
	} else {
		if ((zephir_function_exists(&functionName) == SUCCESS)) {
			ZEPHIR_INIT_VAR(&functionReflection);
			object_init_ex(&functionReflection, zephir_get_internal_ce(SL("reflectionfunction")));
			ZEPHIR_CALL_METHOD(NULL, &functionReflection, "__construct", NULL, 71, &functionName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_14$$10, &functionReflection, "isinternal", NULL, 153);
			zephir_check_call_status();
			if (zephir_is_true(&_14$$10)) {
				ZEPHIR_INIT_VAR(&_15$$11);
				ZVAL_STRING(&_15$$11, "_");
				ZEPHIR_INIT_VAR(&_16$$11);
				ZVAL_STRING(&_16$$11, "-");
				ZEPHIR_INIT_VAR(&preparedFunctionName);
				zephir_fast_str_replace(&preparedFunctionName, &_15$$11, &_16$$11, &functionName);
				ZEPHIR_INIT_NVAR(&functionNameWithLink);
				ZEPHIR_CONCAT_SVSVS(&functionNameWithLink, "<a target=\"_new\" href=\"http://php.net/manual/en/function.", &preparedFunctionName, ".php\">", &functionName, "</a>");
			} else {
				ZEPHIR_CPY_WRT(&functionNameWithLink, &functionName);
			}
		} else {
			ZEPHIR_CPY_WRT(&functionNameWithLink, &functionName);
		}
	}
	ZEPHIR_INIT_VAR(&_17);
	ZEPHIR_CONCAT_SVS(&_17, "<span class=\"error-function\">", &functionNameWithLink, "</span>");
	zephir_concat_self(&html, &_17);
	ZEPHIR_OBS_VAR(&traceArgs);
	if (zephir_array_isset_string_fetch(&traceArgs, &trace, SL("args"), 0)) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
		zephir_is_iterable(&traceArgs, 0, "phalcon/debug.zep", 443);
		if (Z_TYPE_P(&traceArgs) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&traceArgs), _18$$14)
			{
				ZEPHIR_INIT_NVAR(&argument);
				ZVAL_COPY(&argument, _18$$14);
				ZEPHIR_CALL_METHOD(&_20$$15, this_ptr, "_getvardump", &_21, 0, &argument);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_22$$15);
				ZEPHIR_CONCAT_SVS(&_22$$15, "<span class=\"error-parameter\">", &_20$$15, "</span>");
				zephir_array_append(&arguments, &_22$$15, PH_SEPARATE, "phalcon/debug.zep", 437);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &traceArgs, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_19$$14, &traceArgs, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_19$$14)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&argument, &traceArgs, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_23$$16, this_ptr, "_getvardump", &_21, 0, &argument);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_24$$16);
					ZEPHIR_CONCAT_SVS(&_24$$16, "<span class=\"error-parameter\">", &_23$$16, "</span>");
					zephir_array_append(&arguments, &_24$$16, PH_SEPARATE, "phalcon/debug.zep", 437);
				ZEPHIR_CALL_METHOD(NULL, &traceArgs, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&argument);
		ZEPHIR_INIT_VAR(&_25$$14);
		zephir_fast_join_str(&_25$$14, SL(", "), &arguments);
		ZEPHIR_INIT_VAR(&_26$$14);
		ZEPHIR_CONCAT_SVS(&_26$$14, "(", &_25$$14, ")");
		zephir_concat_self(&html, &_26$$14);
	}
	ZEPHIR_OBS_VAR(&filez);
	if (zephir_array_isset_string_fetch(&filez, &trace, SL("file"), 0)) {
		ZEPHIR_OBS_VAR(&_27$$17);
		zephir_array_fetch_string(&_27$$17, &trace, SL("line"), PH_NOISY, "phalcon/debug.zep", 451);
		zephir_get_strval(&_28$$17, &_27$$17);
		ZEPHIR_CPY_WRT(&line, &_28$$17);
		ZEPHIR_INIT_VAR(&_29$$17);
		ZEPHIR_CONCAT_SVSVS(&_29$$17, "<br/><div class=\"error-file\">", &filez, " (", &line, ")</div>");
		zephir_concat_self(&html, &_29$$17);
		ZEPHIR_OBS_VAR(&showFiles);
		zephir_read_property(&showFiles, this_ptr, ZEND_STRL("_showFiles"), PH_NOISY_CC);
		if (zephir_is_true(&showFiles)) {
			ZEPHIR_CALL_FUNCTION(&lines, "file", NULL, 154, &filez);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&numberLines);
			ZVAL_LONG(&numberLines, zephir_fast_count_int(&lines));
			ZEPHIR_OBS_VAR(&showFileFragment);
			zephir_read_property(&showFileFragment, this_ptr, ZEND_STRL("_showFileFragment"), PH_NOISY_CC);
			if (zephir_is_true(&showFileFragment)) {
				beforeLine$$19 = (zephir_get_numberval(&line) - 7);
				if (beforeLine$$19 < 1) {
					ZEPHIR_INIT_VAR(&firstLine);
					ZVAL_LONG(&firstLine, 1);
				} else {
					ZEPHIR_INIT_NVAR(&firstLine);
					ZVAL_LONG(&firstLine, beforeLine$$19);
				}
				afterLine$$19 = (zephir_get_numberval(&line) + 5);
				if (ZEPHIR_LT_LONG(&numberLines, afterLine$$19)) {
					ZEPHIR_CPY_WRT(&lastLine, &numberLines);
				} else {
					ZEPHIR_INIT_NVAR(&lastLine);
					ZVAL_LONG(&lastLine, afterLine$$19);
				}
				ZEPHIR_INIT_VAR(&_30$$19);
				ZEPHIR_CONCAT_SVSVSVS(&_30$$19, "<pre class=\"prettyprint highlight:", &firstLine, ":", &line, " linenums:", &firstLine, "\">");
				zephir_concat_self(&html, &_30$$19);
			} else {
				ZEPHIR_INIT_NVAR(&firstLine);
				ZVAL_LONG(&firstLine, 1);
				ZEPHIR_CPY_WRT(&lastLine, &numberLines);
				ZEPHIR_INIT_VAR(&_31$$24);
				ZEPHIR_CONCAT_SVSVS(&_31$$24, "<pre class=\"prettyprint highlight:", &firstLine, ":", &line, " linenums error-scroll\">");
				zephir_concat_self(&html, &_31$$24);
			}
			i = zephir_get_numberval(&firstLine);
			while (1) {
				if (!(ZEPHIR_GE_LONG(&lastLine, i))) {
					break;
				}
				ZEPHIR_INIT_NVAR(&linePosition);
				ZVAL_LONG(&linePosition, (i - 1));
				ZEPHIR_OBS_NVAR(&currentLine);
				zephir_array_fetch(&currentLine, &lines, &linePosition, PH_NOISY, "phalcon/debug.zep", 523);
				if (zephir_is_true(&showFileFragment)) {
					if (ZEPHIR_IS_LONG(&firstLine, i)) {
						ZEPHIR_INIT_NVAR(&_32$$27);
						ZEPHIR_INIT_NVAR(&_33$$27);
						zephir_fast_trim(&_33$$27, &currentLine, NULL , ZEPHIR_TRIM_RIGHT);
						ZEPHIR_INIT_NVAR(&_34$$27);
						ZVAL_STRING(&_34$$27, "#\\*\\/#");
						ZEPHIR_INIT_NVAR(&_35$$27);
						ZEPHIR_INIT_NVAR(&_36$$27);
						ZVAL_STRING(&_36$$27, "#\\*\\/#");
						zephir_preg_match(&_35$$27, &_36$$27, &_33$$27, &_32$$27, 0, 0 , 0 );
						if (zephir_is_true(&_35$$27)) {
							ZEPHIR_INIT_NVAR(&_37$$28);
							ZEPHIR_INIT_NVAR(&_38$$28);
							ZVAL_STRING(&_38$$28, "* /");
							ZEPHIR_INIT_NVAR(&_39$$28);
							ZVAL_STRING(&_39$$28, " ");
							zephir_fast_str_replace(&_37$$28, &_38$$28, &_39$$28, &currentLine);
							ZEPHIR_CPY_WRT(&currentLine, &_37$$28);
						}
					}
				}
				_40$$25 = ZEPHIR_IS_STRING(&currentLine, "\n");
				if (!(_40$$25)) {
					_40$$25 = ZEPHIR_IS_STRING(&currentLine, "\r\n");
				}
				if (_40$$25) {
					zephir_concat_self_str(&html, SL("&nbsp;\n"));
				} else {
					ZEPHIR_INIT_NVAR(&_41$$30);
					ZEPHIR_INIT_NVAR(&_42$$30);
					ZVAL_STRING(&_42$$30, "\t");
					ZEPHIR_INIT_NVAR(&_43$$30);
					ZVAL_STRING(&_43$$30, "  ");
					zephir_fast_str_replace(&_41$$30, &_42$$30, &_43$$30, &currentLine);
					ZVAL_LONG(&_44$$30, 2);
					ZEPHIR_INIT_NVAR(&_45$$30);
					ZVAL_STRING(&_45$$30, "UTF-8");
					ZEPHIR_CALL_FUNCTION(&_46$$30, "htmlentities", &_47, 150, &_41$$30, &_44$$30, &_45$$30);
					zephir_check_call_status();
					zephir_concat_self(&html, &_46$$30);
				}
				i++;
			}
			zephir_concat_self_str(&html, SL("</pre>"));
		}
	}
	zephir_concat_self_str(&html, SL("</td></tr>"));
	RETURN_CCTOR(&html);

}

/**
 * Throws an exception when a notice or warning is raised
 */
PHP_METHOD(Phalcon_Debug, onUncaughtLowSeverity) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *severity, severity_sub, *message, message_sub, *file, file_sub, *line, line_sub, *context, context_sub, _0, _1, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&severity_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&line_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_ZVAL(severity)
		Z_PARAM_ZVAL(message)
		Z_PARAM_ZVAL(file)
		Z_PARAM_ZVAL(line)
		Z_PARAM_ZVAL(context)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &severity, &message, &file, &line, &context);



	ZEPHIR_CALL_FUNCTION(&_0, "error_reporting", NULL, 155);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_bitwise_and_function(&_1, &_0, severity);
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, zend_ce_error_exception);
		ZVAL_LONG(&_3$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 156, message, &_3$$3, severity, file, line);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/debug.zep", 566);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Handles uncaught exceptions
 */
PHP_METHOD(Phalcon_Debug, onUncaughtException) {

	zend_string *_14$$5, *_21$$5, *_32$$5, *_42$$5, *_50$$19;
	zend_ulong _13$$5, _20$$5, _31$$5, _41$$5, _49$$19;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_16 = NULL, *_24 = NULL, *_34 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exception, exception_sub, __$true, _REQUEST, _SERVER, __$false, obLevel, className, escapedMessage, html, showBackTrace, dataVars, n, traceItem, keyRequest, value, keyServer, keyFile, keyVar, dataVar, _0, _2, _3, _4, _5, _6, _7, _8, _9, _57, _58, _1$$4, _10$$5, *_11$$5, _12$$5, *_18$$5, _19$$5, *_29$$5, _30$$5, _38$$5, *_39$$5, _40$$5, _45$$5, _46$$5, _15$$7, _17$$8, _22$$10, _23$$11, _25$$11, _26$$13, _27$$14, _28$$14, _33$$15, _35$$15, _36$$16, _37$$16, _43$$17, _44$$18, *_47$$19, _48$$19, _51$$20, _52$$20, _53$$20, _54$$21, _55$$21, _56$$21;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exception_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_REQUEST);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&obLevel);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&escapedMessage);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&showBackTrace);
	ZVAL_UNDEF(&dataVars);
	ZVAL_UNDEF(&n);
	ZVAL_UNDEF(&traceItem);
	ZVAL_UNDEF(&keyRequest);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&keyServer);
	ZVAL_UNDEF(&keyFile);
	ZVAL_UNDEF(&keyVar);
	ZVAL_UNDEF(&dataVar);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_57);
	ZVAL_UNDEF(&_58);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_30$$5);
	ZVAL_UNDEF(&_38$$5);
	ZVAL_UNDEF(&_40$$5);
	ZVAL_UNDEF(&_45$$5);
	ZVAL_UNDEF(&_46$$5);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_26$$13);
	ZVAL_UNDEF(&_27$$14);
	ZVAL_UNDEF(&_28$$14);
	ZVAL_UNDEF(&_33$$15);
	ZVAL_UNDEF(&_35$$15);
	ZVAL_UNDEF(&_36$$16);
	ZVAL_UNDEF(&_37$$16);
	ZVAL_UNDEF(&_43$$17);
	ZVAL_UNDEF(&_44$$18);
	ZVAL_UNDEF(&_48$$19);
	ZVAL_UNDEF(&_51$$20);
	ZVAL_UNDEF(&_52$$20);
	ZVAL_UNDEF(&_53$$20);
	ZVAL_UNDEF(&_54$$21);
	ZVAL_UNDEF(&_55$$21);
	ZVAL_UNDEF(&_56$$21);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(exception, zend_ce_exception)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	zephir_fetch_params(1, 1, 0, &exception);



	ZEPHIR_CALL_FUNCTION(&obLevel, "ob_get_level", NULL, 157);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(&obLevel, 0)) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 116);
		zephir_check_call_status();
	}
	zephir_read_static_property_ce(&_0, phalcon_debug_ce, SL("_isActive"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&_1$$4, exception, "getmessage", NULL, 0);
		zephir_check_call_status();
		zend_print_zval(&_1$$4, 0);
		RETURN_MM_NULL();
	}
	zephir_update_static_property_ce(phalcon_debug_ce, ZEND_STRL("_isActive"), &__$true);
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, exception, 0);
	ZEPHIR_CALL_METHOD(&_2, exception, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&escapedMessage, this_ptr, "_escapestring", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&html);
	ZEPHIR_CONCAT_SVSVS(&html, "<html><head><title>", &className, ": ", &escapedMessage, "</title>");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getcsssources", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VS(&_4, &_3, "</head><body>");
	zephir_concat_self(&html, &_4);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getversion", NULL, 0);
	zephir_check_call_status();
	zephir_concat_self(&html, &_5);
	zephir_concat_self_str(&html, SL("<div align=\"center\"><div class=\"error-main\">"));
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_SVSVS(&_6, "<h1>", &className, ": ", &escapedMessage, "</h1>");
	zephir_concat_self(&html, &_6);
	ZEPHIR_CALL_METHOD(&_7, exception, "getfile", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, exception, "getline", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_CONCAT_SVSVS(&_9, "<span class=\"error-file\">", &_7, " (", &_8, ")</span>");
	zephir_concat_self(&html, &_9);
	zephir_concat_self_str(&html, SL("</div>"));
	ZEPHIR_OBS_VAR(&showBackTrace);
	zephir_read_property(&showBackTrace, this_ptr, ZEND_STRL("_showBackTrace"), PH_NOISY_CC);
	if (zephir_is_true(&showBackTrace)) {
		ZEPHIR_OBS_VAR(&dataVars);
		zephir_read_property(&dataVars, this_ptr, ZEND_STRL("_data"), PH_NOISY_CC);
		zephir_concat_self_str(&html, SL("<div class=\"error-info\"><div id=\"tabs\"><ul>"));
		zephir_concat_self_str(&html, SL("<li><a href=\"#error-tabs-1\">Backtrace</a></li>"));
		zephir_concat_self_str(&html, SL("<li><a href=\"#error-tabs-2\">Request</a></li>"));
		zephir_concat_self_str(&html, SL("<li><a href=\"#error-tabs-3\">Server</a></li>"));
		zephir_concat_self_str(&html, SL("<li><a href=\"#error-tabs-4\">Included Files</a></li>"));
		zephir_concat_self_str(&html, SL("<li><a href=\"#error-tabs-5\">Memory</a></li>"));
		if (Z_TYPE_P(&dataVars) == IS_ARRAY) {
			zephir_concat_self_str(&html, SL("<li><a href=\"#error-tabs-6\">Variables</a></li>"));
		}
		zephir_concat_self_str(&html, SL("</ul>"));
		zephir_concat_self_str(&html, SL("<div id=\"error-tabs-1\"><table cellspacing=\"0\" align=\"center\" width=\"100%\">"));
		ZEPHIR_CALL_METHOD(&_10$$5, exception, "gettrace", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(&_10$$5, 0, "phalcon/debug.zep", 660);
		if (Z_TYPE_P(&_10$$5) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_10$$5), _13$$5, _14$$5, _11$$5)
			{
				ZEPHIR_INIT_NVAR(&n);
				if (_14$$5 != NULL) { 
					ZVAL_STR_COPY(&n, _14$$5);
				} else {
					ZVAL_LONG(&n, _13$$5);
				}
				ZEPHIR_INIT_NVAR(&traceItem);
				ZVAL_COPY(&traceItem, _11$$5);
				ZEPHIR_CALL_METHOD(&_15$$7, this_ptr, "showtraceitem", &_16, 158, &n, &traceItem);
				zephir_check_call_status();
				zephir_concat_self(&html, &_15$$7);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_10$$5, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_12$$5, &_10$$5, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_12$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&n, &_10$$5, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&traceItem, &_10$$5, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_17$$8, this_ptr, "showtraceitem", &_16, 158, &n, &traceItem);
					zephir_check_call_status();
					zephir_concat_self(&html, &_17$$8);
				ZEPHIR_CALL_METHOD(NULL, &_10$$5, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&traceItem);
		ZEPHIR_INIT_NVAR(&n);
		zephir_concat_self_str(&html, SL("</table></div>"));
		zephir_concat_self_str(&html, SL("<div id=\"error-tabs-2\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">"));
		zephir_concat_self_str(&html, SL("<tr><th>Key</th><th>Value</th></tr>"));
		zephir_is_iterable(&_REQUEST, 0, "phalcon/debug.zep", 674);
		if (Z_TYPE_P(&_REQUEST) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_REQUEST), _20$$5, _21$$5, _18$$5)
			{
				ZEPHIR_INIT_NVAR(&keyRequest);
				if (_21$$5 != NULL) { 
					ZVAL_STR_COPY(&keyRequest, _21$$5);
				} else {
					ZVAL_LONG(&keyRequest, _20$$5);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _18$$5);
				if (Z_TYPE_P(&value) != IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_22$$10);
					ZEPHIR_CONCAT_SVSVS(&_22$$10, "<tr><td class=\"key\">", &keyRequest, "</td><td>", &value, "</td></tr>");
					zephir_concat_self(&html, &_22$$10);
				} else {
					ZEPHIR_CALL_FUNCTION(&_23$$11, "print_r", &_24, 159, &value, &__$true);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_25$$11);
					ZEPHIR_CONCAT_SVSVS(&_25$$11, "<tr><td class=\"key\">", &keyRequest, "</td><td>", &_23$$11, "</td></tr>");
					zephir_concat_self(&html, &_25$$11);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_REQUEST, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_19$$5, &_REQUEST, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_19$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&keyRequest, &_REQUEST, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &_REQUEST, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&value) != IS_ARRAY) {
						ZEPHIR_INIT_NVAR(&_26$$13);
						ZEPHIR_CONCAT_SVSVS(&_26$$13, "<tr><td class=\"key\">", &keyRequest, "</td><td>", &value, "</td></tr>");
						zephir_concat_self(&html, &_26$$13);
					} else {
						ZEPHIR_CALL_FUNCTION(&_27$$14, "print_r", &_24, 159, &value, &__$true);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_28$$14);
						ZEPHIR_CONCAT_SVSVS(&_28$$14, "<tr><td class=\"key\">", &keyRequest, "</td><td>", &_27$$14, "</td></tr>");
						zephir_concat_self(&html, &_28$$14);
					}
				ZEPHIR_CALL_METHOD(NULL, &_REQUEST, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&keyRequest);
		zephir_concat_self_str(&html, SL("</table></div>"));
		zephir_concat_self_str(&html, SL("<div id=\"error-tabs-3\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">"));
		zephir_concat_self_str(&html, SL("<tr><th>Key</th><th>Value</th></tr>"));
		zephir_is_iterable(&_SERVER, 0, "phalcon/debug.zep", 684);
		if (Z_TYPE_P(&_SERVER) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_SERVER), _31$$5, _32$$5, _29$$5)
			{
				ZEPHIR_INIT_NVAR(&keyServer);
				if (_32$$5 != NULL) { 
					ZVAL_STR_COPY(&keyServer, _32$$5);
				} else {
					ZVAL_LONG(&keyServer, _31$$5);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _29$$5);
				ZEPHIR_CALL_METHOD(&_33$$15, this_ptr, "_getvardump", &_34, 0, &value);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_35$$15);
				ZEPHIR_CONCAT_SVSVS(&_35$$15, "<tr><td class=\"key\">", &keyServer, "</td><td>", &_33$$15, "</td></tr>");
				zephir_concat_self(&html, &_35$$15);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_SERVER, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_30$$5, &_SERVER, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_30$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&keyServer, &_SERVER, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &_SERVER, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_36$$16, this_ptr, "_getvardump", &_34, 0, &value);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_37$$16);
					ZEPHIR_CONCAT_SVSVS(&_37$$16, "<tr><td class=\"key\">", &keyServer, "</td><td>", &_36$$16, "</td></tr>");
					zephir_concat_self(&html, &_37$$16);
				ZEPHIR_CALL_METHOD(NULL, &_SERVER, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&keyServer);
		zephir_concat_self_str(&html, SL("</table></div>"));
		zephir_concat_self_str(&html, SL("<div id=\"error-tabs-4\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">"));
		zephir_concat_self_str(&html, SL("<tr><th>#</th><th>Path</th></tr>"));
		ZEPHIR_CALL_FUNCTION(&_38$$5, "get_included_files", NULL, 160);
		zephir_check_call_status();
		zephir_is_iterable(&_38$$5, 0, "phalcon/debug.zep", 694);
		if (Z_TYPE_P(&_38$$5) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_38$$5), _41$$5, _42$$5, _39$$5)
			{
				ZEPHIR_INIT_NVAR(&keyFile);
				if (_42$$5 != NULL) { 
					ZVAL_STR_COPY(&keyFile, _42$$5);
				} else {
					ZVAL_LONG(&keyFile, _41$$5);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _39$$5);
				ZEPHIR_INIT_NVAR(&_43$$17);
				ZEPHIR_CONCAT_SVSVS(&_43$$17, "<tr><td>", &keyFile, "</th><td>", &value, "</td></tr>");
				zephir_concat_self(&html, &_43$$17);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_38$$5, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_40$$5, &_38$$5, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_40$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&keyFile, &_38$$5, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &_38$$5, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_44$$18);
					ZEPHIR_CONCAT_SVSVS(&_44$$18, "<tr><td>", &keyFile, "</th><td>", &value, "</td></tr>");
					zephir_concat_self(&html, &_44$$18);
				ZEPHIR_CALL_METHOD(NULL, &_38$$5, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&keyFile);
		zephir_concat_self_str(&html, SL("</table></div>"));
		zephir_concat_self_str(&html, SL("<div id=\"error-tabs-5\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">"));
		ZEPHIR_CALL_FUNCTION(&_45$$5, "memory_get_usage", NULL, 161, &__$true);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_46$$5);
		ZEPHIR_CONCAT_SVS(&_46$$5, "<tr><th colspan=\"2\">Memory</th></tr><tr><td>Usage</td><td>", &_45$$5, "</td></tr>");
		zephir_concat_self(&html, &_46$$5);
		zephir_concat_self_str(&html, SL("</table></div>"));
		if (Z_TYPE_P(&dataVars) == IS_ARRAY) {
			zephir_concat_self_str(&html, SL("<div id=\"error-tabs-6\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">"));
			zephir_concat_self_str(&html, SL("<tr><th>Key</th><th>Value</th></tr>"));
			zephir_is_iterable(&dataVars, 0, "phalcon/debug.zep", 712);
			if (Z_TYPE_P(&dataVars) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&dataVars), _49$$19, _50$$19, _47$$19)
				{
					ZEPHIR_INIT_NVAR(&keyVar);
					if (_50$$19 != NULL) { 
						ZVAL_STR_COPY(&keyVar, _50$$19);
					} else {
						ZVAL_LONG(&keyVar, _49$$19);
					}
					ZEPHIR_INIT_NVAR(&dataVar);
					ZVAL_COPY(&dataVar, _47$$19);
					zephir_array_fetch_long(&_52$$20, &dataVar, 0, PH_NOISY | PH_READONLY, "phalcon/debug.zep", 710);
					ZEPHIR_CALL_METHOD(&_51$$20, this_ptr, "_getvardump", &_34, 0, &_52$$20);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_53$$20);
					ZEPHIR_CONCAT_SVSVS(&_53$$20, "<tr><td class=\"key\">", &keyVar, "</td><td>", &_51$$20, "</td></tr>");
					zephir_concat_self(&html, &_53$$20);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &dataVars, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_48$$19, &dataVars, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_48$$19)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&keyVar, &dataVars, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&dataVar, &dataVars, "current", NULL, 0);
					zephir_check_call_status();
						zephir_array_fetch_long(&_55$$21, &dataVar, 0, PH_NOISY | PH_READONLY, "phalcon/debug.zep", 710);
						ZEPHIR_CALL_METHOD(&_54$$21, this_ptr, "_getvardump", &_34, 0, &_55$$21);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_56$$21);
						ZEPHIR_CONCAT_SVSVS(&_56$$21, "<tr><td class=\"key\">", &keyVar, "</td><td>", &_54$$21, "</td></tr>");
						zephir_concat_self(&html, &_56$$21);
					ZEPHIR_CALL_METHOD(NULL, &dataVars, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&dataVar);
			ZEPHIR_INIT_NVAR(&keyVar);
			zephir_concat_self_str(&html, SL("</table></div>"));
		}
		zephir_concat_self_str(&html, SL("</div>"));
	}
	ZEPHIR_CALL_METHOD(&_57, this_ptr, "getjssources", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_58);
	ZEPHIR_CONCAT_VS(&_58, &_57, "</div></body></html>");
	zephir_concat_self(&html, &_58);
	zend_print_zval(&html, 0);
	zephir_update_static_property_ce(phalcon_debug_ce, ZEND_STRL("_isActive"), &__$false);
	RETURN_MM_BOOL(1);

}

