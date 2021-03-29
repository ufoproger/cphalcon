
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * Phalcon\Forms\Element\Select
 *
 * Component SELECT (choice) for forms
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Select) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, Select, phalcon, forms_element_select, phalcon_forms_element_ce, phalcon_forms_element_select_method_entry, 0);

	zend_declare_property_null(phalcon_forms_element_select_ce, SL("_optionsValues"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Phalcon\Forms\Element constructor
 *
 * @param string name
 * @param object|array options
 * @param array attributes
 */
PHP_METHOD(Phalcon_Forms_Element_Select, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *name_param = NULL, *options = NULL, options_sub, *attributes = NULL, attributes_sub, __$null;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&options_sub);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(options)
		Z_PARAM_ZVAL(attributes)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &name_param, &options, &attributes);

	zephir_get_strval(&name, name_param);
	if (!options) {
		options = &options_sub;
		options = &__$null;
	}
	if (!attributes) {
		attributes = &attributes_sub;
		attributes = &__$null;
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("_optionsValues"), options);
	ZEPHIR_CALL_PARENT(NULL, phalcon_forms_element_select_ce, getThis(), "__construct", &_0, 0, &name, attributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Set the choice's options
 *
 * @param array|object options
 * @return \Phalcon\Forms\Element
 */
PHP_METHOD(Phalcon_Forms_Element_Select, setOptions) {

	zval *options, options_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(options)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &options);



	zephir_update_property_zval(this_ptr, ZEND_STRL("_optionsValues"), options);
	RETURN_THISW();

}

/**
 * Returns the choices' options
 *
 * @return array|object
 */
PHP_METHOD(Phalcon_Forms_Element_Select, getOptions) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_optionsValues");

}

/**
 * Adds an option to the current options
 *
 * @param array option
 * @return this
 */
PHP_METHOD(Phalcon_Forms_Element_Select, addOption) {

	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option, option_sub, key, value, *_0$$3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(option)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &option);



	if (Z_TYPE_P(option) == IS_ARRAY) {
		zephir_is_iterable(option, 0, "phalcon/forms/element/select.zep", 84);
		if (Z_TYPE_P(option) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(option), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _3$$3);
				} else {
					ZVAL_LONG(&key, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _0$$3);
				zephir_update_property_array(this_ptr, SL("_optionsValues"), &key, &value);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, option, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, option, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, option, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, option, "current", NULL, 0);
				zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("_optionsValues"), &key, &value);
				ZEPHIR_CALL_METHOD(NULL, option, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		zephir_update_property_array_append(this_ptr, SL("_optionsValues"), option);
	}
	RETURN_THIS();

}

/**
 * Renders the element widget returning html
 *
 * @param array attributes
 */
PHP_METHOD(Phalcon_Forms_Element_Select, render) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *attributes = NULL, attributes_sub, __$null, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(attributes)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &attributes);

	if (!attributes) {
		attributes = &attributes_sub;
		attributes = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_1, this_ptr, "prepareattributes", NULL, 0, attributes);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("_optionsValues"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_tag_select_ce, "selectfield", &_0, 0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

