#include <iostream>
#include <string>

void print(std::string log_msg, int color) {
  auto msg = "\033[" + std::to_string(color) + "m" + log_msg + "\033[0m";
  std::cout << msg << std::endl;
}

void title(std::string msg) { print(msg, 46); }
void info(std::string msg) { print(msg, 36); }