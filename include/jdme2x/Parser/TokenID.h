#ifndef JDME2X_PARSER_TOKENID_H
#define JDME2X_PARSER_TOKENID_H

namespace jdme2x {

namespace parser {

enum class CommandTokenID : unsigned int {
  OpenParen = 1,
  CloseParen,
  Comma,
  Space,
  EventTag,
  Name,
  Number,
  String,
  XML,
  Terminator,
};

enum class ResponseTokenID : unsigned int {
  OpenParen = static_cast<unsigned int>(CommandTokenID::OpenParen),
  CloseParen = static_cast<unsigned int>(CommandTokenID::CloseParen),
  Comma = static_cast<unsigned int>(CommandTokenID::Comma),
  Space = static_cast<unsigned int>(CommandTokenID::Space),
  EventTag = static_cast<unsigned int>(CommandTokenID::EventTag),
  Name = static_cast<unsigned int>(CommandTokenID::Name),
  Number = static_cast<unsigned int>(CommandTokenID::Number),
  String = static_cast<unsigned int>(CommandTokenID::String),
  XML = static_cast<unsigned int>(CommandTokenID::XML),
  Terminator = static_cast<unsigned int>(CommandTokenID::Terminator),
  NumberSign,
  ExclamationMark,
  Ampersand,
  PercentSign,
};

} // namespace parser

} // namespace jdme2x

#endif
