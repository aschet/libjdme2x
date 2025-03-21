//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Parser/MethodParser.h"
#include "TestUtils.h"

#include <boost/test/unit_test.hpp>

using namespace jdme2x;

BOOST_AUTO_TEST_SUITE(MethodParserTest)

BOOST_AUTO_TEST_CASE(parseMethod) {
  MethodParser parser;

  Method getDMEVersion("GetDMEVersion");
  BOOST_TEST(getDMEVersion == parser.parse("GetDMEVersion()").second);

  Method alignPart = Method("AlignPart")
                         .with(Number(0))
                         .with(Number(-1))
                         .with(Number(0))
                         .with(Number(0.6))
                         .with(Number(0))
                         .with(Number(0.8))
                         .with(Number(1));
  BOOST_TEST(alignPart ==
             parser.parse("AlignPart(0, -1, 0, 0.6, 0, 0.8, 1)").second);

  Method onMoveReportE = Method("OnMoveReportE")
                             .with(Property("Time").with(Number(5)))
                             .with(Property("Dis").with(Number(0.34)))
                             .with(Property("X"))
                             .with(Property("Y"))
                             .with(Property("Z"));
  BOOST_TEST(
      onMoveReportE ==
      parser.parse("OnMoveReportE(Time(5), Dis(0.34), X(), Y(), Z())").second);

  Method changeTool = Method("ChangeTool").with(String("RefTool"));
  BOOST_TEST(changeTool == parser.parse("ChangeTool(\"RefTool\")").second);

  Method setCoordSystem(Method("SetCoordSystem").with(Name("PartCsy")));
  BOOST_TEST(setCoordSystem == parser.parse("SetCoordSystem(PartCsy)").second);

  Method methodWithXML = Method("TestE").withXML("<x><y a=\"b\">z</y></x>");
  BOOST_TEST(methodWithXML ==
             parser.parse("TestE(<x><y a=\"b\">z</y></x>)").second);
}

BOOST_AUTO_TEST_SUITE_END()
