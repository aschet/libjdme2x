#ifndef JDME2X_PARSER_RESPONSELEXER_H
#define JDME2X_PARSER_RESPONSELEXER_H

#include "jdme2x/API.h"
#include "jdme2x/Parser/TokenID.h"

#include <functional>
#include <memory>
#include <string_view>

namespace jdme2x {

namespace parser {

class ResponseLexerDefinition;

class JDME2X_API ResponseLexer {
public:
  ResponseLexer();

  ~ResponseLexer();

  ResponseLexer(const ResponseLexer &) = delete;

  ResponseLexer(ResponseLexer &&) = delete;

  ResponseLexer &operator=(const ResponseLexer &) = delete;

  ResponseLexer &operator=(ResponseLexer &&) = delete;

  bool
  tokenize(std::string_view Text,
           std::function<bool(ResponseTokenID, std::string_view)> TokenHandler);

private:
  std::unique_ptr<ResponseLexerDefinition> Impl;
};

} // namespace parser

} // namespace jdme2x

#endif
