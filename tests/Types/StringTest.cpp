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

using namespace jdme2x::types;

BOOST_AUTO_TEST_SUITE(StringTest)

BOOST_AUTO_TEST_CASE(serializeString) {
  BOOST_TEST("\"1.4\"" == test::toString(String("1.4")));
}

BOOST_AUTO_TEST_SUITE_END()
