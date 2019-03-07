#include <list>
#include <string>
#include <cstdio>
#include <stdexcept>
#include "utils.hpp"

enum class TokenType {
  constant,
  function
};

class Token {
public:
  explicit Token(const std::string &token_str)
      : token_str_(token_str) {

    if (utils::IsNumber(token_str)) {
      type_ = TokenType::constant;
    }
    else if (utils::IsOperator(token_str)) {
      type_ = TokenType::function;
    }
    else {
      throw std::runtime_error("Unexpected token");
    }
  }

private:
  std::string token_str_;
  TokenType type_;
};

// "12 33 34 +" -> [ "12", "33", "34", "+" ]
std::list<Token> ParseTokens(const std::string &expr) {
  std::list<std::string> splits = utils::Split(expr);

  std::list<Token> tokens;
  for (std::string &chunk : splits) {
    tokens.push_back(Token(chunk));
  }

  /* DEBUG: Parsed tokens */
  std::cout << "Parsed tokens:" << std::endl;
  for (auto token : splits) {
    std::cout << '"' << token << '"' << std::endl;
  }

  return tokens;
}

int main(int argc, char const *argv[]) {
  // if (argc <= 1) {
  //   std::printf("Wrong input, expected expression\n");
  //   return -1;
  // }

  // const std::string expression = argv[1];
  const std::string expression = "12 23 34 + +";
  auto tokens = ParseTokens(expression);

  return 0;
}
