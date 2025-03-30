//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Client/ServerMethodBuilder.h"
#include "jdme2x/Types/Errors.h"

#include <boost/test/unit_test.hpp>

using namespace jdme2x;

BOOST_AUTO_TEST_SUITE(ServerMethodBuilderTest)

BOOST_AUTO_TEST_CASE(buildStartSession) {
  BOOST_TEST(Method("StartSession") ==
             ServerMethodBuilder::buildStartSession());
}

BOOST_AUTO_TEST_CASE(buildEndSession) {
  BOOST_TEST(Method("EndSession") == ServerMethodBuilder::buildEndSession());
}

BOOST_AUTO_TEST_CASE(buildStopDaemon) {
  BOOST_TEST(Method("StopDaemon").with(Name("E0001")) ==
             ServerMethodBuilder::buildStopDaemon(Tag(0001, TagType::Event)));
}

BOOST_AUTO_TEST_CASE(buildStopAllDaemons) {
  BOOST_TEST(Method("StopAllDaemons") ==
             ServerMethodBuilder::buildStopAllDaemons());
}

BOOST_AUTO_TEST_CASE(buildAbortE) {
  BOOST_TEST(Method("AbortE") == ServerMethodBuilder::buildAbortE());
}

BOOST_AUTO_TEST_CASE(buildGetErrorInfo) {
  BOOST_TEST(Method("GetErrorInfo").with(Name("0008")) ==
             ServerMethodBuilder::buildGetErrorInfo(8));
}

BOOST_AUTO_TEST_CASE(buildGetErrStatusE) {
  BOOST_TEST(Method("GetErrStatusE") ==
             ServerMethodBuilder::buildGetErrStatusE());
}

BOOST_AUTO_TEST_CASE(buildGetXtdErrStatus) {
  BOOST_TEST(Method("GetXtdErrStatus") ==
             ServerMethodBuilder::buildGetXtdErrStatus());
}

BOOST_AUTO_TEST_CASE(buildClearAllErrors) {
  BOOST_TEST(Method("ClearAllErrors") ==
             ServerMethodBuilder::buildClearAllErrors());
}

BOOST_AUTO_TEST_CASE(buildEnumNameSpaces) {
  BOOST_TEST(Method("EnumNameSpaces") ==
             ServerMethodBuilder::buildEnumNameSpaces());
}

BOOST_AUTO_TEST_CASE(buildSetProp) {
  Property property = Property("Tool.PtMeasPar.Accel").with(10);
  BOOST_TEST(Method("SetProp").with(property) ==
             ServerMethodBuilder::buildSetProp({property}));
}

BOOST_AUTO_TEST_CASE(buildGetProp) {
  Name name("Tool.PtMeasPar.Accel");
  BOOST_TEST(Method("GetProp").with(Property(name)) ==
             ServerMethodBuilder::buildGetProp({name}));
}

BOOST_AUTO_TEST_CASE(buildEnumProp) {
  Name name("Tool.PtMeasPar");
  BOOST_TEST(Method("EnumProp").with(Property(name)) ==
             ServerMethodBuilder::buildEnumProp(name));
}

BOOST_AUTO_TEST_CASE(buildEnumAllProp) {
  Name name("Tool.PtMeasPar");
  BOOST_TEST(Method("EnumAllProp").with(Property(name)) ==
             ServerMethodBuilder::buildEnumAllProp(name));
}

BOOST_AUTO_TEST_SUITE_END()
