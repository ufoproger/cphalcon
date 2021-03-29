
extern zend_class_entry *phalcon_cache_frontend_output_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Frontend_Output);

PHP_METHOD(Phalcon_Cache_Frontend_Output, __construct);
PHP_METHOD(Phalcon_Cache_Frontend_Output, getLifetime);
PHP_METHOD(Phalcon_Cache_Frontend_Output, isBuffering);
PHP_METHOD(Phalcon_Cache_Frontend_Output, start);
PHP_METHOD(Phalcon_Cache_Frontend_Output, getContent);
PHP_METHOD(Phalcon_Cache_Frontend_Output, stop);
PHP_METHOD(Phalcon_Cache_Frontend_Output, beforeStore);
PHP_METHOD(Phalcon_Cache_Frontend_Output, afterRetrieve);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_output___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, frontendOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_output_getlifetime, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_output_isbuffering, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_output_start, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_output_getcontent, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_output_stop, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_output_beforestore, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_output_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_frontend_output_method_entry) {
	PHP_ME(Phalcon_Cache_Frontend_Output, __construct, arginfo_phalcon_cache_frontend_output___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Frontend_Output, getLifetime, arginfo_phalcon_cache_frontend_output_getlifetime, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Output, isBuffering, arginfo_phalcon_cache_frontend_output_isbuffering, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Output, start, arginfo_phalcon_cache_frontend_output_start, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Cache_Frontend_Output, getContent, arginfo_phalcon_cache_frontend_output_getcontent, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Cache_Frontend_Output, getContent, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Cache_Frontend_Output, stop, arginfo_phalcon_cache_frontend_output_stop, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Output, beforeStore, arginfo_phalcon_cache_frontend_output_beforestore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Output, afterRetrieve, arginfo_phalcon_cache_frontend_output_afterretrieve, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
