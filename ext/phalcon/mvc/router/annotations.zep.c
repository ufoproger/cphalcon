
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * Phalcon\Mvc\Router\Annotations
 *
 * A router that reads routes annotations from classes/resources
 *
 * <code>
 * use Phalcon\Mvc\Router\Annotations;
 *
 * $di->setShared(
 *     "router",
 *     function() {
 *         // Use the annotations router
 *         $router = new Annotations(false);
 *
 *         // This will do the same as above but only if the handled uri starts with /robots
 *         $router->addResource("Robots", "/robots");
 *
 *         return $router;
 *     }
 * );
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_Annotations) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Router, Annotations, phalcon, mvc_router_annotations, phalcon_mvc_router_ce, phalcon_mvc_router_annotations_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_router_annotations_ce, SL("_handlers"), ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalcon_mvc_router_annotations_ce, SL("_controllerSuffix"), "Controller", ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalcon_mvc_router_annotations_ce, SL("_actionSuffix"), "Action", ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_router_annotations_ce, SL("_routePrefix"), ZEND_ACC_PROTECTED);

	phalcon_mvc_router_annotations_ce->create_object = zephir_init_properties_Phalcon_Mvc_Router_Annotations;

	return SUCCESS;

}

/**
 * Adds a resource to the annotations handler
 * A resource is a class that contains routing annotations
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, addResource) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handler_param = NULL, *prefix_param = NULL;
	zval handler, prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(handler)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(prefix)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &handler_param, &prefix_param);

	if (UNEXPECTED(Z_TYPE_P(handler_param) != IS_STRING && Z_TYPE_P(handler_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'handler' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(handler_param) == IS_STRING)) {
		zephir_get_strval(&handler, handler_param);
	} else {
		ZEPHIR_INIT_VAR(&handler);
		ZVAL_EMPTY_STRING(&handler);
	}
	if (!prefix_param) {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_STRING(&prefix, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(&prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_EMPTY_STRING(&prefix);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, &prefix);
	zephir_array_fast_append(&_0, &handler);
	zephir_update_property_array_append(this_ptr, SL("_handlers"), &_0);
	RETURN_THIS();

}

/**
 * Adds a resource to the annotations handler
 * A resource is a class that contains routing annotations
 * The class is located in a module
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, addModuleResource) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *module_param = NULL, *handler_param = NULL, *prefix_param = NULL;
	zval module, handler, prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(module)
		Z_PARAM_STR(handler)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(prefix)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &module_param, &handler_param, &prefix_param);

	if (UNEXPECTED(Z_TYPE_P(module_param) != IS_STRING && Z_TYPE_P(module_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'module' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(module_param) == IS_STRING)) {
		zephir_get_strval(&module, module_param);
	} else {
		ZEPHIR_INIT_VAR(&module);
		ZVAL_EMPTY_STRING(&module);
	}
	if (UNEXPECTED(Z_TYPE_P(handler_param) != IS_STRING && Z_TYPE_P(handler_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'handler' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(handler_param) == IS_STRING)) {
		zephir_get_strval(&handler, handler_param);
	} else {
		ZEPHIR_INIT_VAR(&handler);
		ZVAL_EMPTY_STRING(&handler);
	}
	if (!prefix_param) {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_STRING(&prefix, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(&prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_EMPTY_STRING(&prefix);
	}
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	zephir_array_fast_append(&_0, &prefix);
	zephir_array_fast_append(&_0, &handler);
	zephir_array_fast_append(&_0, &module);
	zephir_update_property_array_append(this_ptr, SL("_handlers"), &_0);
	RETURN_THIS();

}

/**
 * Produce the routing parameters from the rewrite information
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, handle) {

	zend_string *_13$$17, *_29$$37;
	zend_ulong _12$$17, _28$$37;
	zend_bool _4$$6, _21$$26;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL, *_17 = NULL, *_23 = NULL, *_36 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, __$null, realUri, annotationsService, handlers, controllerSuffix, scope, prefix, dependencyInjector, handler, controllerName, lowerControllerName, namespaceName, moduleName, sufixed, handlerAnnotations, classAnnotations, annotations, annotation, methodAnnotations, method, collection, _0, _1, *_2, _3, _5$$11, *_7$$14, _8$$14, *_10$$17, _11$$17, _14$$19, *_15$$19, _16$$19, _18$$23, *_19$$23, _20$$23, _22$$31, *_24$$34, _25$$34, *_26$$37, _27$$37, _30$$39, *_31$$39, _32$$39, _33$$43, *_34$$43, _35$$43;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&realUri);
	ZVAL_UNDEF(&annotationsService);
	ZVAL_UNDEF(&handlers);
	ZVAL_UNDEF(&controllerSuffix);
	ZVAL_UNDEF(&scope);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&controllerName);
	ZVAL_UNDEF(&lowerControllerName);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&moduleName);
	ZVAL_UNDEF(&sufixed);
	ZVAL_UNDEF(&handlerAnnotations);
	ZVAL_UNDEF(&classAnnotations);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&annotation);
	ZVAL_UNDEF(&methodAnnotations);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$11);
	ZVAL_UNDEF(&_8$$14);
	ZVAL_UNDEF(&_11$$17);
	ZVAL_UNDEF(&_14$$19);
	ZVAL_UNDEF(&_16$$19);
	ZVAL_UNDEF(&_18$$23);
	ZVAL_UNDEF(&_20$$23);
	ZVAL_UNDEF(&_22$$31);
	ZVAL_UNDEF(&_25$$34);
	ZVAL_UNDEF(&_27$$37);
	ZVAL_UNDEF(&_30$$39);
	ZVAL_UNDEF(&_32$$39);
	ZVAL_UNDEF(&_33$$43);
	ZVAL_UNDEF(&_35$$43);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(uri)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri_param);

	if (!uri_param) {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_STRING(&uri, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(&uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_EMPTY_STRING(&uri);
	}
	}


	if (!(!(Z_TYPE_P(&uri) == IS_UNDEF) && Z_STRLEN_P(&uri))) {
		ZEPHIR_CALL_METHOD(&realUri, this_ptr, "getrewriteuri", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&realUri, &uri);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dependencyInjector, &_0);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_router_exception_ce, "A dependency injection container is required to access the 'annotations' service", "phalcon/mvc/router/annotations.zep", 104);
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "annotations");
	ZEPHIR_CALL_METHOD(&annotationsService, &dependencyInjector, "getshared", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&handlers);
	zephir_read_property(&handlers, this_ptr, ZEND_STRL("_handlers"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&controllerSuffix);
	zephir_read_property(&controllerSuffix, this_ptr, ZEND_STRL("_controllerSuffix"), PH_NOISY_CC);
	zephir_is_iterable(&handlers, 0, "phalcon/mvc/router/annotations.zep", 205);
	if (Z_TYPE_P(&handlers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&handlers), _2)
		{
			ZEPHIR_INIT_NVAR(&scope);
			ZVAL_COPY(&scope, _2);
			if (Z_TYPE_P(&scope) != IS_ARRAY) {
				continue;
			}
			ZEPHIR_OBS_NVAR(&prefix);
			zephir_array_fetch_long(&prefix, &scope, 0, PH_NOISY, "phalcon/mvc/router/annotations.zep", 122);
			_4$$6 = !(ZEPHIR_IS_EMPTY(&prefix));
			if (_4$$6) {
				_4$$6 = !(zephir_start_with(&realUri, &prefix, NULL));
			}
			if (_4$$6) {
				continue;
			}
			ZEPHIR_OBS_NVAR(&handler);
			zephir_array_fetch_long(&handler, &scope, 1, PH_NOISY, "phalcon/mvc/router/annotations.zep", 131);
			if (zephir_memnstr_str(&handler, SL("\\"), "phalcon/mvc/router/annotations.zep", 133)) {
				ZEPHIR_INIT_NVAR(&controllerName);
				zephir_get_class_ns(&controllerName, &handler, 0);
				ZEPHIR_INIT_NVAR(&namespaceName);
				zephir_get_ns_class(&namespaceName, &handler, 0);
			} else {
				ZEPHIR_CPY_WRT(&controllerName, &handler);
				ZEPHIR_OBS_NVAR(&namespaceName);
				zephir_fetch_property(&namespaceName, this_ptr, SL("_defaultNamespace"), PH_SILENT_CC);
			}
			zephir_update_property_zval(this_ptr, ZEND_STRL("_routePrefix"), &__$null);
			ZEPHIR_OBS_NVAR(&moduleName);
			zephir_array_isset_long_fetch(&moduleName, &scope, 2, 0);
			ZEPHIR_INIT_NVAR(&sufixed);
			ZEPHIR_CONCAT_VV(&sufixed, &controllerName, &controllerSuffix);
			if (Z_TYPE_P(&namespaceName) != IS_NULL) {
				ZEPHIR_INIT_NVAR(&_5$$11);
				ZEPHIR_CONCAT_VSV(&_5$$11, &namespaceName, "\\", &sufixed);
				ZEPHIR_CPY_WRT(&sufixed, &_5$$11);
			}
			ZEPHIR_CALL_METHOD(&handlerAnnotations, &annotationsService, "get", &_6, 0, &sufixed);
			zephir_check_call_status();
			if (Z_TYPE_P(&handlerAnnotations) != IS_OBJECT) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&classAnnotations, &handlerAnnotations, "getclassannotations", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&classAnnotations) == IS_OBJECT) {
				ZEPHIR_CALL_METHOD(&annotations, &classAnnotations, "getannotations", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&annotations) == IS_ARRAY) {
					zephir_is_iterable(&annotations, 0, "phalcon/mvc/router/annotations.zep", 182);
					if (Z_TYPE_P(&annotations) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&annotations), _7$$14)
						{
							ZEPHIR_INIT_NVAR(&annotation);
							ZVAL_COPY(&annotation, _7$$14);
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "processcontrollerannotation", &_9, 0, &controllerName, &annotation);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &annotations, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_8$$14, &annotations, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_8$$14)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&annotation, &annotations, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "processcontrollerannotation", &_9, 0, &controllerName, &annotation);
								zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &annotations, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&annotation);
				}
			}
			ZEPHIR_CALL_METHOD(&methodAnnotations, &handlerAnnotations, "getmethodsannotations", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&methodAnnotations) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&lowerControllerName);
				zephir_uncamelize(&lowerControllerName, &controllerName, NULL  );
				zephir_is_iterable(&methodAnnotations, 0, "phalcon/mvc/router/annotations.zep", 199);
				if (Z_TYPE_P(&methodAnnotations) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&methodAnnotations), _12$$17, _13$$17, _10$$17)
					{
						ZEPHIR_INIT_NVAR(&method);
						if (_13$$17 != NULL) { 
							ZVAL_STR_COPY(&method, _13$$17);
						} else {
							ZVAL_LONG(&method, _12$$17);
						}
						ZEPHIR_INIT_NVAR(&collection);
						ZVAL_COPY(&collection, _10$$17);
						if (Z_TYPE_P(&collection) == IS_OBJECT) {
							ZEPHIR_CALL_METHOD(&_14$$19, &collection, "getannotations", NULL, 0);
							zephir_check_call_status();
							zephir_is_iterable(&_14$$19, 0, "phalcon/mvc/router/annotations.zep", 197);
							if (Z_TYPE_P(&_14$$19) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_14$$19), _15$$19)
								{
									ZEPHIR_INIT_NVAR(&annotation);
									ZVAL_COPY(&annotation, _15$$19);
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_17, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
									zephir_check_call_status();
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &_14$$19, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_16$$19, &_14$$19, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_16$$19)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&annotation, &_14$$19, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_17, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
										zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, &_14$$19, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&annotation);
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &methodAnnotations, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_11$$17, &methodAnnotations, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_11$$17)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&method, &methodAnnotations, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&collection, &methodAnnotations, "current", NULL, 0);
						zephir_check_call_status();
							if (Z_TYPE_P(&collection) == IS_OBJECT) {
								ZEPHIR_CALL_METHOD(&_18$$23, &collection, "getannotations", NULL, 0);
								zephir_check_call_status();
								zephir_is_iterable(&_18$$23, 0, "phalcon/mvc/router/annotations.zep", 197);
								if (Z_TYPE_P(&_18$$23) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_18$$23), _19$$23)
									{
										ZEPHIR_INIT_NVAR(&annotation);
										ZVAL_COPY(&annotation, _19$$23);
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_17, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
										zephir_check_call_status();
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &_18$$23, "rewind", NULL, 0);
									zephir_check_call_status();
									while (1) {
										ZEPHIR_CALL_METHOD(&_20$$23, &_18$$23, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_20$$23)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&annotation, &_18$$23, "current", NULL, 0);
										zephir_check_call_status();
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_17, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
											zephir_check_call_status();
										ZEPHIR_CALL_METHOD(NULL, &_18$$23, "next", NULL, 0);
										zephir_check_call_status();
									}
								}
								ZEPHIR_INIT_NVAR(&annotation);
							}
						ZEPHIR_CALL_METHOD(NULL, &methodAnnotations, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&collection);
				ZEPHIR_INIT_NVAR(&method);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &handlers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &handlers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&scope, &handlers, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&scope) != IS_ARRAY) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&prefix);
				zephir_array_fetch_long(&prefix, &scope, 0, PH_NOISY, "phalcon/mvc/router/annotations.zep", 122);
				_21$$26 = !(ZEPHIR_IS_EMPTY(&prefix));
				if (_21$$26) {
					_21$$26 = !(zephir_start_with(&realUri, &prefix, NULL));
				}
				if (_21$$26) {
					continue;
				}
				ZEPHIR_OBS_NVAR(&handler);
				zephir_array_fetch_long(&handler, &scope, 1, PH_NOISY, "phalcon/mvc/router/annotations.zep", 131);
				if (zephir_memnstr_str(&handler, SL("\\"), "phalcon/mvc/router/annotations.zep", 133)) {
					ZEPHIR_INIT_NVAR(&controllerName);
					zephir_get_class_ns(&controllerName, &handler, 0);
					ZEPHIR_INIT_NVAR(&namespaceName);
					zephir_get_ns_class(&namespaceName, &handler, 0);
				} else {
					ZEPHIR_CPY_WRT(&controllerName, &handler);
					ZEPHIR_OBS_NVAR(&namespaceName);
					zephir_fetch_property(&namespaceName, this_ptr, SL("_defaultNamespace"), PH_SILENT_CC);
				}
				zephir_update_property_zval(this_ptr, ZEND_STRL("_routePrefix"), &__$null);
				ZEPHIR_OBS_NVAR(&moduleName);
				zephir_array_isset_long_fetch(&moduleName, &scope, 2, 0);
				ZEPHIR_INIT_NVAR(&sufixed);
				ZEPHIR_CONCAT_VV(&sufixed, &controllerName, &controllerSuffix);
				if (Z_TYPE_P(&namespaceName) != IS_NULL) {
					ZEPHIR_INIT_NVAR(&_22$$31);
					ZEPHIR_CONCAT_VSV(&_22$$31, &namespaceName, "\\", &sufixed);
					ZEPHIR_CPY_WRT(&sufixed, &_22$$31);
				}
				ZEPHIR_CALL_METHOD(&handlerAnnotations, &annotationsService, "get", &_23, 0, &sufixed);
				zephir_check_call_status();
				if (Z_TYPE_P(&handlerAnnotations) != IS_OBJECT) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&classAnnotations, &handlerAnnotations, "getclassannotations", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&classAnnotations) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&annotations, &classAnnotations, "getannotations", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&annotations) == IS_ARRAY) {
						zephir_is_iterable(&annotations, 0, "phalcon/mvc/router/annotations.zep", 182);
						if (Z_TYPE_P(&annotations) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&annotations), _24$$34)
							{
								ZEPHIR_INIT_NVAR(&annotation);
								ZVAL_COPY(&annotation, _24$$34);
								ZEPHIR_CALL_METHOD(NULL, this_ptr, "processcontrollerannotation", &_9, 0, &controllerName, &annotation);
								zephir_check_call_status();
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &annotations, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_25$$34, &annotations, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_25$$34)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&annotation, &annotations, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, this_ptr, "processcontrollerannotation", &_9, 0, &controllerName, &annotation);
									zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &annotations, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&annotation);
					}
				}
				ZEPHIR_CALL_METHOD(&methodAnnotations, &handlerAnnotations, "getmethodsannotations", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&methodAnnotations) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&lowerControllerName);
					zephir_uncamelize(&lowerControllerName, &controllerName, NULL  );
					zephir_is_iterable(&methodAnnotations, 0, "phalcon/mvc/router/annotations.zep", 199);
					if (Z_TYPE_P(&methodAnnotations) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&methodAnnotations), _28$$37, _29$$37, _26$$37)
						{
							ZEPHIR_INIT_NVAR(&method);
							if (_29$$37 != NULL) { 
								ZVAL_STR_COPY(&method, _29$$37);
							} else {
								ZVAL_LONG(&method, _28$$37);
							}
							ZEPHIR_INIT_NVAR(&collection);
							ZVAL_COPY(&collection, _26$$37);
							if (Z_TYPE_P(&collection) == IS_OBJECT) {
								ZEPHIR_CALL_METHOD(&_30$$39, &collection, "getannotations", NULL, 0);
								zephir_check_call_status();
								zephir_is_iterable(&_30$$39, 0, "phalcon/mvc/router/annotations.zep", 197);
								if (Z_TYPE_P(&_30$$39) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_30$$39), _31$$39)
									{
										ZEPHIR_INIT_NVAR(&annotation);
										ZVAL_COPY(&annotation, _31$$39);
										ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_17, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
										zephir_check_call_status();
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &_30$$39, "rewind", NULL, 0);
									zephir_check_call_status();
									while (1) {
										ZEPHIR_CALL_METHOD(&_32$$39, &_30$$39, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_32$$39)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&annotation, &_30$$39, "current", NULL, 0);
										zephir_check_call_status();
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_17, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
											zephir_check_call_status();
										ZEPHIR_CALL_METHOD(NULL, &_30$$39, "next", NULL, 0);
										zephir_check_call_status();
									}
								}
								ZEPHIR_INIT_NVAR(&annotation);
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &methodAnnotations, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_27$$37, &methodAnnotations, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_27$$37)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&method, &methodAnnotations, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&collection, &methodAnnotations, "current", NULL, 0);
							zephir_check_call_status();
								if (Z_TYPE_P(&collection) == IS_OBJECT) {
									ZEPHIR_CALL_METHOD(&_33$$43, &collection, "getannotations", NULL, 0);
									zephir_check_call_status();
									zephir_is_iterable(&_33$$43, 0, "phalcon/mvc/router/annotations.zep", 197);
									if (Z_TYPE_P(&_33$$43) == IS_ARRAY) {
										ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_33$$43), _34$$43)
										{
											ZEPHIR_INIT_NVAR(&annotation);
											ZVAL_COPY(&annotation, _34$$43);
											ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_17, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
											zephir_check_call_status();
										} ZEND_HASH_FOREACH_END();
									} else {
										ZEPHIR_CALL_METHOD(NULL, &_33$$43, "rewind", NULL, 0);
										zephir_check_call_status();
										while (1) {
											ZEPHIR_CALL_METHOD(&_35$$43, &_33$$43, "valid", NULL, 0);
											zephir_check_call_status();
											if (!zend_is_true(&_35$$43)) {
												break;
											}
											ZEPHIR_CALL_METHOD(&annotation, &_33$$43, "current", NULL, 0);
											zephir_check_call_status();
												ZEPHIR_CALL_METHOD(NULL, this_ptr, "processactionannotation", &_17, 0, &moduleName, &namespaceName, &lowerControllerName, &method, &annotation);
												zephir_check_call_status();
											ZEPHIR_CALL_METHOD(NULL, &_33$$43, "next", NULL, 0);
											zephir_check_call_status();
										}
									}
									ZEPHIR_INIT_NVAR(&annotation);
								}
							ZEPHIR_CALL_METHOD(NULL, &methodAnnotations, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&collection);
					ZEPHIR_INIT_NVAR(&method);
				}
			ZEPHIR_CALL_METHOD(NULL, &handlers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&scope);
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_router_annotations_ce, getThis(), "handle", &_36, 0, &realUri);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks for annotations in the controller docblock
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, processControllerAnnotation) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *handler_param = NULL, *annotation, annotation_sub, _0, _1$$3, _2$$3;
	zval handler;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&annotation_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(handler)
		Z_PARAM_OBJECT_OF_CLASS(annotation, phalcon_annotations_annotation_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &handler_param, &annotation);

	if (UNEXPECTED(Z_TYPE_P(handler_param) != IS_STRING && Z_TYPE_P(handler_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'handler' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(handler_param) == IS_STRING)) {
		zephir_get_strval(&handler, handler_param);
	} else {
		ZEPHIR_INIT_VAR(&handler);
		ZVAL_EMPTY_STRING(&handler);
	}


	ZEPHIR_CALL_METHOD(&_0, annotation, "getname", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(&_0, "RoutePrefix")) {
		ZVAL_LONG(&_2$$3, 0);
		ZEPHIR_CALL_METHOD(&_1$$3, annotation, "getargument", NULL, 0, &_2$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("_routePrefix"), &_1$$3);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks for annotations in the public methods of the controller
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, processActionAnnotation) {

	zend_string *_10$$23, *_16$$26;
	zend_ulong _9$$23, _15$$26;
	zend_bool isRoute = 0, _19$$10, _6$$21;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_12 = NULL, *_17 = NULL, *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *module_param = NULL, *namespaceName_param = NULL, *controller_param = NULL, *action_param = NULL, *annotation, annotation_sub, name, actionName, routePrefix, paths, value, uri, route, methods, converts, param, convert, conversorParam, routeName, beforeMatch, _0$$10, _1$$10, _2$$10, _3$$10, _4$$10, _5$$21, *_7$$23, _8$$23, *_13$$26, _14$$26;
	zval module, namespaceName, controller, action;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&namespaceName);
	ZVAL_UNDEF(&controller);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&annotation_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&routePrefix);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&converts);
	ZVAL_UNDEF(&param);
	ZVAL_UNDEF(&convert);
	ZVAL_UNDEF(&conversorParam);
	ZVAL_UNDEF(&routeName);
	ZVAL_UNDEF(&beforeMatch);
	ZVAL_UNDEF(&_0$$10);
	ZVAL_UNDEF(&_1$$10);
	ZVAL_UNDEF(&_2$$10);
	ZVAL_UNDEF(&_3$$10);
	ZVAL_UNDEF(&_4$$10);
	ZVAL_UNDEF(&_5$$21);
	ZVAL_UNDEF(&_8$$23);
	ZVAL_UNDEF(&_14$$26);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_STR(module)
		Z_PARAM_STR(namespaceName)
		Z_PARAM_STR(controller)
		Z_PARAM_STR(action)
		Z_PARAM_OBJECT_OF_CLASS(annotation, phalcon_annotations_annotation_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &module_param, &namespaceName_param, &controller_param, &action_param, &annotation);

	if (UNEXPECTED(Z_TYPE_P(module_param) != IS_STRING && Z_TYPE_P(module_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'module' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(module_param) == IS_STRING)) {
		zephir_get_strval(&module, module_param);
	} else {
		ZEPHIR_INIT_VAR(&module);
		ZVAL_EMPTY_STRING(&module);
	}
	if (UNEXPECTED(Z_TYPE_P(namespaceName_param) != IS_STRING && Z_TYPE_P(namespaceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'namespaceName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(namespaceName_param) == IS_STRING)) {
		zephir_get_strval(&namespaceName, namespaceName_param);
	} else {
		ZEPHIR_INIT_VAR(&namespaceName);
		ZVAL_EMPTY_STRING(&namespaceName);
	}
	if (UNEXPECTED(Z_TYPE_P(controller_param) != IS_STRING && Z_TYPE_P(controller_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controller' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controller_param) == IS_STRING)) {
		zephir_get_strval(&controller, controller_param);
	} else {
		ZEPHIR_INIT_VAR(&controller);
		ZVAL_EMPTY_STRING(&controller);
	}
	if (UNEXPECTED(Z_TYPE_P(action_param) != IS_STRING && Z_TYPE_P(action_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'action' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(action_param) == IS_STRING)) {
		zephir_get_strval(&action, action_param);
	} else {
		ZEPHIR_INIT_VAR(&action);
		ZVAL_EMPTY_STRING(&action);
	}


	isRoute = 0;
	ZEPHIR_INIT_VAR(&methods);
	ZVAL_NULL(&methods);
	ZEPHIR_CALL_METHOD(&name, annotation, "getname", NULL, 0);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_STRING(&name, "Route")) {
			isRoute = 1;
			break;
		}
		if (ZEPHIR_IS_STRING(&name, "Get")) {
			isRoute = 1;
			ZEPHIR_INIT_NVAR(&methods);
			ZVAL_STRING(&methods, "GET");
			break;
		}
		if (ZEPHIR_IS_STRING(&name, "Post")) {
			isRoute = 1;
			ZEPHIR_INIT_NVAR(&methods);
			ZVAL_STRING(&methods, "POST");
			break;
		}
		if (ZEPHIR_IS_STRING(&name, "Put")) {
			isRoute = 1;
			ZEPHIR_INIT_NVAR(&methods);
			ZVAL_STRING(&methods, "PUT");
			break;
		}
		if (ZEPHIR_IS_STRING(&name, "Patch")) {
			isRoute = 1;
			ZEPHIR_INIT_NVAR(&methods);
			ZVAL_STRING(&methods, "PATCH");
			break;
		}
		if (ZEPHIR_IS_STRING(&name, "Delete")) {
			isRoute = 1;
			ZEPHIR_INIT_NVAR(&methods);
			ZVAL_STRING(&methods, "DELETE");
			break;
		}
		if (ZEPHIR_IS_STRING(&name, "Options")) {
			isRoute = 1;
			ZEPHIR_INIT_NVAR(&methods);
			ZVAL_STRING(&methods, "OPTIONS");
			break;
		}
	} while(0);

	if (isRoute == 1) {
		ZEPHIR_INIT_VAR(&_0$$10);
		zephir_read_property(&_1$$10, this_ptr, ZEND_STRL("_actionSuffix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$10);
		ZVAL_STRING(&_2$$10, "");
		zephir_fast_str_replace(&_0$$10, &_1$$10, &_2$$10, &action);
		ZEPHIR_INIT_VAR(&actionName);
		zephir_fast_strtolower(&actionName, &_0$$10);
		ZEPHIR_OBS_VAR(&routePrefix);
		zephir_read_property(&routePrefix, this_ptr, ZEND_STRL("_routePrefix"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(&_3$$10);
		ZVAL_STRING(&_3$$10, "paths");
		ZEPHIR_CALL_METHOD(&paths, annotation, "getnamedargument", NULL, 0, &_3$$10);
		zephir_check_call_status();
		if (Z_TYPE_P(&paths) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&paths);
			array_init(&paths);
		}
		if (!(ZEPHIR_IS_EMPTY(&module))) {
			zephir_array_update_string(&paths, SL("module"), &module, PH_COPY | PH_SEPARATE);
		}
		if (!(ZEPHIR_IS_EMPTY(&namespaceName))) {
			zephir_array_update_string(&paths, SL("namespace"), &namespaceName, PH_COPY | PH_SEPARATE);
		}
		zephir_array_update_string(&paths, SL("controller"), &controller, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&paths, SL("action"), &actionName, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_4$$10, 0);
		ZEPHIR_CALL_METHOD(&value, annotation, "getargument", NULL, 0, &_4$$10);
		zephir_check_call_status();
		if (Z_TYPE_P(&value) != IS_NULL) {
			if (!ZEPHIR_IS_STRING(&value, "/")) {
				ZEPHIR_INIT_VAR(&uri);
				ZEPHIR_CONCAT_VV(&uri, &routePrefix, &value);
			} else {
				if (Z_TYPE_P(&routePrefix) != IS_NULL) {
					ZEPHIR_CPY_WRT(&uri, &routePrefix);
				} else {
					ZEPHIR_CPY_WRT(&uri, &value);
				}
			}
		} else {
			ZEPHIR_INIT_NVAR(&uri);
			ZEPHIR_CONCAT_VV(&uri, &routePrefix, &actionName);
		}
		ZEPHIR_CALL_METHOD(&route, this_ptr, "add", NULL, 0, &uri, &paths);
		zephir_check_call_status();
		if (Z_TYPE_P(&methods) != IS_NULL) {
			ZEPHIR_CALL_METHOD(NULL, &route, "via", NULL, 0, &methods);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_5$$21);
			ZVAL_STRING(&_5$$21, "methods");
			ZEPHIR_CALL_METHOD(&methods, annotation, "getnamedargument", NULL, 0, &_5$$21);
			zephir_check_call_status();
			_6$$21 = Z_TYPE_P(&methods) == IS_ARRAY;
			if (!(_6$$21)) {
				_6$$21 = Z_TYPE_P(&methods) == IS_STRING;
			}
			if (_6$$21) {
				ZEPHIR_CALL_METHOD(NULL, &route, "via", NULL, 0, &methods);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&_3$$10);
		ZVAL_STRING(&_3$$10, "converts");
		ZEPHIR_CALL_METHOD(&converts, annotation, "getnamedargument", NULL, 0, &_3$$10);
		zephir_check_call_status();
		if (Z_TYPE_P(&converts) == IS_ARRAY) {
			zephir_is_iterable(&converts, 0, "phalcon/mvc/router/annotations.zep", 343);
			if (Z_TYPE_P(&converts) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&converts), _9$$23, _10$$23, _7$$23)
				{
					ZEPHIR_INIT_NVAR(&param);
					if (_10$$23 != NULL) { 
						ZVAL_STR_COPY(&param, _10$$23);
					} else {
						ZVAL_LONG(&param, _9$$23);
					}
					ZEPHIR_INIT_NVAR(&convert);
					ZVAL_COPY(&convert, _7$$23);
					ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_11, 0, &param, &convert);
					zephir_check_call_status();
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &converts, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_8$$23, &converts, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_8$$23)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&param, &converts, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&convert, &converts, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_12, 0, &param, &convert);
						zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &converts, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&convert);
			ZEPHIR_INIT_NVAR(&param);
		}
		ZEPHIR_INIT_NVAR(&_3$$10);
		ZVAL_STRING(&_3$$10, "conversors");
		ZEPHIR_CALL_METHOD(&converts, annotation, "getnamedargument", NULL, 0, &_3$$10);
		zephir_check_call_status();
		if (Z_TYPE_P(&converts) == IS_ARRAY) {
			zephir_is_iterable(&converts, 0, "phalcon/mvc/router/annotations.zep", 353);
			if (Z_TYPE_P(&converts) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&converts), _15$$26, _16$$26, _13$$26)
				{
					ZEPHIR_INIT_NVAR(&conversorParam);
					if (_16$$26 != NULL) { 
						ZVAL_STR_COPY(&conversorParam, _16$$26);
					} else {
						ZVAL_LONG(&conversorParam, _15$$26);
					}
					ZEPHIR_INIT_NVAR(&convert);
					ZVAL_COPY(&convert, _13$$26);
					ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_17, 0, &conversorParam, &convert);
					zephir_check_call_status();
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &converts, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_14$$26, &converts, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_14$$26)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&conversorParam, &converts, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&convert, &converts, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &route, "convert", &_18, 0, &conversorParam, &convert);
						zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &converts, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&convert);
			ZEPHIR_INIT_NVAR(&conversorParam);
		}
		ZEPHIR_INIT_NVAR(&_3$$10);
		ZVAL_STRING(&_3$$10, "beforeMatch");
		ZEPHIR_CALL_METHOD(&beforeMatch, annotation, "getnamedargument", NULL, 0, &_3$$10);
		zephir_check_call_status();
		_19$$10 = Z_TYPE_P(&beforeMatch) == IS_ARRAY;
		if (!(_19$$10)) {
			_19$$10 = Z_TYPE_P(&beforeMatch) == IS_STRING;
		}
		if (_19$$10) {
			ZEPHIR_CALL_METHOD(NULL, &route, "beforematch", NULL, 0, &beforeMatch);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_NVAR(&_3$$10);
		ZVAL_STRING(&_3$$10, "name");
		ZEPHIR_CALL_METHOD(&routeName, annotation, "getnamedargument", NULL, 0, &_3$$10);
		zephir_check_call_status();
		if (Z_TYPE_P(&routeName) == IS_STRING) {
			ZEPHIR_CALL_METHOD(NULL, &route, "setname", NULL, 0, &routeName);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Changes the controller class suffix
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, setControllerSuffix) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *controllerSuffix_param = NULL;
	zval controllerSuffix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerSuffix);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(controllerSuffix)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &controllerSuffix_param);

	if (UNEXPECTED(Z_TYPE_P(controllerSuffix_param) != IS_STRING && Z_TYPE_P(controllerSuffix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'controllerSuffix' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(controllerSuffix_param) == IS_STRING)) {
		zephir_get_strval(&controllerSuffix, controllerSuffix_param);
	} else {
		ZEPHIR_INIT_VAR(&controllerSuffix);
		ZVAL_EMPTY_STRING(&controllerSuffix);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("_controllerSuffix"), &controllerSuffix);
	ZEPHIR_MM_RESTORE();

}

/**
 * Changes the action method suffix
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, setActionSuffix) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *actionSuffix_param = NULL;
	zval actionSuffix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionSuffix);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(actionSuffix)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionSuffix_param);

	if (UNEXPECTED(Z_TYPE_P(actionSuffix_param) != IS_STRING && Z_TYPE_P(actionSuffix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'actionSuffix' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(actionSuffix_param) == IS_STRING)) {
		zephir_get_strval(&actionSuffix, actionSuffix_param);
	} else {
		ZEPHIR_INIT_VAR(&actionSuffix);
		ZVAL_EMPTY_STRING(&actionSuffix);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("_actionSuffix"), &actionSuffix);
	ZEPHIR_MM_RESTORE();

}

/**
 * Return the registered resources
 */
PHP_METHOD(Phalcon_Mvc_Router_Annotations, getResources) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_handlers");

}

zend_object *zephir_init_properties_Phalcon_Mvc_Router_Annotations(zend_class_entry *class_type) {

		zval _0, _2, _4, _6, _8, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("_keyRouteIds"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("_keyRouteIds"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("_keyRouteNames"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("_keyRouteNames"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("_defaultParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("_defaultParams"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("_params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("_params"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("_handlers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("_handlers"), &_9$$7);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

