#ifndef JDME2X_PARSER_COMMANDLEXER_H
#define JDME2X_PARSER_COMMANDLEXER_H

#include "jdme2x/API.h"
#include "jdme2x/Parser/TokenID.h"

#include <functional>
#include <memory>
#include <string>

namespace jdme2x {

namespace parser {

class CommandLexerDefinition;

class JDME2X_API CommandLexer {
public:
  CommandLexer();

  ~CommandLexer();

  CommandLexer(const CommandLexer &) = delete;

  CommandLexer(CommandLexer &&) = delete;

  CommandLexer &operator=(const CommandLexer &) = delete;

  CommandLexer &operator=(CommandLexer &&) = delete;

  bool tokenize(const std::string &Text,
                std::function<bool(CommandTokenID, const std::string &)>);

private:
  std::unique_ptr<CommandLexerDefinition> Impl;
};

} // namespace parser

} // namespace jdme2x

#endif
