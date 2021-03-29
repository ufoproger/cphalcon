
extern zend_class_entry *phalcon_session_adapter_libmemcached_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Libmemcached);

PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, getLibmemcached);
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, getLifetime);
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, __construct);
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, open);
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, close);
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, read);
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, write);
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, destroy);
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, gc);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_libmemcached_getlibmemcached, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_libmemcached_getlifetime, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_libmemcached___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_libmemcached_open, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_libmemcached_close, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_libmemcached_read, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, sessionId, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_libmemcached_write, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, sessionId, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_libmemcached_destroy, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, sessionId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_adapter_libmemcached_gc, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_adapter_libmemcached_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, getLibmemcached, arginfo_phalcon_session_adapter_libmemcached_getlibmemcached, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, getLibmemcached, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, getLifetime, arginfo_phalcon_session_adapter_libmemcached_getlifetime, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, getLifetime, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, __construct, arginfo_phalcon_session_adapter_libmemcached___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, open, arginfo_phalcon_session_adapter_libmemcached_open, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, close, arginfo_phalcon_session_adapter_libmemcached_close, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, read, arginfo_phalcon_session_adapter_libmemcached_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, write, arginfo_phalcon_session_adapter_libmemcached_write, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, destroy, arginfo_phalcon_session_adapter_libmemcached_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, gc, arginfo_phalcon_session_adapter_libmemcached_gc, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
