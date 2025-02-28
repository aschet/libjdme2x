#include "jdme2x/Tag.h"

#include <boost/test/unit_test.hpp>
#include <string>

using namespace jdme2x;

BOOST_AUTO_TEST_SUITE(TagTest)

BOOST_AUTO_TEST_CASE(serialzeTag) {
  Tag CommandTag(1, TagType::Command);
  std::string Result = CommandTag.toString();
  BOOST_REQUIRE_EQUAL("00001", Result);

  Tag EventTag(1, TagType::Event);
  Result = EventTag.toString();
  BOOST_REQUIRE_EQUAL("E0001", Result);
}

BOOST_AUTO_TEST_SUITE_END()
