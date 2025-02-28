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

using namespace jdme2x::types;

BOOST_AUTO_TEST_SUITE(TagTest)

BOOST_AUTO_TEST_CASE(serializeTag) {
  Tag commandTag(1, TagType::Command);
  BOOST_TEST("00001" == test::toString(commandTag));

  Tag EventTag(1, TagType::Event);
  BOOST_TEST("E0001" == test::toString(EventTag));
}

BOOST_AUTO_TEST_CASE(checkUnsolicitedEvent) {
  BOOST_TEST(Tag(1, TagType::Command) != UnsolicitedEvent);
  BOOST_TEST(Tag(1, TagType::Event) != UnsolicitedEvent);
  BOOST_TEST(Tag(UnsolicitedEvent) == UnsolicitedEvent);
}

BOOST_AUTO_TEST_SUITE_END()
