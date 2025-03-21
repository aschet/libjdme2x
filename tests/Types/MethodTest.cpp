//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Types/Method.h"

#include "TestUtils.h"

#include <boost/test/unit_test.hpp>
#include <string>

using namespace jdme2x;

BOOST_AUTO_TEST_SUITE(MethodTest)

BOOST_AUTO_TEST_CASE(serializeMethod) {
  Method getDMEVersionMethod("GetDMEVersion");
  std::string result = toString(getDMEVersionMethod);
  BOOST_TEST("GetDMEVersion()" == result);

  Method alignPartMethod("AlignPart");
  result = toString(alignPartMethod.with(Number(0))
                              .with(Number(-1))
                              .with(Number(0))
                              .with(Number(0.6))
                              .with(Number(0.0))
                              .with(Number(0.8))
                              .with(Number(1.0)));
  BOOST_TEST("AlignPart(0, -1, 0, 0.6, 0, 0.8, 1)" == result);

  Method onMoveReportEMethod("OnMoveReportE");
  result = toString(
      onMoveReportEMethod.with(Property("Time").with(Number(5)))
          .with(Property("Dis").with(Number(0.34)))
          .with(Property("X"))
          .with(Property("Y"))
          .with(Property("Z")));
  BOOST_TEST("OnMoveReportE(Time(5), Dis(0.34), X(), Y(), Z())" == result);

  Method changeToolMethod("ChangeTool");
  result = toString(changeToolMethod.with(String("RefTool")));
  BOOST_TEST("ChangeTool(\"RefTool\")" == result);

  Method setCoordSystemMethod("SetCoordSystem");
  result = toString(setCoordSystemMethod.with(Name("PartCsy")));
  BOOST_TEST("SetCoordSystem(PartCsy)" == result);
}

BOOST_AUTO_TEST_SUITE_END()
