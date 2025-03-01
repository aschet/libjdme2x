//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Method.h"

#include <boost/test/unit_test.hpp>
#include <string>

using namespace jdme2x;

BOOST_AUTO_TEST_SUITE(MethodTest)

BOOST_AUTO_TEST_CASE(serialzeMethod) {
  Method GetDMEVersionMethod("GetDMEVersion");
  std::string Result = GetDMEVersionMethod.toString();
  BOOST_TEST("GetDMEVersion()" == Result);

  Method AlignPartMethod("AlignPart");
  Result = AlignPartMethod.addValue(0)
               .addValue(-1)
               .addValue(0)
               .addValue(0.6f)
               .addValue(0.0f)
               .addValue(0.8f)
               .addValue(1.0f)
               .toString();
  BOOST_TEST("AlignPart(0, -1, 0, 0.6, 0, 0.8, 1)" == Result);

  Method OnMoveReportEMethod("OnMoveReportE");
  Result = OnMoveReportEMethod.addProperty(Property("Time").addValue(5))
               .addProperty(Property("Dis").addValue(0.34f))
               .addProperty(Property("X"))
               .addProperty(Property("Y"))
               .addProperty(Property("Z"))
               .toString();
  BOOST_TEST("OnMoveReportE(Time(5), Dis(0.34), X(), Y(), Z())" == Result);

  Method ChangeToolMethod("ChangeTool");
  Result = ChangeToolMethod.addString("RefTool").toString();
  BOOST_TEST("ChangeTool(\"RefTool\")" == Result);

  Method SetCoordSystemMethod("SetCoordSystem");
  Result = SetCoordSystemMethod.addName("PartCsy").toString();
  BOOST_TEST("SetCoordSystem(PartCsy)" == Result);
}

BOOST_AUTO_TEST_SUITE_END()
