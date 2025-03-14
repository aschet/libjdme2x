//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/Number.h"

#include "TestUtils.h"

#include <boost/test/unit_test.hpp>

using namespace jdme2x::types;

BOOST_AUTO_TEST_SUITE(NumberTest)

BOOST_AUTO_TEST_CASE(serializeNumber) {
  BOOST_TEST("-1" == test::toString(Number(-1)));
  BOOST_TEST("1" == test::toString(Number(1)));
  BOOST_TEST("1.5" == test::toString(Number(1.5)));
  BOOST_TEST("-1.5" == test::toString(Number(-1.5)));
}

BOOST_AUTO_TEST_CASE(queryNumberType) {
  BOOST_TEST(holdsInt(Number(-1)));
  BOOST_TEST(holdsDouble(Number(1.5)));
}

BOOST_AUTO_TEST_CASE(castNumber) {
  BOOST_TEST(-1 == getInt(Number(-1)));
  BOOST_TEST(-1.0f == getDouble(Number(-1)));
  BOOST_TEST(-1 == getInt(Number(-1.5)));
  BOOST_TEST(-1.5f == getDouble(Number(-1.5)));
  BOOST_TEST(true == getBool(Number(1)));
  BOOST_TEST(false == getBool(Number(0)));
}

BOOST_AUTO_TEST_SUITE_END()
