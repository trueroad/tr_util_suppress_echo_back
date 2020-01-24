//
// Suppress echo back utility
// https://github.com/trueroad/tr_util_suppress_echo_back
//
// sample.cc:
//   Sample for tr_util::suppress_echo_back utility
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

#include <iostream>
#include <string>

#include "tr_util_suppress_echo_back.hh"

int main ()
{
  std::string str;

  std::cout << "normal: " << std::flush;
  std::getline (std::cin, str);

  std::cout << "input = \"" << str << "\"" << std::endl;

  std::cout << "suppress echo back: " << std::flush;
  {
    tr_util::suppress_echo_back seb;
    std::getline (std::cin, str);

    std::cout << std::endl << "input = \"" << str << "\"" << std::endl;

    std::cout << "suppress echo back (nested): " << std::flush;
    {
      tr_util::suppress_echo_back seb_nested;
      std::getline (std::cin, str);
    }
    std::cout << std::endl << "input = \"" << str << "\"" << std::endl;

    std::cout << "suppress echo back: " << std::flush;
    std::getline (std::cin, str);
  }
  std::cout << std::endl << "input = \"" << str << "\"" << std::endl;

  std::cout << "normal: " << std::flush;
  std::getline (std::cin, str);

  std::cout << "input = \"" << str << "\"" << std::endl;

  return 0;
}
