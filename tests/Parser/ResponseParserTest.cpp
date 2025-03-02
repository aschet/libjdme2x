//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Parser/ResponseParser.h"

#include <boost/test/unit_test.hpp>

using namespace jdme2x::parser;

BOOST_AUTO_TEST_SUITE(ResponseParserTest)

BOOST_AUTO_TEST_CASE(parseReponse) {
  ResponseParser Parser;

  BOOST_TEST(Parser.parse("00005 &\r\n"));
  BOOST_TEST(Parser.parse("00005 %\r\n"));
  BOOST_TEST(Parser.parse("E0060 #X(0.35145), Y(0.70290), Z(1.05435)\r\n"));
  BOOST_TEST(Parser.parse(
      "00070 ! Error(2, 0006, \"00070 GoTo(X(20.00000), Y(40.00000), "
      "Z(60.00000))\", \"Transaction aborted (Use ClearAllErrors to "
      "Continue)\")\r\n"));
  BOOST_TEST(Parser.parse("00010 #0.6, 0., 0.8\r\n"));
  BOOST_TEST(Parser.parse("00200 #ChangeToolAction(Switch, X(0.00000), "
                             "Y(0.00000), Z(-8.00000))\r\n"));
}

BOOST_AUTO_TEST_SUITE_END()
