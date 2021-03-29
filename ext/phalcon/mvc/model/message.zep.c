
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


/**
 * Phalcon\Mvc\Model\Message
 *
 * Encapsulates validation info generated before save/delete records fails
 *
 *<code>
 * use Phalcon\Mvc\Model\Message as Message;
 *
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function beforeSave()
 *     {
 *         if ($this->name === "Peter") {
 *             $text  = "A robot cannot be named Peter";
 *             $field = "name";
 *             $type  = "InvalidValue";
 *
 *             $message = new Message($text, $field, $type);
 *
 *             $this->appendMessage($message);
 *         }
 *     }
 * }
 * </code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Message) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Message, phalcon, mvc_model_message, phalcon_mvc_model_message_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_mvc_model_message_ce, SL("_type"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_mvc_model_message_ce, SL("_message"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_model_message_ce, SL("_field"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_model_message_ce, SL("_model"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_mvc_model_message_ce, SL("_code"), ZEND_ACC_PROTECTED);

	zend_class_implements(phalcon_mvc_model_message_ce, 1, phalcon_mvc_model_messageinterface_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, getType) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_type");

}

/**
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, getMessage) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_message");

}

/**
 * Phalcon\Mvc\Model\Message constructor
 *
 * @param string message
 * @param string|array field
 * @param string type
 * @param \Phalcon\Mvc\ModelInterface model
 * @param int|null code
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long code;
	zval *message_param = NULL, *field = NULL, field_sub, *type = NULL, type_sub, *model = NULL, model_sub, *code_param = NULL, __$null, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&type_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_STR(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(field)
		Z_PARAM_ZVAL(type)
		Z_PARAM_ZVAL(model)
		Z_PARAM_LONG_OR_NULL(code, is_null_true)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 4, &message_param, &field, &type, &model, &code_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(&message, message_param);
	} else {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_EMPTY_STRING(&message);
	}
	if (!field) {
		field = &field_sub;
		field = &__$null;
	}
	if (!type) {
		type = &type_sub;
		type = &__$null;
	}
	if (!model) {
		model = &model_sub;
		model = &__$null;
	}
	if (!code_param) {
		code = 0;
	} else {
		code = zephir_get_intval(code_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("_message"), &message);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_field"), field);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_type"), type);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, code);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_code"), &_0);
	if (Z_TYPE_P(model) == IS_OBJECT) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_model"), model);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets message type
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, setType) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *type_param = NULL;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (UNEXPECTED(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("_type"), &type);
	RETURN_THIS();

}

/**
 * Sets verbose message
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, setMessage) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *message_param = NULL;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(&message, message_param);
	} else {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_EMPTY_STRING(&message);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("_message"), &message);
	RETURN_THIS();

}

/**
 * Sets field name related to message
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, setField) {

	zval *field, field_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(field)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &field);



	zephir_update_property_zval(this_ptr, ZEND_STRL("_field"), field);
	RETURN_THISW();

}

/**
 * Returns field name related to message
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, getField) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_field");

}

/**
 * Set the model who generates the message
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, setModel) {

	zval *model, model_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &model);



	zephir_update_property_zval(this_ptr, ZEND_STRL("_model"), model);
	RETURN_THISW();

}

/**
 * Sets code for the message
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, setCode) {

	zval *code_param = NULL, _0;
	zend_long code;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(code)
	ZEND_PARSE_PARAMETERS_END();

#endif


	zephir_fetch_params_without_memory_grow(1, 0, &code_param);

	code = zephir_get_intval(code_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, code);
	zephir_update_property_zval(this_ptr, ZEND_STRL("_code"), &_0);
	RETURN_THISW();

}

/**
 * Returns the model that produced the message
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, getModel) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_model");

}

/**
 * Returns the message code
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, getCode) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_code");

}

/**
 * Magic __toString method returns verbose message
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, __toString) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_message");

}

/**
 * Magic __set_state helps to re-build messages variable exporting
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, __set_state) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, _0, _1, _2, _3;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(message)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	ZEPHIR_OBS_COPY_OR_DUP(&message, message_param);


	object_init_ex(return_value, phalcon_mvc_model_message_ce);
	zephir_array_fetch_string(&_0, &message, SL("_message"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/message.zep", 172);
	zephir_array_fetch_string(&_1, &message, SL("_field"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/message.zep", 172);
	zephir_array_fetch_string(&_2, &message, SL("_type"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/message.zep", 172);
	zephir_array_fetch_string(&_3, &message, SL("_code"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/message.zep", 172);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 3, &_0, &_1, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

