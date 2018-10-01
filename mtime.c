/* mtime extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_mtime.h"

/* {{{ void mtime_test1()
 */
PHP_FUNCTION(mtime_test1)
{
	ZEND_PARSE_PARAMETERS_NONE();

	php_printf("The extension %s is loaded and working!\r\n", "mtime");
}

PHP_FUNCTION(mtime)
{
    
   
  
 
    struct timeval start;
    gettimeofday( &start, NULL );
    long microtime = start.tv_sec * 1000 + start.tv_usec;
    
    RETURN_LONG(microtime);   
  
    
    //RETURN_INT(microtime);
    //php_printf("The extension %s is loaded and working!\r\n", "mtime");
}
/* }}} */

/* {{{ string mtime_test2( [ string $var ] )
 */
PHP_FUNCTION(mtime_test2)
{
	char *var = "World";
	size_t var_len = sizeof("World") - 1;
	zend_string *retval;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(var, var_len)
	ZEND_PARSE_PARAMETERS_END();

	retval = strpprintf(0, "Hello %s", var);

	RETURN_STR(retval);
}
/* }}}*/

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(mtime)
{
#if defined(ZTS) && defined(COMPILE_DL_MTIME)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(mtime)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "mtime support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO(arginfo_mtime_test1, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_mtime_test2, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_mtime, 0)
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ mtime_functions[]
 */
static const zend_function_entry mtime_functions[] = {
	PHP_FE(mtime_test1,		arginfo_mtime_test1)
	PHP_FE(mtime_test2,		arginfo_mtime_test2)
	PHP_FE(mtime,     arginfo_mtime)
    PHP_FE_END
};
/* }}} */

/* {{{ mtime_module_entry
 */
zend_module_entry mtime_module_entry = {
	STANDARD_MODULE_HEADER,
	"mtime",					/* Extension name */
	mtime_functions,			/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(mtime),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(mtime),			/* PHP_MINFO - Module info */
	PHP_MTIME_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_MTIME
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(mtime)
#endif
