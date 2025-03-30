//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Client/DMEMethodBuilder.h"

#include <boost/test/unit_test.hpp>

using namespace jdme2x;

BOOST_AUTO_TEST_SUITE(DMEMethodBuilderTest)

BOOST_AUTO_TEST_CASE(buildGetDMEVersion) {
  BOOST_TEST(Method("GetDMEVersion") == DMEMethodBuilder::buildGetDMEVersion());
}

BOOST_AUTO_TEST_CASE(buildGetSupportedCommands) {
  BOOST_TEST(Method("GetSupportedCommands") ==
             DMEMethodBuilder::buildGetSupportedCommands());
}

BOOST_AUTO_TEST_CASE(buildGetSupportedArguments) {
  BOOST_TEST(Method("GetSupportedArguments") ==
             DMEMethodBuilder::buildGetSupportedArguments());
}

BOOST_AUTO_TEST_CASE(buildGetMachineClass) {
  BOOST_TEST(Method("GetMachineClass") ==
             DMEMethodBuilder::buildGetMachineClass());
}

BOOST_AUTO_TEST_CASE(buildHome) {
  BOOST_TEST(Method("Home") == DMEMethodBuilder::buildHome());
}

BOOST_AUTO_TEST_CASE(buildIsHomed) {
  BOOST_TEST(Method("IsHomed") == DMEMethodBuilder::buildIsHomed());
}

BOOST_AUTO_TEST_SUITE_END()
