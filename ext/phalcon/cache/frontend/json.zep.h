
extern zend_class_entry *phalcon_cache_frontend_json_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Frontend_Json);

PHP_METHOD(Phalcon_Cache_Frontend_Json, __construct);
PHP_METHOD(Phalcon_Cache_Frontend_Json, getLifetime);
PHP_METHOD(Phalcon_Cache_Frontend_Json, isBuffering);
PHP_METHOD(Phalcon_Cache_Frontend_Json, start);
PHP_METHOD(Phalcon_Cache_Frontend_Json, getContent);
PHP_METHOD(Phalcon_Cache_Frontend_Json, stop);
PHP_METHOD(Phalcon_Cache_Frontend_Json, beforeStore);
PHP_METHOD(Phalcon_Cache_Frontend_Json, afterRetrieve);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_json___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, frontendOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_json_getlifetime, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_json_isbuffering, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_json_start, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_json_getcontent, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_json_stop, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_json_beforestore, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_json_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_frontend_json_method_entry) {
	PHP_ME(Phalcon_Cache_Frontend_Json, __construct, arginfo_phalcon_cache_frontend_json___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Frontend_Json, getLifetime, arginfo_phalcon_cache_frontend_json_getlifetime, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Json, isBuffering, arginfo_phalcon_cache_frontend_json_isbuffering, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Cache_Frontend_Json, start, arginfo_phalcon_cache_frontend_json_start, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Cache_Frontend_Json, start, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Cache_Frontend_Json, getContent, arginfo_phalcon_cache_frontend_json_getcontent, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Cache_Frontend_Json, getContent, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Cache_Frontend_Json, stop, arginfo_phalcon_cache_frontend_json_stop, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Json, beforeStore, arginfo_phalcon_cache_frontend_json_beforestore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Json, afterRetrieve, arginfo_phalcon_cache_frontend_json_afterretrieve, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
