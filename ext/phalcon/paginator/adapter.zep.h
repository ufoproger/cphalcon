
extern zend_class_entry *phalcon_paginator_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter);

PHP_METHOD(Phalcon_Paginator_Adapter, getLimit);
PHP_METHOD(Phalcon_Paginator_Adapter, setCurrentPage);
PHP_METHOD(Phalcon_Paginator_Adapter, setLimit);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_paginator_adapter_getlimit, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_adapter_setcurrentpage, 0, 1, Phalcon\\Paginator\\Adapter, 0)
	ZEND_ARG_TYPE_INFO(0, page, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_adapter_setlimit, 0, 1, Phalcon\\Paginator\\Adapter, 0)
	ZEND_ARG_TYPE_INFO(0, limitRows, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_paginator_adapter_method_entry) {
	PHP_ME(Phalcon_Paginator_Adapter, getLimit, arginfo_phalcon_paginator_adapter_getlimit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter, setCurrentPage, arginfo_phalcon_paginator_adapter_setcurrentpage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter, setLimit, arginfo_phalcon_paginator_adapter_setlimit, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
