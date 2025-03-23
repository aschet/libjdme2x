//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Client/BasicClient.h"

#include "jdme2x/Parser/ResponseParser.h"
#include "jdme2x/Types/Command.h"

#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <thread>

namespace jdme2x {

void AbstractBasicClient::sendCommand(const Command &command) {
  send(command.tag, command.method);
}

void AbstractBasicClient::setResponseHandler(ResponseHandler handler) {
  responseHandler = handler;
}

void AbstractBasicClient::notifyResponseHandler(Response &&response) {
  if (responseHandler)
    responseHandler(std::move(response));
}

//  void handleConnectionLost(const boost::system::error_code &ec) {
//  if (ec == boost::asio::error::eof ||
//      ec == boost::asio::error::connection_reset ||
//      ec == boost::asio::error::connection_aborted) {
//    std::cerr << "Connection lost: " << ec.message() << std::endl;
//    context.stop();
//    if (contextRunner) {
//      contextRunner->join();
//    }
//  }
//}

struct BasicClient::Private
    : public std::enable_shared_from_this<BasicClient::Private> {
  Private(ResponseHandler responseHandler)
      : socket(context), resolver(context) {}

  ~Private() {
    context.stop();
    if (contextRunner) {
      contextRunner->join();
    }
  }

  void connect(const std::string_view &host, unsigned short port) {
    auto endpoints = resolver.resolve(host, std::to_string(port));
    boost::asio::connect(socket, endpoints);
    startRead();
    contextRunner = std::make_unique<std::thread>([this]() { context.run(); });
  }

  void send(std::string &&message) {
    auto messageRef = std::make_shared<std::string>(message);
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
    boost::asio::async_read_until(
        socket, buffer, "\n",
        [self = shared_from_this()](boost::system::error_code ec, std::size_t) {
          if (ec) {
            // TODO: report error
            return;
          }

          std::istream stream(&self->buffer);
          std::string line;
          std::getline(stream, line);
          if (!line.empty()) {
            line.pop_back();
            auto [ok, response] = self->parser.parse(line);
            std::cout << response;
            if (self->responseHandler)
              self->responseHandler(std::move(response));
          }

          self->startRead();
        });
  }

  ResponseHandler responseHandler;
  boost::asio::io_context context;
  boost::asio::ip::tcp::socket socket;
  boost::asio::ip::tcp::resolver resolver;
  boost::asio::streambuf buffer;
  std::unique_ptr<std::thread> contextRunner;
  ResponseParser parser;
};

BasicClient::BasicClient(const std::string_view &host, unsigned short port)
    : impl(std::make_shared<BasicClient::Private>([this](Response &&response) {
        notifyResponseHandler(std::move(response));
      })) {
  impl->connect(host, port);
}

BasicClient::~BasicClient() = default;

BasicClient::BasicClient(BasicClient &&) = default;

BasicClient &BasicClient::operator=(BasicClient &&) = default;

void BasicClient::send(const Tag &tag, const Method &method) {
  impl->send(Command::toString(tag, method));
}

} // namespace jdme2x
