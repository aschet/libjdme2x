//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Client/CartCMMMethodBuilder.h"

#include <boost/test/unit_test.hpp>

using namespace jdme2x;

BOOST_AUTO_TEST_SUITE(CartCMMMethodBuilderTest)

BOOST_AUTO_TEST_CASE(buildSetCoordSystem) {
  BOOST_TEST(
      Method("SetCoordSystem").with(String("MachineCsy")) ==
      CartCMMMethodBuilder::buildSetCoordSystem(CoordSystem::MachineCsy));
}

BOOST_AUTO_TEST_CASE(buildGetCoordSystem) {
  BOOST_TEST(Method("GetCoordSystem") ==
             CartCMMMethodBuilder::buildGetCoordSystem());
}

BOOST_AUTO_TEST_CASE(buildSetCsyTransformation) {
  BOOST_TEST(Method("SetCsyTransformation")
                 .with(String("SensorCsy"))
                 .with(Number(0.0))
                 .with(Number(1.0))
                 .with(Number(2.0))
                 .with(Number(3.0))
                 .with(Number(4.0))
                 .with(Number(5.0)) ==
             CartCMMMethodBuilder::buildSetCsyTransformation(
                 CoordSystem::SensorCsy, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0));
}

BOOST_AUTO_TEST_CASE(buildSaveNamedCsyTransformation) {
  BOOST_TEST(Method("SaveNamedCsyTransformation")
                 .with(String("Custom"))
                 .with(Number(0.0))
                 .with(Number(1.0))
                 .with(Number(2.0))
                 .with(Number(3.0))
                 .with(Number(4.0))
                 .with(Number(5.0)) ==
             CartCMMMethodBuilder::buildSaveNamedCsyTransformation(
                 String("Custom"), 0.0, 1.0, 2.0, 3.0, 4.0, 5.0));
}

BOOST_AUTO_TEST_CASE(buildGetNamedCsyTransformation) {
  BOOST_TEST(
      Method("GetNamedCsyTransformation").with(String("Custom")) ==
      CartCMMMethodBuilder::buildGetNamedCsyTransformation(String("Custom")));
}

BOOST_AUTO_TEST_CASE(buildGetCsyTransformation) {
  BOOST_TEST(
      Method("GetCsyTransformation").with(String("SensorCsy")) ==
      CartCMMMethodBuilder::buildGetCsyTransformation(CoordSystem::SensorCsy));
}

BOOST_AUTO_TEST_CASE(buildSaveActiveCoordSystem) {
  BOOST_TEST(
      Method("SaveActiveCoordSystem").with(String("Custom")) ==
      CartCMMMethodBuilder::buildSaveActiveCoordSystem(String("Custom")));
}

BOOST_AUTO_TEST_CASE(buildLoadCoordSystem) {
  BOOST_TEST(Method("LoadCoordSystem").with(String("Custom")) ==
             CartCMMMethodBuilder::buildLoadCoordSystem(String("Custom")));
}

BOOST_AUTO_TEST_CASE(buildDeleteCoordSystem) {
  BOOST_TEST(Method("DeleteCoordSystem").with(String("Custom")) ==
             CartCMMMethodBuilder::buildDeleteCoordSystem(String("Custom")));
}

BOOST_AUTO_TEST_CASE(buildEnumCoordSystems) {
  BOOST_TEST(Method("EnumCoordSystems") ==
             CartCMMMethodBuilder::buildEnumCoordSystems());
}

BOOST_AUTO_TEST_CASE(buildGetTemperatureSensors) {
  BOOST_TEST(Method("GetTemperatureSensors") ==
             CartCMMMethodBuilder::buildGetTemperatureSensors());
}

BOOST_AUTO_TEST_CASE(buildReadTemperatureSensor) {
  BOOST_TEST(Method("ReadTemperatureSensor").with(String("Axis0")) ==
             CartCMMMethodBuilder::buildReadTemperatureSensor(String("Axis0")));
}

BOOST_AUTO_TEST_CASE(buildReadAllTemperatures) {
  BOOST_TEST(Method("ReadAllTemperatures") ==
             CartCMMMethodBuilder::buildReadAllTemperatures());
}

BOOST_AUTO_TEST_SUITE_END()
