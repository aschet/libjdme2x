//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Tag.h"

#include <boost/test/unit_test.hpp>
#include <string>

using namespace jdme2x;

BOOST_AUTO_TEST_SUITE(TagTest)

BOOST_AUTO_TEST_CASE(serialzeTag) {
  Tag CommandTag(1, TagType::Command);
  std::string Result = CommandTag.toString();
  BOOST_TEST("00001" == Result);

  Tag EventTag(1, TagType::Event);
  Result = EventTag.toString();
  BOOST_TEST("E0001" == Result);
}

BOOST_AUTO_TEST_SUITE_END()
