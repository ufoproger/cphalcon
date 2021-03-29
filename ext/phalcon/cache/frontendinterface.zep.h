
extern zend_class_entry *phalcon_cache_frontendinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_FrontendInterface);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontendinterface_getlifetime, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontendinterface_isbuffering, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontendinterface_start, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontendinterface_getcontent, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontendinterface_stop, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontendinterface_beforestore, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontendinterface_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_frontendinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, getLifetime, arginfo_phalcon_cache_frontendinterface_getlifetime)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, isBuffering, arginfo_phalcon_cache_frontendinterface_isbuffering)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, start, arginfo_phalcon_cache_frontendinterface_start)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, getContent, arginfo_phalcon_cache_frontendinterface_getcontent)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, stop, arginfo_phalcon_cache_frontendinterface_stop)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, beforeStore, arginfo_phalcon_cache_frontendinterface_beforestore)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, afterRetrieve, arginfo_phalcon_cache_frontendinterface_afterretrieve)
	PHP_FE_END
};
