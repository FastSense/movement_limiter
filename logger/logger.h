#pragma once
#include <iostream>

namespace movement_limiter {

class Logger {
public:
  Logger() = delete;
  Logger(std::string entity_name):
      entity_name_(entity_name) {}

protected:
  #define LOG(log_line) std::clog << "LOG[" << entity_name_ << "]: " << log_line << '\n';
  std::string entity_name_;
};
  
}  // namespace movement_limiter
