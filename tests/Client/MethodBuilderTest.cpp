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

#include <boost/test/unit_test.hpp>

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

BOOST_AUTO_TEST_SUITE_END()
