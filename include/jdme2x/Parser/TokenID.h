#ifndef JDME2X_PARSER_TOKENID_H
#define JDME2X_PARSER_TOKENID_H

namespace jdme2x {

namespace parser {

enum class TokenID : unsigned int {
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
  NumberSign,
  ExclamationMark,
  Ampersand,
  PercentSign,
};

} // namespace parser

} // namespace jdme2x

#endif
