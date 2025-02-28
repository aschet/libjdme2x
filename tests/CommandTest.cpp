#include "jdme2x/Command.h"
#include "jdme2x/Method.h"
#include "jdme2x/Tag.h"

#include <boost/test/unit_test.hpp>
#include <string>

using namespace jdme2x;

BOOST_AUTO_TEST_SUITE(CommandTest)

BOOST_AUTO_TEST_CASE(serializeCommand) {
  Command GetDMEVersionCommand(Tag(1, TagType::Command),
                               Method("GetDMEVersion"));
  std::string Result = GetDMEVersionCommand.toString();
  BOOST_TEST("00001 GetDMEVersion()\n\r" == Result);
}

BOOST_AUTO_TEST_SUITE_END()
