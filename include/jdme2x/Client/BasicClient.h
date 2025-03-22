//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_CLIENT_BASICCLIENT_H
#define JDME2X_CLIENT_BASICCLIENT_H

#include "jdme2x/API.h"
#include "jdme2x/Types/Method.h"
#include "jdme2x/Types/Tag.h"

#include <memory>
#include <string_view>

namespace jdme2x {

constexpr unsigned int DefaultPort = 1294;

struct JDME2X_API BasicClient {
public:
  BasicClient(const std::string_view &host, unsigned int port = DefaultPort);

  ~BasicClient();

  BasicClient(const BasicClient &) = delete;

  BasicClient(BasicClient &&);

  BasicClient &operator=(const BasicClient &) = delete;

  BasicClient &operator=(BasicClient &&);

  void send(const Method &method);

private:
  struct Private;

  std::shared_ptr<Private> impl;
};

} // namespace jdme2x

#endif
