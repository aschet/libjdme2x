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

using namespace jdme2x;
using namespace jdme2x::types;

BOOST_AUTO_TEST_SUITE(NumberTest)

BOOST_AUTO_TEST_CASE(serialzeNumber) {
  BOOST_TEST("-1" == toString(Number(-1)));
  BOOST_TEST("1" == toString(Number(1)));
  BOOST_TEST("1.5" == toString(Number(1.5f)));
  BOOST_TEST("-1.5" == toString(Number(-1.5f)));
}

BOOST_AUTO_TEST_CASE(queryNumberType) {
  BOOST_TEST(isInt(Number(-1)));
  BOOST_TEST(isFloat(Number(1.5f)));
}

BOOST_AUTO_TEST_CASE(castNumber) {
  BOOST_TEST(-1 == toInt(Number(-1)));
  BOOST_TEST(-1.0f == toFloat(Number(-1)));
  BOOST_TEST(-1 == toInt(Number(-1.5f)));
  BOOST_TEST(-1.5f == toFloat(Number(-1.5f)));
  BOOST_TEST(true == toBool(Number(1)));
  BOOST_TEST(false == toBool(Number(0)));
}

BOOST_AUTO_TEST_SUITE_END()
