#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

std::vector<int> parse_file(const std::string &filename) {
  std::fstream file(filename, std::fstream::in);

  if (!file.is_open()) {
    throw std::runtime_error("File does not exist");
  }

  std::string data;
  std::vector<int> output;

  /* This loop executes until we reach the end of file */
  while (file >> data /* Read SINGLE whitespace separated
                       * string to 'data' from 'file' */) {
    /* Now 'data' contains single term from input file */

    /* Convert string 'data' to integer number
     * using function std::stoi */
    const int data_int = std::stoi(data);

    /* Push the number to the end of vector 'output' */
    output.push_back(data_int);
  }

  return output;
}

int main(int argc, char const *argv[]) {

  try {
    std::vector<int> data = parse_file("source.txt");
    for (auto &x : data) {
      std::cout << x << std::endl;
    }
  }
  catch (const std::exception &ex) {
    std::cout << ex.what() << std::endl;
  }

  return 0;
}
