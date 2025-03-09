//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef PARSER_PARSERSTATE_H
#define PARSER_PARSERSTATE_H

#include "jdme2x/Parser/Lexer.h"

#include <memory>
#include <string_view>

namespace jdme2x {
namespace parser {

template <typename T> class Context;

template <typename T> class StateFacade {
public:
  virtual ~StateFacade() = default;

  virtual bool parse(Context<T> &context, TokenID id,
                     std::string_view text) = 0;

  virtual bool hasCompleteParse(Context<T> &context) = 0;
};

template <typename T> class State : public StateFacade<T> {
public:
  bool parse(Context<T> &context, TokenID id, std::string_view text) {
    switch (id) {
    case TokenID::OpenParen:
      return beginScope(context);
    case TokenID::CloseParen:
      return endScope(context);
    case TokenID::Comma:
      return endSection(context);
    case TokenID::Space:
      return true;
    case TokenID::EventTag:
      return parseEventTag(context, text);
    case TokenID::Name:
      return parseName(context, text);
    case TokenID::Number:
      return parseNumber(context, text);
    case TokenID::String:
      return parseString(context, text);
    case TokenID::XML:
      return parseXML(context, text);
    case TokenID::ResponseType:
      return parseResponseType(context, text);
    case TokenID::Terminator:
      return endLine(context);
    }
    return false;
  }

  virtual bool hasCompleteParse(Context<T> &) { return false; }

  virtual bool beginScope(Context<T> &) { return false; }

  virtual bool endScope(Context<T> &) { return false; }

  virtual bool endSection(Context<T> &) { return false; }

  virtual bool parseEventTag(Context<T> &, std::string_view) { return false; }

  virtual bool parseName(Context<T> &, std::string_view) { return false; }

  virtual bool parseNumber(Context<T> &, std::string_view) { return false; }

  virtual bool parseString(Context<T> &, std::string_view) { return false; }

  virtual bool parseXML(Context<T> &, std::string_view) { return false; }

  virtual bool parseResponseType(Context<T> &, std::string_view) {
    return false;
  }

  virtual bool endLine(Context<T> &) { return false; }
};

template <typename T> class Singleton {
public:
  static T *instance() {
    static T staticInstance;
    return &staticInstance;
  }
};

template <typename T> class Context {
public:
  Context(StateFacade<T> *initialState)
      : initialState(initialState), state(initialState) {}

  bool parse(TokenID id, std::string_view text) {
    return state->parse(*this, id, text);
  }

  bool hasCompleteParse() { return state->hasCompleteParse(*this); }

  void transitionTo(StateFacade<T> *newState) { state = newState; }

  void reset() {
    data = T{};
    state = initialState;
  }

  T data;

private:
  StateFacade<T> *initialState;

  StateFacade<T> *state;
};

} // namespace parser
} // namespace jdme2x

#endif
