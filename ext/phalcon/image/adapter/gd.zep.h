
extern zend_class_entry *phalcon_image_adapter_gd_ce;

ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_Gd);

PHP_METHOD(Phalcon_Image_Adapter_Gd, check);
PHP_METHOD(Phalcon_Image_Adapter_Gd, __construct);
PHP_METHOD(Phalcon_Image_Adapter_Gd, _resize);
PHP_METHOD(Phalcon_Image_Adapter_Gd, _crop);
PHP_METHOD(Phalcon_Image_Adapter_Gd, _rotate);
PHP_METHOD(Phalcon_Image_Adapter_Gd, _flip);
PHP_METHOD(Phalcon_Image_Adapter_Gd, _sharpen);
PHP_METHOD(Phalcon_Image_Adapter_Gd, _reflection);
PHP_METHOD(Phalcon_Image_Adapter_Gd, _watermark);
PHP_METHOD(Phalcon_Image_Adapter_Gd, _text);
PHP_METHOD(Phalcon_Image_Adapter_Gd, _mask);
PHP_METHOD(Phalcon_Image_Adapter_Gd, _background);
PHP_METHOD(Phalcon_Image_Adapter_Gd, _blur);
PHP_METHOD(Phalcon_Image_Adapter_Gd, _pixelate);
PHP_METHOD(Phalcon_Image_Adapter_Gd, _save);
PHP_METHOD(Phalcon_Image_Adapter_Gd, _render);
PHP_METHOD(Phalcon_Image_Adapter_Gd, _create);
PHP_METHOD(Phalcon_Image_Adapter_Gd, __destruct);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_image_adapter_gd_check, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 1)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__resize, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__crop, 0, 0, 4)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offsetX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offsetY, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__rotate, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, degrees, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__flip, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, direction, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__sharpen, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, amount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__reflection, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fadeIn, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__watermark, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, watermark, Phalcon\\Image\\Adapter, 0)
	ZEND_ARG_TYPE_INFO(0, offsetX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offsetY, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__text, 0, 0, 9)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, offsetX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offsetY, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, r, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, g, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fontfile, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__mask, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, mask, Phalcon\\Image\\Adapter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__background, 0, 0, 4)
	ZEND_ARG_TYPE_INFO(0, r, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, g, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, opacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__blur, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, radius, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__pixelate, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, amount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__save, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, quality, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__render, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, ext, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, quality, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__create, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd___destruct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_image_adapter_gd_method_entry) {
	PHP_ME(Phalcon_Image_Adapter_Gd, check, arginfo_phalcon_image_adapter_gd_check, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Image_Adapter_Gd, __construct, arginfo_phalcon_image_adapter_gd___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Image_Adapter_Gd, _resize, arginfo_phalcon_image_adapter_gd__resize, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _crop, arginfo_phalcon_image_adapter_gd__crop, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _rotate, arginfo_phalcon_image_adapter_gd__rotate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _flip, arginfo_phalcon_image_adapter_gd__flip, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _sharpen, arginfo_phalcon_image_adapter_gd__sharpen, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _reflection, arginfo_phalcon_image_adapter_gd__reflection, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _watermark, arginfo_phalcon_image_adapter_gd__watermark, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _text, arginfo_phalcon_image_adapter_gd__text, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _mask, arginfo_phalcon_image_adapter_gd__mask, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _background, arginfo_phalcon_image_adapter_gd__background, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _blur, arginfo_phalcon_image_adapter_gd__blur, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _pixelate, arginfo_phalcon_image_adapter_gd__pixelate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _save, arginfo_phalcon_image_adapter_gd__save, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _render, arginfo_phalcon_image_adapter_gd__render, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _create, arginfo_phalcon_image_adapter_gd__create, ZEND_ACC_PROTECTED)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Image_Adapter_Gd, __destruct, arginfo_phalcon_image_adapter_gd___destruct, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
#else
	PHP_ME(Phalcon_Image_Adapter_Gd, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
#endif
	PHP_FE_END
};
