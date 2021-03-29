
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Validation\Message\Group
 *
 * Represents a group of validation messages
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Message_Group) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Validation\\Message, Group, phalcon, validation_message_group, phalcon_validation_message_group_method_entry, 0);

	zend_declare_property_long(phalcon_validation_message_group_ce, SL("_position"), 0, ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_validation_message_group_ce, SL("_messages"), ZEND_ACC_PROTECTED);

	phalcon_validation_message_group_ce->create_object = zephir_init_properties_Phalcon_Validation_Message_Group;

	zend_class_implements(phalcon_validation_message_group_ce, 1, zend_ce_countable);
	zend_class_implements(phalcon_validation_message_group_ce, 1, zend_ce_arrayaccess);
	zend_class_implements(phalcon_validation_message_group_ce, 1, zend_ce_iterator);
	return SUCCESS;

}

/**
 * Phalcon\Validation\Message\Group constructor
 *
 * @param array messages
 */
PHP_METHOD(Phalcon_Validation_Message_Group, __construct) {

	zval *messages = NULL, messages_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messages_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(messages)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(0, 1, &messages);

	if (!messages) {
		messages = &messages_sub;
		messages = &__$null;
	}


	if (Z_TYPE_P(messages) == IS_ARRAY) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_messages"), messages);
	}

}

/**
 * Gets an attribute a message using the array syntax
 *
 *<code>
 * print_r(
 *     $messages[0]
 * );
 *</code>
 *
 * @param int index
 * @return \Phalcon\Validation\Message
 */
PHP_METHOD(Phalcon_Validation_Message_Group, offsetGet) {

	zval *index, index_sub, message, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(index)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &index);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("_messages"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&message, &_0, index, 1)) {
		RETURN_CTORW(&message);
	}
	RETURN_BOOL(0);

}

/**
 * Sets an attribute using the array-syntax
 *
 *<code>
 * $messages[0] = new \Phalcon\Validation\Message("This is a message");
 *</code>
 *
 * @param int index
 * @param \Phalcon\Validation\Message message
 */
PHP_METHOD(Phalcon_Validation_Message_Group, offsetSet) {

	zval *index, index_sub, *message, message_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&message_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(index)
		Z_PARAM_ZVAL(message)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(2, 0, &index, &message);



	if (Z_TYPE_P(message) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_validation_exception_ce, "The message must be an object", "phalcon/validation/message/group.zep", 84);
		return;
	}
	zephir_update_property_array(this_ptr, SL("_messages"), index, message);

}

/**
 * Checks if an index exists
 *
 *<code>
 * var_dump(
 *     isset($message["database"])
 * );
 *</code>
 *
 * @param int index
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Message_Group, offsetExists) {

	zval *index, index_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(index)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &index);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("_messages"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, index));

}

/**
 * Removes a message from the list
 *
 *<code>
 * unset($message["database"]);
 *</code>
 */
PHP_METHOD(Phalcon_Validation_Message_Group, offsetUnset) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index, index_sub, _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(index)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("_messages"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, index)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("_messages"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_2$$3, 1);
		ZEPHIR_MAKE_REF(&_1$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "array_splice", NULL, 385, &_1$$3, index, &_2$$3);
		ZEPHIR_UNREF(&_1$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Appends a message to the group
 *
 *<code>
 * $messages->appendMessage(
 *     new \Phalcon\Validation\Message("This is a message")
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Validation_Message_Group, appendMessage) {

	zval *message, message_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_validation_messageinterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &message);



	zephir_update_property_array_append(this_ptr, SL("_messages"), message);

}

/**
 * Appends an array of messages to the group
 *
 *<code>
 * $messages->appendMessages($messagesArray);
 *</code>
 *
 * @param \Phalcon\Validation\MessageInterface[] messages
 */
PHP_METHOD(Phalcon_Validation_Message_Group, appendMessages) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *messages, messages_sub, currentMessages, finalMessages, message, _1$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messages_sub);
	ZVAL_UNDEF(&currentMessages);
	ZVAL_UNDEF(&finalMessages);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_1$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(messages)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &messages);



	_0 = Z_TYPE_P(messages) != IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(messages) != IS_OBJECT;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "The messages must be array or object", "phalcon/validation/message/group.zep", 148);
		return;
	}
	ZEPHIR_OBS_VAR(&currentMessages);
	zephir_read_property(&currentMessages, this_ptr, ZEND_STRL("_messages"), PH_NOISY_CC);
	if (Z_TYPE_P(messages) == IS_ARRAY) {
		if (Z_TYPE_P(&currentMessages) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&finalMessages);
			zephir_fast_array_merge(&finalMessages, &currentMessages, messages);
		} else {
			ZEPHIR_CPY_WRT(&finalMessages, messages);
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("_messages"), &finalMessages);
	} else {
		ZEPHIR_CALL_METHOD(NULL, messages, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1$$7, messages, "valid", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_1$$7))) {
				break;
			}
			ZEPHIR_CALL_METHOD(&message, messages, "current", &_2, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_3, 0, &message);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, messages, "next", &_4, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Filters the message group by field name
 *
 * @param string fieldName
 * @return array
 */
PHP_METHOD(Phalcon_Validation_Message_Group, filter) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fieldName_param = NULL, filtered, messages, message, *_0$$3, _1$$3, _2$$5, _3$$8;
	zval fieldName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fieldName);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(fieldName)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fieldName_param);

	if (UNEXPECTED(Z_TYPE_P(fieldName_param) != IS_STRING && Z_TYPE_P(fieldName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'fieldName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(fieldName_param) == IS_STRING)) {
		zephir_get_strval(&fieldName, fieldName_param);
	} else {
		ZEPHIR_INIT_VAR(&fieldName);
		ZVAL_EMPTY_STRING(&fieldName);
	}


	ZEPHIR_INIT_VAR(&filtered);
	array_init(&filtered);
	ZEPHIR_OBS_VAR(&messages);
	zephir_read_property(&messages, this_ptr, ZEND_STRL("_messages"), PH_NOISY_CC);
	if (Z_TYPE_P(&messages) == IS_ARRAY) {
		zephir_is_iterable(&messages, 0, "phalcon/validation/message/group.zep", 210);
		if (Z_TYPE_P(&messages) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&messages), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_COPY(&message, _0$$3);
				if ((zephir_method_exists_ex(&message, ZEND_STRL("getfield")) == SUCCESS)) {
					ZEPHIR_CALL_METHOD(&_2$$5, &message, "getfield", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_EQUAL(&fieldName, &_2$$5)) {
						zephir_array_append(&filtered, &message, PH_SEPARATE, "phalcon/validation/message/group.zep", 206);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &messages, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &messages, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&message, &messages, "current", NULL, 0);
				zephir_check_call_status();
					if ((zephir_method_exists_ex(&message, ZEND_STRL("getfield")) == SUCCESS)) {
						ZEPHIR_CALL_METHOD(&_3$$8, &message, "getfield", NULL, 0);
						zephir_check_call_status();
						if (ZEPHIR_IS_EQUAL(&fieldName, &_3$$8)) {
							zephir_array_append(&filtered, &message, PH_SEPARATE, "phalcon/validation/message/group.zep", 206);
						}
					}
				ZEPHIR_CALL_METHOD(NULL, &messages, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&message);
	}
	RETURN_CCTOR(&filtered);

}

/**
 * Returns the number of messages in the list
 */
PHP_METHOD(Phalcon_Validation_Message_Group, count) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("_messages"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0));

}

/**
 * Rewinds the internal iterator
 */
PHP_METHOD(Phalcon_Validation_Message_Group, rewind) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_position"), &_0);

}

/**
 * Returns the current message in the iterator
 */
PHP_METHOD(Phalcon_Validation_Message_Group, current) {

	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("_messages"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("_position"), PH_NOISY_CC);
	zephir_array_fetch(&_1, &_0, &_2, PH_NOISY | PH_READONLY, "phalcon/validation/message/group.zep", 236);
	RETURN_CTOR(&_1);

}

/**
 * Returns the current position/key in the iterator
 */
PHP_METHOD(Phalcon_Validation_Message_Group, key) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_position");

}

/**
 * Moves the internal iteration pointer to the next position
 */
PHP_METHOD(Phalcon_Validation_Message_Group, next) {

	zval *this_ptr = getThis();



	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_position")));

}

/**
 * Check if the current message in the iterator is valid
 */
PHP_METHOD(Phalcon_Validation_Message_Group, valid) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("_messages"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("_position"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, &_1));

}

/**
 * Magic __set_state helps to re-build messages variable when exporting
 *
 * @param array group
 * @return \Phalcon\Validation\Message\Group
 */
PHP_METHOD(Phalcon_Validation_Message_Group, __set_state) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *group, group_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(group)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &group);



	object_init_ex(return_value, phalcon_validation_message_group_ce);
	zephir_array_fetch_string(&_0, group, SL("_messages"), PH_NOISY | PH_READONLY, "phalcon/validation/message/group.zep", 271);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 2, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Phalcon_Validation_Message_Group(zend_class_entry *class_type) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("_messages"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("_messages"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

