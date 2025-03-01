//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Parser/CommandParser.h"

#include <boost/test/unit_test.hpp>

using namespace jdme2x::parser;

BOOST_AUTO_TEST_SUITE(CommandParserTest)

BOOST_AUTO_TEST_CASE(parseCommand) {
  CommandParser Parser;
  BOOST_TEST(Parser
                 .parse("00001 Test ( \"Ref Tool\"  , E0001, Time(5), XT.R.A( "
                        ") ,Roi(-5, .5,+5E7,5e-03) )\n\r")
                 .first);

  std::string GetDMEVersionText = "00001 GetDMEVersion()\n\r";
  BOOST_TEST(GetDMEVersionText ==
             Parser.parse(GetDMEVersionText).second.toString());

  std::string AlignPartText = "00002 AlignPart(0, -1, 0, 0.6, 0, 0.8, 1)\n\r";
  BOOST_TEST(AlignPartText == Parser.parse(AlignPartText).second.toString());

  std::string OnMoveReportEText =
      "E0001 OnMoveReportE(Time(5), Dis(0.34), X(), Y(), Z())\n\r";
  BOOST_TEST(OnMoveReportEText ==
             Parser.parse(OnMoveReportEText).second.toString());

  std::string ChangeToolText = "00003 ChangeTool(\"RefTool\")\n\r";
  BOOST_TEST(ChangeToolText == Parser.parse(ChangeToolText).second.toString());

  std::string SetCoordSystem = "00004 SetCoordSystem(23, PartCsy)\n\r";
  BOOST_TEST(SetCoordSystem == Parser.parse(SetCoordSystem).second.toString());
}

BOOST_AUTO_TEST_SUITE_END()
