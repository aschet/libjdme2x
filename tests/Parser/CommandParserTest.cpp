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
#include "jdme2x/Types/Command.h"

#include "TestUtils.h"

#include <boost/test/unit_test.hpp>

using namespace jdme2x::types;
using namespace jdme2x::parser;

BOOST_AUTO_TEST_SUITE(CommandParserTest)

BOOST_AUTO_TEST_CASE(parseCommand) {
  CommandParser parser;
  Command getDMEVersion(Tag(1, TagType::Command), Method("GetDMEVersion"));
  BOOST_TEST(getDMEVersion == parser.parse("00001 GetDMEVersion()\r\n").second);

  Command onMoveReportE(Tag(1, TagType::Event),
                        Method("OnMoveReportE")
                            .with(Property("Time").with(5))
                            .with(Property("Dis").with(0.34f))
                            .with(Property("X"))
                            .with(Property("Y"))
                            .with(Property("Z")));
  BOOST_TEST(
      onMoveReportE ==
      parser.parse("E0001 OnMoveReportE(Time(5), Dis(0.34), X(), Y(), Z())\r\n")
          .second);
}

BOOST_AUTO_TEST_SUITE_END()
