//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Parser/ParserUtils.h"

#include <boost/test/unit_test.hpp>
#include <string>
#include <variant>

using namespace jdme2x;
using namespace jdme2x::parser;

static void testInt(int ExpectedValue, std::string_view Text) {
  std::optional<Number> Value = parseNumber(Text);
  BOOST_TEST(Value.has_value());
  BOOST_TEST(!isFloat(*Value));
  BOOST_TEST(isInt(*Value));
  BOOST_TEST(ExpectedValue == toInt(*Value));
}

static void testFloat(float ExpectedValue, std::string_view Text) {
  std::optional<Number> Value = parseNumber(Text);
  BOOST_TEST(Value.has_value());
  BOOST_TEST(!isInt(*Value));
  BOOST_TEST(isFloat(*Value));
  BOOST_TEST(ExpectedValue == toFloat(*Value));
}

BOOST_AUTO_TEST_SUITE(ParserUtilsTest)

BOOST_AUTO_TEST_CASE(parseInt) {
  testInt(5, "5");
  testInt(-5, "-5");
  testInt(5, "+5");
}

BOOST_AUTO_TEST_CASE(parseFloat) {
  testFloat(5.05f, "5.05");
  testFloat(-5.05f, "-5.05");
  testFloat(-5.05f, "-5.05");
  testFloat(0.05f, ".05");
  testFloat(5e3f, "5e3");
  testFloat(5e3f, "5E3");
  testFloat(5e3f, "5E+3");
  testFloat(5e-3f, "5e-3");
  testFloat(5e-3f, "5E-3");
}

BOOST_AUTO_TEST_SUITE_END()
