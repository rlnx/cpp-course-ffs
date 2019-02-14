#include <list>
#include <string>
#include <cstdio>
#include "utils.hpp"

enum class TokenType {
  constant,
  function
};

class Token {
public:
  explicit Token(const std::string &token_str) {

  }

private:
  std::string token_str_;
  TokenType type_;
};

// "12 33 34 +" -> [ "12", "33", "34", "+" ]
std::list<Token> ParseTokens(const std::string &expr) {
  std::list<std::string> split = utils::Split(expr);

  /* DEBUG: Parsed tokens */
  std::cout << "Parsed tokens:" << std::endl;
  for (auto token : split) {
    std::cout << '"' << token << '"' << std::endl;
  }

  return std::list<Token>();
}

int main(int argc, char const *argv[]) {
  if (argc <= 1) {
    std::printf("Wrong input, expected expression\n");
    return -1;
  }

  const std::string expression = argv[1];
  auto tokens = ParseTokens(expression);

  return 0;
}
