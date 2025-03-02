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

BOOST_AUTO_TEST_CASE(serialzeProperty) {
  Property XProperty("X");
  std::string Result = test::toString(XProperty);
  BOOST_TEST("X()" == Result);

  Property YValueProperty("Y");
  Result = test::toString(YValueProperty.addArgument(-100));
  BOOST_TEST("Y(-100)" == Result);

  Property TestProperty("Test");
  Result = test::toString(
      TestProperty.addArgument(-100).addArgument(0).addArgument(100));
  BOOST_TEST("Test(-100, 0, 100)" == Result);
}

BOOST_AUTO_TEST_SUITE_END()
