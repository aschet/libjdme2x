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
#include "jdme2x/Types/Number.h"
#include "jdme2x/Types/Property.h"
#include "jdme2x/Types/String.h"

#include "TestUtils.h"

#include <boost/test/unit_test.hpp>

using namespace jdme2x;

BOOST_AUTO_TEST_SUITE(ArgumentTest)

BOOST_AUTO_TEST_CASE(serializArgument) {
  BOOST_TEST("\"RefTool\"" == toString(Argument(String("RefTool"))));
  BOOST_TEST("PartCsy" == toString(Argument(Name("PartCsy"))));
  BOOST_TEST("1" == toString(Argument(Number(1))));
  BOOST_TEST("E0000" == toString(Argument(UnsolicitedEvent)));
  BOOST_TEST("X()" == toString(Property("X")));
}

BOOST_AUTO_TEST_SUITE_END()
