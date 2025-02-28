#include "jdme2x/Parser/ResponseParser.h"

#include <boost/test/unit_test.hpp>

using namespace jdme2x;

BOOST_AUTO_TEST_SUITE(ResponseParserTest)

BOOST_AUTO_TEST_CASE(parseReponse) {
  ResponseParser Parser;

  BOOST_REQUIRE(Parser.parse("00005 &\n\r"));
  BOOST_REQUIRE(Parser.parse("00005 %\n\r"));
  BOOST_REQUIRE(Parser.parse("E0060 #X(0.35145), Y(0.70290), Z(1.05435)\n\r"));
  BOOST_REQUIRE(Parser.parse(
      "00070 ! Error(2, 0006, \"00070 GoTo(X(20.00000), Y(40.00000), "
      "Z(60.00000))\", \"Transaction aborted (Use ClearAllErrors to "
      "Continue)\")\n\r"));
  BOOST_REQUIRE(Parser.parse("00010 #0.6, 0., 0.8\n\r"));
  BOOST_REQUIRE(Parser.parse("00200 #ChangeToolAction(Switch, X(0.00000), "
                             "Y(0.00000), Z(-8.00000))\n\r"));
}

BOOST_AUTO_TEST_SUITE_END()
