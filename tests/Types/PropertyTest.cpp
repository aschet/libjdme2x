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

using namespace jdme2x::types;

BOOST_AUTO_TEST_SUITE(PropertyTest)

BOOST_AUTO_TEST_CASE(serializeProperty) {
  BOOST_TEST("X()" == test::toString(Property("X")));
  BOOST_TEST("Y(-100)" == test::toString(Property("Y").with(-100)));
  BOOST_TEST("Test(-100, 0, 100)" ==
             test::toString(Property("Test").with(-100).with(0).with(100)));
}

BOOST_AUTO_TEST_SUITE_END()
