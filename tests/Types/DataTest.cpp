//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/Data.h"
#include "TestUtils.h"

#include <boost/test/unit_test.hpp>

using namespace jdme2x::types;

BOOST_AUTO_TEST_SUITE(DataTest)

BOOST_AUTO_TEST_CASE(serialzePropertyData) {
  BOOST_TEST("\"GoToPar.Speed\", \"Number\"" ==
             test::toString(PropertyData("GoToPar.Speed", "Number")));
}

BOOST_AUTO_TEST_CASE(serialzePropertyList) {
  PropertyList Properties;
  Properties.emplace_back(Property("Y").addArgument(-0.77f));
  Properties.emplace_back(Property("X").addArgument(2.01f));
  BOOST_TEST("Y(-0.77), X(2.01)" == test::toString(Properties));
}

BOOST_AUTO_TEST_CASE(serialzeData) {
  Method ChangeToolAction("ChangeToolAction");
  ChangeToolAction.addArgument(Name("MoveAuto"))
      .addArgument(Property("X").addArgument(1))
      .addArgument(Property("Y").addArgument(2))
      .addArgument(Property("Z").addArgument(3));
  
  Data MethodData = std::move(ChangeToolAction);

  BOOST_TEST("ChangeToolAction(MoveAuto, X(1), Y(2), Z(3))" == test::toString(MethodData));
}

BOOST_AUTO_TEST_SUITE_END()
