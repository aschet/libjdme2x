#include "jdme2x/Property.h"

#include <sstream>

namespace jdme2x {

Property::Property() = default;

Property::Property(std::string_view Name) : Name(Name) {}

void Property::setName(std::string_view Value) { Name = Value; }

const std::string &Property::getName() const { return Name; }

const Arguments &Property::getArguments() const { return PropertyArguments; }

Property &Property::addArgument(std::shared_ptr<Argument> Value) {
  PropertyArguments.emplace_back(Value);
  return *this;
}

Property &Property::addValue(int Value) {
  PropertyArguments.emplace_back(std::make_shared<IntArgument>(Value));
  return *this;
}

Property &Property::addValue(float Value) {
  PropertyArguments.emplace_back(std::make_shared<FloatArgument>(Value));
  return *this;
}

std::string Property::toString() const {
  std::ostringstream Stream;
  Stream << Name;
  Stream << '(';
  Stream << jdme2x::toString(PropertyArguments);
  Stream << ')';
  return Stream.str();
}

} // namespace jdme2x
