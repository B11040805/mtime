/* mtime extension for PHP */

#ifndef PHP_MTIME_H
# define PHP_MTIME_H

extern zend_module_entry mtime_module_entry;
# define phpext_mtime_ptr &mtime_module_entry

# define PHP_MTIME_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_MTIME)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_MTIME_H */
