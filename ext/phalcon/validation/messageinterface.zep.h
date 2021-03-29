
extern zend_class_entry *phalcon_validation_messageinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_MessageInterface);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_validation_messageinterface_settype, 0, 1, Phalcon\\Validation\\Message, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_messageinterface_gettype, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_validation_messageinterface_setmessage, 0, 1, Phalcon\\Validation\\Message, 0)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_messageinterface_getmessage, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_validation_messageinterface_setfield, 0, 1, Phalcon\\Validation\\Message, 0)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_messageinterface_getfield, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_messageinterface___tostring, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_validation_messageinterface___set_state, 0, 1, Phalcon\\Validation\\MessageInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, message, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_messageinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, setType, arginfo_phalcon_validation_messageinterface_settype)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, getType, arginfo_phalcon_validation_messageinterface_gettype)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, setMessage, arginfo_phalcon_validation_messageinterface_setmessage)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, getMessage, arginfo_phalcon_validation_messageinterface_getmessage)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, setField, arginfo_phalcon_validation_messageinterface_setfield)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, getField, arginfo_phalcon_validation_messageinterface_getfield)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, __toString, arginfo_phalcon_validation_messageinterface___tostring)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_validation_messageinterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
