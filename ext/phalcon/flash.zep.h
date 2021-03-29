
extern zend_class_entry *phalcon_flash_ce;

ZEPHIR_INIT_CLASS(Phalcon_Flash);

PHP_METHOD(Phalcon_Flash, __construct);
PHP_METHOD(Phalcon_Flash, getAutoescape);
PHP_METHOD(Phalcon_Flash, setAutoescape);
PHP_METHOD(Phalcon_Flash, getEscaperService);
PHP_METHOD(Phalcon_Flash, setEscaperService);
PHP_METHOD(Phalcon_Flash, setDI);
PHP_METHOD(Phalcon_Flash, getDI);
PHP_METHOD(Phalcon_Flash, setImplicitFlush);
PHP_METHOD(Phalcon_Flash, setAutomaticHtml);
PHP_METHOD(Phalcon_Flash, setCssClasses);
PHP_METHOD(Phalcon_Flash, error);
PHP_METHOD(Phalcon_Flash, notice);
PHP_METHOD(Phalcon_Flash, success);
PHP_METHOD(Phalcon_Flash, warning);
PHP_METHOD(Phalcon_Flash, outputMessage);
PHP_METHOD(Phalcon_Flash, clear);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, cssClasses)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_getautoescape, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_flash_setautoescape, 0, 1, Phalcon\\Flash, 0)
	ZEND_ARG_TYPE_INFO(0, autoescape, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_flash_getescaperservice, 0, 0, Phalcon\\EscaperInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_flash_setescaperservice, 0, 1, Phalcon\\Flash, 0)
	ZEND_ARG_OBJ_INFO(0, escaperService, Phalcon\\EscaperInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_flash_setdi, 0, 1, Phalcon\\Flash, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_flash_getdi, 0, 0, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_flash_setimplicitflush, 0, 1, Phalcon\\FlashInterface, 0)
	ZEND_ARG_TYPE_INFO(0, implicitFlush, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_flash_setautomatichtml, 0, 1, Phalcon\\FlashInterface, 0)
	ZEND_ARG_TYPE_INFO(0, automaticHtml, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_flash_setcssclasses, 0, 1, Phalcon\\FlashInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, cssClasses, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_error, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_notice, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_success, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_warning, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_outputmessage, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_flash_clear, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_flash_method_entry) {
	PHP_ME(Phalcon_Flash, __construct, arginfo_phalcon_flash___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Flash, getAutoescape, arginfo_phalcon_flash_getautoescape, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, setAutoescape, arginfo_phalcon_flash_setautoescape, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, getEscaperService, arginfo_phalcon_flash_getescaperservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, setEscaperService, arginfo_phalcon_flash_setescaperservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, setDI, arginfo_phalcon_flash_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, getDI, arginfo_phalcon_flash_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, setImplicitFlush, arginfo_phalcon_flash_setimplicitflush, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, setAutomaticHtml, arginfo_phalcon_flash_setautomatichtml, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, setCssClasses, arginfo_phalcon_flash_setcssclasses, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, error, arginfo_phalcon_flash_error, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, notice, arginfo_phalcon_flash_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, success, arginfo_phalcon_flash_success, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, warning, arginfo_phalcon_flash_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, outputMessage, arginfo_phalcon_flash_outputmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, clear, arginfo_phalcon_flash_clear, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
