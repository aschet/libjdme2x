//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/Error.h"
#include "jdme2x/Types/Errors.h"

#include "TestUtils.h"

#include <boost/test/unit_test.hpp>

using namespace jdme2x;

BOOST_AUTO_TEST_SUITE(ErrorTest)

BOOST_AUTO_TEST_CASE(serializeError) {
  BOOST_TEST(
      "! Error(3, 0008, \"Server::someMethod()\", \"Protocol error\")" ==
      test::toString(Error(errors::ProtocolError, "Server::someMethod()")));
}

BOOST_AUTO_TEST_SUITE_END()
