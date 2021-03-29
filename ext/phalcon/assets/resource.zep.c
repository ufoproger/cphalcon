
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/string.h"


/**
 * Phalcon\Assets\Resource
 *
 * Represents an asset resource
 *
 *<code>
 * $resource = new \Phalcon\Assets\Resource("js", "javascripts/jquery.js");
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Resource) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Assets, Resource, phalcon, assets_resource, phalcon_assets_resource_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_resource_ce, SL("_type"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_resource_ce, SL("_path"), ZEND_ACC_PROTECTED);

	/**
	 * @var boolean
	 */
	zend_declare_property_null(phalcon_assets_resource_ce, SL("_local"), ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_null(phalcon_assets_resource_ce, SL("_filter"), ZEND_ACC_PROTECTED);

	/**
	 * @var array | null
	 */
	zend_declare_property_null(phalcon_assets_resource_ce, SL("_attributes"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_assets_resource_ce, SL("_sourcePath"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_assets_resource_ce, SL("_targetPath"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_assets_resource_ce, SL("_targetUri"), ZEND_ACC_PROTECTED);

	zend_class_implements(phalcon_assets_resource_ce, 1, phalcon_assets_resourceinterface_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Phalcon_Assets_Resource, getType) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_type");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Resource, getPath) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_path");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Resource, getLocal) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_local");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Resource, getFilter) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_filter");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Resource, getAttributes) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_attributes");

}

PHP_METHOD(Phalcon_Assets_Resource, getSourcePath) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_sourcePath");

}

PHP_METHOD(Phalcon_Assets_Resource, getTargetPath) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_targetPath");

}

PHP_METHOD(Phalcon_Assets_Resource, getTargetUri) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_targetUri");

}

/**
 * Phalcon\Assets\Resource constructor
 *
 * @param string type
 * @param string path
 * @param boolean local
 * @param boolean filter
 * @param array attributes
 */
PHP_METHOD(Phalcon_Assets_Resource, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool local, filter;
	zval *type_param = NULL, *path_param = NULL, *local_param = NULL, *filter_param = NULL, *attributes = NULL, attributes_sub, __$true, __$false, __$null;
	zval type, path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 5)
		Z_PARAM_STR(type)
		Z_PARAM_STR(path)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(local)
		Z_PARAM_BOOL(filter)
		Z_PARAM_ZVAL(attributes)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &type_param, &path_param, &local_param, &filter_param, &attributes);

	zephir_get_strval(&type, type_param);
	zephir_get_strval(&path, path_param);
	if (!local_param) {
		local = 1;
	} else {
		local = zephir_get_boolval(local_param);
	}
	if (!filter_param) {
		filter = 1;
	} else {
		filter = zephir_get_boolval(filter_param);
	}
	if (!attributes) {
		attributes = &attributes_sub;
		attributes = &__$null;
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("_type"), &type);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_path"), &path);
	if (local) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_local"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_local"), &__$false);
	}
	if (filter) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_filter"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_filter"), &__$false);
	}
	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_attributes"), attributes);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the resource's type
 */
PHP_METHOD(Phalcon_Assets_Resource, setType) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *type_param = NULL;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	zephir_get_strval(&type, type_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("_type"), &type);
	RETURN_THIS();

}

/**
 * Sets the resource's path
 */
PHP_METHOD(Phalcon_Assets_Resource, setPath) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *path_param = NULL;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("_path"), &path);
	RETURN_THIS();

}

/**
 * Sets if the resource is local or external
 */
PHP_METHOD(Phalcon_Assets_Resource, setLocal) {

	zval *local_param = NULL, __$true, __$false;
	zend_bool local;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(local)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &local_param);

	local = zephir_get_boolval(local_param);


	if (local) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_local"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_local"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Sets if the resource must be filtered or not
 */
PHP_METHOD(Phalcon_Assets_Resource, setFilter) {

	zval *filter_param = NULL, __$true, __$false;
	zend_bool filter;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(filter)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &filter_param);

	filter = zephir_get_boolval(filter_param);


	if (filter) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_filter"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_filter"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Sets extra HTML attributes
 */
PHP_METHOD(Phalcon_Assets_Resource, setAttributes) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attributes_param = NULL;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	zephir_get_arrval(&attributes, attributes_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("_attributes"), &attributes);
	RETURN_THIS();

}

/**
 * Sets a target uri for the generated HTML
 */
PHP_METHOD(Phalcon_Assets_Resource, setTargetUri) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *targetUri_param = NULL;
	zval targetUri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetUri);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(targetUri)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &targetUri_param);

	zephir_get_strval(&targetUri, targetUri_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("_targetUri"), &targetUri);
	RETURN_THIS();

}

/**
 * Sets the resource's source path
 */
PHP_METHOD(Phalcon_Assets_Resource, setSourcePath) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *sourcePath_param = NULL;
	zval sourcePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sourcePath);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(sourcePath)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sourcePath_param);

	zephir_get_strval(&sourcePath, sourcePath_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("_sourcePath"), &sourcePath);
	RETURN_THIS();

}

/**
 * Sets the resource's target path
 */
PHP_METHOD(Phalcon_Assets_Resource, setTargetPath) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *targetPath_param = NULL;
	zval targetPath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetPath);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(targetPath)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &targetPath_param);

	zephir_get_strval(&targetPath, targetPath_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("_targetPath"), &targetPath);
	RETURN_THIS();

}

/**
 * Returns the content of the resource as an string
 * Optionally a base path where the resource is located can be set
 */
PHP_METHOD(Phalcon_Assets_Resource, getContent) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *basePath_param = NULL, sourcePath, completePath, content, _0, _1$$5, _2$$5, _3$$6, _4$$6;
	zval basePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath);
	ZVAL_UNDEF(&sourcePath);
	ZVAL_UNDEF(&completePath);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(basePath)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &basePath_param);

	if (!basePath_param) {
		ZEPHIR_INIT_VAR(&basePath);
		ZVAL_STRING(&basePath, "");
	} else {
		zephir_get_strval(&basePath, basePath_param);
	}


	ZEPHIR_OBS_VAR(&sourcePath);
	zephir_read_property(&sourcePath, this_ptr, ZEND_STRL("_sourcePath"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&sourcePath)) {
		ZEPHIR_OBS_NVAR(&sourcePath);
		zephir_read_property(&sourcePath, this_ptr, ZEND_STRL("_path"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&completePath);
	ZEPHIR_CONCAT_VV(&completePath, &basePath, &sourcePath);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("_local"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		if (!((zephir_file_exists(&completePath) == SUCCESS))) {
			ZEPHIR_INIT_VAR(&_1$$5);
			object_init_ex(&_1$$5, phalcon_assets_exception_ce);
			ZEPHIR_INIT_VAR(&_2$$5);
			ZEPHIR_CONCAT_SVS(&_2$$5, "Resource's content for '", &completePath, "' cannot be read");
			ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", NULL, 4, &_2$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$5, "phalcon/assets/resource.zep", 183);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&content);
	zephir_file_get_contents(&content, &completePath);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&content)) {
		ZEPHIR_INIT_VAR(&_3$$6);
		object_init_ex(&_3$$6, phalcon_assets_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$6);
		ZEPHIR_CONCAT_SVS(&_4$$6, "Resource's content for '", &completePath, "' cannot be read");
		ZEPHIR_CALL_METHOD(NULL, &_3$$6, "__construct", NULL, 4, &_4$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$6, "phalcon/assets/resource.zep", 192);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&content);

}

/**
 * Returns the real target uri for the generated HTML
 */
PHP_METHOD(Phalcon_Assets_Resource, getRealTargetUri) {

	zval targetUri;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetUri);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&targetUri);
	zephir_read_property(&targetUri, this_ptr, ZEND_STRL("_targetUri"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&targetUri)) {
		ZEPHIR_OBS_NVAR(&targetUri);
		zephir_read_property(&targetUri, this_ptr, ZEND_STRL("_path"), PH_NOISY_CC);
	}
	RETURN_CCTOR(&targetUri);

}

/**
 * Returns the complete location where the resource is located
 */
PHP_METHOD(Phalcon_Assets_Resource, getRealSourcePath) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *basePath_param = NULL, sourcePath, _0, _1$$4;
	zval basePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath);
	ZVAL_UNDEF(&sourcePath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(basePath)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &basePath_param);

	if (!basePath_param) {
		ZEPHIR_INIT_VAR(&basePath);
		ZVAL_STRING(&basePath, "");
	} else {
		zephir_get_strval(&basePath, basePath_param);
	}


	ZEPHIR_OBS_VAR(&sourcePath);
	zephir_read_property(&sourcePath, this_ptr, ZEND_STRL("_sourcePath"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&sourcePath)) {
		ZEPHIR_OBS_NVAR(&sourcePath);
		zephir_read_property(&sourcePath, this_ptr, ZEND_STRL("_path"), PH_NOISY_CC);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("_local"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_CONCAT_VV(&_1$$4, &basePath, &sourcePath);
		ZEPHIR_RETURN_CALL_FUNCTION("realpath", NULL, 53, &_1$$4);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&sourcePath);

}

/**
 * Returns the complete location where the resource must be written
 */
PHP_METHOD(Phalcon_Assets_Resource, getRealTargetPath) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *basePath_param = NULL, targetPath, completePath, _0;
	zval basePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath);
	ZVAL_UNDEF(&targetPath);
	ZVAL_UNDEF(&completePath);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(basePath)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &basePath_param);

	if (!basePath_param) {
		ZEPHIR_INIT_VAR(&basePath);
		ZVAL_STRING(&basePath, "");
	} else {
		zephir_get_strval(&basePath, basePath_param);
	}


	ZEPHIR_OBS_VAR(&targetPath);
	zephir_read_property(&targetPath, this_ptr, ZEND_STRL("_targetPath"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&targetPath)) {
		ZEPHIR_OBS_NVAR(&targetPath);
		zephir_read_property(&targetPath, this_ptr, ZEND_STRL("_path"), PH_NOISY_CC);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("_local"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&completePath);
		ZEPHIR_CONCAT_VV(&completePath, &basePath, &targetPath);
		if ((zephir_file_exists(&completePath) == SUCCESS)) {
			ZEPHIR_RETURN_CALL_FUNCTION("realpath", NULL, 53, &completePath);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_CCTOR(&completePath);
	}
	RETURN_CCTOR(&targetPath);

}

/**
 * Gets the resource's key.
 */
PHP_METHOD(Phalcon_Assets_Resource, getResourceKey) {

	zval key, _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getpath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&key);
	ZEPHIR_CONCAT_VSV(&key, &_0, ":", &_1);
	zephir_md5(return_value, &key);
	RETURN_MM();

}

