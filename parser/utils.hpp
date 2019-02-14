#ifndef PARSER_UTILS_HPP_
#define PARSER_UTILS_HPP_

#include <list>
#include <string>
#include <iostream>

namespace utils {

// expr = "12 33 34 +" -> list = [ "12", "33", "34", "+" ]
std::list<std::string> Split(const std::string &expr) {
  const char *expr_c_str = expr.c_str();
  const char *beg = expr_c_str;
  const char *end = expr_c_str;

  constexpr char sep = ' ';
  for (size_t i = 0; i <= expr.size(); i++) {
    if (*end == sep || i == expr.size()) {
      if (*beg != sep) {
        std::cout << std::string(beg, end) << std::endl;
      }
      beg = end + 1;
    }
    end++;
  }

  return std::list<std::string>();
  // char *beg = "4252";
  // char *end = beg + 2;
  // std::string(beg, end);
}

} // utils

#endif // PARSER_UTILS_HPP_
