
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/memory.h"


/**
 * Phalcon\Acl\Resource
 *
 * This class defines resource entity and its description
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_Resource) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Acl, Resource, phalcon, acl_resource, phalcon_acl_resource_method_entry, 0);

	/**
	 * Resource name
	 * @var string
	 */
	zend_declare_property_null(phalcon_acl_resource_ce, SL("_name"), ZEND_ACC_PROTECTED);

	/**
	 * Resource description
	 * @var string
	 */
	zend_declare_property_null(phalcon_acl_resource_ce, SL("_description"), ZEND_ACC_PROTECTED);

	zend_class_implements(phalcon_acl_resource_ce, 1, phalcon_acl_resourceinterface_ce);
	return SUCCESS;

}

/**
 * Resource name
 */
PHP_METHOD(Phalcon_Acl_Resource, getName) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_name");

}

/**
 * Resource name
 */
PHP_METHOD(Phalcon_Acl_Resource, __toString) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_name");

}

/**
 * Resource description
 */
PHP_METHOD(Phalcon_Acl_Resource, getDescription) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "_description");

}

/**
 * Phalcon\Acl\Resource constructor
 */
PHP_METHOD(Phalcon_Acl_Resource, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, *description_param = NULL;
	zval name, description;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&description);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(description)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &description_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!description_param) {
		ZEPHIR_INIT_VAR(&description);
		ZVAL_STRING(&description, "");
	} else {
		zephir_get_strval(&description, description_param);
	}


	if (ZEPHIR_IS_STRING(&name, "*")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Resource name cannot be '*'", "phalcon/acl/resource.zep", 50);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("_name"), &name);
	if (!(Z_TYPE_P(&description) == IS_UNDEF) && Z_STRLEN_P(&description)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_description"), &description);
	}
	ZEPHIR_MM_RESTORE();

}

