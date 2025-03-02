#include <jdme2x/Parser/CommandLexer.h>
#include <jdme2x/Parser/ResponseLexer.h>

#include <iostream>

using namespace jdme2x::parser;

static void tokenizeCommand() {
  const char *CommandText = "00002 AlignPart(0, -1, 0, 0.6, 0, 0.8, 1)\r\n";
  CommandLexer Lexer;
  std::cout << "Tokens of " << CommandText;
  Lexer.tokenize(CommandText, [](TokenID ID, std::string_view Text) -> bool {
    if (ID != TokenID::Space && ID != TokenID::Terminator)
      std::cout << Text << "\n";
    return true;
  });
  std::cout << "\n";
}

static void tokenizeResponse() {
  const char *ResponseText = "E0005 %\r\n";
  ResponseLexer Lexer;
  std::cout << "Tokens of " << ResponseText;
  Lexer.tokenize(ResponseText, [](TokenID ID, std::string_view Text) -> bool {
    if (ID != TokenID::Space && ID != TokenID::Terminator)
      std::cout << Text << "\n";
    return true;
  });
  std::cout << "\n";
}

int main() {
  tokenizeCommand();
  tokenizeResponse();
  return 0;
}
