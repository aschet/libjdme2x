//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Command.h"
#include "jdme2x/Method.h"
#include "jdme2x/Types/Tag.h"

#include <boost/test/unit_test.hpp>
#include <string>

using namespace jdme2x;
using namespace jdme2x::types;

BOOST_AUTO_TEST_SUITE(CommandTest)

BOOST_AUTO_TEST_CASE(serializeCommand) {
  Command GetDMEVersionCommand(Tag(1, TagType::Command),
                               Method("GetDMEVersion"));
  std::string Result = GetDMEVersionCommand.toString();
  BOOST_TEST("00001 GetDMEVersion()\r\n" == Result);
}

BOOST_AUTO_TEST_SUITE_END()
