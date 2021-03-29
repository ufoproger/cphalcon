
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


/**
 * Phalcon\Mvc\Collection\Manager
 *
 * This components controls the initialization of models, keeping record of relations
 * between the different models of the application.
 *
 * A CollectionManager is injected to a model via a Dependency Injector Container such as Phalcon\Di.
 *
 * <code>
 * $di = new \Phalcon\Di();
 *
 * $di->set(
 *     "collectionManager",
 *     function () {
 *         return new \Phalcon\Mvc\Collection\Manager();
 *     }
 * );
 *
 * $robot = new Robots($di);
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection_Manager) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Collection, Manager, phalcon, mvc_collection_manager, phalcon_mvc_collection_manager_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_initialized"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_lastInitialized"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_customEventsManager"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_connectionServices"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_implicitObjectsIds"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_behaviors"), ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalcon_mvc_collection_manager_ce, SL("_serviceName"), "mongo", ZEND_ACC_PROTECTED);

	zend_class_implements(phalcon_mvc_collection_manager_ce, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_mvc_collection_manager_ce, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Mvc_Collection_Manager, getServiceName) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_serviceName");

}

PHP_METHOD(Phalcon_Mvc_Collection_Manager, setServiceName) {

	zval *serviceName, serviceName_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&serviceName_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(serviceName)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &serviceName);



	zephir_update_property_zval(this_ptr, ZEND_STRL("_serviceName"), serviceName);
	RETURN_THISW();

}

/**
 * Sets the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setDI) {

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

}

/**
 * Returns the DependencyInjector container
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getDI) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Sets the event manager
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setEventsManager) {

	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &eventsManager);



	zephir_update_property_zval(this_ptr, ZEND_STRL("_eventsManager"), eventsManager);

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getEventsManager) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_eventsManager");

}

/**
 * Sets a custom events manager for a specific model
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setCustomEventsManager) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *model, model_sub, *eventsManager, eventsManager_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&eventsManager_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_collectioninterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &eventsManager);



	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, model, 0);
	zephir_update_property_array(this_ptr, SL("_customEventsManager"), &_0, eventsManager);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a custom events manager related to a model
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getCustomEventsManager) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *model, model_sub, customEventsManager, className, _0$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&customEventsManager);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_collectioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_OBS_VAR(&customEventsManager);
	zephir_read_property(&customEventsManager, this_ptr, ZEND_STRL("_customEventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(&customEventsManager) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&className);
		zephir_get_class(&className, model, 1);
		if (zephir_array_isset(&customEventsManager, &className)) {
			zephir_array_fetch(&_0$$4, &customEventsManager, &className, PH_NOISY | PH_READONLY, "phalcon/mvc/collection/manager.zep", 122);
			RETURN_CTOR(&_0$$4);
		}
	}
	RETURN_MM_NULL();

}

/**
 * Initializes a model in the models manager
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, initialize) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, className, initialized, eventsManager, _0$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&initialized);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&_0$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_collectioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, model, 0);
	ZEPHIR_OBS_VAR(&initialized);
	zephir_read_property(&initialized, this_ptr, ZEND_STRL("_initialized"), PH_NOISY_CC);
	if (!(zephir_array_isset(&initialized, &className))) {
		if ((zephir_method_exists_ex(model, ZEND_STRL("initialize")) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(NULL, model, "initialize", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_VAR(&eventsManager);
		zephir_read_property(&eventsManager, this_ptr, ZEND_STRL("_eventsManager"), PH_NOISY_CC);
		if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_0$$5);
			ZVAL_STRING(&_0$$5, "collectionManager:afterInitialize");
			ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_0$$5, model);
			zephir_check_call_status();
		}
		zephir_update_property_array(this_ptr, SL("_initialized"), &className, model);
		zephir_update_property_zval(this_ptr, ZEND_STRL("_lastInitialized"), model);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether a model is already initialized
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, isInitialized) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *modelName_param = NULL, _0, _1;
	zval modelName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(modelName)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modelName_param);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("_initialized"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strtolower(&_1, &modelName);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &_1));

}

/**
 * Get the latest initialized model
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getLastInitialized) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_lastInitialized");

}

/**
 * Sets a connection service for a specific model
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setConnectionService) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval connectionService;
	zval *model, model_sub, *connectionService_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&connectionService);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_collectioninterface_ce)
		Z_PARAM_STR(connectionService)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionService_param);

	if (UNEXPECTED(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		zephir_get_strval(&connectionService, connectionService_param);
	} else {
		ZEPHIR_INIT_VAR(&connectionService);
		ZVAL_EMPTY_STRING(&connectionService);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, model, 0);
	zephir_update_property_array(this_ptr, SL("_connectionServices"), &_0, &connectionService);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets a connection service for a specific model
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getConnectionService) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *model, model_sub, service, entityName, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&entityName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_collectioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_OBS_VAR(&service);
	zephir_read_property(&service, this_ptr, ZEND_STRL("_serviceName"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&entityName);
	zephir_get_class(&entityName, model, 0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("_connectionServices"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &entityName)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("_connectionServices"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&service);
		zephir_array_fetch(&service, &_1$$3, &entityName, PH_NOISY, "phalcon/mvc/collection/manager.zep", 198);
	}
	RETURN_CCTOR(&service);

}

/**
 * Sets whether a model must use implicit objects ids
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, useImplicitObjectIds) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool useImplicitObjectIds;
	zval *model, model_sub, *useImplicitObjectIds_param = NULL, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_collectioninterface_ce)
		Z_PARAM_BOOL(useImplicitObjectIds)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &useImplicitObjectIds_param);

	useImplicitObjectIds = zephir_get_boolval(useImplicitObjectIds_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, model, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_BOOL(&_1, useImplicitObjectIds);
	zephir_update_property_array(this_ptr, SL("_implicitObjectsIds"), &_0, &_1);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if a model is using implicit object ids
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, isUsingImplicitObjectIds) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *model, model_sub, implicit, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&implicit);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_collectioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("_implicitObjectsIds"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_get_class(&_1, model, 0);
	if (zephir_array_isset_fetch(&implicit, &_0, &_1, 1)) {
		RETURN_CTOR(&implicit);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Returns the connection related to a model
 *
 * @param \Phalcon\Mvc\CollectionInterface $model
 * @return \Mongo
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getConnection) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, service, connectionService, connection, dependencyInjector, entityName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&connectionService);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&entityName);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_collectioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_OBS_VAR(&service);
	zephir_read_property(&service, this_ptr, ZEND_STRL("_serviceName"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&connectionService);
	zephir_read_property(&connectionService, this_ptr, ZEND_STRL("_connectionServices"), PH_NOISY_CC);
	if (Z_TYPE_P(&connectionService) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&entityName);
		zephir_get_class(&entityName, model, 0);
		if (zephir_array_isset(&connectionService, &entityName)) {
			ZEPHIR_OBS_NVAR(&service);
			zephir_array_fetch(&service, &connectionService, &entityName, PH_NOISY, "phalcon/mvc/collection/manager.zep", 248);
		}
	}
	ZEPHIR_OBS_VAR(&dependencyInjector);
	zephir_read_property(&dependencyInjector, this_ptr, ZEND_STRL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "A dependency injector container is required to obtain the services related to the ORM", "phalcon/mvc/collection/manager.zep", 254);
		return;
	}
	ZEPHIR_CALL_METHOD(&connection, &dependencyInjector, "getshared", NULL, 0, &service);
	zephir_check_call_status();
	if (Z_TYPE_P(&connection) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Invalid injected connection service", "phalcon/mvc/collection/manager.zep", 262);
		return;
	}
	RETURN_CCTOR(&connection);

}

/**
 * Receives events generated in the models and dispatches them to an events-manager if available
 * Notify the behaviors that are listening in the model
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, notifyEvent) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventName_param = NULL, *model, model_sub, behavior, behaviors, modelsBehaviors, eventsManager, status, customEventsManager, _0$$3, *_1$$4, _2$$4, _4$$11;
	zval eventName, _3$$9, _5$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_5$$12);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&behavior);
	ZVAL_UNDEF(&behaviors);
	ZVAL_UNDEF(&modelsBehaviors);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&customEventsManager);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$11);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(eventName)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_collectioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &eventName_param, &model);

	if (UNEXPECTED(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(eventName_param) == IS_STRING)) {
		zephir_get_strval(&eventName, eventName_param);
	} else {
		ZEPHIR_INIT_VAR(&eventName);
		ZVAL_EMPTY_STRING(&eventName);
	}


	ZEPHIR_INIT_VAR(&status);
	ZVAL_NULL(&status);
	ZEPHIR_OBS_VAR(&behaviors);
	zephir_read_property(&behaviors, this_ptr, ZEND_STRL("_behaviors"), PH_NOISY_CC);
	if (Z_TYPE_P(&behaviors) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&modelsBehaviors);
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_get_class(&_0$$3, model, 1);
		if (zephir_array_isset_fetch(&modelsBehaviors, &behaviors, &_0$$3, 0)) {
			zephir_is_iterable(&modelsBehaviors, 0, "phalcon/mvc/collection/manager.zep", 289);
			if (Z_TYPE_P(&modelsBehaviors) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&modelsBehaviors), _1$$4)
				{
					ZEPHIR_INIT_NVAR(&behavior);
					ZVAL_COPY(&behavior, _1$$4);
					ZEPHIR_CALL_METHOD(&status, &behavior, "notify", NULL, 0, &eventName, model);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
						RETURN_MM_BOOL(0);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &modelsBehaviors, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_2$$4, &modelsBehaviors, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_2$$4)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&behavior, &modelsBehaviors, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&status, &behavior, "notify", NULL, 0, &eventName, model);
						zephir_check_call_status();
						if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
							RETURN_MM_BOOL(0);
						}
					ZEPHIR_CALL_METHOD(NULL, &modelsBehaviors, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&behavior);
		}
	}
	ZEPHIR_OBS_VAR(&eventsManager);
	zephir_read_property(&eventsManager, this_ptr, ZEND_STRL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_3$$9);
		ZEPHIR_CONCAT_SV(&_3$$9, "collection:", &eventName);
		ZEPHIR_CALL_METHOD(&status, &eventsManager, "fire", NULL, 0, &_3$$9, model);
		zephir_check_call_status();
		if (!(zephir_is_true(&status))) {
			RETURN_CCTOR(&status);
		}
	}
	ZEPHIR_OBS_VAR(&customEventsManager);
	zephir_read_property(&customEventsManager, this_ptr, ZEND_STRL("_customEventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(&customEventsManager) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_4$$11);
		zephir_get_class(&_4$$11, model, 1);
		if (zephir_array_isset(&customEventsManager, &_4$$11)) {
			ZEPHIR_INIT_VAR(&_5$$12);
			ZEPHIR_CONCAT_SV(&_5$$12, "collection:", &eventName);
			ZEPHIR_CALL_METHOD(&status, &customEventsManager, "fire", NULL, 0, &_5$$12, model);
			zephir_check_call_status();
			if (!(zephir_is_true(&status))) {
				RETURN_CCTOR(&status);
			}
		}
	}
	RETURN_CCTOR(&status);

}

/**
 * Dispatch an event to the listeners and behaviors
 * This method expects that the endpoint listeners/behaviors returns true
 * meaning that at least one was implemented
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, missingMethod) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval eventName, _3$$9;
	zval *model, model_sub, *eventName_param = NULL, *data, data_sub, behaviors, modelsBehaviors, result, eventsManager, behavior, _0$$3, *_1$$4, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&behaviors);
	ZVAL_UNDEF(&modelsBehaviors);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&behavior);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&_3$$9);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_collectioninterface_ce)
		Z_PARAM_STR(eventName)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &model, &eventName_param, &data);

	if (UNEXPECTED(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(eventName_param) == IS_STRING)) {
		zephir_get_strval(&eventName, eventName_param);
	} else {
		ZEPHIR_INIT_VAR(&eventName);
		ZVAL_EMPTY_STRING(&eventName);
	}


	ZEPHIR_OBS_VAR(&behaviors);
	zephir_read_property(&behaviors, this_ptr, ZEND_STRL("_behaviors"), PH_NOISY_CC);
	if (Z_TYPE_P(&behaviors) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&modelsBehaviors);
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_get_class(&_0$$3, model, 1);
		if (zephir_array_isset_fetch(&modelsBehaviors, &behaviors, &_0$$3, 0)) {
			zephir_is_iterable(&modelsBehaviors, 0, "phalcon/mvc/collection/manager.zep", 345);
			if (Z_TYPE_P(&modelsBehaviors) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&modelsBehaviors), _1$$4)
				{
					ZEPHIR_INIT_NVAR(&behavior);
					ZVAL_COPY(&behavior, _1$$4);
					ZEPHIR_CALL_METHOD(&result, &behavior, "missingmethod", NULL, 0, model, &eventName, data);
					zephir_check_call_status();
					if (Z_TYPE_P(&result) != IS_NULL) {
						RETURN_CCTOR(&result);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &modelsBehaviors, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_2$$4, &modelsBehaviors, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_2$$4)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&behavior, &modelsBehaviors, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&result, &behavior, "missingmethod", NULL, 0, model, &eventName, data);
						zephir_check_call_status();
						if (Z_TYPE_P(&result) != IS_NULL) {
							RETURN_CCTOR(&result);
						}
					ZEPHIR_CALL_METHOD(NULL, &modelsBehaviors, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&behavior);
		}
	}
	ZEPHIR_OBS_VAR(&eventsManager);
	zephir_read_property(&eventsManager, this_ptr, ZEND_STRL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_3$$9);
		ZEPHIR_CONCAT_SV(&_3$$9, "model:", &eventName);
		ZEPHIR_RETURN_CALL_METHOD(&eventsManager, "fire", NULL, 0, &_3$$9, model, data);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Binds a behavior to a model
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, addBehavior) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *model, model_sub, *behavior, behavior_sub, entityName, modelsBehaviors, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&behavior_sub);
	ZVAL_UNDEF(&entityName);
	ZVAL_UNDEF(&modelsBehaviors);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_collectioninterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(behavior, phalcon_mvc_collection_behaviorinterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &behavior);



	ZEPHIR_INIT_VAR(&entityName);
	zephir_get_class(&entityName, model, 1);
	ZEPHIR_OBS_VAR(&modelsBehaviors);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("_behaviors"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&modelsBehaviors, &_0, &entityName, 0))) {
		ZEPHIR_INIT_NVAR(&modelsBehaviors);
		array_init(&modelsBehaviors);
	}
	zephir_array_append(&modelsBehaviors, behavior, PH_SEPARATE, "phalcon/mvc/collection/manager.zep", 378);
	zephir_update_property_array(this_ptr, SL("_behaviors"), &entityName, &modelsBehaviors);
	ZEPHIR_MM_RESTORE();

}

