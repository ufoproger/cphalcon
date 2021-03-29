
extern zend_class_entry *phalcon_cli_task_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_Task);

PHP_METHOD(Phalcon_Cli_Task, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_task___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cli_task_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Cli_Task, __construct, arginfo_phalcon_cli_task___construct, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR)
#else
	PHP_ME(Phalcon_Cli_Task, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR)
#endif
	PHP_FE_END
};
