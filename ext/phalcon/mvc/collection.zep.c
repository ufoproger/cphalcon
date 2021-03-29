
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * Phalcon\Mvc\Collection
 *
 * This component implements a high level abstraction for NoSQL databases which
 * works with documents
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc, Collection, phalcon, mvc_collection, phalcon_mvc_collection_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_id"), ZEND_ACC_PUBLIC);

	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_modelsManager"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_source"), ZEND_ACC_PROTECTED);

	zend_declare_property_long(phalcon_mvc_collection_ce, SL("_operationMade"), 0, ZEND_ACC_PROTECTED);

	zend_declare_property_long(phalcon_mvc_collection_ce, SL("_dirtyState"), 1, ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_connection"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_errorMessages"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_reserved"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);

	zend_declare_property_null(phalcon_mvc_collection_ce, SL("_disableEvents"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);

	zend_declare_property_bool(phalcon_mvc_collection_ce, SL("_skipped"), 0, ZEND_ACC_PROTECTED);

	phalcon_mvc_collection_ce->create_object = zephir_init_properties_Phalcon_Mvc_Collection;
	zephir_declare_class_constant_long(phalcon_mvc_collection_ce, SL("OP_NONE"), 0);

	zephir_declare_class_constant_long(phalcon_mvc_collection_ce, SL("OP_CREATE"), 1);

	zephir_declare_class_constant_long(phalcon_mvc_collection_ce, SL("OP_UPDATE"), 2);

	zephir_declare_class_constant_long(phalcon_mvc_collection_ce, SL("OP_DELETE"), 3);

	zephir_declare_class_constant_long(phalcon_mvc_collection_ce, SL("DIRTY_STATE_PERSISTENT"), 0);

	zephir_declare_class_constant_long(phalcon_mvc_collection_ce, SL("DIRTY_STATE_TRANSIENT"), 1);

	zephir_declare_class_constant_long(phalcon_mvc_collection_ce, SL("DIRTY_STATE_DETACHED"), 2);

	zend_class_implements(phalcon_mvc_collection_ce, 1, phalcon_mvc_entityinterface_ce);
	zend_class_implements(phalcon_mvc_collection_ce, 1, phalcon_mvc_collectioninterface_ce);
	zend_class_implements(phalcon_mvc_collection_ce, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_mvc_collection_ce, 1, zend_ce_serializable);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Collection constructor
 */
PHP_METHOD(Phalcon_Mvc_Collection, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *dependencyInjector = NULL, dependencyInjector_sub, *modelsManager = NULL, modelsManager_sub, __$null, _1$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);
	ZVAL_UNDEF(&modelsManager_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(dependencyInjector, phalcon_diinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(modelsManager, phalcon_mvc_collection_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &dependencyInjector, &modelsManager);

	if (!dependencyInjector) {
		dependencyInjector = &dependencyInjector_sub;
		ZEPHIR_CPY_WRT(dependencyInjector, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(dependencyInjector);
	}
	if (!modelsManager) {
		modelsManager = &modelsManager_sub;
		ZEPHIR_CPY_WRT(modelsManager, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(modelsManager);
	}


	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(dependencyInjector, phalcon_di_ce, "getdefault", &_0, 0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "A dependency injector container is required to obtain the services related to the ODM", "phalcon/mvc/collection.zep", 92);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("_dependencyInjector"), dependencyInjector);
	if (Z_TYPE_P(modelsManager) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$5);
		ZVAL_STRING(&_1$$5, "collectionManager");
		ZEPHIR_CALL_METHOD(modelsManager, dependencyInjector, "getshared", NULL, 0, &_1$$5);
		zephir_check_call_status();
		if (Z_TYPE_P(modelsManager) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "The injected service 'modelsManager' is not valid", "phalcon/mvc/collection.zep", 103);
			return;
		}
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("_modelsManager"), modelsManager);
	ZEPHIR_CALL_METHOD(NULL, modelsManager, "initialize", NULL, 0, this_ptr);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(this_ptr, ZEND_STRL("onconstruct")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "onconstruct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a value for the _id property, creates a MongoId object if needed
 *
 * @param mixed id
 */
PHP_METHOD(Phalcon_Mvc_Collection, setId) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, mongoId, _0$$3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&mongoId);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(id)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	if (Z_TYPE_P(id) != IS_OBJECT) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_1$$3, &_0$$3, "isusingimplicitobjectids", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(&_1$$3)) {
			ZEPHIR_INIT_VAR(&mongoId);
			object_init_ex(&mongoId, zephir_get_internal_ce(SL("mongoid")));
			if (zephir_has_constructor(&mongoId)) {
				ZEPHIR_CALL_METHOD(NULL, &mongoId, "__construct", NULL, 0, id);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_CPY_WRT(&mongoId, id);
		}
	} else {
		ZEPHIR_CPY_WRT(&mongoId, id);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("_id"), &mongoId);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the value of the _id property
 *
 * @return \MongoId
 */
PHP_METHOD(Phalcon_Mvc_Collection, getId) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_id");

}

/**
 * Sets the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Collection, setDI) {

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
 * Returns the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Collection, getDI) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Sets a custom events manager
 */
PHP_METHOD(Phalcon_Mvc_Collection, setEventsManager) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventsManager, eventsManager_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_mvc_collection_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventsManager);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setcustomeventsmanager", NULL, 0, this_ptr, eventsManager);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the custom events manager
 */
PHP_METHOD(Phalcon_Mvc_Collection, getEventsManager) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getcustomeventsmanager", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the models manager related to the entity instance
 */
PHP_METHOD(Phalcon_Mvc_Collection, getCollectionManager) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_modelsManager");

}

/**
 * Returns an array with reserved properties that cannot be part of the insert/update
 */
PHP_METHOD(Phalcon_Mvc_Collection, getReservedAttributes) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, reserved, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&reserved);
	ZVAL_UNDEF(&_0$$3);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&reserved);
	zephir_read_static_property_ce(&reserved, phalcon_mvc_collection_ce, SL("_reserved"), PH_NOISY_CC);
	if (Z_TYPE_P(&reserved) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 8, 0);
		zephir_array_update_string(&_0$$3, SL("_connection"), &__$true, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_0$$3, SL("_dependencyInjector"), &__$true, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_0$$3, SL("_source"), &__$true, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_0$$3, SL("_operationMade"), &__$true, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_0$$3, SL("_errorMessages"), &__$true, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_0$$3, SL("_dirtyState"), &__$true, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_0$$3, SL("_modelsManager"), &__$true, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_0$$3, SL("_skipped"), &__$true, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&reserved, &_0$$3);
		zephir_update_static_property_ce(phalcon_mvc_collection_ce, ZEND_STRL("_reserved"), &reserved);
	}
	RETURN_CCTOR(&reserved);

}

/**
 * Sets if a model must use implicit objects ids
 */
PHP_METHOD(Phalcon_Mvc_Collection, useImplicitObjectIds) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *useImplicitObjectIds_param = NULL, _0, _1;
	zend_bool useImplicitObjectIds;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(useImplicitObjectIds)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &useImplicitObjectIds_param);

	useImplicitObjectIds = zephir_get_boolval(useImplicitObjectIds_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	if (useImplicitObjectIds) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "useimplicitobjectids", NULL, 0, this_ptr, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets collection name which model should be mapped
 */
PHP_METHOD(Phalcon_Mvc_Collection, setSource) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *source_param = NULL;
	zval source;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&source);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(source)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &source_param);

	if (UNEXPECTED(Z_TYPE_P(source_param) != IS_STRING && Z_TYPE_P(source_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'source' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(source_param) == IS_STRING)) {
		zephir_get_strval(&source, source_param);
	} else {
		ZEPHIR_INIT_VAR(&source);
		ZVAL_EMPTY_STRING(&source);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("_source"), &source);
	RETURN_THIS();

}

/**
 * Returns collection name mapped in the model
 */
PHP_METHOD(Phalcon_Mvc_Collection, getSource) {

	zval collection, _0, _1$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("_source"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CPY_WRT(&collection, this_ptr);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_get_class_ns(&_2$$3, &collection, 0);
		zephir_uncamelize(&_1$$3, &_2$$3, NULL  );
		zephir_update_property_zval(this_ptr, ZEND_STRL("_source"), &_1$$3);
	}
	RETURN_MM_MEMBER(getThis(), "_source");

}

/**
 * Sets the DependencyInjection connection service name
 */
PHP_METHOD(Phalcon_Mvc_Collection, setConnectionService) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connectionService_param = NULL, _0;
	zval connectionService;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connectionService);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(connectionService)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService_param);

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


	zephir_read_property(&_0, this_ptr, ZEND_STRL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setconnectionservice", NULL, 0, this_ptr, &connectionService);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Returns DependencyInjection connection service
 */
PHP_METHOD(Phalcon_Mvc_Collection, getConnectionService) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getconnectionservice", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Retrieves a database connection
 *
 * @return \MongoDb
 */
PHP_METHOD(Phalcon_Mvc_Collection, getConnection) {

	zval _0, _1$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) != IS_OBJECT) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_2$$3, &_1$$3, "getconnection", NULL, 0, this_ptr);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("_connection"), &_2$$3);
	}
	RETURN_MM_MEMBER(getThis(), "_connection");

}

/**
 * Reads an attribute value by its name
 *
 *<code>
 *	echo $robot->readAttribute("name");
 *</code>
 *
 * @param string attribute
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Collection, readAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attribute_param = NULL, _0;
	zval attribute;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(attribute)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attribute_param);

	if (UNEXPECTED(Z_TYPE_P(attribute_param) != IS_STRING && Z_TYPE_P(attribute_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'attribute' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(attribute_param) == IS_STRING)) {
		zephir_get_strval(&attribute, attribute_param);
	} else {
		ZEPHIR_INIT_VAR(&attribute);
		ZVAL_EMPTY_STRING(&attribute);
	}


	if (!(zephir_isset_property_zval(this_ptr, &attribute))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property_zval(&_0, this_ptr, &attribute, PH_NOISY_CC);
	RETURN_CCTOR(&_0);

}

/**
 * Writes an attribute value by its name
 *
 *<code>
 *	$robot->writeAttribute("name", "Rosey");
 *</code>
 *
 * @param string attribute
 * @param mixed value
 */
PHP_METHOD(Phalcon_Mvc_Collection, writeAttribute) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attribute_param = NULL, *value, value_sub;
	zval attribute;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(attribute)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &attribute_param, &value);

	zephir_get_strval(&attribute, attribute_param);


	zephir_update_property_zval_zval(this_ptr, &attribute, value);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a cloned collection
 */
PHP_METHOD(Phalcon_Mvc_Collection, cloneResult) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval document;
	zval *collection, collection_sub, *document_param = NULL, clonedCollection, key, value, *_0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection_sub);
	ZVAL_UNDEF(&clonedCollection);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&document);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(collection, phalcon_mvc_collectioninterface_ce)
		Z_PARAM_ARRAY(document)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &collection, &document_param);

	ZEPHIR_OBS_COPY_OR_DUP(&document, document_param);


	ZEPHIR_INIT_VAR(&clonedCollection);
	if (zephir_clone(&clonedCollection, collection) == FAILURE) {
		RETURN_MM();
	}
	zephir_is_iterable(&document, 0, "phalcon/mvc/collection.zep", 334);
	if (Z_TYPE_P(&document) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&document), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_CALL_METHOD(NULL, &clonedCollection, "writeattribute", &_4, 0, &key, &value);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &document, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &document, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &document, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &document, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &clonedCollection, "writeattribute", &_5, 0, &key, &value);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &document, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	if ((zephir_method_exists_ex(&clonedCollection, ZEND_STRL("afterfetch")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, &clonedCollection, "afterfetch", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&clonedCollection);

}

/**
 * Returns a collection resultset
 *
 * @param array params
 * @param \Phalcon\Mvc\Collection collection
 * @param \MongoDb connection
 * @param boolean unique
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Collection, _getResultset) {

	zend_class_entry *_1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool unique, _2$$3;
	zval *params, params_sub, *collection, collection_sub, *connection, connection_sub, *unique_param = NULL, __$false, source, mongoCollection, conditions, base, documentsCursor, fields, skip, limit, sort, document, collections, className, _6, *_7, _8, _0$$3, _3$$4, _4$$4, _5$$6, _9$$19, _11$$20;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&collection_sub);
	ZVAL_UNDEF(&connection_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&mongoCollection);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&base);
	ZVAL_UNDEF(&documentsCursor);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&skip);
	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&sort);
	ZVAL_UNDEF(&document);
	ZVAL_UNDEF(&collections);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_9$$19);
	ZVAL_UNDEF(&_11$$20);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_ZVAL(params)
		Z_PARAM_OBJECT_OF_CLASS(collection, phalcon_mvc_collectioninterface_ce)
		Z_PARAM_ZVAL(connection)
		Z_PARAM_BOOL(unique)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &params, &collection, &connection, &unique_param);

	unique = zephir_get_boolval(unique_param);


	ZEPHIR_OBS_VAR(&className);
	if (zephir_array_isset_string_fetch(&className, params, SL("class"), 0)) {
		ZEPHIR_INIT_VAR(&base);
		zephir_fetch_safe_class(&_0$$3, &className);
		_1$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_0$$3), Z_STRLEN_P(&_0$$3), ZEND_FETCH_CLASS_AUTO);
		if(!_1$$3) {
			RETURN_MM_NULL();
		}
		object_init_ex(&base, _1$$3);
		if (zephir_has_constructor(&base)) {
			ZEPHIR_CALL_METHOD(NULL, &base, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		_2$$3 = zephir_instance_of_ev(&base, phalcon_mvc_collectioninterface_ce);
		if (!(_2$$3)) {
			_2$$3 = zephir_instance_of_ev(&base, phalcon_mvc_collection_document_ce);
		}
		if (!(_2$$3)) {
			ZEPHIR_INIT_VAR(&_3$$4);
			object_init_ex(&_3$$4, phalcon_mvc_collection_exception_ce);
			ZEPHIR_INIT_VAR(&_4$$4);
			ZEPHIR_CONCAT_SVS(&_4$$4, "Object of class '", &className, "' must be an implementation of Phalcon\\Mvc\\CollectionInterface or an instance of Phalcon\\Mvc\\Collection\\Document");
			ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 4, &_4$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$4, "phalcon/mvc/collection.zep", 364);
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_CPY_WRT(&base, collection);
	}
	if (zephir_instance_of_ev(&base, phalcon_mvc_collection_ce)) {
		ZVAL_LONG(&_5$$6, 0);
		ZEPHIR_CALL_METHOD(NULL, &base, "setdirtystate", NULL, 0, &_5$$6);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&source, collection, "getsource", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&source)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string", "phalcon/mvc/collection.zep", 376);
		return;
	}
	ZEPHIR_CALL_METHOD(&mongoCollection, connection, "selectcollection", NULL, 0, &source);
	zephir_check_call_status();
	if (Z_TYPE_P(&mongoCollection) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Couldn't select mongo collection", "phalcon/mvc/collection.zep", 382);
		return;
	}
	ZEPHIR_OBS_VAR(&conditions);
	if (!(zephir_array_isset_long_fetch(&conditions, params, 0, 0))) {
		ZEPHIR_OBS_NVAR(&conditions);
		if (!(zephir_array_isset_string_fetch(&conditions, params, SL("conditions"), 0))) {
			ZEPHIR_INIT_NVAR(&conditions);
			array_init(&conditions);
		}
	}
	if (Z_TYPE_P(&conditions) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Find parameters must be an array", "phalcon/mvc/collection.zep", 395);
		return;
	}
	ZEPHIR_OBS_VAR(&fields);
	if (zephir_array_isset_string_fetch(&fields, params, SL("fields"), 0)) {
		ZEPHIR_CALL_METHOD(&documentsCursor, &mongoCollection, "find", NULL, 0, &conditions, &fields);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&documentsCursor, &mongoCollection, "find", NULL, 0, &conditions);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&limit);
	if (zephir_array_isset_string_fetch(&limit, params, SL("limit"), 0)) {
		ZEPHIR_CALL_METHOD(NULL, &documentsCursor, "limit", NULL, 0, &limit);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&sort);
	if (zephir_array_isset_string_fetch(&sort, params, SL("sort"), 0)) {
		ZEPHIR_CALL_METHOD(NULL, &documentsCursor, "sort", NULL, 0, &sort);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&skip);
	if (zephir_array_isset_string_fetch(&skip, params, SL("skip"), 0)) {
		ZEPHIR_CALL_METHOD(NULL, &documentsCursor, "skip", NULL, 0, &skip);
		zephir_check_call_status();
	}
	if (unique == 1) {
		ZEPHIR_CALL_METHOD(NULL, &documentsCursor, "rewind", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&document, &documentsCursor, "current", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&document) != IS_ARRAY) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_RETURN_CALL_STATIC("cloneresult", NULL, 0, &base, &document);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&collections);
	array_init(&collections);
	ZEPHIR_CALL_FUNCTION(&_6, "iterator_to_array", NULL, 239, &documentsCursor, &__$false);
	zephir_check_call_status();
	zephir_is_iterable(&_6, 0, "phalcon/mvc/collection.zep", 459);
	if (Z_TYPE_P(&_6) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_6), _7)
		{
			ZEPHIR_INIT_NVAR(&document);
			ZVAL_COPY(&document, _7);
			ZEPHIR_CALL_STATIC(&_9$$19, "cloneresult", &_10, 0, &base, &document);
			zephir_check_call_status();
			zephir_array_append(&collections, &_9$$19, PH_SEPARATE, "phalcon/mvc/collection.zep", 456);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_6, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_8, &_6, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&document, &_6, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_STATIC(&_11$$20, "cloneresult", &_10, 0, &base, &document);
				zephir_check_call_status();
				zephir_array_append(&collections, &_11$$20, PH_SEPARATE, "phalcon/mvc/collection.zep", 456);
			ZEPHIR_CALL_METHOD(NULL, &_6, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&document);
	RETURN_CCTOR(&collections);

}

/**
 * Perform a count over a resultset
 *
 * @param array params
 * @param \Phalcon\Mvc\Collection collection
 * @param \MongoDb connection
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Collection, _getGroupResultset) {

	zend_bool _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params, params_sub, *collection, collection_sub, *connection, connection_sub, source, mongoCollection, conditions, limit, sort, documentsCursor;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params_sub);
	ZVAL_UNDEF(&collection_sub);
	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&mongoCollection);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&sort);
	ZVAL_UNDEF(&documentsCursor);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(params)
		Z_PARAM_OBJECT_OF_CLASS(collection, phalcon_mvc_collection_ce)
		Z_PARAM_ZVAL(connection)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &params, &collection, &connection);



	ZEPHIR_CALL_METHOD(&source, collection, "getsource", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&source)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string", "phalcon/mvc/collection.zep", 476);
		return;
	}
	ZEPHIR_CALL_METHOD(&mongoCollection, connection, "selectcollection", NULL, 0, &source);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&conditions);
	if (!(zephir_array_isset_long_fetch(&conditions, params, 0, 0))) {
		ZEPHIR_OBS_NVAR(&conditions);
		if (!(zephir_array_isset_string_fetch(&conditions, params, SL("conditions"), 0))) {
			ZEPHIR_INIT_NVAR(&conditions);
			array_init(&conditions);
		}
	}
	_0 = zephir_array_isset_string(params, SL("limit"));
	if (!(_0)) {
		_0 = zephir_array_isset_string(params, SL("sort"));
	}
	_1 = _0;
	if (!(_1)) {
		_1 = zephir_array_isset_string(params, SL("skip"));
	}
	if (_1) {
		ZEPHIR_CALL_METHOD(&documentsCursor, &mongoCollection, "find", NULL, 0, &conditions);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&limit);
		if (zephir_array_isset_string_fetch(&limit, params, SL("limit"), 0)) {
			ZEPHIR_CALL_METHOD(NULL, &documentsCursor, "limit", NULL, 0, &limit);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_VAR(&sort);
		if (zephir_array_isset_string_fetch(&sort, params, SL("sort"), 0)) {
			ZEPHIR_CALL_METHOD(NULL, &documentsCursor, "sort", NULL, 0, &sort);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_NVAR(&sort);
		if (zephir_array_isset_string_fetch(&sort, params, SL("skip"), 0)) {
			ZEPHIR_CALL_METHOD(NULL, &documentsCursor, "skip", NULL, 0, &sort);
			zephir_check_call_status();
		}
		RETURN_MM_LONG(zephir_fast_count_int(&documentsCursor));
	}
	ZEPHIR_RETURN_CALL_METHOD(&mongoCollection, "count", NULL, 0, &conditions);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Executes internal hooks before save a document
 *
 * @param \Phalcon\DiInterface dependencyInjector
 * @param boolean disableEvents
 * @param boolean exists
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, _preSave) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool disableEvents, exists;
	zval *dependencyInjector, dependencyInjector_sub, *disableEvents_param = NULL, *exists_param = NULL, eventName, _3, _4, _0$$3, _1$$3, _2$$3, _5$$9, _6$$10, _7$$10, _8$$10, _9$$10, _10$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);
	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$10);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(dependencyInjector)
		Z_PARAM_BOOL(disableEvents)
		Z_PARAM_BOOL(exists)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &dependencyInjector, &disableEvents_param, &exists_param);

	disableEvents = zephir_get_boolval(disableEvents_param);
	exists = zephir_get_boolval(exists_param);


	if (!(disableEvents)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "beforeValidation");
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "fireeventcancel", NULL, 0, &_1$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_0$$3)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(&eventName);
		if (!(exists)) {
			ZVAL_STRING(&eventName, "beforeValidationOnCreate");
		} else {
			ZVAL_STRING(&eventName, "beforeValidationOnUpdate");
		}
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "fireeventcancel", NULL, 0, &eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_2$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "validation");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "fireeventcancel", NULL, 0, &_4);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_3)) {
		if (!(disableEvents)) {
			ZEPHIR_INIT_VAR(&_5$$9);
			ZVAL_STRING(&_5$$9, "onValidationFails");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_5$$9);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(0);
	}
	if (!(disableEvents)) {
		ZEPHIR_INIT_NVAR(&eventName);
		if (!(exists)) {
			ZVAL_STRING(&eventName, "afterValidationOnCreate");
		} else {
			ZVAL_STRING(&eventName, "afterValidationOnUpdate");
		}
		ZEPHIR_CALL_METHOD(&_6$$10, this_ptr, "fireeventcancel", NULL, 0, &eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_6$$10)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(&_8$$10);
		ZVAL_STRING(&_8$$10, "afterValidation");
		ZEPHIR_CALL_METHOD(&_7$$10, this_ptr, "fireeventcancel", NULL, 0, &_8$$10);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_7$$10)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(&_8$$10);
		ZVAL_STRING(&_8$$10, "beforeSave");
		ZEPHIR_CALL_METHOD(&_9$$10, this_ptr, "fireeventcancel", NULL, 0, &_8$$10);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_9$$10)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(&eventName);
		if (exists) {
			ZVAL_STRING(&eventName, "beforeUpdate");
		} else {
			ZVAL_STRING(&eventName, "beforeCreate");
		}
		ZEPHIR_CALL_METHOD(&_10$$10, this_ptr, "fireeventcancel", NULL, 0, &eventName);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_10$$10)) {
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Executes internal events after save a document
 */
PHP_METHOD(Phalcon_Mvc_Collection, _postSave) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *disableEvents_param = NULL, *success_param = NULL, *exists_param = NULL, eventName, _2, _0$$4, _1$$7;
	zend_bool disableEvents, success, exists;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_BOOL(disableEvents)
		Z_PARAM_BOOL(success)
		Z_PARAM_BOOL(exists)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &disableEvents_param, &success_param, &exists_param);

	disableEvents = zephir_get_boolval(disableEvents_param);
	success = zephir_get_boolval(success_param);
	exists = zephir_get_boolval(exists_param);


	if (success) {
		if (!(disableEvents)) {
			ZEPHIR_INIT_VAR(&eventName);
			if (exists) {
				ZVAL_STRING(&eventName, "afterUpdate");
			} else {
				ZVAL_STRING(&eventName, "afterCreate");
			}
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &eventName);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_0$$4);
			ZVAL_STRING(&_0$$4, "afterSave");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_0$$4);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(success);
	}
	if (!(disableEvents)) {
		ZEPHIR_INIT_VAR(&_1$$7);
		ZVAL_STRING(&_1$$7, "notSave");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_1$$7);
		zephir_check_call_status();
	}
	if (disableEvents) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_canceloperation", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_MM_BOOL(0);

}

/**
 * Executes validators on every validation call
 *
 *<code>
 * use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionIn;
 *
 * class Subscriptors extends \Phalcon\Mvc\Collection
 * {
 *     public function validation()
 *     {
 *         // Old, deprecated syntax, use new one below
 *         $this->validate(
 *             new ExclusionIn(
 *                 [
 *                     "field"  => "status",
 *                     "domain" => ["A", "I"],
 *                 ]
 *             )
 *         );
 *
 *         if ($this->validationHasFailed() == true) {
 *             return false;
 *         }
 *     }
 * }
 *</code>
 *
 *<code>
 * use Phalcon\Validation\Validator\ExclusionIn as ExclusionIn;
 * use Phalcon\Validation;
 *
 * class Subscriptors extends \Phalcon\Mvc\Collection
 * {
 *     public function validation()
 *     {
 *         $validator = new Validation();
 *         $validator->add("status",
 *             new ExclusionIn(
 *                 [
 *                     "domain" => ["A", "I"]
 *                 ]
 *             )
 *         );
 *
 *         return $this->validate($validator);
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, validate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validator, validator_sub, messages, message, _0$$3, _1$$4, *_2$$4, _3$$4, _4$$7, _5$$8, _7$$9, _8$$9, _9$$9, _10$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validator_sub);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(validator)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &validator);



	if (zephir_instance_of_ev(validator, phalcon_mvc_model_validatorinterface_ce)) {
		ZEPHIR_CALL_METHOD(&_0$$3, validator, "validate", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_0$$3)) {
			ZEPHIR_CALL_METHOD(&_1$$4, validator, "getmessages", NULL, 0);
			zephir_check_call_status();
			zephir_is_iterable(&_1$$4, 0, "phalcon/mvc/collection.zep", 700);
			if (Z_TYPE_P(&_1$$4) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1$$4), _2$$4)
				{
					ZEPHIR_INIT_NVAR(&message);
					ZVAL_COPY(&message, _2$$4);
					zephir_update_property_array_append(this_ptr, SL("_errorMessages"), &message);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_1$$4, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_3$$4, &_1$$4, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_3$$4)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&message, &_1$$4, "current", NULL, 0);
					zephir_check_call_status();
						zephir_update_property_array_append(this_ptr, SL("_errorMessages"), &message);
					ZEPHIR_CALL_METHOD(NULL, &_1$$4, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&message);
		}
	} else if (zephir_instance_of_ev(validator, phalcon_validationinterface_ce)) {
		ZVAL_NULL(&_4$$7);
		ZEPHIR_CALL_METHOD(&messages, validator, "validate", NULL, 0, &_4$$7, this_ptr);
		zephir_check_call_status();
		if (((Z_TYPE_P(&messages) == IS_TRUE || Z_TYPE_P(&messages) == IS_FALSE) != 1)) {
			ZEPHIR_CALL_METHOD(NULL, &messages, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$8, &messages, "valid", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(&_5$$8))) {
					break;
				}
				ZEPHIR_CALL_METHOD(&message, &messages, "current", &_6, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_7$$9);
				object_init_ex(&_7$$9, phalcon_mvc_model_message_ce);
				ZEPHIR_CALL_METHOD(&_8$$9, &message, "getmessage", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_9$$9, &message, "getfield", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_10$$9, &message, "gettype", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_7$$9, "__construct", &_11, 3, &_8$$9, &_9$$9, &_10$$9);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_12, 0, &_7$$9);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &messages, "next", &_13, 0);
				zephir_check_call_status();
			}
			RETURN_MM_BOOL(!(zephir_fast_count_int(&messages)));
		}
		RETURN_CCTOR(&messages);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "You should pass Phalcon\\Mvc\\Model\\ValidatorInterface or Phalcon\\ValidationInterface object", "phalcon/mvc/collection.zep", 732);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether validation process has generated any messages
 *
 *<code>
 * use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionIn;
 *
 * class Subscriptors extends \Phalcon\Mvc\Collection
 * {
 *     public function validation()
 *     {
 *         $this->validate(
 *             new ExclusionIn(
 *                 [
 *                     "field"  => "status",
 *                     "domain" => ["A", "I"],
 *                 ]
 *             )
 *         );
 *
 *         if ($this->validationHasFailed() == true) {
 *             return false;
 *         }
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, validationHasFailed) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("_errorMessages"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL((zephir_fast_count_int(&_0) > 0));

}

/**
 * Fires an internal event
 */
PHP_METHOD(Phalcon_Mvc_Collection, fireEvent) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventName_param = NULL, _0;
	zval eventName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(eventName)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName_param);

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


	if ((zephir_method_exists(this_ptr, &eventName)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &eventName, NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "notifyevent", NULL, 0, &eventName, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Fires an internal event that cancels the operation
 */
PHP_METHOD(Phalcon_Mvc_Collection, fireEventCancel) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventName_param = NULL, _0$$3, _1, _2;
	zval eventName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(eventName)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName_param);

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


	if ((zephir_method_exists(this_ptr, &eventName)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD_ZVAL(&_0$$3, this_ptr, &eventName, NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_0$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "notifyevent", NULL, 0, &eventName, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_2)) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Cancel the current operation
 */
PHP_METHOD(Phalcon_Mvc_Collection, _cancelOperation) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *disableEvents_param = NULL, eventName, _0$$3;
	zend_bool disableEvents;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&_0$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(disableEvents)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &disableEvents_param);

	disableEvents = zephir_get_boolval(disableEvents_param);


	if (!(disableEvents)) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("_operationMade"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&eventName);
		if (ZEPHIR_IS_LONG(&_0$$3, 3)) {
			ZVAL_STRING(&eventName, "notDeleted");
		} else {
			ZVAL_STRING(&eventName, "notSaved");
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &eventName);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Checks if the document exists in the collection
 *
 * @param \MongoCollection collection
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection, _exists) {

	zval _4;
	zend_bool exists = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection, collection_sub, id, mongoId, _2, _3, _0$$5, _1$$5, _5$$9, _6$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection_sub);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&mongoId);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(collection)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collection);



	ZEPHIR_OBS_VAR(&id);
	if (!(zephir_fetch_property(&id, this_ptr, SL("_id"), PH_SILENT_CC))) {
		RETURN_MM_BOOL(0);
	}
	if (Z_TYPE_P(&id) == IS_OBJECT) {
		ZEPHIR_CPY_WRT(&mongoId, &id);
	} else {
		zephir_read_property(&_0$$5, this_ptr, ZEND_STRL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_1$$5, &_0$$5, "isusingimplicitobjectids", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(&_1$$5)) {
			ZEPHIR_INIT_NVAR(&mongoId);
			object_init_ex(&mongoId, zephir_get_internal_ce(SL("mongoid")));
			if (zephir_has_constructor(&mongoId)) {
				ZEPHIR_CALL_METHOD(NULL, &mongoId, "__construct", NULL, 0, &id);
				zephir_check_call_status();
			}
			zephir_update_property_zval(this_ptr, ZEND_STRL("_id"), &mongoId);
		} else {
			ZEPHIR_CPY_WRT(&mongoId, &id);
		}
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("_dirtyState"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_2))) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 1, 0);
	zephir_array_update_string(&_4, SL("_id"), &mongoId, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_3, collection, "count", NULL, 0, &_4);
	zephir_check_call_status();
	exists = ZEPHIR_GT_LONG(&_3, 0);
	if (exists) {
		ZEPHIR_INIT_ZVAL_NREF(_5$$9);
		ZVAL_LONG(&_5$$9, 0);
		zephir_update_property_zval(this_ptr, ZEND_STRL("_dirtyState"), &_5$$9);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_6$$10);
		ZVAL_LONG(&_6$$10, 1);
		zephir_update_property_zval(this_ptr, ZEND_STRL("_dirtyState"), &_6$$10);
	}
	RETURN_MM_BOOL(exists);

}

/**
 * Returns all the validation messages
 *
 * <code>
 * $robot = new Robots();
 *
 * $robot->type = "mechanical";
 * $robot->name = "Astro Boy";
 * $robot->year = 1952;
 *
 * if ($robot->save() === false) {
 *     echo "Umh, We can't store robots right now ";
 *
 *     $messages = $robot->getMessages();
 *
 *     foreach ($messages as $message) {
 *         echo $message;
 *     }
 * } else {
 *     echo "Great, a new robot was saved successfully!";
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, getMessages) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_errorMessages");

}

/**
 * Appends a customized message on the validation process
 *
 *<code>
 * use \Phalcon\Mvc\Model\Message as Message;
 *
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function beforeSave()
 *     {
 *         if ($this->name === "Peter") {
 *             $message = new Message(
 *                 "Sorry, but a robot cannot be named Peter"
 *             );
 *
 *             $this->appendMessage(message);
 *         }
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, appendMessage) {

	zval *message, message_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_mvc_model_messageinterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &message);



	zephir_update_property_array_append(this_ptr, SL("_errorMessages"), message);

}

/**
 * Shared Code for CU Operations
 * Prepares Collection
 */
PHP_METHOD(Phalcon_Mvc_Collection, prepareCU) {

	zval dependencyInjector, connection, source, collection;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&collection);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&dependencyInjector);
	zephir_read_property(&dependencyInjector, this_ptr, ZEND_STRL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "A dependency injector container is required to obtain the services related to the ODM", "phalcon/mvc/collection.zep", 941);
		return;
	}
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&source)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string", "phalcon/mvc/collection.zep", 946);
		return;
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&collection, &connection, "selectcollection", NULL, 0, &source);
	zephir_check_call_status();
	RETURN_CCTOR(&collection);

}

/**
 * Creates/Updates a collection based on the values in the attributes
 */
PHP_METHOD(Phalcon_Mvc_Collection, save) {

	zval _6;
	zend_bool success = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, exists, data, status, id, ok, collection, _2, _3, _4, _5, _8, _9, _0$$3, _1$$4, _7$$9;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&exists);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&ok);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_6);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&collection, this_ptr, "preparecu", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&exists, this_ptr, "_exists", NULL, 0, &collection);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&exists)) {
		ZEPHIR_INIT_ZVAL_NREF(_0$$3);
		ZVAL_LONG(&_0$$3, 1);
		zephir_update_property_zval(this_ptr, ZEND_STRL("_operationMade"), &_0$$3);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_1$$4);
		ZVAL_LONG(&_1$$4, 2);
		zephir_update_property_zval(this_ptr, ZEND_STRL("_operationMade"), &_1$$4);
	}
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_errorMessages"), &_2);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	zephir_read_static_property_ce(&_5, phalcon_mvc_collection_ce, SL("_disableEvents"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "_presave", NULL, 240, &_4, &_5, &exists);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_3)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&data, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	success = 0;
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 1, 0);
	zephir_array_update_string(&_6, SL("w"), &__$true, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&status, &collection, "save", NULL, 0, &data, &_6);
	zephir_check_call_status();
	if (Z_TYPE_P(&status) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&ok);
		if (zephir_array_isset_string_fetch(&ok, &status, SL("ok"), 0)) {
			if (zephir_is_true(&ok)) {
				success = 1;
				if (ZEPHIR_IS_FALSE_IDENTICAL(&exists)) {
					ZEPHIR_OBS_VAR(&id);
					if (zephir_array_isset_string_fetch(&id, &data, SL("_id"), 0)) {
						zephir_update_property_zval(this_ptr, ZEND_STRL("_id"), &id);
					}
					ZEPHIR_INIT_ZVAL_NREF(_7$$9);
					ZVAL_LONG(&_7$$9, 0);
					zephir_update_property_zval(this_ptr, ZEND_STRL("_dirtyState"), &_7$$9);
				}
			}
		}
	}
	zephir_read_static_property_ce(&_8, phalcon_mvc_collection_ce, SL("_disableEvents"), PH_NOISY_CC | PH_READONLY);
	if (success) {
		ZVAL_BOOL(&_9, 1);
	} else {
		ZVAL_BOOL(&_9, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_postsave", NULL, 241, &_8, &_9, &exists);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Creates a collection based on the values in the attributes
 */
PHP_METHOD(Phalcon_Mvc_Collection, create) {

	zval _5;
	zend_bool exists = 0, success = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, data, status, id, ok, collection, _0, _1, _2, _3, _4, _7, _8, _9, _6$$7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&ok);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_5);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&collection, this_ptr, "preparecu", NULL, 0);
	zephir_check_call_status();
	exists = 0;
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_operationMade"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_errorMessages"), &_1);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	zephir_read_static_property_ce(&_3, phalcon_mvc_collection_ce, SL("_disableEvents"), PH_NOISY_CC | PH_READONLY);
	if (exists) {
		ZVAL_BOOL(&_4, 1);
	} else {
		ZVAL_BOOL(&_4, 0);
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "_presave", NULL, 240, &_0, &_3, &_4);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_2)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&data, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	success = 0;
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 1, 0);
	zephir_array_update_string(&_5, SL("w"), &__$true, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&status, &collection, "insert", NULL, 0, &data, &_5);
	zephir_check_call_status();
	if (Z_TYPE_P(&status) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&ok);
		if (zephir_array_isset_string_fetch(&ok, &status, SL("ok"), 0)) {
			if (zephir_is_true(&ok)) {
				success = 1;
				if (exists == 0) {
					ZEPHIR_OBS_VAR(&id);
					if (zephir_array_isset_string_fetch(&id, &data, SL("_id"), 0)) {
						zephir_update_property_zval(this_ptr, ZEND_STRL("_id"), &id);
					}
					ZEPHIR_INIT_ZVAL_NREF(_6$$7);
					ZVAL_LONG(&_6$$7, 0);
					zephir_update_property_zval(this_ptr, ZEND_STRL("_dirtyState"), &_6$$7);
				}
			}
		}
	}
	zephir_read_static_property_ce(&_7, phalcon_mvc_collection_ce, SL("_disableEvents"), PH_NOISY_CC | PH_READONLY);
	if (success) {
		ZVAL_BOOL(&_8, 1);
	} else {
		ZVAL_BOOL(&_8, 0);
	}
	if (exists) {
		ZVAL_BOOL(&_9, 1);
	} else {
		ZVAL_BOOL(&_9, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_postsave", NULL, 241, &_7, &_8, &_9);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Creates a document based on the values in the attributes, if not found by criteria
 * Preferred way to avoid duplication is to create index on attribute
 *
 * <code>
 * $robot = new Robot();
 *
 * $robot->name = "MyRobot";
 * $robot->type = "Droid";
 *
 * // Create only if robot with same name and type does not exist
 * $robot->createIfNotExist(
 *     [
 *         "name",
 *         "type",
 *     ]
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, createIfNotExist) {

	zend_bool exists = 0, success = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *criteria_param = NULL, __$false, __$true, data, keys, query, status, doc, collection, _0, _1, _2, _3, _4, _5, _8, _13, _14, _9$$7, _10$$7, _11$$8, _12$$8;
	zval criteria, _6, _7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&criteria);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&doc);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(criteria)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &criteria_param);

	ZEPHIR_OBS_COPY_OR_DUP(&criteria, criteria_param);


	if (ZEPHIR_IS_EMPTY(&criteria)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Criteria parameter must be array with one or more attributes of the model", "phalcon/mvc/collection.zep", 1101);
		return;
	}
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "preparecu", NULL, 0);
	zephir_check_call_status();
	exists = 0;
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_operationMade"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_errorMessages"), &_1);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	zephir_read_static_property_ce(&_3, phalcon_mvc_collection_ce, SL("_disableEvents"), PH_NOISY_CC | PH_READONLY);
	if (exists) {
		ZVAL_BOOL(&_4, 1);
	} else {
		ZVAL_BOOL(&_4, 0);
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "_presave", NULL, 240, &_0, &_3, &_4);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_2)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_FUNCTION(&keys, "array_flip", NULL, 242, &criteria);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&data, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_5, "array_diff_key", NULL, 243, &keys, &data);
	zephir_check_call_status();
	if (zephir_is_true(&_5)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Criteria parameter must be array with one or more attributes of the model", "phalcon/mvc/collection.zep", 1136);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&query, "array_intersect_key", NULL, 244, &data, &keys);
	zephir_check_call_status();
	success = 0;
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 1, 0);
	zephir_array_update_string(&_6, SL("$setOnInsert"), &data, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 2, 0);
	zephir_array_update_string(&_7, SL("new"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_7, SL("upsert"), &__$true, PH_COPY | PH_SEPARATE);
	ZVAL_NULL(&_8);
	ZEPHIR_CALL_METHOD(&status, &collection, "findandmodify", NULL, 0, &query, &_6, &_8, &_7);
	zephir_check_call_status();
	if (Z_TYPE_P(&status) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&doc, &collection, "findone", NULL, 0, &query);
		zephir_check_call_status();
		if (Z_TYPE_P(&doc) == IS_ARRAY) {
			success = 1;
			ZEPHIR_INIT_ZVAL_NREF(_9$$7);
			ZVAL_LONG(&_9$$7, 1);
			zephir_update_property_zval(this_ptr, ZEND_STRL("_operationMade"), &_9$$7);
			zephir_array_fetch_string(&_10$$7, &doc, SL("_id"), PH_NOISY | PH_READONLY, "phalcon/mvc/collection.zep", 1156);
			zephir_update_property_zval(this_ptr, ZEND_STRL("_id"), &_10$$7);
		}
	} else {
		ZEPHIR_INIT_VAR(&_11$$8);
		object_init_ex(&_11$$8, phalcon_mvc_model_message_ce);
		ZEPHIR_INIT_VAR(&_12$$8);
		ZVAL_STRING(&_12$$8, "Document already exists");
		ZEPHIR_CALL_METHOD(NULL, &_11$$8, "__construct", NULL, 3, &_12$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", NULL, 0, &_11$$8);
		zephir_check_call_status();
	}
	zephir_read_static_property_ce(&_8, phalcon_mvc_collection_ce, SL("_disableEvents"), PH_NOISY_CC | PH_READONLY);
	if (success) {
		ZVAL_BOOL(&_13, 1);
	} else {
		ZVAL_BOOL(&_13, 0);
	}
	if (exists) {
		ZVAL_BOOL(&_14, 1);
	} else {
		ZVAL_BOOL(&_14, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_postsave", NULL, 241, &_8, &_13, &_14);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Creates/Updates a collection based on the values in the attributes
 */
PHP_METHOD(Phalcon_Mvc_Collection, update) {

	zval _4, _6;
	zend_bool success = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, exists, data, status, ok, collection, _0, _1, _2, _3, _5, _7, _8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&exists);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&ok);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&collection, this_ptr, "preparecu", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&exists, this_ptr, "_exists", NULL, 0, &collection);
	zephir_check_call_status();
	if (!(zephir_is_true(&exists))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "The document cannot be updated because it doesn't exist", "phalcon/mvc/collection.zep", 1183);
		return;
	}
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 2);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_operationMade"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_errorMessages"), &_1);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	zephir_read_static_property_ce(&_3, phalcon_mvc_collection_ce, SL("_disableEvents"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "_presave", NULL, 240, &_0, &_3, &exists);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_2)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&data, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	success = 0;
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 1, 0);
	ZEPHIR_OBS_VAR(&_5);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("_id"), PH_NOISY_CC);
	zephir_array_update_string(&_4, SL("_id"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 1, 0);
	zephir_array_update_string(&_6, SL("w"), &__$true, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&status, &collection, "update", NULL, 0, &_4, &data, &_6);
	zephir_check_call_status();
	if (Z_TYPE_P(&status) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&ok);
		if (zephir_array_isset_string_fetch(&ok, &status, SL("ok"), 0)) {
			if (zephir_is_true(&ok)) {
				success = 1;
			}
		}
	} else {
		success = 0;
	}
	zephir_read_static_property_ce(&_7, phalcon_mvc_collection_ce, SL("_disableEvents"), PH_NOISY_CC | PH_READONLY);
	if (success) {
		ZVAL_BOOL(&_8, 1);
	} else {
		ZVAL_BOOL(&_8, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_postsave", NULL, 241, &_7, &_8, &exists);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Find a document by its id (_id)
 *
 * <code>
 * // Find user by using \MongoId object
 * $user = Users::findById(
 *     new \MongoId("545eb081631d16153a293a66")
 * );
 *
 * // Find user by using id as sting
 * $user = Users::findById("45cbc4a0e4123f6920000002");
 *
 * // Validate input
 * if ($user = Users::findById($_POST["id"])) {
 *     // ...
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, findById) {

	zend_class_entry *_5$$3;
	zval _8, _9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, className, collection, mongoId, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3, _6$$3, _7$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&mongoId);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(id)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	if (Z_TYPE_P(id) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "/^[a-f\\d]{24}$/i");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "/^[a-f\\d]{24}$/i");
		zephir_preg_match(&_2$$3, &_3$$3, id, &_0$$3, 0, 0 , 0 );
		if (!(zephir_is_true(&_2$$3))) {
			RETURN_MM_NULL();
		}
		ZEPHIR_INIT_VAR(&className);
		zephir_get_called_class(&className);
		ZEPHIR_INIT_VAR(&collection);
		zephir_fetch_safe_class(&_4$$3, &className);
		_5$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_4$$3), Z_STRLEN_P(&_4$$3), ZEND_FETCH_CLASS_AUTO);
		if(!_5$$3) {
			RETURN_MM_NULL();
		}
		object_init_ex(&collection, _5$$3);
		if (zephir_has_constructor(&collection)) {
			ZEPHIR_CALL_METHOD(NULL, &collection, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_6$$3, &collection, "getcollectionmanager", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7$$3, &_6$$3, "isusingimplicitobjectids", NULL, 0, &collection);
		zephir_check_call_status();
		if (zephir_is_true(&_7$$3)) {
			ZEPHIR_INIT_VAR(&mongoId);
			object_init_ex(&mongoId, zephir_get_internal_ce(SL("mongoid")));
			if (zephir_has_constructor(&mongoId)) {
				ZEPHIR_CALL_METHOD(NULL, &mongoId, "__construct", NULL, 0, id);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_CPY_WRT(&mongoId, id);
		}
	} else {
		ZEPHIR_CPY_WRT(&mongoId, id);
	}
	ZEPHIR_INIT_VAR(&_8);
	zephir_create_array(&_8, 1, 0);
	ZEPHIR_INIT_VAR(&_9);
	zephir_create_array(&_9, 1, 0);
	zephir_array_update_string(&_9, SL("_id"), &mongoId, PH_COPY | PH_SEPARATE);
	zephir_array_fast_append(&_8, &_9);
	ZEPHIR_RETURN_CALL_STATIC("findfirst", NULL, 0, &_8);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Allows to query the first record that match the specified conditions
 *
 * <code>
 * // What's the first robot in the robots table?
 * $robot = Robots::findFirst();
 *
 * echo "The robot name is ", $robot->name, "\n";
 *
 * // What's the first mechanical robot in robots table?
 * $robot = Robots::findFirst(
 *     [
 *         [
 *             "type" => "mechanical",
 *         ]
 *     ]
 * );
 *
 * echo "The first mechanical robot name is ", $robot->name, "\n";
 *
 * // Get first virtual robot ordered by name
 * $robot = Robots::findFirst(
 *     [
 *         [
 *             "type" => "mechanical",
 *         ],
 *         "order" => [
 *             "name" => 1,
 *         ],
 *     ]
 * );
 *
 * echo "The first virtual robot name is ", $robot->name, "\n";
 *
 * // Get first robot by id (_id)
 * $robot = Robots::findFirst(
 *     [
 *         [
 *             "_id" => new \MongoId("45cbc4a0e4123f6920000002"),
 *         ]
 *     ]
 * );
 *
 * echo "The robot id is ", $robot->_id, "\n";
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, findFirst) {

	zend_class_entry *_1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, className, collection, connection, _0, _2;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters_param);

	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&className);
	zephir_get_called_class(&className);
	ZEPHIR_INIT_VAR(&collection);
	zephir_fetch_safe_class(&_0, &className);
	_1 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_0), Z_STRLEN_P(&_0), ZEND_FETCH_CLASS_AUTO);
	if(!_1) {
		RETURN_MM_NULL();
	}
	object_init_ex(&collection, _1);
	if (zephir_has_constructor(&collection)) {
		ZEPHIR_CALL_METHOD(NULL, &collection, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&connection, &collection, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZVAL_BOOL(&_2, 1);
	ZEPHIR_RETURN_CALL_STATIC("_getresultset", NULL, 0, &parameters, &collection, &connection, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Allows to query a set of records that match the specified conditions
 *
 * <code>
 * // How many robots are there?
 * $robots = Robots::find();
 *
 * echo "There are ", count($robots), "\n";
 *
 * // How many mechanical robots are there?
 * $robots = Robots::find(
 *     [
 *         [
 *             "type" => "mechanical",
 *         ]
 *     ]
 * );
 *
 * echo "There are ", count(robots), "\n";
 *
 * // Get and print virtual robots ordered by name
 * $robots = Robots::findFirst(
 *     [
 *         [
 *             "type" => "virtual"
 *         ],
 *         "order" => [
 *             "name" => 1,
 *         ]
 *     ]
 * );
 *
 * foreach ($robots as $robot) {
 *	   echo $robot->name, "\n";
 * }
 *
 * // Get first 100 virtual robots ordered by name
 * $robots = Robots::find(
 *     [
 *         [
 *             "type" => "virtual",
 *         ],
 *         "order" => [
 *             "name" => 1,
 *         ],
 *         "limit" => 100,
 *     ]
 * );
 *
 * foreach ($robots as $robot) {
 *	   echo $robot->name, "\n";
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, find) {

	zend_class_entry *_1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, className, collection, _0, _2, _3;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters_param);

	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&className);
	zephir_get_called_class(&className);
	ZEPHIR_INIT_VAR(&collection);
	zephir_fetch_safe_class(&_0, &className);
	_1 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_0), Z_STRLEN_P(&_0), ZEND_FETCH_CLASS_AUTO);
	if(!_1) {
		RETURN_MM_NULL();
	}
	object_init_ex(&collection, _1);
	if (zephir_has_constructor(&collection)) {
		ZEPHIR_CALL_METHOD(NULL, &collection, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_2, &collection, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZVAL_BOOL(&_3, 0);
	ZEPHIR_RETURN_CALL_STATIC("_getresultset", NULL, 0, &parameters, &collection, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Perform a count over a collection
 *
 *<code>
 * echo "There are ", Robots::count(), " robots";
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, count) {

	zend_class_entry *_1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, className, collection, connection, _0;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters_param);

	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&className);
	zephir_get_called_class(&className);
	ZEPHIR_INIT_VAR(&collection);
	zephir_fetch_safe_class(&_0, &className);
	_1 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_0), Z_STRLEN_P(&_0), ZEND_FETCH_CLASS_AUTO);
	if(!_1) {
		RETURN_MM_NULL();
	}
	object_init_ex(&collection, _1);
	if (zephir_has_constructor(&collection)) {
		ZEPHIR_CALL_METHOD(NULL, &collection, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&connection, &collection, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_STATIC("_getgroupresultset", NULL, 0, &parameters, &collection, &connection);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Perform an aggregation using the Mongo aggregation framework
 */
PHP_METHOD(Phalcon_Mvc_Collection, aggregate) {

	zend_class_entry *_1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters_param = NULL, *options_param = NULL, className, model, connection, source, _0, _2;
	zval parameters, options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_OR_NULL(parameters)
		Z_PARAM_ARRAY_OR_NULL(options)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &parameters_param, &options_param);

	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&className);
	zephir_get_called_class(&className);
	ZEPHIR_INIT_VAR(&model);
	zephir_fetch_safe_class(&_0, &className);
	_1 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_0), Z_STRLEN_P(&_0), ZEND_FETCH_CLASS_AUTO);
	if(!_1) {
		RETURN_MM_NULL();
	}
	object_init_ex(&model, _1);
	if (zephir_has_constructor(&model)) {
		ZEPHIR_CALL_METHOD(NULL, &model, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&connection, &model, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&source)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string", "phalcon/mvc/collection.zep", 1429);
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, &connection, "selectcollection", NULL, 0, &source);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_2, "aggregate", NULL, 0, &parameters, &options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Allows to perform a summatory group for a column in the collection
 */
PHP_METHOD(Phalcon_Mvc_Collection, summatory) {

	zend_class_entry *_1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, *conditions = NULL, conditions_sub, *finalize = NULL, finalize_sub, __$null, className, model, connection, source, collection, initial, reduce, group, retval, firstRetval, _0, _2, _4$$6;
	zval field, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&conditions_sub);
	ZVAL_UNDEF(&finalize_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&initial);
	ZVAL_UNDEF(&reduce);
	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&retval);
	ZVAL_UNDEF(&firstRetval);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(field)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(conditions)
		Z_PARAM_ZVAL(finalize)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &field_param, &conditions, &finalize);

	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(&field, field_param);
	} else {
		ZEPHIR_INIT_VAR(&field);
		ZVAL_EMPTY_STRING(&field);
	}
	if (!conditions) {
		conditions = &conditions_sub;
		conditions = &__$null;
	}
	if (!finalize) {
		finalize = &finalize_sub;
		finalize = &__$null;
	}


	ZEPHIR_INIT_VAR(&className);
	zephir_get_called_class(&className);
	ZEPHIR_INIT_VAR(&model);
	zephir_fetch_safe_class(&_0, &className);
	_1 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_0), Z_STRLEN_P(&_0), ZEND_FETCH_CLASS_AUTO);
	if(!_1) {
		RETURN_MM_NULL();
	}
	object_init_ex(&model, _1);
	if (zephir_has_constructor(&model)) {
		ZEPHIR_CALL_METHOD(NULL, &model, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&connection, &model, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&source)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string", "phalcon/mvc/collection.zep", 1451);
		return;
	}
	ZEPHIR_CALL_METHOD(&collection, &connection, "selectcollection", NULL, 0, &source);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&initial);
	zephir_create_array(&initial, 1, 0);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_array_update_string(&initial, SL("summatory"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SVSVSVS(&_3, "function (curr, result) { if (typeof result.summatory[curr.", &field, "] === \"undefined\") { result.summatory[curr.", &field, "] = 1; } else { result.summatory[curr.", &field, "]++; } }");
	ZEPHIR_CPY_WRT(&reduce, &_3);
	ZEPHIR_INIT_NVAR(&_2);
	array_init(&_2);
	ZEPHIR_CALL_METHOD(&group, &collection, "group", NULL, 0, &_2, &initial, &reduce);
	zephir_check_call_status();
	if (zephir_array_isset_string_fetch(&retval, &group, SL("retval"), 1)) {
		if (zephir_array_isset_long_fetch(&firstRetval, &retval, 0, 1)) {
			if (zephir_array_isset_string(&firstRetval, SL("summatory"))) {
				zephir_array_fetch_string(&_4$$6, &firstRetval, SL("summatory"), PH_NOISY | PH_READONLY, "phalcon/mvc/collection.zep", 1471);
				RETURN_CTOR(&_4$$6);
			}
			RETURN_CTOR(&firstRetval);
		}
		RETURN_CTOR(&retval);
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * Deletes a model instance. Returning true on success or false otherwise.
 *
 * <code>
 * $robot = Robots::findFirst();
 *
 * $robot->delete();
 *
 * $robots = Robots::find();
 *
 * foreach ($robots as $robot) {
 *     $robot->delete();
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, delete) {

	zval _5, _6;
	zend_bool success = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, disableEvents, status, id, connection, source, collection, mongoId, ok, _2, _0$$4, _1$$4, _3$$9, _4$$9, _7$$15, _8$$14;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&disableEvents);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&mongoId);
	ZVAL_UNDEF(&ok);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_7$$15);
	ZVAL_UNDEF(&_8$$14);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&id);
	if (!(zephir_fetch_property(&id, this_ptr, SL("_id"), PH_SILENT_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "The document cannot be deleted because it doesn't exist", "phalcon/mvc/collection.zep", 1502);
		return;
	}
	ZEPHIR_OBS_VAR(&disableEvents);
	zephir_read_static_property_ce(&disableEvents, phalcon_mvc_collection_ce, SL("_disableEvents"), PH_NOISY_CC);
	if (!(zephir_is_true(&disableEvents))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "beforeDelete");
		ZEPHIR_CALL_METHOD(&_0$$4, this_ptr, "fireeventcancel", NULL, 0, &_1$$4);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_0$$4)) {
			RETURN_MM_BOOL(0);
		}
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("_skipped"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_2)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&source)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Method getSource() returns empty string", "phalcon/mvc/collection.zep", 1521);
		return;
	}
	ZEPHIR_CALL_METHOD(&collection, &connection, "selectcollection", NULL, 0, &source);
	zephir_check_call_status();
	if (Z_TYPE_P(&id) == IS_OBJECT) {
		ZEPHIR_CPY_WRT(&mongoId, &id);
	} else {
		zephir_read_property(&_3$$9, this_ptr, ZEND_STRL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_4$$9, &_3$$9, "isusingimplicitobjectids", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(&_4$$9)) {
			ZEPHIR_INIT_NVAR(&mongoId);
			object_init_ex(&mongoId, zephir_get_internal_ce(SL("mongoid")));
			if (zephir_has_constructor(&mongoId)) {
				ZEPHIR_CALL_METHOD(NULL, &mongoId, "__construct", NULL, 0, &id);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_CPY_WRT(&mongoId, &id);
		}
	}
	success = 0;
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 1, 0);
	zephir_array_update_string(&_5, SL("_id"), &mongoId, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 1, 0);
	zephir_array_update_string(&_6, SL("w"), &__$true, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&status, &collection, "remove", NULL, 0, &_5, &_6);
	zephir_check_call_status();
	if (Z_TYPE_P(&status) != IS_ARRAY) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(&ok);
	if (zephir_array_isset_string_fetch(&ok, &status, SL("ok"), 0)) {
		if (zephir_is_true(&ok)) {
			success = 1;
			if (!(zephir_is_true(&disableEvents))) {
				ZEPHIR_INIT_VAR(&_7$$15);
				ZVAL_STRING(&_7$$15, "afterDelete");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_7$$15);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_ZVAL_NREF(_8$$14);
			ZVAL_LONG(&_8$$14, 2);
			zephir_update_property_zval(this_ptr, ZEND_STRL("_dirtyState"), &_8$$14);
		}
	} else {
		success = 0;
	}
	RETURN_MM_BOOL(success);

}

/**
 * Sets the dirty state of the object using one of the DIRTY_STATE_* constants
 */
PHP_METHOD(Phalcon_Mvc_Collection, setDirtyState) {

	zval *dirtyState_param = NULL, _0;
	zend_long dirtyState;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(dirtyState)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &dirtyState_param);

	dirtyState = zephir_get_intval(dirtyState_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, dirtyState);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_dirtyState"), &_0);
	RETURN_THISW();

}

/**
 * Returns one of the DIRTY_STATE_* constants telling if the document exists in the collection or not
 */
PHP_METHOD(Phalcon_Mvc_Collection, getDirtyState) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_dirtyState");

}

/**
 * Sets up a behavior in a collection
 */
PHP_METHOD(Phalcon_Mvc_Collection, addBehavior) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *behavior, behavior_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&behavior_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(behavior, phalcon_mvc_collection_behaviorinterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &behavior);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "addbehavior", NULL, 0, this_ptr, behavior);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Skips the current operation forcing a success state
 */
PHP_METHOD(Phalcon_Mvc_Collection, skipOperation) {

	zval *skip_param = NULL, __$true, __$false;
	zend_bool skip;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(skip)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &skip_param);

	skip = zephir_get_boolval(skip_param);


	if (skip) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_skipped"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_skipped"), &__$false);
	}

}

/**
 * Returns the instance as an array representation
 *
 *<code>
 * print_r(
 *     $robot->toArray()
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Collection, toArray) {

	zend_string *_4;
	zend_ulong _3;
	zval data, reserved, key, value, _0, *_1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&reserved);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&reserved, this_ptr, "getreservedattributes", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 17, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/mvc/collection.zep", 1635);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			if (ZEPHIR_IS_STRING(&key, "_id")) {
				if (zephir_is_true(&value)) {
					zephir_array_update_zval(&data, &key, &value, PH_COPY | PH_SEPARATE);
				}
			} else {
				if (!(zephir_array_isset(&reserved, &key))) {
					zephir_array_update_zval(&data, &key, &value, PH_COPY | PH_SEPARATE);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_0, "current", NULL, 0);
			zephir_check_call_status();
				if (ZEPHIR_IS_STRING(&key, "_id")) {
					if (zephir_is_true(&value)) {
						zephir_array_update_zval(&data, &key, &value, PH_COPY | PH_SEPARATE);
					}
				} else {
					if (!(zephir_array_isset(&reserved, &key))) {
						zephir_array_update_zval(&data, &key, &value, PH_COPY | PH_SEPARATE);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&data);

}

/**
 * Serializes the object ignoring connections or protected properties
 */
PHP_METHOD(Phalcon_Mvc_Collection, serialize) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 54, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserializes the object from a serialized string
 */
PHP_METHOD(Phalcon_Mvc_Collection, unserialize) {

	zend_string *_5$$3;
	zend_ulong _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, attributes, dependencyInjector, manager, key, value, _1$$3, *_2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_CALL_FUNCTION(&attributes, "unserialize", NULL, 55, data);
	zephir_check_call_status();
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "A dependency injector container is required to obtain the services related to the ODM", "phalcon/mvc/collection.zep", 1664);
			return;
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("_dependencyInjector"), &dependencyInjector);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "collectionManager");
		ZEPHIR_CALL_METHOD(&manager, &dependencyInjector, "getshared", NULL, 0, &_1$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(&manager) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "The injected service 'collectionManager' is not valid", "phalcon/mvc/collection.zep", 1677);
			return;
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("_modelsManager"), &manager);
		zephir_is_iterable(&attributes, 0, "phalcon/mvc/collection.zep", 1691);
		if (Z_TYPE_P(&attributes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&attributes), _4$$3, _5$$3, _2$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_5$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _5$$3);
				} else {
					ZVAL_LONG(&key, _4$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _2$$3);
				zephir_update_property_zval_zval(this_ptr, &key, &value);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_3$$3, &attributes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &attributes, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &attributes, "current", NULL, 0);
				zephir_check_call_status();
					zephir_update_property_zval_zval(this_ptr, &key, &value);
				ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	}
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Phalcon_Mvc_Collection(zend_class_entry *class_type) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("_errorMessages"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("_errorMessages"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

