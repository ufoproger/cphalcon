
extern zend_class_entry *phalcon_cache_backend_file_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_File);

PHP_METHOD(Phalcon_Cache_Backend_File, __construct);
PHP_METHOD(Phalcon_Cache_Backend_File, get);
PHP_METHOD(Phalcon_Cache_Backend_File, save);
PHP_METHOD(Phalcon_Cache_Backend_File, delete);
PHP_METHOD(Phalcon_Cache_Backend_File, queryKeys);
PHP_METHOD(Phalcon_Cache_Backend_File, exists);
PHP_METHOD(Phalcon_Cache_Backend_File, increment);
PHP_METHOD(Phalcon_Cache_Backend_File, decrement);
PHP_METHOD(Phalcon_Cache_Backend_File, flush);
PHP_METHOD(Phalcon_Cache_Backend_File, getKey);
PHP_METHOD(Phalcon_Cache_Backend_File, useSafeKey);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, frontend, Phalcon\\Cache\\FrontendInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, keyName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, lifetime, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_file_save, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
	ZEND_ARG_TYPE_INFO(0, stopBuffer, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_file_delete, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_file_querykeys, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_file_exists, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_TYPE_INFO(0, lifetime, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_file_increment, 0, 0, IS_LONG, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_file_decrement, 0, 0, IS_LONG, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_file_flush, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_file_getkey, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cache_backend_file_usesafekey, 0, 1, Phalcon\\Cache\\Backend\\File, 0)
	ZEND_ARG_TYPE_INFO(0, useSafeKey, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_backend_file_method_entry) {
	PHP_ME(Phalcon_Cache_Backend_File, __construct, arginfo_phalcon_cache_backend_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Backend_File, get, arginfo_phalcon_cache_backend_file_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, save, arginfo_phalcon_cache_backend_file_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, delete, arginfo_phalcon_cache_backend_file_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, queryKeys, arginfo_phalcon_cache_backend_file_querykeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, exists, arginfo_phalcon_cache_backend_file_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, increment, arginfo_phalcon_cache_backend_file_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, decrement, arginfo_phalcon_cache_backend_file_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, flush, arginfo_phalcon_cache_backend_file_flush, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, getKey, arginfo_phalcon_cache_backend_file_getkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, useSafeKey, arginfo_phalcon_cache_backend_file_usesafekey, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
