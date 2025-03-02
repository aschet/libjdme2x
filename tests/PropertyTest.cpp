//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Property.h"

#include <boost/test/unit_test.hpp>
#include <string>

using namespace jdme2x;

BOOST_AUTO_TEST_SUITE(PropertyTest)

BOOST_AUTO_TEST_CASE(serialzeProperty) {
  Property XProperty("X");
  std::string Result = XProperty.toString();
  BOOST_TEST("X()" == Result);

  Property YValueProperty("Y");
  Result = YValueProperty.addNumber(-100).toString();
  BOOST_TEST("Y(-100)" == Result);
}

BOOST_AUTO_TEST_SUITE_END()
