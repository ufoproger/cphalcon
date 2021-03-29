
extern zend_class_entry *phalcon_acl_adapter_memory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter_Memory);

PHP_METHOD(Phalcon_Acl_Adapter_Memory, __construct);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addRole);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addInherit);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isRole);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isResource);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResource);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResourceAccess);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, dropResourceAccess);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, _allowOrDeny);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allow);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, deny);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isAllowed);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, setNoArgumentsDefaultAction);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getNoArgumentsDefaultAction);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getRoles);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getResources);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_addrole, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, role)
	ZEND_ARG_INFO(0, accessInherits)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_addinherit, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, roleName, IS_STRING, 0)
	ZEND_ARG_INFO(0, roleToInherit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_isrole, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, roleName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_isresource, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, resourceName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_addresource, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, resourceValue)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_addresourceaccess, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, resourceName, IS_STRING, 0)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_dropresourceaccess, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, resourceName, IS_STRING, 0)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory__allowordeny, 0, 0, 4)
	ZEND_ARG_TYPE_INFO(0, roleName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, resourceName, IS_STRING, 0)
	ZEND_ARG_INFO(0, access)
	ZEND_ARG_INFO(0, action)
	ZEND_ARG_INFO(0, func)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_allow, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, roleName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, resourceName, IS_STRING, 0)
	ZEND_ARG_INFO(0, access)
	ZEND_ARG_INFO(0, func)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_deny, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, roleName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, resourceName, IS_STRING, 0)
	ZEND_ARG_INFO(0, access)
	ZEND_ARG_INFO(0, func)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_isallowed, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_TYPE_INFO(0, access, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_setnoargumentsdefaultaction, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, defaultAccess, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_getnoargumentsdefaultaction, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_getroles, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_getresources, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_adapter_memory_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Acl_Adapter_Memory, __construct, arginfo_phalcon_acl_adapter_memory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#else
	PHP_ME(Phalcon_Acl_Adapter_Memory, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#endif
	PHP_ME(Phalcon_Acl_Adapter_Memory, addRole, arginfo_phalcon_acl_adapter_memory_addrole, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, addInherit, arginfo_phalcon_acl_adapter_memory_addinherit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, isRole, arginfo_phalcon_acl_adapter_memory_isrole, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, isResource, arginfo_phalcon_acl_adapter_memory_isresource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, addResource, arginfo_phalcon_acl_adapter_memory_addresource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, addResourceAccess, arginfo_phalcon_acl_adapter_memory_addresourceaccess, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, dropResourceAccess, arginfo_phalcon_acl_adapter_memory_dropresourceaccess, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, _allowOrDeny, arginfo_phalcon_acl_adapter_memory__allowordeny, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Acl_Adapter_Memory, allow, arginfo_phalcon_acl_adapter_memory_allow, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, deny, arginfo_phalcon_acl_adapter_memory_deny, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, isAllowed, arginfo_phalcon_acl_adapter_memory_isallowed, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, setNoArgumentsDefaultAction, arginfo_phalcon_acl_adapter_memory_setnoargumentsdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, getNoArgumentsDefaultAction, arginfo_phalcon_acl_adapter_memory_getnoargumentsdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, getRoles, arginfo_phalcon_acl_adapter_memory_getroles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, getResources, arginfo_phalcon_acl_adapter_memory_getresources, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
