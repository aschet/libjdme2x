//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Interfaces/Server/EndSession.h"

#include <boost/test/unit_test.hpp>

using namespace jdme2x::interfaces;
using namespace jdme2x::types;

BOOST_AUTO_TEST_SUITE(EndSessionTest)

BOOST_AUTO_TEST_CASE(encodeParameters) {
  BOOST_TEST(ArgumentList() == EndSessionParameters().encode());
}

BOOST_AUTO_TEST_CASE(encodeResultData) {
  BOOST_TEST(DataList() == EndSessionReturnData().encode());
}

BOOST_AUTO_TEST_SUITE_END()
