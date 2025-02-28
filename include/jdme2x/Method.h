#ifndef JDME2X_METHOD_H
#define JDME2X_METHOD_H

#include "jdme2x/API.h"
#include "jdme2x/Argument.h"
#include "jdme2x/Property.h"
#include "jdme2x/Serializeable.h"
#include "jdme2x/Tag.h"

#include <string>
#include <string_view>

namespace jdme2x {

class JDME2X_API Method : public Serializeable {
private:
  std::string Name;

  Arguments MethodArguments;

  std::string XML;

public:
  Method();

  Method(std::string_view Value);

  void setName(std::string_view Value);

  const std::string &getName() const;

  const Arguments &getArguments() const;

  Method &addArgument(std::shared_ptr<Argument> Value);

  Method &addValue(int Value);

  Method &addValue(float Value);

  Method &addString(std::string_view Value);

  Method &addName(std::string_view Value);

  Method &addEventTag(const Tag& Value);

  Method &addProperty(const Property &Value);

  void setXML(std::string_view Value);

  const std::string &getXML() const;

  std::string toString() const override;
};

} // namespace jdme2x

#endif
