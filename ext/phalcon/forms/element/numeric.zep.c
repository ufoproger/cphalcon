
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * Phalcon\Forms\Element\Numeric
 *
 * Component INPUT[type=number] for forms
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Numeric) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, Numeric, phalcon, forms_element_numeric, phalcon_forms_element_ce, phalcon_forms_element_numeric_method_entry, 0);

	return SUCCESS;

}

/**
 * Renders the element widget returning html
 *
 * @param array $attributes
 */
PHP_METHOD(Phalcon_Forms_Element_Numeric, render) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *attributes = NULL, attributes_sub, __$null, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1);
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
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_tag_ce, "numericfield", &_0, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

