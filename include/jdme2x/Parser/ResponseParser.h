#ifndef JDME2X_PARSER_RESPONSEPARSER_H
#define JDME2X_PARSER_RESPONSEPARSER_H

#include "jdme2x/API.h"

#include <memory>
#include <string_view>
#include <utility>

namespace jdme2x {

namespace parser {

class JDME2X_API ResponseParser {
public:
  ResponseParser();

  ~ResponseParser();

  ResponseParser(const ResponseParser &) = delete;

  ResponseParser(ResponseParser &&) = delete;

  ResponseParser &operator=(const ResponseParser &) = delete;

  ResponseParser &operator=(ResponseParser &&) = delete;

  bool parse(std::string_view Text);

private:
  struct Private;

  std::unique_ptr<Private> Impl;
};

} // namespace parser

} // namespace jdme2x

#endif
