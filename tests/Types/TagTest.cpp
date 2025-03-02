//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/Tag.h"
#include "TestUtils.h"

#include <boost/test/unit_test.hpp>
#include <string>

using namespace jdme2x;
using namespace jdme2x::types;

BOOST_AUTO_TEST_SUITE(TagTest)

BOOST_AUTO_TEST_CASE(serialzeTag) {
  Tag CommandTag(1, TagType::Command);
  std::string Result = toString(CommandTag);
  BOOST_TEST("00001" == Result);

  Tag EventTag(1, TagType::Event);
  Result = toString(EventTag);
  BOOST_TEST("E0001" == Result);
}

BOOST_AUTO_TEST_CASE(checkForUnsolicitedEvent) {
  BOOST_TEST(!Tag(1, TagType::Command).isUnsolicitedEvent());
  BOOST_TEST(!Tag(1, TagType::Event).isUnsolicitedEvent());
  BOOST_TEST(Tag::createUnsolicitedEvent().isUnsolicitedEvent());
}

BOOST_AUTO_TEST_SUITE_END()
