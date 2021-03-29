
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/string.h"


/**
 * Phalcon\Cache\Frontend\Json
 *
 * Allows to cache data converting/deconverting them to JSON.
 *
 * This adapter uses the json_encode/json_decode PHP's functions
 *
 * As the data is encoded in JSON other systems accessing the same backend could
 * process them
 *
 *<code>
 *<?php
 *
 * // Cache the data for 2 days
 * $frontCache = new \Phalcon\Cache\Frontend\Json(
 *     [
 *         "lifetime" => 172800,
 *     ]
 * );
 *
 * // Create the Cache setting memcached connection options
 * $cache = new \Phalcon\Cache\Backend\Memcache(
 *     $frontCache,
 *     [
 *         "host"       => "localhost",
 *         "port"       => 11211,
 *         "persistent" => false,
 *     ]
 * );
 *
 * // Cache arbitrary data
 * $cache->save("my-data", [1, 2, 3, 4, 5]);
 *
 * // Get data
 * $data = $cache->get("my-data");
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Frontend_Json) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Cache\\Frontend, Json, phalcon, cache_frontend_json, phalcon_cache_frontend_json_method_entry, 0);

	zend_declare_property_null(phalcon_cache_frontend_json_ce, SL("_frontendOptions"), ZEND_ACC_PROTECTED);

	zend_class_implements(phalcon_cache_frontend_json_ce, 1, phalcon_cache_frontendinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Cache\Frontend\Base64 constructor
 *
 * @param array frontendOptions
 */
PHP_METHOD(Phalcon_Cache_Frontend_Json, __construct) {

	zval *frontendOptions = NULL, frontendOptions_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&frontendOptions_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(frontendOptions)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(0, 1, &frontendOptions);

	if (!frontendOptions) {
		frontendOptions = &frontendOptions_sub;
		frontendOptions = &__$null;
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("_frontendOptions"), frontendOptions);

}

/**
 * Returns the cache lifetime
 */
PHP_METHOD(Phalcon_Cache_Frontend_Json, getLifetime) {

	zval options, lifetime;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&lifetime);



	zephir_read_property(&options, this_ptr, ZEND_STRL("_frontendOptions"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		if (zephir_array_isset_string_fetch(&lifetime, &options, SL("lifetime"), 1)) {
			RETURN_CTORW(&lifetime);
		}
	}
	RETURN_LONG(1);

}

/**
 * Check whether if frontend is buffering output
 */
PHP_METHOD(Phalcon_Cache_Frontend_Json, isBuffering) {

	zval *this_ptr = getThis();



	RETURN_BOOL(0);

}

/**
 * Starts output frontend. Actually, does nothing
 */
PHP_METHOD(Phalcon_Cache_Frontend_Json, start) {

	zval *this_ptr = getThis();




}

/**
 * Returns output cached content
 *
 * @return string
 */
PHP_METHOD(Phalcon_Cache_Frontend_Json, getContent) {

	zval *this_ptr = getThis();



	RETURN_NULL();

}

/**
 * Stops output frontend
 */
PHP_METHOD(Phalcon_Cache_Frontend_Json, stop) {

	zval *this_ptr = getThis();




}

/**
 * Serializes data before storing them
 */
PHP_METHOD(Phalcon_Cache_Frontend_Json, beforeStore) {

	zval *data, data_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &data);



	zephir_json_encode(return_value, data, 0 );
	return;

}

/**
 * Unserializes data after retrieval
 */
PHP_METHOD(Phalcon_Cache_Frontend_Json, afterRetrieve) {

	zval *data, data_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &data);



	zephir_json_decode(return_value, data, 0 );
	return;

}

