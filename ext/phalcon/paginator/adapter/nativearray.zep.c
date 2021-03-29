
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"


/**
 * Phalcon\Paginator\Adapter\NativeArray
 *
 * Pagination using a PHP array as source of data
 *
 * <code>
 * use Phalcon\Paginator\Adapter\NativeArray;
 *
 * $paginator = new NativeArray(
 *     [
 *         "data"  => [
 *             ["id" => 1, "name" => "Artichoke"],
 *             ["id" => 2, "name" => "Carrots"],
 *             ["id" => 3, "name" => "Beet"],
 *             ["id" => 4, "name" => "Lettuce"],
 *             ["id" => 5, "name" => ""],
 *         ],
 *         "limit" => 2,
 *         "page"  => $currentPage,
 *     ]
 * );
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_NativeArray) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Paginator\\Adapter, NativeArray, phalcon, paginator_adapter_nativearray, phalcon_paginator_adapter_ce, phalcon_paginator_adapter_nativearray_method_entry, 0);

	/**
	 * Configuration of the paginator
	 */
	zend_declare_property_null(phalcon_paginator_adapter_nativearray_ce, SL("_config"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Phalcon\Paginator\Adapter\NativeArray constructor
 */
PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *config_param = NULL, page, limit;
	zval config;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&page);
	ZVAL_UNDEF(&limit);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(config)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config_param);

	zephir_get_arrval(&config, config_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("_config"), &config);
	if (zephir_array_isset_string_fetch(&limit, &config, SL("limit"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_limitRows"), &limit);
	}
	if (zephir_array_isset_string_fetch(&page, &config, SL("page"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_page"), &page);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a slice of the resultset to show in the pagination
 *
 * @deprecated will be removed after 4.0
 */
PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, getPaginate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "paginate", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a slice of the resultset to show in the pagination
 */
PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, paginate) {

	double roundedTotal = 0;
	zval config, items, page, _0, _1, _2, _3, _4, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, show = 0, pageNumber = 0, totalPages = 0, number = 0, previous = 0, next = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&page);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&config);
	zephir_read_property(&config, this_ptr, ZEND_STRL("_config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&items);
	zephir_array_fetch_string(&items, &config, SL("data"), PH_NOISY, "phalcon/paginator/adapter/nativearray.zep", 97);
	if (Z_TYPE_P(&items) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "Invalid data for paginator", "phalcon/paginator/adapter/nativearray.zep", 100);
		return;
	}
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("_limitRows"), PH_NOISY_CC);
	show = zephir_get_intval(&_0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("_page"), PH_NOISY_CC);
	pageNumber = zephir_get_intval(&_1);
	if (pageNumber <= 0) {
		pageNumber = 1;
	}
	number = zephir_fast_count_int(&items);
	ZVAL_LONG(&_2, show);
	ZEPHIR_CALL_FUNCTION(&_3, "floatval", NULL, 256, &_2);
	zephir_check_call_status();
	roundedTotal = zephir_safe_div_long_zval(number, &_3);
	totalPages = (int) (roundedTotal);
	if (totalPages != roundedTotal) {
		totalPages++;
	}
	ZVAL_LONG(&_2, (show * ((pageNumber - 1))));
	ZVAL_LONG(&_4, show);
	ZEPHIR_CALL_FUNCTION(&_5, "array_slice", NULL, 326, &items, &_2, &_4);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&items, &_5);
	if (pageNumber < totalPages) {
		next = (pageNumber + 1);
	} else {
		next = totalPages;
	}
	if (pageNumber > 1) {
		previous = (pageNumber - 1);
	} else {
		previous = 1;
	}
	ZEPHIR_INIT_VAR(&page);
	object_init(&page);
	zephir_update_property_zval(&page, ZEND_STRL("items"), &items);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, 1);
	zephir_update_property_zval(&page, ZEND_STRL("first"), &_2);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, previous);
	zephir_update_property_zval(&page, ZEND_STRL("before"), &_2);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, previous);
	zephir_update_property_zval(&page, ZEND_STRL("previous"), &_2);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, pageNumber);
	zephir_update_property_zval(&page, ZEND_STRL("current"), &_2);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, totalPages);
	zephir_update_property_zval(&page, ZEND_STRL("last"), &_2);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, next);
	zephir_update_property_zval(&page, ZEND_STRL("next"), &_2);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, totalPages);
	zephir_update_property_zval(&page, ZEND_STRL("total_pages"), &_2);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, number);
	zephir_update_property_zval(&page, ZEND_STRL("total_items"), &_2);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("_limitRows"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(&page, ZEND_STRL("limit"), &_2);
	RETURN_CCTOR(&page);

}

