/*
 * Summary: compile-time version informations
 * Description: compile-time version informations for the XML library
 *
 * Copy: See Copyright for the status of this software.
 *
 * Author: Daniel Veillard
 */

#ifndef __XML_VERSION_H__
#define __XML_VERSION_H__

#include "xmlexports.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * use those to be sure nothing nasty will happen if
 * your library and includes mismatch
 */
#ifndef LIBXML2_COMPILING_MSCCDEF
XMLPUBFUN void XMLCALL xmlCheckVersion(int version);
#endif /* LIBXML2_COMPILING_MSCCDEF */

/**
 * LIBXML_DOTTED_VERSION:
 *
 * the version string like "1.2.3"
 */
#define LIBXML_DOTTED_VERSION "2.7.8"

/**
 * LIBXML_VERSION:
 *
 * the version number: 1.2.3 value is 10203
 */
#define LIBXML_VERSION 20708

/**
 * LIBXML_VERSION_STRING:
 *
 * the version number string, 1.2.3 value is "10203"
 */
#define LIBXML_VERSION_STRING "20708"

/**
 * LIBXML_VERSION_EXTRA:
 *
 * extra version information, used to show a CVS compilation
 */
#define LIBXML_VERSION_EXTRA "-GITv2.7.8-56-g8973d58"

/**
 * LIBXML_TEST_VERSION:
 *
 * Macro to check that the libxml version in use is compatible with
 * the version the software has been compiled against
 */
#define LIBXML_TEST_VERSION xmlCheckVersion(20708);

#ifndef VMS
#if 0
/**
 * WITH_TRIO:
 *
 * defined if the trio support need to be configured in
 */
#define WITH_TRIO
#else
/**
 * WITHOUT_TRIO:
 *
 * defined if the trio support should not be configured in
 */
#define WITHOUT_TRIO
#endif
#else /* VMS */
/**
 * WITH_TRIO:
 *
 * defined if the trio support need to be configured in
 */
#define WITH_TRIO 1
#endif /* VMS */

/**
 * LIBXML_TREE_ENABLED:
 *
 * Whether the DOM like tree manipulation API support is configured in
 */
#if 1
#define LIBXML_TREE_ENABLED
#endif

/**
 * LIBXML_PUSH_ENABLED:
 *
 * Whether the push parsing interfaces are configured in
 */
#if 1
#define LIBXML_PUSH_ENABLED
#endif

/**
 * LIBXML_READER_ENABLED:
 *
 * Whether the xmlReader parsing interface is configured in
 */
#if 1
#define LIBXML_READER_ENABLED
#endif

/**
 * LIBXML_VALID_ENABLED:
 *
 * Whether the DTD validation support is configured in
 */
#if 0
#define LIBXML_VALID_ENABLED
#endif

/**
 * LIBXML_C14N_ENABLED:
 *
 * Whether the Canonicalization support is configured in
 */
#if 0
#define LIBXML_C14N_ENABLED
#endif

/**
 * LIBXML_ICONV_ENABLED:
 *
 * Whether iconv support is available
 */
#if 0
#define LIBXML_ICONV_ENABLED
#endif

/**
 * LIBXML_ISO8859X_ENABLED:
 *
 * Whether ISO-8859-* support is made available in case iconv is not
 */
#if 1
#define LIBXML_ISO8859X_ENABLED
#endif

/**
 * DEBUG_MEMORY_LOCATION:
 *
 * Whether the memory debugging is configured in
 */
#if 0
#define DEBUG_MEMORY_LOCATION
#endif

/**
 * LIBXML_DEBUG_RUNTIME:
 *
 * Whether the runtime debugging is configured in
 */
#if 0
#define LIBXML_DEBUG_RUNTIME
#endif

/**
 * LIBXML_UNICODE_ENABLED:
 *
 * Whether the Unicode related interfaces are compiled in
 */
#if 0
#define LIBXML_UNICODE_ENABLED
#endif

/**
 * LIBXML_REGEXP_ENABLED:
 *
 * Whether the regular expressions interfaces are compiled in
 */
#if 0
#define LIBXML_REGEXP_ENABLED
#endif

/**
 * LIBXML_AUTOMATA_ENABLED:
 *
 * Whether the automata interfaces are compiled in
 */
#if 1
#define LIBXML_AUTOMATA_ENABLED
#endif

/**
 * LIBXML_EXPR_ENABLED:
 *
 * Whether the formal expressions interfaces are compiled in
 */
#if 0
#define LIBXML_EXPR_ENABLED
#endif

/**
 * LIBXML_MODULES_ENABLED:
 *
 * Whether the module interfaces are compiled in
 */
#if 1
#define LIBXML_MODULES_ENABLED
/**
 * LIBXML_MODULE_EXTENSION:
 *
 * the string suffix used by dynamic modules (usually shared libraries)
 */
#define LIBXML_MODULE_EXTENSION "" 
#endif

/**
 * LIBXML_LZMA_ENABLED:
 *
 * Whether the Lzma support is compiled in
 */
#if 0
#define LIBXML_LZMA_ENABLED
#endif

#ifdef __GNUC__
#ifdef HAVE_ANSIDECL_H
#include <ansidecl.h>
#endif

/**
 * ATTRIBUTE_UNUSED:
 *
 * Macro used to signal to GCC unused function parameters
 */

#ifndef ATTRIBUTE_UNUSED
#define ATTRIBUTE_UNUSED __attribute__((unused))
#endif

/**
 * LIBXML_ATTR_ALLOC_SIZE:
 *
 * Macro used to indicate to GCC this is an allocator function
 */

#ifndef LIBXML_ATTR_ALLOC_SIZE
# if ((__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 3)))
#  define LIBXML_ATTR_ALLOC_SIZE(x) __attribute__((alloc_size(x)))
# else
#  define LIBXML_ATTR_ALLOC_SIZE(x)
# endif
#else
# define LIBXML_ATTR_ALLOC_SIZE(x)
#endif

/**
 * LIBXML_ATTR_FORMAT:
 *
 * Macro used to indicate to GCC the parameter are printf like
 */

#ifndef LIBXML_ATTR_FORMAT
# if ((__GNUC__ > 3) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 3)))
#  define LIBXML_ATTR_FORMAT(fmt,args) __attribute__((__format__(__printf__,fmt,args)))
# else
#  define LIBXML_ATTR_FORMAT(fmt,args)
# endif
#else
# define LIBXML_ATTR_FORMAT(fmt,args)
#endif

#else /* ! __GNUC__ */
/**
 * ATTRIBUTE_UNUSED:
 *
 * Macro used to signal to GCC unused function parameters
 */
#define ATTRIBUTE_UNUSED
/**
 * LIBXML_ATTR_ALLOC_SIZE:
 *
 * Macro used to indicate to GCC this is an allocator function
 */
#define LIBXML_ATTR_ALLOC_SIZE(x)
/**
 * LIBXML_ATTR_FORMAT:
 *
 * Macro used to indicate to GCC the parameter are printf like
 */
#define LIBXML_ATTR_FORMAT(fmt,args)
#endif /* __GNUC__ */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif


