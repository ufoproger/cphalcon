
extern zend_class_entry *phalcon_assets_resourceinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_ResourceInterface);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_resourceinterface_settype, 0, 1, Phalcon\\Assets\\ResourceInterface, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_resourceinterface_gettype, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_resourceinterface_setfilter, 0, 1, Phalcon\\Assets\\ResourceInterface, 0)
	ZEND_ARG_TYPE_INFO(0, filter, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_resourceinterface_getfilter, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_resourceinterface_setattributes, 0, 1, Phalcon\\Assets\\ResourceInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_resourceinterface_getattributes, 0, 0, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_resourceinterface_getresourcekey, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_resourceinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Assets_ResourceInterface, setType, arginfo_phalcon_assets_resourceinterface_settype)
	PHP_ABSTRACT_ME(Phalcon_Assets_ResourceInterface, getType, arginfo_phalcon_assets_resourceinterface_gettype)
	PHP_ABSTRACT_ME(Phalcon_Assets_ResourceInterface, setFilter, arginfo_phalcon_assets_resourceinterface_setfilter)
	PHP_ABSTRACT_ME(Phalcon_Assets_ResourceInterface, getFilter, arginfo_phalcon_assets_resourceinterface_getfilter)
	PHP_ABSTRACT_ME(Phalcon_Assets_ResourceInterface, setAttributes, arginfo_phalcon_assets_resourceinterface_setattributes)
	PHP_ABSTRACT_ME(Phalcon_Assets_ResourceInterface, getAttributes, arginfo_phalcon_assets_resourceinterface_getattributes)
	PHP_ABSTRACT_ME(Phalcon_Assets_ResourceInterface, getResourceKey, arginfo_phalcon_assets_resourceinterface_getresourcekey)
	PHP_FE_END
};
