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
#include "jdme2x/Types/Error.h"
#include "jdme2x/Types/Errors.h"
#include "jdme2x/Types/Tag.h"

#include <boost/test/unit_test.hpp>
#include <string_view>

using namespace jdme2x::types;
using namespace jdme2x::parser;

static void testInt(int expectedValue, std::string_view text) {
  auto value = createNumber(text);
  BOOST_TEST(value.has_value());
  BOOST_TEST(holdsInt(*value));
  BOOST_TEST(expectedValue == getInt(*value));
}

static void testDouble(double expectedValue, std::string_view text) {
  auto value = createNumber(text);
  BOOST_TEST(value.has_value());
  BOOST_TEST(holdsDouble(*value));
  BOOST_TEST(expectedValue == getDouble(*value));
}

BOOST_AUTO_TEST_SUITE(ParserUtilsTest)

BOOST_AUTO_TEST_CASE(parseTag) {
  BOOST_TEST(Tag(123, TagType::Event) == *createTag("E0123"));
  BOOST_TEST(Tag(5, TagType::Command) == *createTag("00005"));
}

BOOST_AUTO_TEST_CASE(parseIntNumber) {
  testInt(5, "5");
  testInt(-5, "-5");
  testInt(5, "+5");
}

BOOST_AUTO_TEST_CASE(parseFloatNumber) {
  testDouble(5.05, "5.05");
  testDouble(-5.05, "-5.05");
  testDouble(-5.05, "-5.05");
  testDouble(0.05, ".05");
  testDouble(-0.05, "-.05");
  testDouble(0.05, "+.05");
  testDouble(5e3, "5e3");
  testDouble(5e3, "5E3");
  testDouble(5e3, "5E+3");
  testDouble(5e-3, "5e-3");
  testDouble(5e-3, "5E-3");
}

BOOST_AUTO_TEST_CASE(parseString) {
  BOOST_TEST("1.4" == createString("\"1.4\"")->value);
}

BOOST_AUTO_TEST_CASE(convertToError) {
  Error error(errors::BadContext, "Server::someMethod()");
  Method errorMethod = Method(ErrorName)
                           .with(static_cast<int>(error.severity))
                           .with(error.number)
                           .with(error.cause)
                           .with(error.information);
  BOOST_TEST(error == *createError(errorMethod));
}

BOOST_AUTO_TEST_CASE(convertToProperty) {
  Property property = Property("X").with(Number(-100));
  Method propertyMethod = Method(property.name).with(Number(-100));
  BOOST_TEST(property == *createProperty(propertyMethod));
}

BOOST_AUTO_TEST_SUITE_END()
