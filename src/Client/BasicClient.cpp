//===----------------------------------------------------------------------===//
//
// Copyright (c) 2025 Thomas Ascher
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSEor copy at http://www.boost.org/LICENSE_1_0.txt)
// SPDX-License-Identifier: BSL-1.0
//
//===----------------------------------------------------------------------===//

#include "jdme2x/Client/BasicClient.h"

#include "jdme2x/Types/Command.h"

#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <thread>

namespace jdme2x {

struct BasicClient::Private
    : public std::enable_shared_from_this<BasicClient::Private> {
  Private() : socket(context), resolver(context) {}

  ~Private() {
    context.stop();
    if (contextRunner) {
      contextRunner->join();
    }
  }

  void connect(const std::string_view &host, unsigned int port) {
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
            std::cerr << "Error sending message: " << ec.message() << std::endl;
          }
        });
  }

  void startRead() {
    boost::asio::async_read_until(
        socket, buffer, "\r\n",
        [self = shared_from_this()](boost::system::error_code ec, std::size_t) {
          if (ec) {
            std::cerr << "Error reading: " << ec.message() << std::endl;
            return;
          }

          std::istream stream(&self->buffer);
          std::string message;
          std::getline(stream, message);
          std::cout << message;

          // self->callback_(
          //     message); // Notify callback about the received message

          self->startRead(); // Continue reading asynchronously
        });
  }

  boost::asio::io_context context;
  boost::asio::ip::tcp::socket socket;
  boost::asio::ip::tcp::resolver resolver;
  boost::asio::streambuf buffer;
  std::unique_ptr<std::thread> contextRunner;
};

BasicClient::BasicClient(const std::string_view &host, unsigned int port)
    : impl(std::make_shared<BasicClient::Private>()) {
  impl->connect(host, port);
}

BasicClient::~BasicClient() = default;

BasicClient::BasicClient(BasicClient &&) = default;

BasicClient &BasicClient::operator=(BasicClient &&) = default;

void BasicClient::send(const Method &method) {
  static int counter = 0;
  ++counter;
  Tag tag;
  if (method.isPrioritized())
    tag = Tag(counter, TagType::Event);
  else
    tag = Tag(counter, TagType::Command);

  impl->send(Command::toString(tag, method));
}

} // namespace jdme2x
