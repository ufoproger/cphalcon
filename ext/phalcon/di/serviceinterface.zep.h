
extern zend_class_entry *phalcon_di_serviceinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_ServiceInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface_getname, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface_setshared, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, shared, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_serviceinterface_isshared, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface_setdefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface_getdefinition, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface_resolve, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_di_serviceinterface_setparameter, 0, 2, Phalcon\\Di\\ServiceInterface, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, parameter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_di_serviceinterface___set_state, 0, 1, Phalcon\\Di\\ServiceInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_serviceinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Di_ServiceInterface, getName, arginfo_phalcon_di_serviceinterface_getname)
	PHP_ABSTRACT_ME(Phalcon_Di_ServiceInterface, setShared, arginfo_phalcon_di_serviceinterface_setshared)
	PHP_ABSTRACT_ME(Phalcon_Di_ServiceInterface, isShared, arginfo_phalcon_di_serviceinterface_isshared)
	PHP_ABSTRACT_ME(Phalcon_Di_ServiceInterface, setDefinition, arginfo_phalcon_di_serviceinterface_setdefinition)
	PHP_ABSTRACT_ME(Phalcon_Di_ServiceInterface, getDefinition, arginfo_phalcon_di_serviceinterface_getdefinition)
	PHP_ABSTRACT_ME(Phalcon_Di_ServiceInterface, resolve, arginfo_phalcon_di_serviceinterface_resolve)
	PHP_ABSTRACT_ME(Phalcon_Di_ServiceInterface, setParameter, arginfo_phalcon_di_serviceinterface_setparameter)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_di_serviceinterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
