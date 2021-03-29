
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * Phalcon\Flash
 *
 * Shows HTML notifications related to different circumstances. Classes can be stylized using CSS
 *
 *<code>
 * $flash->success("The record was successfully deleted");
 * $flash->error("Cannot open the file");
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Flash) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Flash, phalcon, flash, phalcon_flash_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_flash_ce, SL("_cssClasses"), ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalcon_flash_ce, SL("_implicitFlush"), 1, ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalcon_flash_ce, SL("_automaticHtml"), 1, ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_flash_ce, SL("_escaperService"), ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalcon_flash_ce, SL("_autoescape"), 1, ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_flash_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_flash_ce, SL("_messages"), ZEND_ACC_PROTECTED);

	zend_class_implements(phalcon_flash_ce, 1, phalcon_flashinterface_ce);
	zend_class_implements(phalcon_flash_ce, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Flash constructor
 */
PHP_METHOD(Phalcon_Flash, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *cssClasses = NULL, cssClasses_sub, __$null, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cssClasses_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(cssClasses)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &cssClasses);

	if (!cssClasses) {
		cssClasses = &cssClasses_sub;
		ZEPHIR_CPY_WRT(cssClasses, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(cssClasses);
	}


	if (Z_TYPE_P(cssClasses) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 4, 0);
		add_assoc_stringl_ex(&_0$$3, SL("error"), SL("errorMessage"));
		add_assoc_stringl_ex(&_0$$3, SL("notice"), SL("noticeMessage"));
		add_assoc_stringl_ex(&_0$$3, SL("success"), SL("successMessage"));
		add_assoc_stringl_ex(&_0$$3, SL("warning"), SL("warningMessage"));
		ZEPHIR_CPY_WRT(cssClasses, &_0$$3);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("_cssClasses"), cssClasses);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the autoescape mode in generated html
 */
PHP_METHOD(Phalcon_Flash, getAutoescape) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_autoescape");

}

/**
 * Set the autoescape mode in generated html
 */
PHP_METHOD(Phalcon_Flash, setAutoescape) {

	zval *autoescape_param = NULL, __$true, __$false;
	zend_bool autoescape;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(autoescape)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &autoescape_param);

	autoescape = zephir_get_boolval(autoescape_param);


	if (autoescape) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_autoescape"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_autoescape"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Returns the Escaper Service
 */
PHP_METHOD(Phalcon_Flash, getEscaperService) {

	zval escaper, dependencyInjector, _0$$3, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&escaper);
	zephir_read_property(&escaper, this_ptr, ZEND_STRL("_escaperService"), PH_NOISY_CC);
	if (Z_TYPE_P(&escaper) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&dependencyInjector, &_0$$3);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "escaper");
		ZEPHIR_CALL_METHOD(&_0$$3, &dependencyInjector, "getshared", NULL, 0, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&escaper, &_0$$3);
		zephir_update_property_zval(this_ptr, ZEND_STRL("_escaperService"), &escaper);
	}
	RETURN_CCTOR(&escaper);

}

/**
 * Sets the Escaper Service
 */
PHP_METHOD(Phalcon_Flash, setEscaperService) {

	zval *escaperService, escaperService_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaperService_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(escaperService, phalcon_escaperinterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &escaperService);



	zephir_update_property_zval(this_ptr, ZEND_STRL("_escaperService"), escaperService);
	RETURN_THISW();

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Flash, setDI) {

	zval *dependencyInjector, dependencyInjector_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(dependencyInjector, phalcon_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &dependencyInjector);



	zephir_update_property_zval(this_ptr, ZEND_STRL("_dependencyInjector"), dependencyInjector);
	RETURN_THISW();

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Flash, getDI) {

	zval di;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&di);
	zephir_read_property(&di, this_ptr, ZEND_STRL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(&di) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&di, phalcon_di_ce, "getdefault", &_0, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&di);

}

/**
 * Set whether the output must be implicitly flushed to the output or returned as string
 */
PHP_METHOD(Phalcon_Flash, setImplicitFlush) {

	zval *implicitFlush_param = NULL, __$true, __$false;
	zend_bool implicitFlush;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(implicitFlush)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &implicitFlush_param);

	implicitFlush = zephir_get_boolval(implicitFlush_param);


	if (implicitFlush) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_implicitFlush"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_implicitFlush"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Set if the output must be implicitly formatted with HTML
 */
PHP_METHOD(Phalcon_Flash, setAutomaticHtml) {

	zval *automaticHtml_param = NULL, __$true, __$false;
	zend_bool automaticHtml;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(automaticHtml)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &automaticHtml_param);

	automaticHtml = zephir_get_boolval(automaticHtml_param);


	if (automaticHtml) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_automaticHtml"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_automaticHtml"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Set an array with CSS classes to format the messages
 */
PHP_METHOD(Phalcon_Flash, setCssClasses) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *cssClasses_param = NULL;
	zval cssClasses;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cssClasses);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(cssClasses)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cssClasses_param);

	ZEPHIR_OBS_COPY_OR_DUP(&cssClasses, cssClasses_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("_cssClasses"), &cssClasses);
	RETURN_THIS();

}

/**
 * Shows a HTML error message
 *
 *<code>
 * $flash->error("This is an error");
 *</code>
 */
PHP_METHOD(Phalcon_Flash, error) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message, message_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(message)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "error");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, message);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Shows a HTML notice/information message
 *
 *<code>
 * $flash->notice("This is an information");
 *</code>
 */
PHP_METHOD(Phalcon_Flash, notice) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message, message_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(message)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "notice");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, message);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Shows a HTML success message
 *
 *<code>
 * $flash->success("The process was finished successfully");
 *</code>
 */
PHP_METHOD(Phalcon_Flash, success) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message, message_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(message)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "success");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, message);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Shows a HTML warning message
 *
 *<code>
 * $flash->warning("Hey, this is important");
 *</code>
 */
PHP_METHOD(Phalcon_Flash, warning) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message, message_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(message)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "warning");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, message);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Outputs a message formatting it with HTML
 *
 *<code>
 * $flash->outputMessage("error", $message);
 *</code>
 *
 * @param string|array message
 * @return string|void
 */
PHP_METHOD(Phalcon_Flash, outputMessage) {

	zend_bool automaticHtml = 0, implicitFlush = 0, autoEscape = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *message, message_sub, content, cssClasses, classes, typeClasses, eol, msg, htmlMessage, escaper, preparedMsg, _0, _1$$5, *_2$$9, _3$$9;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&cssClasses);
	ZVAL_UNDEF(&classes);
	ZVAL_UNDEF(&typeClasses);
	ZVAL_UNDEF(&eol);
	ZVAL_UNDEF(&msg);
	ZVAL_UNDEF(&htmlMessage);
	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&preparedMsg);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_3$$9);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(type)
		Z_PARAM_ZVAL(message)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &message);

	zephir_get_strval(&type, type_param);


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("_automaticHtml"), PH_NOISY_CC);
	automaticHtml = zephir_get_boolval(&_0);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("_autoescape"), PH_NOISY_CC);
	autoEscape = zephir_get_boolval(&_0);
	if (automaticHtml == 1) {
		ZEPHIR_OBS_VAR(&classes);
		zephir_read_property(&classes, this_ptr, ZEND_STRL("_cssClasses"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(&typeClasses);
		if (zephir_array_isset_fetch(&typeClasses, &classes, &type, 0)) {
			ZEPHIR_INIT_VAR(&cssClasses);
			if (Z_TYPE_P(&typeClasses) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(&_1$$5);
				zephir_fast_join_str(&_1$$5, SL(" "), &typeClasses);
				ZEPHIR_CONCAT_SVS(&cssClasses, " class=\"", &_1$$5, "\"");
			} else {
				ZEPHIR_CONCAT_SVS(&cssClasses, " class=\"", &typeClasses, "\"");
			}
		} else {
			ZEPHIR_INIT_NVAR(&cssClasses);
			ZVAL_STRING(&cssClasses, "");
		}
		ZEPHIR_INIT_VAR(&eol);
		ZEPHIR_GET_CONSTANT(&eol, "PHP_EOL");
	}
	if (autoEscape == 1) {
		ZEPHIR_CALL_METHOD(&escaper, this_ptr, "getescaperservice", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("_implicitFlush"), PH_NOISY_CC);
	implicitFlush = zephir_get_boolval(&_0);
	if (Z_TYPE_P(message) == IS_ARRAY) {
		if (implicitFlush == 0) {
			ZEPHIR_INIT_VAR(&content);
			ZVAL_STRING(&content, "");
		}
		zephir_is_iterable(message, 0, "phalcon/flash.zep", 288);
		if (Z_TYPE_P(message) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(message), _2$$9)
			{
				ZEPHIR_INIT_NVAR(&msg);
				ZVAL_COPY(&msg, _2$$9);
				if (autoEscape == 1) {
					ZEPHIR_CALL_METHOD(&preparedMsg, &escaper, "escapehtml", &_4, 0, &msg);
					zephir_check_call_status();
				} else {
					ZEPHIR_CPY_WRT(&preparedMsg, &msg);
				}
				if (automaticHtml == 1) {
					ZEPHIR_INIT_NVAR(&htmlMessage);
					ZEPHIR_CONCAT_SVSVSV(&htmlMessage, "<div", &cssClasses, ">", &preparedMsg, "</div>", &eol);
				} else {
					ZEPHIR_CPY_WRT(&htmlMessage, &preparedMsg);
				}
				if (implicitFlush == 1) {
					zend_print_zval(&htmlMessage, 0);
				} else {
					zephir_concat_self(&content, &htmlMessage);
					zephir_update_property_array_append(this_ptr, SL("_messages"), &htmlMessage);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, message, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_3$$9, message, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$9)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&msg, message, "current", NULL, 0);
				zephir_check_call_status();
					if (autoEscape == 1) {
						ZEPHIR_CALL_METHOD(&preparedMsg, &escaper, "escapehtml", &_5, 0, &msg);
						zephir_check_call_status();
					} else {
						ZEPHIR_CPY_WRT(&preparedMsg, &msg);
					}
					if (automaticHtml == 1) {
						ZEPHIR_INIT_NVAR(&htmlMessage);
						ZEPHIR_CONCAT_SVSVSV(&htmlMessage, "<div", &cssClasses, ">", &preparedMsg, "</div>", &eol);
					} else {
						ZEPHIR_CPY_WRT(&htmlMessage, &preparedMsg);
					}
					if (implicitFlush == 1) {
						zend_print_zval(&htmlMessage, 0);
					} else {
						zephir_concat_self(&content, &htmlMessage);
						zephir_update_property_array_append(this_ptr, SL("_messages"), &htmlMessage);
					}
				ZEPHIR_CALL_METHOD(NULL, message, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&msg);
		if (implicitFlush == 0) {
			RETURN_CCTOR(&content);
		}
	} else {
		if (autoEscape == 1) {
			ZEPHIR_CALL_METHOD(&preparedMsg, &escaper, "escapehtml", NULL, 0, message);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&preparedMsg, message);
		}
		if (automaticHtml == 1) {
			ZEPHIR_INIT_NVAR(&htmlMessage);
			ZEPHIR_CONCAT_SVSVSV(&htmlMessage, "<div", &cssClasses, ">", &preparedMsg, "</div>", &eol);
		} else {
			ZEPHIR_CPY_WRT(&htmlMessage, &preparedMsg);
		}
		if (implicitFlush == 1) {
			zend_print_zval(&htmlMessage, 0);
		} else {
			zephir_update_property_array_append(this_ptr, SL("_messages"), &htmlMessage);
			RETURN_CCTOR(&htmlMessage);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Clears accumulated messages when implicit flush is disabled
 */
PHP_METHOD(Phalcon_Flash, clear) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_messages"), &_0);
	ZEPHIR_MM_RESTORE();

}

