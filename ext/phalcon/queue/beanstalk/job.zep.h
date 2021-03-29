
extern zend_class_entry *phalcon_queue_beanstalk_job_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Beanstalk_Job);

PHP_METHOD(Phalcon_Queue_Beanstalk_Job, getId);
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, getBody);
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, __construct);
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, delete);
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, release);
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, bury);
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, touch);
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, kick);
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, stats);
PHP_METHOD(Phalcon_Queue_Beanstalk_Job, __wakeup);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_beanstalk_job_getid, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_job_getbody, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_job___construct, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, queue, Phalcon\\Queue\\Beanstalk, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
	ZEND_ARG_INFO(0, body)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_beanstalk_job_delete, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_beanstalk_job_release, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, priority, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, delay, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_beanstalk_job_bury, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, priority, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_beanstalk_job_touch, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_beanstalk_job_kick, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_job_stats, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_job___wakeup, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_beanstalk_job_method_entry) {
	PHP_ME(Phalcon_Queue_Beanstalk_Job, getId, arginfo_phalcon_queue_beanstalk_job_getid, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Queue_Beanstalk_Job, getBody, arginfo_phalcon_queue_beanstalk_job_getbody, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Queue_Beanstalk_Job, getBody, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Queue_Beanstalk_Job, __construct, arginfo_phalcon_queue_beanstalk_job___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Queue_Beanstalk_Job, delete, arginfo_phalcon_queue_beanstalk_job_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk_Job, release, arginfo_phalcon_queue_beanstalk_job_release, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk_Job, bury, arginfo_phalcon_queue_beanstalk_job_bury, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk_Job, touch, arginfo_phalcon_queue_beanstalk_job_touch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk_Job, kick, arginfo_phalcon_queue_beanstalk_job_kick, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Queue_Beanstalk_Job, stats, arginfo_phalcon_queue_beanstalk_job_stats, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Queue_Beanstalk_Job, stats, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Queue_Beanstalk_Job, __wakeup, arginfo_phalcon_queue_beanstalk_job___wakeup, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Queue_Beanstalk_Job, __wakeup, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
