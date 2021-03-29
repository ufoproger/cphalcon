
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * Phalcon\Version
 *
 * This class allows to get the installed version of the framework
 */
ZEPHIR_INIT_CLASS(Phalcon_Version) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Version, phalcon, version, phalcon_version_method_entry, 0);

	/**
	 * The constant referencing the major version. Returns 0
	 *
	 * <code>
	 * echo Phalcon\Version::getPart(
	 *     Phalcon\Version::VERSION_MAJOR
	 * );
	 * </code>
	 */
	zephir_declare_class_constant_long(phalcon_version_ce, SL("VERSION_MAJOR"), 0);

	/**
	 * The constant referencing the major version. Returns 1
	 *
	 * <code>
	 * echo Phalcon\Version::getPart(
	 *     Phalcon\Version::VERSION_MEDIUM
	 * );
	 * </code>
	 */
	zephir_declare_class_constant_long(phalcon_version_ce, SL("VERSION_MEDIUM"), 1);

	/**
	 * The constant referencing the major version. Returns 2
	 *
	 * <code>
	 * echo Phalcon\Version::getPart(
	 *     Phalcon\Version::VERSION_MINOR
	 * );
	 * </code>
	 */
	zephir_declare_class_constant_long(phalcon_version_ce, SL("VERSION_MINOR"), 2);

	/**
	 * The constant referencing the major version. Returns 3
	 *
	 * <code>
	 * echo Phalcon\Version::getPart(
	 *     Phalcon\Version::VERSION_SPECIAL
	 * );
	 * </code>
	 */
	zephir_declare_class_constant_long(phalcon_version_ce, SL("VERSION_SPECIAL"), 3);

	/**
	 * The constant referencing the major version. Returns 4
	 *
	 * <code>
	 * echo Phalcon\Version::getPart(
	 *     Phalcon\Version::VERSION_SPECIAL_NUMBER
	 * );
	 * </code>
	 */
	zephir_declare_class_constant_long(phalcon_version_ce, SL("VERSION_SPECIAL_NUMBER"), 4);

	return SUCCESS;

}

/**
 * Area where the version number is set. The format is as follows:
 * ABBCCDE
 *
 * A - Major version
 * B - Med version (two digits)
 * C - Min version (two digits)
 * D - Special release: 1 = Alpha, 2 = Beta, 3 = RC, 4 = Stable
 * E - Special release version i.e. RC1, Beta2 etc.
 */
PHP_METHOD(Phalcon_Version, _getVersion) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 5, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, 3);
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, 4);
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, 5);
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, 4);
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, 0);
	zephir_array_fast_append(return_value, &_0);
	RETURN_MM();

}

/**
 * Translates a number to a special release
 *
 * If Special release = 1 this function will return ALPHA
 */
PHP_METHOD(Phalcon_Version, _getSpecial) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *special_param = NULL, suffix;
	zend_long special;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&suffix);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(special)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &special_param);

	special = zephir_get_intval(special_param);


	ZEPHIR_INIT_VAR(&suffix);
	ZVAL_STRING(&suffix, "");
	do {
		if (special == 1) {
			ZEPHIR_INIT_NVAR(&suffix);
			ZVAL_STRING(&suffix, "ALPHA");
			break;
		}
		if (special == 2) {
			ZEPHIR_INIT_NVAR(&suffix);
			ZVAL_STRING(&suffix, "BETA");
			break;
		}
		if (special == 3) {
			ZEPHIR_INIT_NVAR(&suffix);
			ZVAL_STRING(&suffix, "RC");
			break;
		}
	} while(0);

	RETURN_CCTOR(&suffix);

}

/**
 * Returns the active version (string)
 *
 * <code>
 * echo Phalcon\Version::get();
 * </code>
 */
PHP_METHOD(Phalcon_Version, get) {

	zval version, major, medium, minor, special, specialNumber, result, suffix, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&major);
	ZVAL_UNDEF(&medium);
	ZVAL_UNDEF(&minor);
	ZVAL_UNDEF(&special);
	ZVAL_UNDEF(&specialNumber);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&suffix);
	ZVAL_UNDEF(&_1$$3);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_STATIC(&version, "_getversion", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&major);
	zephir_array_fetch_long(&major, &version, 0, PH_NOISY, "phalcon/version.zep", 139);
	ZEPHIR_OBS_VAR(&medium);
	zephir_array_fetch_long(&medium, &version, 1, PH_NOISY, "phalcon/version.zep", 140);
	ZEPHIR_OBS_VAR(&minor);
	zephir_array_fetch_long(&minor, &version, 2, PH_NOISY, "phalcon/version.zep", 141);
	ZEPHIR_OBS_VAR(&special);
	zephir_array_fetch_long(&special, &version, 3, PH_NOISY, "phalcon/version.zep", 142);
	ZEPHIR_OBS_VAR(&specialNumber);
	zephir_array_fetch_long(&specialNumber, &version, 4, PH_NOISY, "phalcon/version.zep", 143);
	ZEPHIR_INIT_VAR(&result);
	ZEPHIR_CONCAT_VSVSVS(&result, &major, ".", &medium, ".", &minor, " ");
	ZEPHIR_CALL_STATIC(&suffix, "_getspecial", &_0, 392, &special);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING(&suffix, "")) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_VSV(&_1$$3, &suffix, " ", &specialNumber);
		zephir_concat_self(&result, &_1$$3);
	}
	zephir_fast_trim(return_value, &result, NULL , ZEPHIR_TRIM_BOTH);
	RETURN_MM();

}

/**
 * Returns the numeric active version
 *
 * <code>
 * echo Phalcon\Version::getId();
 * </code>
 */
PHP_METHOD(Phalcon_Version, getId) {

	zval version, major, medium, minor, special, specialNumber, _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&major);
	ZVAL_UNDEF(&medium);
	ZVAL_UNDEF(&minor);
	ZVAL_UNDEF(&special);
	ZVAL_UNDEF(&specialNumber);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_STATIC(&version, "_getversion", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&major);
	zephir_array_fetch_long(&major, &version, 0, PH_NOISY, "phalcon/version.zep", 169);
	ZEPHIR_OBS_VAR(&medium);
	zephir_array_fetch_long(&medium, &version, 1, PH_NOISY, "phalcon/version.zep", 170);
	ZEPHIR_OBS_VAR(&minor);
	zephir_array_fetch_long(&minor, &version, 2, PH_NOISY, "phalcon/version.zep", 171);
	ZEPHIR_OBS_VAR(&special);
	zephir_array_fetch_long(&special, &version, 3, PH_NOISY, "phalcon/version.zep", 172);
	ZEPHIR_OBS_VAR(&specialNumber);
	zephir_array_fetch_long(&specialNumber, &version, 4, PH_NOISY, "phalcon/version.zep", 173);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "%02s");
	ZEPHIR_CALL_FUNCTION(&_1, "sprintf", NULL, 138, &_0, &medium);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "%02s");
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 138, &_0, &minor);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVVVV(return_value, &major, &_1, &_2, &special, &specialNumber);
	RETURN_MM();

}

/**
 * Returns a specific part of the version. If the wrong parameter is passed
 * it will return the full version
 *
 * <code>
 * echo Phalcon\Version::getPart(
 *     Phalcon\Version::VERSION_MAJOR
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Version, getPart) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *part_param = NULL, version, result, _1$$4;
	zend_long part, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(part)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &part_param);

	part = zephir_get_intval(part_param);


	ZEPHIR_CALL_STATIC(&version, "_getversion", NULL, 0);
	zephir_check_call_status();
	do {
		if (part == 0 || part == 1 || part == 2 || part == 4) {
			ZEPHIR_OBS_VAR(&result);
			zephir_array_fetch_long(&result, &version, part, PH_NOISY, "phalcon/version.zep", 200);
			break;
		}
		if (part == 3) {
			zephir_array_fetch_long(&_1$$4, &version, 3, PH_NOISY | PH_READONLY, "phalcon/version.zep", 204);
			ZEPHIR_CALL_STATIC(&result, "_getspecial", &_0, 392, &_1$$4);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_CALL_STATIC(&result, "get", NULL, 0);
		zephir_check_call_status();
		break;
	} while(0);

	RETURN_CCTOR(&result);

}

