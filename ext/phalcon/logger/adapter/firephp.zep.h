
extern zend_class_entry *phalcon_logger_adapter_firephp_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_Firephp);

PHP_METHOD(Phalcon_Logger_Adapter_Firephp, getFormatter);
PHP_METHOD(Phalcon_Logger_Adapter_Firephp, logInternal);
PHP_METHOD(Phalcon_Logger_Adapter_Firephp, close);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_adapter_firephp_getformatter, 0, 0, Phalcon\\Logger\\FormatterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapter_firephp_loginternal, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, time, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapter_firephp_close, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_adapter_firephp_method_entry) {
	PHP_ME(Phalcon_Logger_Adapter_Firephp, getFormatter, arginfo_phalcon_logger_adapter_firephp_getformatter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_Firephp, logInternal, arginfo_phalcon_logger_adapter_firephp_loginternal, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_Firephp, close, arginfo_phalcon_logger_adapter_firephp_close, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
