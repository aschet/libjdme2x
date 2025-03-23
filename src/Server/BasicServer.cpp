//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Server/BasicServer.h"

#include "jdme2x/Parser/CommandParser.h"

#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <type_traits>

namespace jdme2x {

void AbstractBasicServer::sendUnsolicitedEvent(const ResponseValue &response) {
  send(UnsolicitedEvent, response);
}

void AbstractBasicServer::sendAcknowledge(const Tag &tag) {
  send(tag, Acknowledge());
}

void AbstractBasicServer::sendDone(const Tag &tag) { send(tag, Done()); }

void AbstractBasicServer::sendData(const Tag &tag, Data &&data) {
  send(tag, std::move(data));
}

void AbstractBasicServer::sendError(const Tag &tag, Error &&error) {
  send(tag, std::move(error));
}

void AbstractBasicServer::sendResponse(const Response &response) {
  send(response.tag, response.value);
}

void AbstractBasicServer::setCommandHandler(CommandHandler handler) {
  commandHandler = handler;
}

void AbstractBasicServer::notifyCommandHandler(Command &&command) {
  if (commandHandler)
    commandHandler(std::move(command));
}

struct BasicServer::Private
    : public std::enable_shared_from_this<BasicServer::Private> {
  Private(CommandHandler commandHandler)
      : commandHandler(commandHandler), acceptor(context), socket(context) {}

  ~Private() {}

  void start(unsigned short port) {
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v6(), port);
    acceptor.open(endpoint.protocol());
    acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
    acceptor.set_option(boost::asio::ip::v6_only(false));
    acceptor.bind(endpoint);
    acceptor.listen(1);

    acceptConnection();
    context.run();
  }

  void acceptConnection() {
    acceptor.async_accept(socket, [this](const boost::system::error_code &ec) {
      if (!ec) {
        startRead();
      }
    });
  }

  void send(std::string &&message) {
    if (!socket.is_open()) {
      return;
    }

    auto messageRef = std::make_shared<std::string>(std::move(message));
    boost::asio::async_write(
        socket, boost::asio::buffer(*messageRef),
        [self = shared_from_this(),
         messageRef = messageRef](boost::system::error_code ec, std::size_t) {
          if (ec) {
            // TODO: report error
          }
        });
  }

  void startRead() {
    if (!socket.is_open()) {
      acceptConnection();
      return;
    }

    boost::asio::async_read_until(
        socket, buffer, "\n",
        [self = shared_from_this()](boost::system::error_code ec, std::size_t) {
          if (ec) {
            self->acceptConnection();
            return;
          }

          std::istream stream(&self->buffer);
          std::string line;
          std::getline(stream, line);
          if (!line.empty()) {
            line.pop_back();
            auto [ok, command] = self->parser.parse(line);
            if (self->commandHandler)
              self->commandHandler(std::move(command));
          }

          self->startRead();
        });
  }

  CommandHandler commandHandler;
  boost::asio::io_context context;
  boost::asio::ip::tcp::acceptor acceptor;
  boost::asio::ip::tcp::socket socket;
  boost::asio::streambuf buffer;
  std::unique_ptr<std::thread> contextRunner;
  CommandParser parser;
};

BasicServer::BasicServer()
    : impl(std::make_shared<BasicServer::Private>([this](Command &&command) {
        notifyCommandHandler(std::move(command));
      })) {}

BasicServer::~BasicServer() = default;

BasicServer::BasicServer(BasicServer &&) = default;

BasicServer &BasicServer::operator=(BasicServer &&) = default;

void BasicServer::send(const Tag &tag, const ResponseValue &value) {
  impl->send(Response::toString(tag, value));
}

void BasicServer::start(unsigned short port) { impl->start(port); }

} // namespace jdme2x
