#include "jdme2x/Argument.h"

#include <algorithm>
#include <exception>
#include <iomanip>
#include <iterator>
#include <sstream>

namespace jdme2x {

Argument::~Argument() = default;

IntArgument::IntArgument(int Value) : Value(Value) {}

int IntArgument::getValue() const { return Value; }

std::string IntArgument::toString() const { return std::to_string(Value); }

FloatArgument::FloatArgument(float Value) : Value(Value) {}

float FloatArgument::getValue() const { return Value; }

std::string FloatArgument::toString() const {
  std::stringstream Stream;
  Stream << Value;
  return Stream.str();
}

StringArgument::StringArgument(std::string_view Value) : Value(Value) {}

const std::string &StringArgument::getValue() const { return Value; }

std::string StringArgument::toString() const {
  std::ostringstream Stream;
  Stream << '"';
  Stream << Value;
  Stream << '"';
  return Stream.str();
}

NameArgument::NameArgument(std::string_view Value) : Value(Value) {}

const std::string &NameArgument::getValue() const { return Value; }

std::string NameArgument::toString() const { return Value; }

EventTagArgument::EventTagArgument(const Tag &Value) : Value(Value) {
  if (Value.getType() != TagType::Event)
    throw std::invalid_argument("Type of Tag Value must be Event");
}

const Tag &EventTagArgument::getValue() const { return Value; }

std::string EventTagArgument::toString() const { return Value.toString(); }

JDME2X_API std::string toString(const Arguments &Args) {
  if (Args.empty())
    return std::string();

  std::ostringstream Stream;
  std::transform(Args.begin(), Args.end() - 1,
                 std::ostream_iterator<std::string>(Stream, ", "),
                 [](const std::shared_ptr<Argument> &CurrentArgument) {
                   return CurrentArgument->toString();
                 });
  Stream << Args.back()->toString();
  return Stream.str();
}

} // namespace jdme2x
