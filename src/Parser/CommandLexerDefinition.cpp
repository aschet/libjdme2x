#include "CommandLexerDefinition.h"

namespace jdme2x {

CommandLexerDefinition::CommandLexerDefinition() {
  add("\\(", CommandTokenID::OpenParen);
  add("\\)", CommandTokenID::CloseParen);
  add(",", CommandTokenID::Comma);
  add("[ ]+", CommandTokenID::Space);
  add("E\\d{4}", CommandTokenID::EventTag);
  add("[a-zA-Z][a-zA-Z0-9]*(\\.[a-zA-Z][a-zA-Z0-9]*)*", CommandTokenID::Name);
  add("[+\\-]?(\\d+(\\.\\d*)?|(\\.\\d+))([eE][+\\-]?\\d{1,3})?",
      CommandTokenID::Number);
  add("\\\"[ !-~]+\\\"", CommandTokenID::String);
  // TODO: XML <[^>]+>([^<]*)<\/[^>]+>
  add("\n\r|\n|\r", CommandTokenID::Terminator);
}

} // namespace jdme2x
