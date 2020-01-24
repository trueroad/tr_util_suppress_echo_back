#
# Suppress echo back utility
# https://github.com/trueroad/tr_util_suppress_echo_back
#
# tr_cxx_check_windows_suppress_echo_back.m4:
#   autoconf macro TR_CXX_CHECK_WINDOWS_SUPPRESS_ECHO_BACK
#
# Copyright (C) 2020 Masamichi Hosoda.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# * Redistributions of source code must retain the above copyright notice,
#   this list of conditions and the following disclaimer.
#
# * Redistributions in binary form must reproduce the above copyright notice,
#   this list of conditions and the following disclaimer in the documentation
#   and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.
# IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
#

AC_DEFUN([TR_CXX_CHECK_WINDOWS_SUPPRESS_ECHO_BACK],
    [AC_LANG_PUSH([C++])
     AC_MSG_CHECKING([for Windows suppress echo back method on C++])
     AC_COMPILE_IFELSE(
         [AC_LANG_PROGRAM([[
#include <windows.h>
              ]], [[
HANDLE hStdin = GetStdHandle (STD_INPUT_HANDLE);
DWORD dwMode;
GetConsoleMode (hStdin, &dwMode);
dwMode &= ~ENABLE_ECHO_INPUT;
dwMode |=ENABLE_ECHO_INPUT;
SetConsoleMode (hStdin, dwMode);
              ]])],
         [HAVE_WINDOWS_SUPPRESS_ECHO_BACK=1
          AC_DEFINE([HAVE_WINDOWS_SUPPRESS_ECHO_BACK], [1],
              [Define if you have Windows suppress echo back method on C++])
          AC_MSG_RESULT([yes])],
         [HAVE_WINDOWS_SUPPRESS_ECHO_BACK=0
          AC_MSG_RESULT([no])])
     AC_LANG_POP([C++])])
