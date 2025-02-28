#include "jdme2x/Method.h"

#include <boost/test/unit_test.hpp>
#include <string>

using namespace jdme2x;

BOOST_AUTO_TEST_SUITE(MethodTest)

BOOST_AUTO_TEST_CASE(serialzeMethod) {
  Method GetDMEVersionMethod("GetDMEVersion");
  std::string Result = GetDMEVersionMethod.toString();
  BOOST_REQUIRE_EQUAL("GetDMEVersion()", Result);

  Method AlignPartMethod("AlignPart");
  Result = AlignPartMethod.addValue(0)
               .addValue(-1)
               .addValue(0)
               .addValue(0.6f)
               .addValue(0.0f)
               .addValue(0.8f)
               .addValue(1.0f)
               .toString();
  BOOST_REQUIRE_EQUAL("AlignPart(0, -1, 0, 0.6, 0, 0.8, 1)", Result);

  Method OnMoveReportEMethod("OnMoveReportE");
  Result = OnMoveReportEMethod.addProperty(Property("Time").addValue(5))
               .addProperty(Property("Dis").addValue(0.34f))
               .addProperty(Property("X"))
               .addProperty(Property("Y"))
               .addProperty(Property("Z"))
               .toString();
  BOOST_REQUIRE_EQUAL("OnMoveReportE(Time(5), Dis(0.34), X(), Y(), Z())",
                      Result);

  Method ChangeToolMethod("ChangeTool");
  Result = ChangeToolMethod.addString("RefTool").toString();
  BOOST_REQUIRE_EQUAL("ChangeTool(\"RefTool\")", Result);

  Method SetCoordSystemMethod("SetCoordSystem");
  Result = SetCoordSystemMethod.addName("PartCsy").toString();
  BOOST_REQUIRE_EQUAL("SetCoordSystem(PartCsy)", Result);
}

BOOST_AUTO_TEST_SUITE_END()
