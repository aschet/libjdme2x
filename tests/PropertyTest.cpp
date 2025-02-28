#include "jdme2x/Property.h"

#include <boost/test/unit_test.hpp>
#include <string>

using namespace jdme2x;

BOOST_AUTO_TEST_SUITE(PropertyTest)

BOOST_AUTO_TEST_CASE(serialzeProperty) {
  Property XProperty("X");
  std::string Result = XProperty.toString();
  BOOST_REQUIRE_EQUAL("X()", Result);

  Property YValueProperty("Y");
  Result = YValueProperty.addValue(-100).toString();
  BOOST_REQUIRE_EQUAL("Y(-100)", Result);
}

BOOST_AUTO_TEST_SUITE_END()
