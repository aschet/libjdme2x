//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/Name.h"

#include "TestUtils.h"

#include <boost/test/unit_test.hpp>

using namespace jdme2x;

BOOST_AUTO_TEST_SUITE(NameTest)

BOOST_AUTO_TEST_CASE(serializeName) {
  BOOST_TEST(test::toString(Name("AbortE")) == "AbortE");
}

BOOST_AUTO_TEST_CASE(checkBasicName) {
  BOOST_TEST(Name("AbortE").isBasic());
  BOOST_TEST(!Name("GoToPar.Speed").isBasic());
}

BOOST_AUTO_TEST_SUITE_END()
