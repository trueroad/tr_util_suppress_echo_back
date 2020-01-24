#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libtr_util_suppress_echo_back], [20200124])
AC_CONFIG_AUX_DIR([.])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_SRCDIR([src/tr_util_suppress_echo_back.cc])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AX_CXX_COMPILE_STDCXX([14], [ext], [optional])
AS_IF([test $HAVE_CXX14 = 0],
    [AX_CXX_COMPILE_STDCXX([11], [ext], [mandatory])])
AC_PROG_RANLIB

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
TR_CXX_CHECK_POSIX_SUPPRESS_ECHO_BACK
TR_CXX_CHECK_WINDOWS_SUPPRESS_ECHO_BACK

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
