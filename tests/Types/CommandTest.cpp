//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/Command.h"
#include "jdme2x/Types/Method.h"
#include "jdme2x/Types/Tag.h"

#include "TestUtils.h"

#include <boost/test/unit_test.hpp>
#include <string>

using namespace jdme2x;

BOOST_AUTO_TEST_SUITE(CommandTest)

BOOST_AUTO_TEST_CASE(serializeCommand) {
  Command getDMEVersionCommand(Tag(1, TagType::Command),
                               Method("GetDMEVersion"));
  BOOST_TEST("00001 GetDMEVersion()\r\n" ==
             toString(getDMEVersionCommand));
}

BOOST_AUTO_TEST_SUITE_END()
