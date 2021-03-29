
extern zend_class_entry *phalcon_assets_filters_jsmin_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_Filters_Jsmin);

PHP_METHOD(Phalcon_Assets_Filters_Jsmin, filter);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_filters_jsmin_filter, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_filters_jsmin_method_entry) {
	PHP_ME(Phalcon_Assets_Filters_Jsmin, filter, arginfo_phalcon_assets_filters_jsmin_filter, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
