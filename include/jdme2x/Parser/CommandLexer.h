#ifndef JDME2X_PARSER_COMMANDLEXER_H
#define JDME2X_PARSER_COMMANDLEXER_H

#include "jdme2x/API.h"
#include "jdme2x/Parser/TokenID.h"

#include <functional>
#include <memory>
#include <string_view>

namespace jdme2x {

namespace parser {

class CommandLexerImpl;

class JDME2X_API CommandLexer {
public:
  CommandLexer();

  ~CommandLexer();

  CommandLexer(const CommandLexer &) = delete;

  CommandLexer(CommandLexer &&) = delete;

  CommandLexer &operator=(const CommandLexer &) = delete;

  CommandLexer &operator=(CommandLexer &&) = delete;

  bool
  tokenize(std::string_view Text,
           std::function<bool(TokenID, std::string_view)> TokenHandler) const;

private:
  std::unique_ptr<CommandLexerImpl> Impl;
};

} // namespace parser

} // namespace jdme2x

#endif
