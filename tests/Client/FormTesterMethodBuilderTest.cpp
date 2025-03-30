//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Client/FormTesterMethodBuilder.h"

#include <boost/test/unit_test.hpp>

using namespace jdme2x;

BOOST_AUTO_TEST_SUITE(FormTesterMethodBuilderTest)

BOOST_AUTO_TEST_CASE(buildCenterPart) {
  BOOST_TEST(Method("CenterPart")
                 .with(Number(0.0))
                 .with(Number(1.0))
                 .with(Number(2.0))
                 .with(Number(3.0)) ==
             FormTesterMethodBuilder::buildCenterPart(0.0, 1.0, 2.0, 3.0));
}

BOOST_AUTO_TEST_CASE(buildTiltPart) {
  BOOST_TEST(Method("TiltPart")
                 .with(Number(0.0))
                 .with(Number(1.0))
                 .with(Number(2.0))
                 .with(Number(3.0)) ==
             FormTesterMethodBuilder::buildTiltPart(0.0, 1.0, 2.0, 3.0));
}

BOOST_AUTO_TEST_CASE(buildTiltCenterPart) {
  BOOST_TEST(Method("TiltCenterPart")
                 .with(Number(0.0))
                 .with(Number(1.0))
                 .with(Number(2.0))
                 .with(Number(3.0))
                 .with(Number(4.0))
                 .with(Number(5.0))
                 .with(Number(6.0)) ==
             FormTesterMethodBuilder::buildTiltCenterPart(0.0, 1.0, 2.0, 3.0,
                                                          4.0, 5.0, 6.0));
}

BOOST_AUTO_TEST_CASE(buildLockAxis) {
  BOOST_TEST(Method("LockAxis").with(Property("X")).with(Property("R")) ==
             FormTesterMethodBuilder::buildLockAxis(true, false, false, true,
                                                    false, false, false));
}

BOOST_AUTO_TEST_CASE(buildLockPosition) {
  BOOST_TEST(
      Method("LockPosition").with(Property("RFR")).with(Property("PFR")) ==
      FormTesterMethodBuilder::buildLockPosition(false, false, false, true,
                                                 true));
}

BOOST_AUTO_TEST_SUITE_END()
