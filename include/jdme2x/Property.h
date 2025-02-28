#ifndef JDME2X_PROPERTY_H
#define JDME2X_PROPERTY_H

#include "jdme2x/API.h"
#include "jdme2x/Argument.h"

#include <string>
#include <string_view>

namespace jdme2x {

class JDME2X_API Property : public Argument {
private:
  std::string Name;

  Arguments PropertyArguments;

public:
  Property();

  Property(std::string_view Name);

  void setName(std::string_view Value);

  const std::string &getName() const;

  const Arguments &getArguments() const;

  Property &addArgument(std::shared_ptr<Argument> Value);

  Property &addValue(int Value);

  Property &addValue(float Value);

  std::string toString() const override;
};

} // namespace jdme2x

#endif
