//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/Argument.h"
#include "TestUtils.h"

#include <boost/test/unit_test.hpp>

using namespace jdme2x::types;

BOOST_AUTO_TEST_SUITE(ArgumentTest)

BOOST_AUTO_TEST_CASE(serializArgument) {
  BOOST_TEST(test::toString(Argument(String("RefTool"))) == "\"RefTool\"");
  BOOST_TEST(test::toString(Argument(Name("PartCsy"))) == "PartCsy");
  BOOST_TEST(test::toString(Argument(Number(1))) == "1");
  BOOST_TEST(test::toString(Argument(Tag::createUnsolicitedEvent())) ==
             "E0000");
  BOOST_TEST(test::toString(Property("X")) == "X()");
}

BOOST_AUTO_TEST_SUITE_END()
