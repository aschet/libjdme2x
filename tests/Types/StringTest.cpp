//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/String.h"
#include "TestUtils.h"

#include <boost/test/unit_test.hpp>

#include <iostream>

using namespace jdme2x;
using namespace jdme2x::types;

BOOST_AUTO_TEST_SUITE(StringTest)

BOOST_AUTO_TEST_CASE(serialzeString) {
  BOOST_TEST("\"1.4\"" == toString(String("1.4")));
}

BOOST_AUTO_TEST_CASE(constructString) {
  BOOST_TEST(String("1.4") == "1.4");
  BOOST_TEST(String("\"1.4\"") == "1.4");
}

BOOST_AUTO_TEST_SUITE_END()
