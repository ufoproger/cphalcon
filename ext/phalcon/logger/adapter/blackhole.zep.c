
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * Phalcon\Logger\Adapter\Blackhole
 *
 * Any record it can handle will be thrown away.
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_Blackhole) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger\\Adapter, Blackhole, phalcon, logger_adapter_blackhole, phalcon_logger_adapter_ce, phalcon_logger_adapter_blackhole_method_entry, 0);

	return SUCCESS;

}

/**
 * Returns the internal formatter
 */
PHP_METHOD(Phalcon_Logger_Adapter_Blackhole, getFormatter) {

	zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("_formatter"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_logger_formatter_line_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 233);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("_formatter"), &_1$$3);
	}
	RETURN_MM_MEMBER(getThis(), "_formatter");

}

/**
 * Writes the log to the blackhole
 */
PHP_METHOD(Phalcon_Logger_Adapter_Blackhole, logInternal) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval context;
	zend_long type, time;
	zval *message_param = NULL, *type_param = NULL, *time_param = NULL, *context_param = NULL;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&context);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_STR(message)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(time)
		Z_PARAM_ARRAY(context)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &message_param, &type_param, &time_param, &context_param);

	zephir_get_strval(&message, message_param);
	type = zephir_get_intval(type_param);
	time = zephir_get_intval(time_param);
	zephir_get_arrval(&context, context_param);



}

/**
 * Closes the logger
 */
PHP_METHOD(Phalcon_Logger_Adapter_Blackhole, close) {

	zval *this_ptr = getThis();




}

