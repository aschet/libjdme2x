//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/Property.h"

#include "TestUtils.h"

#include <boost/test/unit_test.hpp>
#include <string>

using namespace jdme2x;

BOOST_AUTO_TEST_SUITE(PropertyTest)

BOOST_AUTO_TEST_CASE(serializeProperty) {
  BOOST_TEST("X()" == toString(Property("X")));
  BOOST_TEST("Y(-100)" == toString(Property("Y").with(Number(-100))));
  BOOST_TEST("Test(-100, 0, 100)" == toString(Property("Test")
                                                        .with(Number(-100))
                                                        .with(Number(0))
                                                        .with(Number(100))));
}

BOOST_AUTO_TEST_SUITE_END()
