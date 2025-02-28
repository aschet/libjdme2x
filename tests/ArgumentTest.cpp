#include "jdme2x/Argument.h"

#include <boost/test/unit_test.hpp>

using namespace jdme2x;

BOOST_AUTO_TEST_SUITE(ArgumentTest)

BOOST_AUTO_TEST_CASE(serializeBasicArgument) {
  BOOST_REQUIRE_EQUAL("-1", IntArgument(-1).toString());
  BOOST_REQUIRE_EQUAL("1", IntArgument(1).toString());
  BOOST_REQUIRE_EQUAL("1.5", FloatArgument(1.5).toString());
  BOOST_REQUIRE_EQUAL("-1.5", FloatArgument(-1.5).toString());
  BOOST_REQUIRE_EQUAL("\"RefTool\"", StringArgument("RefTool").toString());
  BOOST_REQUIRE_EQUAL("PartCsy", NameArgument("PartCsy").toString());
}

BOOST_AUTO_TEST_SUITE_END()
