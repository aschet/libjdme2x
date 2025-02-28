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
#include "jdme2x/Types/Property.h"
#include "jdme2x/Types/Method.h"
#include "jdme2x/Types/Name.h"

#include "TestUtils.h"

#include <boost/test/unit_test.hpp>

using namespace jdme2x::types;

BOOST_AUTO_TEST_SUITE(DataTest)

BOOST_AUTO_TEST_CASE(serializePropertyData) {
  BOOST_TEST("\"GoToPar.Speed\", \"Number\"" ==
             test::toString(PropertyData("GoToPar.Speed", "Number")));
}

BOOST_AUTO_TEST_CASE(serializePropertyList) {
  PropertyList properties = {Property("Y").with(-0.77f),
                             Property("X").with(2.01f)};
  BOOST_TEST("Y(-0.77), X(2.01)" == test::toString(properties));
}

BOOST_AUTO_TEST_CASE(serializeData) {
  Method changeToolAction("ChangeToolAction");
  changeToolAction.with(Name("MoveAuto"))
      .with(Property("X").with(1))
      .with(Property("Y").with(2))
      .with(Property("Z").with(3));
  BOOST_TEST("# ChangeToolAction(MoveAuto, X(1), Y(2), Z(3))" ==
             test::toString(Data(changeToolAction)));
}

BOOST_AUTO_TEST_SUITE_END()
