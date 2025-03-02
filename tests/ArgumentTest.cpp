//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Argument.h"

#include <boost/test/unit_test.hpp>

using namespace jdme2x;

BOOST_AUTO_TEST_SUITE(ArgumentTest)

BOOST_AUTO_TEST_CASE(serializeBasicArgument) {
  BOOST_TEST("\"RefTool\"" == StringArgument("RefTool").toString());
  BOOST_TEST("PartCsy" == NameArgument("PartCsy").toString());
}

BOOST_AUTO_TEST_SUITE_END()
