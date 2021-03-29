
extern zend_class_entry *phalcon_cache_backend_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend);

PHP_METHOD(Phalcon_Cache_Backend, getFrontend);
PHP_METHOD(Phalcon_Cache_Backend, setFrontend);
PHP_METHOD(Phalcon_Cache_Backend, getOptions);
PHP_METHOD(Phalcon_Cache_Backend, setOptions);
PHP_METHOD(Phalcon_Cache_Backend, getLastKey);
PHP_METHOD(Phalcon_Cache_Backend, setLastKey);
PHP_METHOD(Phalcon_Cache_Backend, __construct);
PHP_METHOD(Phalcon_Cache_Backend, start);
PHP_METHOD(Phalcon_Cache_Backend, stop);
PHP_METHOD(Phalcon_Cache_Backend, isFresh);
PHP_METHOD(Phalcon_Cache_Backend, isStarted);
PHP_METHOD(Phalcon_Cache_Backend, getLifetime);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_getfrontend, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_setfrontend, 0, 0, 1)
	ZEND_ARG_INFO(0, frontend)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_getoptions, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_getlastkey, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_setlastkey, 0, 0, 1)
	ZEND_ARG_INFO(0, lastKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, frontend, Phalcon\\Cache\\FrontendInterface, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_start, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_stop, 0, 0, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, stopBuffer, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_isfresh, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_isstarted, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_getlifetime, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_backend_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Cache_Backend, getFrontend, arginfo_phalcon_cache_backend_getfrontend, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Cache_Backend, getFrontend, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Cache_Backend, setFrontend, arginfo_phalcon_cache_backend_setfrontend, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Cache_Backend, getOptions, arginfo_phalcon_cache_backend_getoptions, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Cache_Backend, getOptions, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Cache_Backend, setOptions, arginfo_phalcon_cache_backend_setoptions, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Cache_Backend, getLastKey, arginfo_phalcon_cache_backend_getlastkey, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Cache_Backend, getLastKey, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Cache_Backend, setLastKey, arginfo_phalcon_cache_backend_setlastkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend, __construct, arginfo_phalcon_cache_backend___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Backend, start, arginfo_phalcon_cache_backend_start, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend, stop, arginfo_phalcon_cache_backend_stop, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend, isFresh, arginfo_phalcon_cache_backend_isfresh, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend, isStarted, arginfo_phalcon_cache_backend_isstarted, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend, getLifetime, arginfo_phalcon_cache_backend_getlifetime, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
