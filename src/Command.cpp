#include "jdme2x/Command.h"

#include <iomanip>
#include <sstream>

namespace jdme2x {

Command::Command() = default;

Command::Command(const Tag &CommandTag, const Method &CommandMethod)
    : CommandTag(CommandTag), CommandMethod(CommandMethod) {}

void Command::setTag(const Tag &Value) { CommandTag = Value; }

const Tag &Command::getTag() const { return CommandTag; }

void Command::setMethod(const Method &Value) { CommandMethod = Value; }

const Method &Command::getMethod() const { return CommandMethod; }

Method &Command::getMethod() { return CommandMethod; }

std::string Command::toString() const {
  std::ostringstream Stream;
  Stream << std::noskipws;
  Stream << CommandTag.toString();
  Stream << ' ';
  Stream << CommandMethod.toString();
  Stream << "\n\r";
  return Stream.str();
}

} // namespace jdme2x
