#ifndef JDME2X_PARSER_TOKENID_H
#define JDME2X_PARSER_TOKENID_H

namespace jdme2x {

namespace parser {

enum class CommandTokenID {
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

enum class ResponseTokenID {
  OpenParen = CommandTokenID::OpenParen,
  CloseParen = CommandTokenID::CloseParen,
  Comma = CommandTokenID::Comma,
  Space = CommandTokenID::Space,
  EventTag = CommandTokenID::EventTag,
  Name = CommandTokenID::Name,
  Number = CommandTokenID::Number,
  String = CommandTokenID::String,
  XML = CommandTokenID::XML,
  Terminator = CommandTokenID::Terminator,
  NumberSign,
  ExclamationMark,
  Ampersand,
  PercentSign,
};

} // namespace parser

} // namespace jdme2x

#endif
