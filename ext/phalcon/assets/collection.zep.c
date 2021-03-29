
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/file.h"


/**
 * Phalcon\Assets\Collection
 *
 * Represents a collection of resources
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Collection) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Assets, Collection, phalcon, assets_collection, phalcon_assets_collection_method_entry, 0);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_prefix"), ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalcon_assets_collection_ce, SL("_local"), 1, ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_resources"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_codes"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_position"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_filters"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_attributes"), ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalcon_assets_collection_ce, SL("_join"), 1, ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_targetUri"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_targetPath"), ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalcon_assets_collection_ce, SL("_targetLocal"), 1, ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_sourcePath"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_assets_collection_ce, SL("_includedResources"), ZEND_ACC_PROTECTED);

	phalcon_assets_collection_ce->create_object = zephir_init_properties_Phalcon_Assets_Collection;

	zend_class_implements(phalcon_assets_collection_ce, 1, zend_ce_countable);
	zend_class_implements(phalcon_assets_collection_ce, 1, zend_ce_iterator);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Assets_Collection, getPrefix) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_prefix");

}

PHP_METHOD(Phalcon_Assets_Collection, getLocal) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_local");

}

PHP_METHOD(Phalcon_Assets_Collection, getResources) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_resources");

}

PHP_METHOD(Phalcon_Assets_Collection, getCodes) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_codes");

}

PHP_METHOD(Phalcon_Assets_Collection, getPosition) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_position");

}

PHP_METHOD(Phalcon_Assets_Collection, getFilters) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_filters");

}

PHP_METHOD(Phalcon_Assets_Collection, getAttributes) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_attributes");

}

PHP_METHOD(Phalcon_Assets_Collection, getJoin) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_join");

}

PHP_METHOD(Phalcon_Assets_Collection, getTargetUri) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_targetUri");

}

PHP_METHOD(Phalcon_Assets_Collection, getTargetPath) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_targetPath");

}

PHP_METHOD(Phalcon_Assets_Collection, getTargetLocal) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_targetLocal");

}

PHP_METHOD(Phalcon_Assets_Collection, getSourcePath) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_sourcePath");

}

/**
 * Phalcon\Assets\Collection constructor
 */
PHP_METHOD(Phalcon_Assets_Collection, __construct) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_includedResources"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a resource to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, add) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *resource, resource_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resource_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(resource, phalcon_assets_resource_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &resource);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addresource", NULL, 86, resource);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds an inline code to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addInline) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *code, code_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&code_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(code, phalcon_assets_inline_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &code);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addresource", NULL, 86, code);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Checks this the resource is added to the collection.
 *
 * <code>
 * use Phalcon\Assets\Resource;
 * use Phalcon\Assets\Collection;
 *
 * $collection = new Collection();
 * $resource = new Resource("js", "js/jquery.js");
 * $collection->add($resource);
 * $collection->has($resource); // true
 * </code>
 */
PHP_METHOD(Phalcon_Assets_Collection, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *resource, resource_sub, key, resources;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resource_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&resources);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(resource, phalcon_assets_resourceinterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &resource);



	ZEPHIR_CALL_METHOD(&key, resource, "getresourcekey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&resources);
	zephir_read_property(&resources, this_ptr, ZEND_STRL("_includedResources"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_fast_in_array(&key, &resources));

}

/**
 * Adds a CSS resource to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addCss) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool filter;
	zval *path_param = NULL, *local = NULL, local_sub, *filter_param = NULL, *attributes = NULL, attributes_sub, __$null, collectionLocal, collectionAttributes, _0, _1;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&local_sub);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&collectionLocal);
	ZVAL_UNDEF(&collectionAttributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(path)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(local)
		Z_PARAM_BOOL(filter)
		Z_PARAM_ZVAL(attributes)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &path_param, &local, &filter_param, &attributes);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}
	if (!local) {
		local = &local_sub;
		local = &__$null;
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


	if (((Z_TYPE_P(local) == IS_TRUE || Z_TYPE_P(local) == IS_FALSE) == 1)) {
		ZEPHIR_CPY_WRT(&collectionLocal, local);
	} else {
		ZEPHIR_OBS_NVAR(&collectionLocal);
		zephir_read_property(&collectionLocal, this_ptr, ZEND_STRL("_local"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&collectionAttributes, attributes);
	} else {
		ZEPHIR_OBS_NVAR(&collectionAttributes);
		zephir_read_property(&collectionAttributes, this_ptr, ZEND_STRL("_attributes"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_assets_resource_css_ce);
	if (filter) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 87, &path, &collectionLocal, &_1, &collectionAttributes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds an inline CSS to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addInlineCss) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool filter;
	zval *content_param = NULL, *filter_param = NULL, *attributes = NULL, attributes_sub, __$null, collectionAttributes, _0, _1;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&collectionAttributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(content)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(filter)
		Z_PARAM_ZVAL(attributes)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &content_param, &filter_param, &attributes);

	zephir_get_strval(&content, content_param);
	if (!filter_param) {
		filter = 1;
	} else {
		filter = zephir_get_boolval(filter_param);
	}
	if (!attributes) {
		attributes = &attributes_sub;
		attributes = &__$null;
	}


	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&collectionAttributes, attributes);
	} else {
		ZEPHIR_OBS_NVAR(&collectionAttributes);
		zephir_read_property(&collectionAttributes, this_ptr, ZEND_STRL("_attributes"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_assets_inline_css_ce);
	if (filter) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 88, &content, &_1, &collectionAttributes);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("_codes"), &_0);
	RETURN_THIS();

}

/**
 * Adds a javascript resource to the collection
 *
 * @param string path
 * @param boolean local
 * @param boolean filter
 * @param array attributes
 * @return \Phalcon\Assets\Collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addJs) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool filter;
	zval *path_param = NULL, *local = NULL, local_sub, *filter_param = NULL, *attributes = NULL, attributes_sub, __$null, collectionLocal, collectionAttributes, _0, _1;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&local_sub);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&collectionLocal);
	ZVAL_UNDEF(&collectionAttributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(path)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(local)
		Z_PARAM_BOOL(filter)
		Z_PARAM_ZVAL(attributes)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &path_param, &local, &filter_param, &attributes);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}
	if (!local) {
		local = &local_sub;
		local = &__$null;
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


	if (((Z_TYPE_P(local) == IS_TRUE || Z_TYPE_P(local) == IS_FALSE) == 1)) {
		ZEPHIR_CPY_WRT(&collectionLocal, local);
	} else {
		ZEPHIR_OBS_NVAR(&collectionLocal);
		zephir_read_property(&collectionLocal, this_ptr, ZEND_STRL("_local"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&collectionAttributes, attributes);
	} else {
		ZEPHIR_OBS_NVAR(&collectionAttributes);
		zephir_read_property(&collectionAttributes, this_ptr, ZEND_STRL("_attributes"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_assets_resource_js_ce);
	if (filter) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 89, &path, &collectionLocal, &_1, &collectionAttributes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds an inline javascript to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addInlineJs) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool filter;
	zval *content_param = NULL, *filter_param = NULL, *attributes = NULL, attributes_sub, __$null, collectionAttributes, _0, _1;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&collectionAttributes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(content)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(filter)
		Z_PARAM_ZVAL(attributes)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &content_param, &filter_param, &attributes);

	zephir_get_strval(&content, content_param);
	if (!filter_param) {
		filter = 1;
	} else {
		filter = zephir_get_boolval(filter_param);
	}
	if (!attributes) {
		attributes = &attributes_sub;
		attributes = &__$null;
	}


	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&collectionAttributes, attributes);
	} else {
		ZEPHIR_OBS_NVAR(&collectionAttributes);
		zephir_read_property(&collectionAttributes, this_ptr, ZEND_STRL("_attributes"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_assets_inline_js_ce);
	if (filter) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 90, &content, &_1, &collectionAttributes);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("_codes"), &_0);
	RETURN_THIS();

}

/**
 * Returns the number of elements in the form
 */
PHP_METHOD(Phalcon_Assets_Collection, count) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("_resources"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0));

}

/**
 * Rewinds the internal iterator
 */
PHP_METHOD(Phalcon_Assets_Collection, rewind) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_position"), &_0);

}

/**
 * Returns the current resource in the iterator
 */
PHP_METHOD(Phalcon_Assets_Collection, current) {

	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("_resources"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("_position"), PH_NOISY_CC);
	zephir_array_fetch(&_1, &_0, &_2, PH_NOISY | PH_READONLY, "phalcon/assets/collection.zep", 225);
	RETURN_CTOR(&_1);

}

/**
 * Returns the current position/key in the iterator
 *
 * @return int
 */
PHP_METHOD(Phalcon_Assets_Collection, key) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_position");

}

/**
 * Moves the internal iteration pointer to the next position
 */
PHP_METHOD(Phalcon_Assets_Collection, next) {

	zval *this_ptr = getThis();



	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_position")));

}

/**
 * Check if the current element in the iterator is valid
 */
PHP_METHOD(Phalcon_Assets_Collection, valid) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("_resources"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("_position"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, &_1));

}

/**
 * Sets the target path of the file for the filtered/join output
 */
PHP_METHOD(Phalcon_Assets_Collection, setTargetPath) {

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

	if (UNEXPECTED(Z_TYPE_P(targetPath_param) != IS_STRING && Z_TYPE_P(targetPath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'targetPath' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(targetPath_param) == IS_STRING)) {
		zephir_get_strval(&targetPath, targetPath_param);
	} else {
		ZEPHIR_INIT_VAR(&targetPath);
		ZVAL_EMPTY_STRING(&targetPath);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("_targetPath"), &targetPath);
	RETURN_THIS();

}

/**
 * Sets a base source path for all the resources in this collection
 */
PHP_METHOD(Phalcon_Assets_Collection, setSourcePath) {

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

	if (UNEXPECTED(Z_TYPE_P(sourcePath_param) != IS_STRING && Z_TYPE_P(sourcePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sourcePath' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sourcePath_param) == IS_STRING)) {
		zephir_get_strval(&sourcePath, sourcePath_param);
	} else {
		ZEPHIR_INIT_VAR(&sourcePath);
		ZVAL_EMPTY_STRING(&sourcePath);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("_sourcePath"), &sourcePath);
	RETURN_THIS();

}

/**
 * Sets a target uri for the generated HTML
 */
PHP_METHOD(Phalcon_Assets_Collection, setTargetUri) {

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

	if (UNEXPECTED(Z_TYPE_P(targetUri_param) != IS_STRING && Z_TYPE_P(targetUri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'targetUri' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(targetUri_param) == IS_STRING)) {
		zephir_get_strval(&targetUri, targetUri_param);
	} else {
		ZEPHIR_INIT_VAR(&targetUri);
		ZVAL_EMPTY_STRING(&targetUri);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("_targetUri"), &targetUri);
	RETURN_THIS();

}

/**
 * Sets a common prefix for all the resources
 */
PHP_METHOD(Phalcon_Assets_Collection, setPrefix) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *prefix_param = NULL;
	zval prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(prefix)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefix_param);

	if (UNEXPECTED(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(&prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_EMPTY_STRING(&prefix);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("_prefix"), &prefix);
	RETURN_THIS();

}

/**
 * Sets if the collection uses local resources by default
 */
PHP_METHOD(Phalcon_Assets_Collection, setLocal) {

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

	if (UNEXPECTED(Z_TYPE_P(local_param) != IS_TRUE && Z_TYPE_P(local_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'local' must be of the type bool"));
		RETURN_NULL();
	}
	local = (Z_TYPE_P(local_param) == IS_TRUE);


	if (local) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_local"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_local"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Sets extra HTML attributes
 */
PHP_METHOD(Phalcon_Assets_Collection, setAttributes) {

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

	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("_attributes"), &attributes);
	RETURN_THIS();

}

/**
 * Sets an array of filters in the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, setFilters) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *filters_param = NULL;
	zval filters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filters);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(filters)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filters_param);

	ZEPHIR_OBS_COPY_OR_DUP(&filters, filters_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("_filters"), &filters);
	RETURN_THIS();

}

/**
 * Sets the target local
 */
PHP_METHOD(Phalcon_Assets_Collection, setTargetLocal) {

	zval *targetLocal_param = NULL, __$true, __$false;
	zend_bool targetLocal;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(targetLocal)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &targetLocal_param);

	if (UNEXPECTED(Z_TYPE_P(targetLocal_param) != IS_TRUE && Z_TYPE_P(targetLocal_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'targetLocal' must be of the type bool"));
		RETURN_NULL();
	}
	targetLocal = (Z_TYPE_P(targetLocal_param) == IS_TRUE);


	if (targetLocal) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_targetLocal"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_targetLocal"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Sets if all filtered resources in the collection must be joined in a single result file
 */
PHP_METHOD(Phalcon_Assets_Collection, join) {

	zval *join_param = NULL, __$true, __$false;
	zend_bool join;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(join)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &join_param);

	join = zephir_get_boolval(join_param);


	if (join) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_join"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_join"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Returns the complete location where the joined/filtered collection must be written
 */
PHP_METHOD(Phalcon_Assets_Collection, getRealTargetPath) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *basePath_param = NULL, targetPath, completePath;
	zval basePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePath);
	ZVAL_UNDEF(&targetPath);
	ZVAL_UNDEF(&completePath);
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


	ZEPHIR_OBS_VAR(&targetPath);
	zephir_read_property(&targetPath, this_ptr, ZEND_STRL("_targetPath"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&completePath);
	ZEPHIR_CONCAT_VV(&completePath, &basePath, &targetPath);
	if ((zephir_file_exists(&completePath) == SUCCESS)) {
		ZEPHIR_RETURN_CALL_FUNCTION("realpath", NULL, 53, &completePath);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&completePath);

}

/**
 * Adds a filter to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addFilter) {

	zval *filter, filter_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(filter, phalcon_assets_filterinterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &filter);



	zephir_update_property_array_append(this_ptr, SL("_filters"), filter);
	RETURN_THISW();

}

/**
 * Adds a resource or inline-code to the collection
 */
PHP_METHOD(Phalcon_Assets_Collection, addResource) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *resource, resource_sub, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resource_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(resource, phalcon_assets_resourceinterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &resource);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, resource);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		if (zephir_instance_of_ev(resource, phalcon_assets_resource_ce)) {
			zephir_update_property_array_append(this_ptr, SL("_resources"), resource);
		} else {
			zephir_update_property_array_append(this_ptr, SL("_codes"), resource);
		}
		ZEPHIR_CALL_METHOD(&_1$$3, resource, "getresourcekey", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_array_append(this_ptr, SL("_includedResources"), &_1$$3);
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

zend_object *zephir_init_properties_Phalcon_Assets_Collection(zend_class_entry *class_type) {

		zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _7$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("_attributes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("_attributes"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("_filters"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("_filters"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("_codes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("_codes"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("_resources"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("_resources"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

