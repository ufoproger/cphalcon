
extern zend_class_entry *phalcon_cache_frontend_msgpack_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Frontend_Msgpack);

PHP_METHOD(Phalcon_Cache_Frontend_Msgpack, __construct);
PHP_METHOD(Phalcon_Cache_Frontend_Msgpack, getLifetime);
PHP_METHOD(Phalcon_Cache_Frontend_Msgpack, isBuffering);
PHP_METHOD(Phalcon_Cache_Frontend_Msgpack, start);
PHP_METHOD(Phalcon_Cache_Frontend_Msgpack, getContent);
PHP_METHOD(Phalcon_Cache_Frontend_Msgpack, stop);
PHP_METHOD(Phalcon_Cache_Frontend_Msgpack, beforeStore);
PHP_METHOD(Phalcon_Cache_Frontend_Msgpack, afterRetrieve);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_msgpack___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, frontendOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_msgpack_getlifetime, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_msgpack_isbuffering, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_msgpack_start, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_msgpack_getcontent, 0, 0, IS_NULL, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_msgpack_stop, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_msgpack_beforestore, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_msgpack_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_frontend_msgpack_method_entry) {
	PHP_ME(Phalcon_Cache_Frontend_Msgpack, __construct, arginfo_phalcon_cache_frontend_msgpack___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Frontend_Msgpack, getLifetime, arginfo_phalcon_cache_frontend_msgpack_getlifetime, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Msgpack, isBuffering, arginfo_phalcon_cache_frontend_msgpack_isbuffering, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Cache_Frontend_Msgpack, start, arginfo_phalcon_cache_frontend_msgpack_start, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Cache_Frontend_Msgpack, start, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Cache_Frontend_Msgpack, getContent, arginfo_phalcon_cache_frontend_msgpack_getcontent, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Cache_Frontend_Msgpack, stop, arginfo_phalcon_cache_frontend_msgpack_stop, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Cache_Frontend_Msgpack, stop, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Cache_Frontend_Msgpack, beforeStore, arginfo_phalcon_cache_frontend_msgpack_beforestore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Msgpack, afterRetrieve, arginfo_phalcon_cache_frontend_msgpack_afterretrieve, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
