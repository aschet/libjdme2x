#include <jdme2x/Parser/CommandParser.h>
#include <jdme2x/Parser/Lexer.h>
#include <jdme2x/Parser/ResponseParser.h>

#include <iostream>

using namespace jdme2x;

static void tokenizeCommand() {
  const char *commandText = "00002 AlignPart(0, -1, 0, 0.6, 0, 0.8, 1)\r\n";
  Lexer lexer;
  std::cout << "Tokens of " << commandText;
  lexer.tokenize(commandText, [](TokenID id, std::string_view text) -> bool {
    if (id != TokenID::Space && id != TokenID::Terminator)
      std::cout << text << "\n";
    return true;
  });
  std::cout << "\n";
}

static void parseCommand() {
  const char *commandText = "00002 AlignPart(0, -1, 0, 0.6, 0, 0.8, 1)\r\n";
  CommandParser parser;
  auto [isOK, command] = parser.parse(commandText);
  if (isOK) {
    std::cout << "Command of " << commandText;
    std::cout << "Method: " << command.method.name << "\n";
    std::cout << "Args: " << command.method.args << "\n";
  }
}

static void tokenizeResponse() {
  const char *responseText = "E0005 %\r\n";
  Lexer lexer;
  std::cout << "Tokens of " << responseText;
  lexer.tokenize(responseText, [](TokenID id, std::string_view text) -> bool {
    if (id != TokenID::Space && id != TokenID::Terminator)
      std::cout << text << "\n";
    return true;
  });
  std::cout << "\n";
}

static void parseResponse() {
  const char *responseText = "00010 # 0.6, 0., 0.8\r\n";
  ResponseParser parser;
  auto [isOK, response] = parser.parse(responseText);
  if (isOK && response.holdsNumericData()) {
    std::cout << "Data of " << responseText;
    std::cout << response.numericData();
  }
}

int main() {
  tokenizeCommand();
  parseCommand();
  tokenizeResponse();
  parseResponse();
  return 0;
}
