//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Parser/ResponseParser.h"
#include "jdme2x/Types/Response.h"

#include <boost/test/unit_test.hpp>

using namespace jdme2x::parser;
using namespace jdme2x::types;

BOOST_AUTO_TEST_SUITE(ResponseParserTest)

BOOST_AUTO_TEST_CASE(parseAcknowledgeReponse) {
  ResponseParser parser;
  BOOST_TEST(Response(Tag(5, TagType::Command), Acknowledge()) ==
             parser.parse("00005 &\r\n").second);
}

BOOST_AUTO_TEST_CASE(parseDoneReponse) {
  ResponseParser parser;
  BOOST_TEST(Response(Tag(5, TagType::Command), Done()) ==
             parser.parse("00005 %\r\n").second);
}

BOOST_AUTO_TEST_CASE(parseErrorReponse) {
  ResponseParser parser;
  Response errorResponse(
      Tag(70, TagType::Command),
      Error(ErrorSeverity::Error, 6,
            String("00070 GoTo(X(20.00000), Y(40.00000), Z(60.00000))"),
            String("Transaction aborted (Use ClearAllErrors to Continue)")));
  BOOST_TEST(
      errorResponse ==
      parser
          .parse(
              "00070 ! Error(2, 0006, \"00070 GoTo(X(20.00000), Y(40.00000), "
              "Z(60.00000))\", \"Transaction aborted (Use ClearAllErrors to "
              "Continue)\")\r\n")
          .second);
}

BOOST_AUTO_TEST_CASE(parseNumericDataResponse) {
  ResponseParser parser;
  Response dataResponse(Tag(10, TagType::Command),
                        NumericalData{0.6f, 0.0f, 0.8f});
  BOOST_TEST(dataResponse == parser.parse("00010 # 0.6, 0., 0.8\r\n").second);
}

BOOST_AUTO_TEST_CASE(parsePropertyListDataResponse) {
  ResponseParser parser;
  Response dataResponse(Tag(60, TagType::Event),
                        PropertyList{Property("X").with(0.35145f),
                                     Property("Y").with(0.70290f),
                                     Property("Z").with(1.05435f)});
  BOOST_TEST(
      dataResponse ==
      parser.parse("E0060 # X(0.35145), Y(0.70290), Z(1.05435)\r\n").second);
}

BOOST_AUTO_TEST_CASE(parseMethodDataResponse) {
  ResponseParser parser;
  Response dataResponse(Tag(200, TagType::Command),
                        Method("ChangeToolAction")
                            .with(Name("Switch"))
                            .with(Property("X").with(0.0f))
                            .with(Property("Y").with(0.0f))
                            .with(Property("Z").with(-8.0f)));
  BOOST_TEST(dataResponse ==
             parser
                 .parse("00200 #ChangeToolAction(Switch, X(0.00000), "
                        "Y(0.00000), Z(-8.00000))\r\n")
                 .second);
}

BOOST_AUTO_TEST_CASE(parsePropertyDataResponse) {
  ResponseParser parser;
  Response dataResponse(Tag(10, TagType::Command),
                        PropertyData("GoToPar.Speed.Def", String("Number")));
  BOOST_TEST(
      dataResponse ==
      parser.parse("00010 # \"GoToPar.Speed.Def\", \"Number\"\r\n").second);
}

BOOST_AUTO_TEST_SUITE_END()
