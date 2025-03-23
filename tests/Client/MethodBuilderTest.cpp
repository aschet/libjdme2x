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
    server.send(Response(command.tag, Acknowledge()));
    server.send(Response(command.tag, Error(errors::BufferFull, "serverTest")));
    server.send(Response(command.tag, Done()));
  });
  server.start();
}

BOOST_AUTO_TEST_SUITE_END()
