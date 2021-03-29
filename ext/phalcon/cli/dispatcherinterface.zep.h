
extern zend_class_entry *phalcon_cli_dispatcherinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_DispatcherInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_settasksuffix, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, taskSuffix, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_setdefaulttask, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, taskName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_settaskname, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, taskName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_gettaskname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_getlasttask, 0, 0, Phalcon\\Cli\\TaskInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cli_dispatcherinterface_getactivetask, 0, 0, Phalcon\\Cli\\TaskInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cli_dispatcherinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Cli_DispatcherInterface, setTaskSuffix, arginfo_phalcon_cli_dispatcherinterface_settasksuffix)
	PHP_ABSTRACT_ME(Phalcon_Cli_DispatcherInterface, setDefaultTask, arginfo_phalcon_cli_dispatcherinterface_setdefaulttask)
	PHP_ABSTRACT_ME(Phalcon_Cli_DispatcherInterface, setTaskName, arginfo_phalcon_cli_dispatcherinterface_settaskname)
	PHP_ABSTRACT_ME(Phalcon_Cli_DispatcherInterface, getTaskName, arginfo_phalcon_cli_dispatcherinterface_gettaskname)
	PHP_ABSTRACT_ME(Phalcon_Cli_DispatcherInterface, getLastTask, arginfo_phalcon_cli_dispatcherinterface_getlasttask)
	PHP_ABSTRACT_ME(Phalcon_Cli_DispatcherInterface, getActiveTask, arginfo_phalcon_cli_dispatcherinterface_getactivetask)
	PHP_FE_END
};
