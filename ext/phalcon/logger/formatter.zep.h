
extern zend_class_entry *phalcon_logger_formatter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter);

PHP_METHOD(Phalcon_Logger_Formatter, getTypeString);
PHP_METHOD(Phalcon_Logger_Formatter, interpolate);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_formatter_gettypestring, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_interpolate, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_formatter_method_entry) {
	PHP_ME(Phalcon_Logger_Formatter, getTypeString, arginfo_phalcon_logger_formatter_gettypestring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter, interpolate, arginfo_phalcon_logger_formatter_interpolate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
