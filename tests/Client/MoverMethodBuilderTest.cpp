//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Client/MoverMethodBuilder.h"

#include <boost/test/unit_test.hpp>

using namespace jdme2x;

BOOST_AUTO_TEST_SUITE(MoverMethodBuilderTest)

BOOST_AUTO_TEST_CASE(buildEnableUser) {
  BOOST_TEST(Method("EnableUser") == MoverMethodBuilder::buildEnableUser());
}

BOOST_AUTO_TEST_CASE(buildDisableUser) {
  BOOST_TEST(Method("DisableUser") == MoverMethodBuilder::buildDisableUser());
}

BOOST_AUTO_TEST_CASE(buildIsUserEnabled) {
  BOOST_TEST(Method("IsUserEnabled") == MoverMethodBuilder::buildIsUserEnabled());
}

BOOST_AUTO_TEST_CASE(buildEnumerateMoverAxes) {
  BOOST_TEST(Method("EnumerateMoverAxes") ==
             MoverMethodBuilder::buildEnumerateMoverAxes());
}

BOOST_AUTO_TEST_CASE(buildUpdateScaleTemperatures) {
  BOOST_TEST(Method("UpdateScaleTemperatures") ==
             MoverMethodBuilder::buildUpdateScaleTemperatures());
}

BOOST_AUTO_TEST_SUITE_END()
