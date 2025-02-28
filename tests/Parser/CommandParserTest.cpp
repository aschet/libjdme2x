#include "jdme2x/Parser/CommandParser.h"

#include <boost/test/unit_test.hpp>

using namespace jdme2x;

BOOST_AUTO_TEST_SUITE(CommandParserTest)

BOOST_AUTO_TEST_CASE(parseCommand) {
  CommandParser Parser;
  BOOST_REQUIRE(Parser
                    .parse("00001 Test ( \"Ref Tool\"  , E0001, Time(5), XT.R.A( "
                           ") ,Roi(-5, .5,+5E7,5e-03) )\n\r")
                    .first);

  std::string GetDMEVersionText = "00001 GetDMEVersion()\n\r";
  BOOST_REQUIRE_EQUAL(GetDMEVersionText,
                      Parser.parse(GetDMEVersionText).second.toString());

  std::string AlignPartText = "00002 AlignPart(0, -1, 0, 0.6, 0, 0.8, 1)\n\r";
  BOOST_REQUIRE_EQUAL(AlignPartText,
                      Parser.parse(AlignPartText).second.toString());

  std::string OnMoveReportEText =
      "E0001 OnMoveReportE(Time(5), Dis(0.34), X(), Y(), Z())\n\r";
  BOOST_REQUIRE_EQUAL(OnMoveReportEText,
                      Parser.parse(OnMoveReportEText).second.toString());

  std::string ChangeToolText = "00003 ChangeTool(\"RefTool\")\n\r";
  BOOST_REQUIRE_EQUAL(ChangeToolText,
                      Parser.parse(ChangeToolText).second.toString());

  std::string SetCoordSystem = "00004 SetCoordSystem(23, PartCsy)\n\r";
  BOOST_REQUIRE_EQUAL(SetCoordSystem,
                      Parser.parse(SetCoordSystem).second.toString());
}

BOOST_AUTO_TEST_SUITE_END()
