
extern zend_class_entry *phalcon_db_columninterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_ColumnInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_columninterface_getschemaname, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_columninterface_getname, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_columninterface_gettype, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_columninterface_gettypereference, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_columninterface_gettypevalues, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_columninterface_getsize, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_columninterface_getscale, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_columninterface_isunsigned, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_columninterface_isnotnull, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_columninterface_isprimary, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_columninterface_isautoincrement, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_columninterface_isnumeric, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_columninterface_isfirst, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_columninterface_getafterposition, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_columninterface_getbindtype, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_columninterface_getdefault, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_columninterface_hasdefault, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_columninterface___set_state, 0, 1, Phalcon\\Db\\ColumnInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_columninterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getSchemaName, arginfo_phalcon_db_columninterface_getschemaname)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getName, arginfo_phalcon_db_columninterface_getname)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getType, arginfo_phalcon_db_columninterface_gettype)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getTypeReference, arginfo_phalcon_db_columninterface_gettypereference)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getTypeValues, arginfo_phalcon_db_columninterface_gettypevalues)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getSize, arginfo_phalcon_db_columninterface_getsize)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getScale, arginfo_phalcon_db_columninterface_getscale)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, isUnsigned, arginfo_phalcon_db_columninterface_isunsigned)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, isNotNull, arginfo_phalcon_db_columninterface_isnotnull)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, isPrimary, arginfo_phalcon_db_columninterface_isprimary)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, isAutoIncrement, arginfo_phalcon_db_columninterface_isautoincrement)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, isNumeric, arginfo_phalcon_db_columninterface_isnumeric)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, isFirst, arginfo_phalcon_db_columninterface_isfirst)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getAfterPosition, arginfo_phalcon_db_columninterface_getafterposition)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getBindType, arginfo_phalcon_db_columninterface_getbindtype)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getDefault, arginfo_phalcon_db_columninterface_getdefault)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, hasDefault, arginfo_phalcon_db_columninterface_hasdefault)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_db_columninterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
