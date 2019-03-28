#ifndef PARSER_UTILS_HPP_
#define PARSER_UTILS_HPP_

#include <list>
#include <string>
#include <iostream>

namespace utils {

inline bool IsSeparator(char sep) {
  return sep == ' ' || sep == '\0';
}

inline bool IsOperator(const std::string &expr) {
  return (expr.size() == 1) && (expr[0] == '+' ||
                                expr[0] == '-' ||
                                expr[0] == '*' ||
                                expr[0] == '/');
}

inline bool IsNumber(const std::string &expr) {
  bool is_number = true;
  for (char c : expr) {
    is_number = is_number && std::isdigit(c);
  }

  // The same:
  // for (char c : expr) {
  //   if (!std::isdigit(c)) {
  //     return false;
  //   }
  // }

  // The same:
  // for (size_t i = 0; i < expr.size(); i++) {
  //   const char c = expr[i];
  //   is_number = is_number && std::isdigit(c);
  // }
  return is_number;
}

// expr = "12 33 34 +" -> list = [ "12", "33", "34", "+" ]
inline std::list<std::string> Split(const std::string &expr) {
  const char *expr_c_str = expr.c_str();
  const char *beg = expr_c_str;
  const char *end = expr_c_str;

  std::list<std::string> results;
  for (size_t i = 0; i <= expr.size(); i++) {
    if (IsSeparator(*end)) {
      if (!IsSeparator(*beg)) {
        results.push_back(std::string(beg, end));
      }
      beg = end + 1;
    }
    end++;
  }

  return results;
}

} // utils

#endif // PARSER_UTILS_HPP_
