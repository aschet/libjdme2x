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

using namespace jdme2x::types;

BOOST_AUTO_TEST_SUITE(MethodTest)

BOOST_AUTO_TEST_CASE(serialzeMethod) {
  Method GetDMEVersionMethod("GetDMEVersion");
  std::string Result = test::toString(GetDMEVersionMethod);
  BOOST_TEST("GetDMEVersion()" == Result);

  Method AlignPartMethod("AlignPart");
  Result = test::toString(AlignPartMethod.addArgument(Number(0))
                              .addArgument(-1)
                              .addArgument(Number(0))
                              .addArgument(0.6f)
                              .addArgument(0.0f)
                              .addArgument(0.8f)
                              .addArgument(1.0f));
  BOOST_TEST("AlignPart(0, -1, 0, 0.6, 0, 0.8, 1)" == Result);

  Method OnMoveReportEMethod("OnMoveReportE");
  Result = test::toString(
      OnMoveReportEMethod.addArgument(Property("Time").addArgument(5))
          .addArgument(Property("Dis").addArgument(0.34f))
          .addArgument(Property("X"))
          .addArgument(Property("Y"))
          .addArgument(Property("Z")));
  BOOST_TEST("OnMoveReportE(Time(5), Dis(0.34), X(), Y(), Z())" == Result);

  Method ChangeToolMethod("ChangeTool");
  Result = test::toString(ChangeToolMethod.addArgument(String("RefTool")));
  BOOST_TEST("ChangeTool(\"RefTool\")" == Result);

  Method SetCoordSystemMethod("SetCoordSystem");
  Result = test::toString(SetCoordSystemMethod.addArgument(Name("PartCsy")));
  BOOST_TEST("SetCoordSystem(PartCsy)" == Result);
}

BOOST_AUTO_TEST_SUITE_END()
