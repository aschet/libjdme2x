#include "jdme2x/Tag.h"

#include <iomanip>
#include <sstream>

namespace jdme2x {

Tag::Tag() : Number(0), Type(TagType::Command) {};

Tag::Tag(unsigned int Number, TagType Type) : Number(Number), Type(Type) {}

void Tag::setNumber(unsigned int Value) { Number = Value; }

unsigned int Tag::getNumber() const { return Number; }

void Tag::setType(TagType Value) { Type = Value; }

TagType Tag::getType() const { return Type; }

std::string Tag::toString() const {
  std::ostringstream Steam;
  if (Type == TagType::Command)
    Steam << std::setw(5) << std::setfill('0') << Number;
  else
    Steam << 'E' << std::setw(4) << std::setfill('0') << Number;
  return Steam.str();
}

} // namespace jdme2x
