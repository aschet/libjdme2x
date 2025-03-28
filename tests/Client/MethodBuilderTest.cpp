//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Client/MethodBuilder.h"
#include "jdme2x/MethodNames.h"

#include "jdme2x/Client/BasicClient.h"
#include "jdme2x/Server/BasicServer.h"
#include "jdme2x/Types/Errors.h"

#include <boost/test/unit_test.hpp>
#include <thread>

using namespace jdme2x;

BOOST_AUTO_TEST_SUITE(MethodBuilderTest)

BOOST_AUTO_TEST_CASE(buildStartSession) {
  BOOST_TEST(Method("StartSession") == MethodBuilder::buildStartSession());
}

BOOST_AUTO_TEST_CASE(buildEndSession) {
  BOOST_TEST(Method("EndSession") == MethodBuilder::buildEndSession());
}

BOOST_AUTO_TEST_CASE(buildStopDaemon) {
  BOOST_TEST(Method("StopDaemon").with(Name("E0001")) ==
             MethodBuilder::buildStopDaemon(Tag(0001, TagType::Event)));
}

BOOST_AUTO_TEST_CASE(buildStopAllDaemons) {
  BOOST_TEST(Method("StopAllDaemons") == MethodBuilder::buildStopAllDaemons());
}

BOOST_AUTO_TEST_CASE(buildAbortE) {
  BOOST_TEST(Method("AbortE") == MethodBuilder::buildAbortE());
}

BOOST_AUTO_TEST_CASE(buildGetErrorInfo) {
  BOOST_TEST(Method("GetErrorInfo").with(Name("0008")) ==
             MethodBuilder::buildGetErrorInfo(8));
}

BOOST_AUTO_TEST_CASE(buildGetErrStatusE) {
  BOOST_TEST(Method("GetErrStatusE") == MethodBuilder::buildGetErrStatusE());
}

BOOST_AUTO_TEST_CASE(buildGetXtdErrStatus) {
  BOOST_TEST(Method("GetXtdErrStatus") ==
             MethodBuilder::buildGetXtdErrStatus());
}

BOOST_AUTO_TEST_CASE(buildClearAllErrors) {
  BOOST_TEST(Method("ClearAllErrors") == MethodBuilder::buildClearAllErrors());
}

BOOST_AUTO_TEST_CASE(buildEnumNameSpaces) {
  BOOST_TEST(Method("EnumNameSpaces") == MethodBuilder::buildEnumNameSpaces());
}

BOOST_AUTO_TEST_CASE(buildSetProp) {
  Property property = Property("Tool.PtMeasPar.Accel").with(10);
  BOOST_TEST(Method("SetProp").with(property) ==
             MethodBuilder::buildSetProp({property}));
}

BOOST_AUTO_TEST_CASE(buildGetProp) {
  Name name("Tool.PtMeasPar.Accel");
  BOOST_TEST(Method("GetProp").with(Property(name)) ==
             MethodBuilder::buildGetProp({name}));
}

BOOST_AUTO_TEST_CASE(buildEnumProp) {
  Name name("Tool.PtMeasPar");
  BOOST_TEST(Method("EnumProp").with(Property(name)) ==
             MethodBuilder::buildEnumProp(name));
}

BOOST_AUTO_TEST_CASE(buildEnumAllProp) {
  Name name("Tool.PtMeasPar");
  BOOST_TEST(Method("EnumAllProp").with(Property(name)) ==
             MethodBuilder::buildEnumAllProp(name));
}

BOOST_AUTO_TEST_CASE(buildGetDMEVersion) {
  BOOST_TEST(Method("GetDMEVersion") == MethodBuilder::buildGetDMEVersion());
}

BOOST_AUTO_TEST_CASE(buildGetSupportedCommands) {
  BOOST_TEST(Method("GetSupportedCommands") ==
             MethodBuilder::buildGetSupportedCommands());
}

BOOST_AUTO_TEST_CASE(buildGetSupportedArguments) {
  BOOST_TEST(Method("GetSupportedArguments") ==
             MethodBuilder::buildGetSupportedArguments());
}

BOOST_AUTO_TEST_CASE(buildGetMachineClass) {
  BOOST_TEST(Method("GetMachineClass") ==
             MethodBuilder::buildGetMachineClass());
}

BOOST_AUTO_TEST_CASE(buildHome) {
  BOOST_TEST(Method("Home") == MethodBuilder::buildHome());
}

BOOST_AUTO_TEST_CASE(buildIsHomed) {
  BOOST_TEST(Method("IsHomed") == MethodBuilder::buildIsHomed());
}

BOOST_AUTO_TEST_CASE(buildSetCoordSystem) {
  BOOST_TEST(Method("SetCoordSystem").with(String("MachineCsy")) ==
             MethodBuilder::buildSetCoordSystem(CoordSystem::MachineCsy));
}

BOOST_AUTO_TEST_CASE(buildGetCoordSystem) {
  BOOST_TEST(Method("GetCoordSystem") == MethodBuilder::buildGetCoordSystem());
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
             MethodBuilder::buildSetCsyTransformation(
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
             MethodBuilder::buildSaveNamedCsyTransformation(
                 String("Custom"), 0.0, 1.0, 2.0, 3.0, 4.0, 5.0));
}

BOOST_AUTO_TEST_CASE(buildGetNamedCsyTransformation) {
  BOOST_TEST(Method("GetNamedCsyTransformation").with(String("Custom")) ==
             MethodBuilder::buildGetNamedCsyTransformation(String("Custom")));
}

BOOST_AUTO_TEST_CASE(buildGetCsyTransformation) {
  BOOST_TEST(Method("GetCsyTransformation").with(String("SensorCsy")) ==
             MethodBuilder::buildGetCsyTransformation(CoordSystem::SensorCsy));
}

BOOST_AUTO_TEST_CASE(buildSaveActiveCoordSystem) {
  BOOST_TEST(Method("SaveActiveCoordSystem").with(String("Custom")) ==
             MethodBuilder::buildSaveActiveCoordSystem(String("Custom")));
}

BOOST_AUTO_TEST_CASE(buildLoadCoordSystem) {
  BOOST_TEST(Method("LoadCoordSystem").with(String("Custom")) ==
             MethodBuilder::buildLoadCoordSystem(String("Custom")));
}

BOOST_AUTO_TEST_CASE(buildDeleteCoordSystem) {
  BOOST_TEST(Method("DeleteCoordSystem").with(String("Custom")) ==
             MethodBuilder::buildDeleteCoordSystem(String("Custom")));
}

BOOST_AUTO_TEST_CASE(buildEnumCoordSystems) {
  BOOST_TEST(Method("EnumCoordSystems") ==
             MethodBuilder::buildEnumCoordSystems());
}

BOOST_AUTO_TEST_CASE(buildGetTemperatureSensors) {
  BOOST_TEST(Method("GetTemperatureSensors") ==
             MethodBuilder::buildGetTemperatureSensors());
}

BOOST_AUTO_TEST_CASE(buildReadTemperatureSensor) {
  BOOST_TEST(Method("ReadTemperatureSensor").with(String("Axis0")) ==
             MethodBuilder::buildReadTemperatureSensor(String("Axis0")));
}

BOOST_AUTO_TEST_CASE(buildReadAllTemperatures) {
  BOOST_TEST(Method("ReadAllTemperatures") ==
             MethodBuilder::buildReadAllTemperatures());
}

BOOST_AUTO_TEST_CASE(buildCenterPart) {
  BOOST_TEST(Method("CenterPart")
                 .with(Number(0.0))
                 .with(Number(1.0))
                 .with(Number(2.0))
                 .with(Number(3.0)) ==
             MethodBuilder::buildCenterPart(0.0, 1.0, 2.0, 3.0));
}

BOOST_AUTO_TEST_CASE(buildTiltPart) {
  BOOST_TEST(Method("TiltPart")
                 .with(Number(0.0))
                 .with(Number(1.0))
                 .with(Number(2.0))
                 .with(Number(3.0)) ==
             MethodBuilder::buildTiltPart(0.0, 1.0, 2.0, 3.0));
}

BOOST_AUTO_TEST_CASE(buildTiltCenterPart) {
  BOOST_TEST(Method("TiltCenterPart")
                 .with(Number(0.0))
                 .with(Number(1.0))
                 .with(Number(2.0))
                 .with(Number(3.0))
                 .with(Number(4.0))
                 .with(Number(5.0))
                 .with(Number(6.0)) == MethodBuilder::buildTiltCenterPart(
                                           0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0));
}

BOOST_AUTO_TEST_CASE(buildEnableUser) {
  BOOST_TEST(Method("EnableUser") == MethodBuilder::buildEnableUser());
}

BOOST_AUTO_TEST_CASE(buildDisableUser) {
  BOOST_TEST(Method("DisableUser") == MethodBuilder::buildDisableUser());
}

BOOST_AUTO_TEST_CASE(buildIsUserEnabled) {
  BOOST_TEST(Method("IsUserEnabled") == MethodBuilder::buildIsUserEnabled());
}

BOOST_AUTO_TEST_CASE(buildEnumerateMoverAxes) {
  BOOST_TEST(Method("EnumerateMoverAxes") ==
             MethodBuilder::buildEnumerateMoverAxes());
}

BOOST_AUTO_TEST_CASE(buildUpdateScaleTemperatures) {
  BOOST_TEST(Method("UpdateScaleTemperatures") ==
             MethodBuilder::buildUpdateScaleTemperatures());
}

BOOST_AUTO_TEST_CASE(clientTest) {
  BasicClient client("localhost");
  client.send(Tag(1, TagType::Command), MethodBuilder::buildStartSession());
  client.send(Tag(2, TagType::Command), MethodBuilder::buildIsHomed());
  client.send(Tag(3, TagType::Command), MethodBuilder::buildEndSession());
  std::this_thread::sleep_for(std::chrono::seconds(5));
}

BOOST_AUTO_TEST_CASE(serverTest) {
  BasicServer server;
  server.setCommandHandler([&server](Command &&command) {
    server.sendAcknowledge(command.tag);
    server.sendError(command.tag, Error(errors::BufferFull, "serverTest"));
    server.sendDone(command.tag);
  });
  server.start();
}

BOOST_AUTO_TEST_SUITE_END()
