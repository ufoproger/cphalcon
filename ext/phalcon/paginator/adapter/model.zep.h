
extern zend_class_entry *phalcon_paginator_adapter_model_ce;

ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_Model);

PHP_METHOD(Phalcon_Paginator_Adapter_Model, __construct);
PHP_METHOD(Phalcon_Paginator_Adapter_Model, getPaginate);
PHP_METHOD(Phalcon_Paginator_Adapter_Model, paginate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_model___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_adapter_model_getpaginate, 0, 0, stdClass, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_paginator_adapter_model_paginate, 0, 0, stdClass, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_paginator_adapter_model_method_entry) {
	PHP_ME(Phalcon_Paginator_Adapter_Model, __construct, arginfo_phalcon_paginator_adapter_model___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Paginator_Adapter_Model, getPaginate, arginfo_phalcon_paginator_adapter_model_getpaginate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_Model, paginate, arginfo_phalcon_paginator_adapter_model_paginate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
