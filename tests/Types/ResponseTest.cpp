//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/Response.h"
#include "jdme2x/Types/Errors.h"

#include "TestUtils.h"

#include <boost/test/unit_test.hpp>
#include <string>

using namespace jdme2x::types;

BOOST_AUTO_TEST_SUITE(ResponseTest)

BOOST_AUTO_TEST_CASE(serializeAcknowledgeResponse) {
  Response response(Tag(1, TagType::Command), Acknowledge());
  BOOST_TEST(response.holdsAcknowledge());
  BOOST_TEST("00001 &\r\n" == test::toString(response));
}

BOOST_AUTO_TEST_CASE(serializeDataResponse) {
  Response response(Tag(1, TagType::Command),
                    NumericalData{Number(12), Number(13)});
  BOOST_TEST(response.holdsData());
  BOOST_TEST("00001 # 12, 13\r\n" == test::toString(response));
  response.data();
}

BOOST_AUTO_TEST_CASE(serializeDoneResponse) {
  Response response(Tag(1, TagType::Command), Done());
  BOOST_TEST(response.holdsDone());
  BOOST_TEST("00001 %\r\n" == test::toString(response));
}

BOOST_AUTO_TEST_CASE(serializeErrorResponse) {
  Response response(Tag(1, TagType::Command),
                    Error(errors::AxisDoesNotExist, "Test::Test()"));
  BOOST_TEST(response.holdsError());
  BOOST_TEST(
      "00001 ! Error(9, 1002, \"Test::Test()\", \"Axis does not exist\")\r\n" ==
      test::toString(response));
  response.error();
}

BOOST_AUTO_TEST_SUITE_END()
