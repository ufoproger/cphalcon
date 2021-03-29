
extern zend_class_entry *phalcon_cache_frontend_none_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Frontend_None);

PHP_METHOD(Phalcon_Cache_Frontend_None, getLifetime);
PHP_METHOD(Phalcon_Cache_Frontend_None, isBuffering);
PHP_METHOD(Phalcon_Cache_Frontend_None, start);
PHP_METHOD(Phalcon_Cache_Frontend_None, getContent);
PHP_METHOD(Phalcon_Cache_Frontend_None, stop);
PHP_METHOD(Phalcon_Cache_Frontend_None, beforeStore);
PHP_METHOD(Phalcon_Cache_Frontend_None, afterRetrieve);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_none_getlifetime, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_none_isbuffering, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_none_start, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_none_getcontent, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_none_stop, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_none_beforestore, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_none_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_frontend_none_method_entry) {
	PHP_ME(Phalcon_Cache_Frontend_None, getLifetime, arginfo_phalcon_cache_frontend_none_getlifetime, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_None, isBuffering, arginfo_phalcon_cache_frontend_none_isbuffering, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Cache_Frontend_None, start, arginfo_phalcon_cache_frontend_none_start, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Cache_Frontend_None, start, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Cache_Frontend_None, getContent, arginfo_phalcon_cache_frontend_none_getcontent, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Cache_Frontend_None, getContent, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Cache_Frontend_None, stop, arginfo_phalcon_cache_frontend_none_stop, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Cache_Frontend_None, stop, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Cache_Frontend_None, beforeStore, arginfo_phalcon_cache_frontend_none_beforestore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_None, afterRetrieve, arginfo_phalcon_cache_frontend_none_afterretrieve, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
