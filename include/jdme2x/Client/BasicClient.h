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
#include "jdme2x/Port.h"
#include "jdme2x/Types/Command.h"
#include "jdme2x/Types/Method.h"
#include "jdme2x/Types/Response.h"
#include "jdme2x/Types/Tag.h"

#include <functional>
#include <memory>

namespace jdme2x {

using ResponseHandler = std::function<void(Response &&)>;

class JDME2X_API AbstractBasicClient {
public:
  AbstractBasicClient() = default;

  virtual ~AbstractBasicClient() = default;

  AbstractBasicClient(const AbstractBasicClient &) = default;

  AbstractBasicClient(AbstractBasicClient &&) = default;

  AbstractBasicClient &operator=(const AbstractBasicClient &) = default;

  AbstractBasicClient &operator=(AbstractBasicClient &&) = default;

  void sendCommand(const Command &command);

  virtual void send(const Tag &tag, const Method &method) = 0;

  void setResponseHandler(ResponseHandler handler);

protected:
  void notifyResponseHandler(Response &&response);

private:
  ResponseHandler responseHandler;
};

class JDME2X_API BasicClient : public AbstractBasicClient {
public:
  BasicClient(const std::string_view &host, unsigned short port = DefaultPort);

  ~BasicClient();

  BasicClient(const BasicClient &) = delete;

  BasicClient(BasicClient &&);

  BasicClient &operator=(const BasicClient &) = delete;

  BasicClient &operator=(BasicClient &&);

  void send(const Tag &tag, const Method &method) override;

private:
  struct Private;

  std::shared_ptr<Private> impl;
};

} // namespace jdme2x

#endif
