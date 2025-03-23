//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#ifndef JDME2X_SERVER_BASICSERVER_H
#define JDME2X_SERVER_BASICSERVER_H

#include "jdme2x/API.h"
#include "jdme2x/Port.h"
#include "jdme2x/Types/Command.h"
#include "jdme2x/Types/Response.h"
#include "jdme2x/Types/Tag.h"

#include <functional>
#include <memory>
#include <string_view>

namespace jdme2x {

using CommandHandler = std::function<void(Command &&)>;

class JDME2X_API AbstractBasicServer {
public:
  virtual ~AbstractBasicServer() = default;

  void sendUnsolicitedEvent(const ResponseValue &response);

  void sendAcknowledge(const Tag& tag);

  void sendDone(const Tag& tag);

  void sendData(const Tag &tag, Data &&data);

  void sendError(const Tag& tag, Error &&error);

  void sendResponse(const Response &response);

  virtual void send(const Tag &tag, const ResponseValue &value) = 0;

  void setCommandHandler(CommandHandler handler);

protected:
  void notifyCommandHandler(Command &&command);

private:
  CommandHandler commandHandler;
};

class JDME2X_API BasicServer : public AbstractBasicServer {
public:
  BasicServer();

  ~BasicServer();

  BasicServer(const BasicServer &) = delete;

  BasicServer(BasicServer &&);

  BasicServer &operator=(const BasicServer &) = delete;

  BasicServer &operator=(BasicServer &&);

  void send(const Tag &tag, const ResponseValue &value) override;

  void start(unsigned short port = DefaultPort);

private:
  struct Private;

  std::shared_ptr<Private> impl;
};

} // namespace jdme2x

#endif
