//
// Suppress echo back utility
// https://github.com/trueroad/tr_util_suppress_echo_back
//
// tr_util_suppress_echo_back.cc:
//   suppress_echo_back utility implementation
//
// Copyright (C) 2019, 2020 Masamichi Hosoda.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED.
// IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
// SUCH DAMAGE.
//

#include "config.h"

#include "tr_util_suppress_echo_back.hh"

#ifdef HAVE_POSIX_SUPPRESS_ECHO_BACK
#include <termios.h>
#include <unistd.h>
#else
#ifdef HAVE_WINDOWS_SUPPRESS_ECHO_BACK
#include <windows.h>
#else
#warning cannot suppress echo back
#endif
#endif

namespace tr_util
{

  suppress_echo_back::suppress_echo_back ()
  {
    if (n++ == 0)
      {
#ifdef HAVE_POSIX_SUPPRESS_ECHO_BACK
        struct termios tty;
        tcgetattr (STDIN_FILENO, &tty);
        tty.c_lflag &= ~ECHO;
        tcsetattr (STDIN_FILENO, TCSANOW, &tty);
#else
#ifdef HAVE_WINDOWS_SUPPRESS_ECHO_BACK
        HANDLE hStdin = GetStdHandle (STD_INPUT_HANDLE);
        DWORD dwMode;
        GetConsoleMode (hStdin, &dwMode);
        dwMode &= ~ENABLE_ECHO_INPUT;
        SetConsoleMode (hStdin, dwMode);
#endif
#endif
      }
  }

  suppress_echo_back::~suppress_echo_back ()
  {
    if (--n == 0)
      {
#ifdef HAVE_POSIX_SUPPRESS_ECHO_BACK
        struct termios tty;
        tcgetattr (STDIN_FILENO, &tty);
        tty.c_lflag |= ECHO;
        tcsetattr (STDIN_FILENO, TCSANOW, &tty);
#else
#ifdef HAVE_WINDOWS_SUPPRESS_ECHO_BACK
        HANDLE hStdin = GetStdHandle (STD_INPUT_HANDLE);
        DWORD dwMode;
        GetConsoleMode (hStdin, &dwMode);
        dwMode |=ENABLE_ECHO_INPUT;
        SetConsoleMode (hStdin, dwMode);
#endif
#endif
      }
  }

  std::atomic<int> suppress_echo_back::n {0};

};
