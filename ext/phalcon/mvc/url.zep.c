
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "phalcon/mvc/url/utils.h"


/**
 * Phalcon\Mvc\Url
 *
 * This components helps in the generation of: URIs, URLs and Paths
 *
 *<code>
 * // Generate a URL appending the URI to the base URI
 * echo $url->get("products/edit/1");
 *
 * // Generate a URL for a predefined route
 * echo $url->get(
 *     [
 *         "for"   => "blog-post",
 *         "title" => "some-cool-stuff",
 *         "year"  => "2012",
 *     ]
 * );
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Url) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc, Url, phalcon, mvc_url, phalcon_mvc_url_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_url_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_url_ce, SL("_baseUri"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_url_ce, SL("_staticBaseUri"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_url_ce, SL("_basePath"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_url_ce, SL("_router"), ZEND_ACC_PROTECTED);

	zend_class_implements(phalcon_mvc_url_ce, 1, phalcon_mvc_urlinterface_ce);
	zend_class_implements(phalcon_mvc_url_ce, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;

}

/**
 * Sets the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Url, setDI) {

	zval *dependencyInjector, dependencyInjector_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(dependencyInjector, phalcon_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &dependencyInjector);



	zephir_update_property_zval(this_ptr, ZEND_STRL("_dependencyInjector"), dependencyInjector);

}

/**
 * Returns the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Url, getDI) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Sets a prefix for all the URIs to be generated
 *
 *<code>
 * $url->setBaseUri("/invo/");
 *
 * $url->setBaseUri("/invo/index.php/");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Url, setBaseUri) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *baseUri_param = NULL, _0;
	zval baseUri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&baseUri);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(baseUri)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &baseUri_param);

	if (UNEXPECTED(Z_TYPE_P(baseUri_param) != IS_STRING && Z_TYPE_P(baseUri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'baseUri' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(baseUri_param) == IS_STRING)) {
		zephir_get_strval(&baseUri, baseUri_param);
	} else {
		ZEPHIR_INIT_VAR(&baseUri);
		ZVAL_EMPTY_STRING(&baseUri);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("_baseUri"), &baseUri);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("_staticBaseUri"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_staticBaseUri"), &baseUri);
	}
	RETURN_THIS();

}

/**
 * Sets a prefix for all static URLs generated
 *
 *<code>
 * $url->setStaticBaseUri("/invo/");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Url, setStaticBaseUri) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *staticBaseUri_param = NULL;
	zval staticBaseUri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&staticBaseUri);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(staticBaseUri)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &staticBaseUri_param);

	if (UNEXPECTED(Z_TYPE_P(staticBaseUri_param) != IS_STRING && Z_TYPE_P(staticBaseUri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'staticBaseUri' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(staticBaseUri_param) == IS_STRING)) {
		zephir_get_strval(&staticBaseUri, staticBaseUri_param);
	} else {
		ZEPHIR_INIT_VAR(&staticBaseUri);
		ZVAL_EMPTY_STRING(&staticBaseUri);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("_staticBaseUri"), &staticBaseUri);
	RETURN_THIS();

}

/**
 * Returns the prefix for all the generated urls. By default /
 */
PHP_METHOD(Phalcon_Mvc_Url, getBaseUri) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval _SERVER, baseUri, phpSelf, uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&baseUri);
	ZVAL_UNDEF(&phpSelf);
	ZVAL_UNDEF(&uri);


	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	ZEPHIR_OBS_VAR(&baseUri);
	zephir_read_property(&baseUri, this_ptr, ZEND_STRL("_baseUri"), PH_NOISY_CC);
	if (Z_TYPE_P(&baseUri) == IS_NULL) {
		ZEPHIR_OBS_VAR(&phpSelf);
		if (zephir_array_isset_string_fetch(&phpSelf, &_SERVER, SL("PHP_SELF"), 0)) {
			ZEPHIR_INIT_VAR(&uri);
			phalcon_get_uri(&uri, &phpSelf);
		} else {
			ZEPHIR_INIT_NVAR(&uri);
			ZVAL_NULL(&uri);
		}
		ZEPHIR_INIT_NVAR(&baseUri);
		if (!(zephir_is_true(&uri))) {
			ZVAL_STRING(&baseUri, "/");
		} else {
			ZEPHIR_CONCAT_SVS(&baseUri, "/", &uri, "/");
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("_baseUri"), &baseUri);
	}
	RETURN_CCTOR(&baseUri);

}

/**
 * Returns the prefix for all the generated static urls. By default /
 */
PHP_METHOD(Phalcon_Mvc_Url, getStaticBaseUri) {

	zval staticBaseUri;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&staticBaseUri);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&staticBaseUri);
	zephir_read_property(&staticBaseUri, this_ptr, ZEND_STRL("_staticBaseUri"), PH_NOISY_CC);
	if (Z_TYPE_P(&staticBaseUri) != IS_NULL) {
		RETURN_CCTOR(&staticBaseUri);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getbaseuri", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets a base path for all the generated paths
 *
 *<code>
 * $url->setBasePath("/var/www/htdocs/");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Url, setBasePath) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *basePath_param = NULL;
	zval basePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(basePath)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &basePath_param);

	if (UNEXPECTED(Z_TYPE_P(basePath_param) != IS_STRING && Z_TYPE_P(basePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'basePath' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(basePath_param) == IS_STRING)) {
		zephir_get_strval(&basePath, basePath_param);
	} else {
		ZEPHIR_INIT_VAR(&basePath);
		ZVAL_EMPTY_STRING(&basePath);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("_basePath"), &basePath);
	RETURN_THIS();

}

/**
 * Returns the base path
 */
PHP_METHOD(Phalcon_Mvc_Url, getBasePath) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_basePath");

}

/**
 * Generates a URL
 *
 *<code>
 * // Generate a URL appending the URI to the base URI
 * echo $url->get("products/edit/1");
 *
 * // Generate a URL for a predefined route
 * echo $url->get(
 *     [
 *         "for"   => "blog-post",
 *         "title" => "some-cool-stuff",
 *         "year"  => "2015",
 *     ]
 * );
 *
 * // Generate a URL with GET arguments (/show/products?id=1&name=Carrots)
 * echo $url->get(
 *     "show/products",
 *     [
 *         "id"   => 1,
 *         "name" => "Carrots",
 *     ]
 * );
 *
 * // Generate an absolute URL by setting the third parameter as false.
 * echo $url->get(
 *     "https://phalconphp.com/",
 *     null,
 *     false
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Url, get) {

	unsigned char _18$$14, _20$$14, _25$$16;
	zend_bool _0$$3, _1$$3, _16$$14, _17$$14, _19$$14, _23$$16, _24$$16, _26$$19;
	zval strUri, _15$$14;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri = NULL, uri_sub, *args = NULL, args_sub, *local = NULL, local_sub, *baseUri = NULL, baseUri_sub, __$null, router, dependencyInjector, routeName, route, queryString, _2$$4, _3$$4, _4$$4, _5$$4, _6$$9, _10$$9, _13$$9, _14$$9, _7$$11, _8$$11, _9$$11, _11$$13, _12$$13, _21$$15, _22$$15, _27$$20, _28$$20, _29$$21, _30$$22;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_UNDEF(&args_sub);
	ZVAL_UNDEF(&local_sub);
	ZVAL_UNDEF(&baseUri_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&queryString);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_27$$20);
	ZVAL_UNDEF(&_28$$20);
	ZVAL_UNDEF(&_29$$21);
	ZVAL_UNDEF(&_30$$22);
	ZVAL_UNDEF(&strUri);
	ZVAL_UNDEF(&_15$$14);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 4)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(uri)
		Z_PARAM_ZVAL(args)
		Z_PARAM_ZVAL(local)
		Z_PARAM_ZVAL(baseUri)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &uri, &args, &local, &baseUri);

	if (!uri) {
		uri = &uri_sub;
		ZEPHIR_CPY_WRT(uri, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(uri);
	}
	if (!args) {
		args = &args_sub;
		args = &__$null;
	}
	if (!local) {
		local = &local_sub;
		ZEPHIR_CPY_WRT(local, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(local);
	}
	if (!baseUri) {
		baseUri = &baseUri_sub;
		ZEPHIR_CPY_WRT(baseUri, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(baseUri);
	}


	if (Z_TYPE_P(local) == IS_NULL) {
		_0$$3 = Z_TYPE_P(uri) == IS_STRING;
		if (_0$$3) {
			_1$$3 = zephir_memnstr_str(uri, SL("//"), "phalcon/mvc/url.zep", 208);
			if (!(_1$$3)) {
				_1$$3 = zephir_memnstr_str(uri, SL(":"), "phalcon/mvc/url.zep", 208);
			}
			_0$$3 = _1$$3;
		}
		if (_0$$3) {
			ZEPHIR_INIT_VAR(&_2$$4);
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "#^((//)|([a-z0-9]+://)|([a-z0-9]+:))#i");
			ZEPHIR_INIT_VAR(&_4$$4);
			ZEPHIR_INIT_VAR(&_5$$4);
			ZVAL_STRING(&_5$$4, "#^((//)|([a-z0-9]+://)|([a-z0-9]+:))#i");
			zephir_preg_match(&_4$$4, &_5$$4, uri, &_2$$4, 0, 0 , 0 );
			ZEPHIR_INIT_NVAR(local);
			if (zephir_is_true(&_4$$4)) {
				ZVAL_BOOL(local, 0);
			} else {
				ZVAL_BOOL(local, 1);
			}
		} else {
			ZEPHIR_INIT_NVAR(local);
			ZVAL_BOOL(local, 1);
		}
	}
	if (Z_TYPE_P(baseUri) != IS_STRING) {
		ZEPHIR_CALL_METHOD(baseUri, this_ptr, "getbaseuri", NULL, 0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(uri) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&routeName);
		if (!(zephir_array_isset_string_fetch(&routeName, uri, SL("for"), 0))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_url_exception_ce, "It's necessary to define the route name with the parameter 'for'", "phalcon/mvc/url.zep", 226);
			return;
		}
		zephir_read_property(&_6$$9, this_ptr, ZEND_STRL("_router"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&router, &_6$$9);
		if (Z_TYPE_P(&router) != IS_OBJECT) {
			zephir_read_property(&_7$$11, this_ptr, ZEND_STRL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&dependencyInjector, &_7$$11);
			if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_url_exception_ce, "A dependency injector container is required to obtain the 'router' service", "phalcon/mvc/url.zep", 238);
				return;
			}
			ZEPHIR_INIT_VAR(&_9$$11);
			ZVAL_STRING(&_9$$11, "router");
			ZEPHIR_CALL_METHOD(&_8$$11, &dependencyInjector, "getshared", NULL, 0, &_9$$11);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&router, &_8$$11);
			zephir_update_property_zval(this_ptr, ZEND_STRL("_router"), &router);
		}
		ZEPHIR_CALL_METHOD(&_10$$9, &router, "getroutebyname", NULL, 0, &routeName);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&route, &_10$$9);
		if (Z_TYPE_P(&route) != IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_11$$13);
			object_init_ex(&_11$$13, phalcon_mvc_url_exception_ce);
			ZEPHIR_INIT_VAR(&_12$$13);
			ZEPHIR_CONCAT_SVS(&_12$$13, "Cannot obtain a route using the name '", &routeName, "'");
			ZEPHIR_CALL_METHOD(NULL, &_11$$13, "__construct", NULL, 4, &_12$$13);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_11$$13, "phalcon/mvc/url.zep", 250);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_13$$9);
		ZEPHIR_CALL_METHOD(&_10$$9, &route, "getpattern", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_14$$9, &route, "getreversedpaths", NULL, 0);
		zephir_check_call_status();
		phalcon_replace_paths(&_13$$9, &_10$$9, &_14$$9, uri);
		ZEPHIR_CPY_WRT(uri, &_13$$9);
	}
	if (zephir_is_true(local)) {
		zephir_get_strval(&_15$$14, uri);
		ZEPHIR_CPY_WRT(&strUri, &_15$$14);
		_16$$14 = ZEPHIR_IS_STRING(baseUri, "/");
		if (_16$$14) {
			_16$$14 = zephir_fast_strlen_ev(&strUri) > 2;
		}
		_17$$14 = _16$$14;
		if (_17$$14) {
			_18$$14 = ZEPHIR_STRING_OFFSET(&strUri, 0);
			_17$$14 = _18$$14 == '/';
		}
		_19$$14 = _17$$14;
		if (_19$$14) {
			_20$$14 = ZEPHIR_STRING_OFFSET(&strUri, 1);
			_19$$14 = _20$$14 != '/';
		}
		if (_19$$14) {
			ZVAL_LONG(&_21$$15, 1);
			ZEPHIR_INIT_VAR(&_22$$15);
			zephir_substr(&_22$$15, &strUri, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_INIT_NVAR(uri);
			ZEPHIR_CONCAT_VV(uri, baseUri, &_22$$15);
		} else {
			_23$$16 = ZEPHIR_IS_STRING(baseUri, "/");
			if (_23$$16) {
				_23$$16 = zephir_fast_strlen_ev(&strUri) == 1;
			}
			_24$$16 = _23$$16;
			if (_24$$16) {
				_25$$16 = ZEPHIR_STRING_OFFSET(&strUri, 0);
				_24$$16 = _25$$16 == '/';
			}
			if (_24$$16) {
				ZEPHIR_CPY_WRT(uri, baseUri);
			} else {
				ZEPHIR_INIT_NVAR(uri);
				ZEPHIR_CONCAT_VV(uri, baseUri, &strUri);
			}
		}
	}
	if (zephir_is_true(args)) {
		ZEPHIR_CALL_FUNCTION(&queryString, "http_build_query", NULL, 315, args);
		zephir_check_call_status();
		_26$$19 = Z_TYPE_P(&queryString) == IS_STRING;
		if (_26$$19) {
			_26$$19 = ((zephir_fast_strlen_ev(&queryString)) ? 1 : 0);
		}
		if (_26$$19) {
			ZEPHIR_INIT_VAR(&_27$$20);
			ZVAL_STRING(&_27$$20, "?");
			ZEPHIR_INIT_VAR(&_28$$20);
			zephir_fast_strpos(&_28$$20, uri, &_27$$20, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&_28$$20)) {
				ZEPHIR_INIT_VAR(&_29$$21);
				ZEPHIR_CONCAT_SV(&_29$$21, "&", &queryString);
				zephir_concat_self(uri, &_29$$21);
			} else {
				ZEPHIR_INIT_VAR(&_30$$22);
				ZEPHIR_CONCAT_SV(&_30$$22, "?", &queryString);
				zephir_concat_self(uri, &_30$$22);
			}
		}
	}
	RETVAL_ZVAL(uri, 1, 0);
	RETURN_MM();

}

/**
 * Generates a URL for a static resource
 *
 *<code>
 * // Generate a URL for a static resource
 * echo $url->getStatic("img/logo.png");
 *
 * // Generate a URL for a static predefined route
 * echo $url->getStatic(
 *     [
 *         "for" => "logo-cdn",
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Url, getStatic) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri = NULL, uri_sub, __$null, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(uri)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri);

	if (!uri) {
		uri = &uri_sub;
		uri = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getstaticbaseuri", NULL, 0);
	zephir_check_call_status();
	ZVAL_NULL(&_1);
	ZVAL_NULL(&_2);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, uri, &_1, &_2, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generates a local path
 */
PHP_METHOD(Phalcon_Mvc_Url, path) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *path_param = NULL, _0;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(path)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &path_param);

	if (!path_param) {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_STRING(&path, "");
	} else {
		zephir_get_strval(&path, path_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("_basePath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VV(return_value, &_0, &path);
	RETURN_MM();

}

