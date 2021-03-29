
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


/**
 * Phalcon\Annotations\Reflection
 *
 * Allows to manipulate the annotations reflection in an OO manner
 *
 *<code>
 * use Phalcon\Annotations\Reader;
 * use Phalcon\Annotations\Reflection;
 *
 * // Parse the annotations in a class
 * $reader = new Reader();
 * $parsing = $reader->parse("MyComponent");
 *
 * // Create the reflection
 * $reflection = new Reflection($parsing);
 *
 * // Get the annotations in the class docblock
 * $classAnnotations = $reflection->getClassAnnotations();
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Reflection) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations, Reflection, phalcon, annotations_reflection, phalcon_annotations_reflection_method_entry, 0);

	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("_reflectionData"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("_classAnnotations"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("_methodAnnotations"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("_propertyAnnotations"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Phalcon\Annotations\Reflection constructor
 *
 * @param array reflectionData
 */
PHP_METHOD(Phalcon_Annotations_Reflection, __construct) {

	zval *reflectionData = NULL, reflectionData_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reflectionData_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(reflectionData)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(0, 1, &reflectionData);

	if (!reflectionData) {
		reflectionData = &reflectionData_sub;
		reflectionData = &__$null;
	}


	if (Z_TYPE_P(reflectionData) == IS_ARRAY) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_reflectionData"), reflectionData);
	}

}

/**
 * Returns the annotations found in the class docblock
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getClassAnnotations) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, annotations, reflectionClass, collection, _0$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&reflectionClass);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0$$3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&annotations, this_ptr, ZEND_STRL("_classAnnotations"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&annotations) != IS_OBJECT) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("_reflectionData"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_string_fetch(&reflectionClass, &_0$$3, SL("class"), 1)) {
			ZEPHIR_INIT_VAR(&collection);
			object_init_ex(&collection, phalcon_annotations_collection_ce);
			ZEPHIR_CALL_METHOD(NULL, &collection, "__construct", NULL, 12, &reflectionClass);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, ZEND_STRL("_classAnnotations"), &collection);
			RETURN_CCTOR(&collection);
		}
		if (0) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("_classAnnotations"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("_classAnnotations"), &__$false);
		}
		RETURN_MM_BOOL(0);
	}
	RETURN_CTOR(&annotations);

}

/**
 * Returns the annotations found in the methods' docblocks
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getMethodsAnnotations) {

	zend_string *_4$$5;
	zend_ulong _3$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, annotations, reflectionMethods, collections, methodName, reflectionMethod, _0$$3, *_1$$5, _2$$5, _5$$6, _7$$7;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&reflectionMethods);
	ZVAL_UNDEF(&collections);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&reflectionMethod);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_7$$7);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&annotations);
	zephir_read_property(&annotations, this_ptr, ZEND_STRL("_methodAnnotations"), PH_NOISY_CC);
	if (Z_TYPE_P(&annotations) != IS_OBJECT) {
		ZEPHIR_OBS_VAR(&reflectionMethods);
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("_reflectionData"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_string_fetch(&reflectionMethods, &_0$$3, SL("methods"), 0)) {
			if (zephir_fast_count_int(&reflectionMethods)) {
				ZEPHIR_INIT_VAR(&collections);
				array_init(&collections);
				zephir_is_iterable(&reflectionMethods, 0, "phalcon/annotations/reflection.zep", 104);
				if (Z_TYPE_P(&reflectionMethods) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&reflectionMethods), _3$$5, _4$$5, _1$$5)
					{
						ZEPHIR_INIT_NVAR(&methodName);
						if (_4$$5 != NULL) { 
							ZVAL_STR_COPY(&methodName, _4$$5);
						} else {
							ZVAL_LONG(&methodName, _3$$5);
						}
						ZEPHIR_INIT_NVAR(&reflectionMethod);
						ZVAL_COPY(&reflectionMethod, _1$$5);
						ZEPHIR_INIT_NVAR(&_5$$6);
						object_init_ex(&_5$$6, phalcon_annotations_collection_ce);
						ZEPHIR_CALL_METHOD(NULL, &_5$$6, "__construct", &_6, 12, &reflectionMethod);
						zephir_check_call_status();
						zephir_array_update_zval(&collections, &methodName, &_5$$6, PH_COPY | PH_SEPARATE);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &reflectionMethods, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_2$$5, &reflectionMethods, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_2$$5)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&methodName, &reflectionMethods, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&reflectionMethod, &reflectionMethods, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_7$$7);
							object_init_ex(&_7$$7, phalcon_annotations_collection_ce);
							ZEPHIR_CALL_METHOD(NULL, &_7$$7, "__construct", &_6, 12, &reflectionMethod);
							zephir_check_call_status();
							zephir_array_update_zval(&collections, &methodName, &_7$$7, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD(NULL, &reflectionMethods, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&reflectionMethod);
				ZEPHIR_INIT_NVAR(&methodName);
				zephir_update_property_zval(this_ptr, ZEND_STRL("_methodAnnotations"), &collections);
				RETURN_CCTOR(&collections);
			}
		}
		if (0) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("_methodAnnotations"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("_methodAnnotations"), &__$false);
		}
		RETURN_MM_BOOL(0);
	}
	RETURN_CCTOR(&annotations);

}

/**
 * Returns the annotations found in the properties' docblocks
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getPropertiesAnnotations) {

	zend_string *_4$$5;
	zend_ulong _3$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, annotations, reflectionProperties, collections, property, reflectionProperty, _0$$3, *_1$$5, _2$$5, _5$$6, _7$$7;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&reflectionProperties);
	ZVAL_UNDEF(&collections);
	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&reflectionProperty);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_7$$7);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&annotations);
	zephir_read_property(&annotations, this_ptr, ZEND_STRL("_propertyAnnotations"), PH_NOISY_CC);
	if (Z_TYPE_P(&annotations) != IS_OBJECT) {
		ZEPHIR_OBS_VAR(&reflectionProperties);
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("_reflectionData"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_string_fetch(&reflectionProperties, &_0$$3, SL("properties"), 0)) {
			if (zephir_fast_count_int(&reflectionProperties)) {
				ZEPHIR_INIT_VAR(&collections);
				array_init(&collections);
				zephir_is_iterable(&reflectionProperties, 0, "phalcon/annotations/reflection.zep", 131);
				if (Z_TYPE_P(&reflectionProperties) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&reflectionProperties), _3$$5, _4$$5, _1$$5)
					{
						ZEPHIR_INIT_NVAR(&property);
						if (_4$$5 != NULL) { 
							ZVAL_STR_COPY(&property, _4$$5);
						} else {
							ZVAL_LONG(&property, _3$$5);
						}
						ZEPHIR_INIT_NVAR(&reflectionProperty);
						ZVAL_COPY(&reflectionProperty, _1$$5);
						ZEPHIR_INIT_NVAR(&_5$$6);
						object_init_ex(&_5$$6, phalcon_annotations_collection_ce);
						ZEPHIR_CALL_METHOD(NULL, &_5$$6, "__construct", &_6, 12, &reflectionProperty);
						zephir_check_call_status();
						zephir_array_update_zval(&collections, &property, &_5$$6, PH_COPY | PH_SEPARATE);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &reflectionProperties, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_2$$5, &reflectionProperties, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_2$$5)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&property, &reflectionProperties, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&reflectionProperty, &reflectionProperties, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_7$$7);
							object_init_ex(&_7$$7, phalcon_annotations_collection_ce);
							ZEPHIR_CALL_METHOD(NULL, &_7$$7, "__construct", &_6, 12, &reflectionProperty);
							zephir_check_call_status();
							zephir_array_update_zval(&collections, &property, &_7$$7, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD(NULL, &reflectionProperties, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&reflectionProperty);
				ZEPHIR_INIT_NVAR(&property);
				zephir_update_property_zval(this_ptr, ZEND_STRL("_propertyAnnotations"), &collections);
				RETURN_CCTOR(&collections);
			}
		}
		if (0) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("_propertyAnnotations"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("_propertyAnnotations"), &__$false);
		}
		RETURN_MM_BOOL(0);
	}
	RETURN_CCTOR(&annotations);

}

/**
 * Returns the raw parsing intermediate definitions used to construct the reflection
 *
 * @return array
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getReflectionData) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_reflectionData");

}

/**
 * Restores the state of a Phalcon\Annotations\Reflection variable export
 *
 * @return array data
 */
PHP_METHOD(Phalcon_Annotations_Reflection, __set_state) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, reflectionData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&reflectionData);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	if (Z_TYPE_P(data) == IS_ARRAY) {
		if (zephir_array_isset_string_fetch(&reflectionData, data, SL("_reflectionData"), 1)) {
			object_init_ex(return_value, phalcon_annotations_reflection_ce);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 10, &reflectionData);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	object_init_ex(return_value, phalcon_annotations_reflection_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 10);
	zephir_check_call_status();
	RETURN_MM();

}

