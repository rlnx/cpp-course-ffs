#include <iostream>

class string {
public:
  /* Empty constructor */
  string() {
    size_ = 0;
    str_ = nullptr;
  }

  /* Constructor from C-style string */
  string(const char *source) {
    size_ = string_length(source);
    str_ = copy_string(source, size_);
    std::cout << "[DEBUG]: Constructor called" << std::endl;
  }

  /* Copy constructor */
  string(const string &other) {
    size_ = other.size_;
    str_ = copy_string(other.str_, size_);
    std::cout << "[DEBUG]: Copy constructor called" << std::endl;
  }

  /* Destructor */
  ~string() {
    delete[] str_;
    size_ = 0;
    std::cout << "[DEBUG]: Destructor called" << std::endl;
  }

  /* Assignment operator */
  string &operator=(const string &other) {
    /* Self assignment check */
    /* Avoid self assignment!!! */
    if (this != &other) {
      delete[] this->str_;
      this->size_ = other.size_;
      this->str_ = copy_string(other.str_, size_);
    }
    std::cout << "[DEBUG]: Assignment operator" << std::endl;
    return *this;
  }

  /* Concatenation operator (+ operator overloading) */
  string operator+(const string &other) {
    char *concat = new char[size_ + other.size_ + 1];
    for (size_t i = 0; i < size_; i++) {
      concat[i] = str_[i];
    }
    for (size_t i = 0; i < other.size_; i++) {
      concat[size_ + i] = other.str_[i];
    }

    string result;
    result.str_ = concat;
    result.size_ = size_ + other.size_;

    return result;
  }

  void debug_print() const {
    std::cout << "[DEBUG]: " << str_ << std::endl;
  }

private:
  /* Computes length of the C-style string (excluding null-character) */
  size_t string_length(const char *source) {
    size_t i = 0;
    /* Perform iterations until null-character is found */
    while (source[i] != '\0') {
      i++;
    }
    return i;
  }

  /* Allocates array of the given length and copies the given
   * C-style string to that array, returns a new array pointer */
  char *copy_string(const char *source, size_t length) {
    /* Add 1 to the length to store null-character */
    char *copy = new char[length + 1];
    for (size_t i = 0; i < length; i++) {
      copy[i] = source[i];
    }
    copy[length] = '\0';
    return copy;
  }

  /* Class-scope variables (fields of the class) */
  char *str_;  /* C-style array containing characters */
  size_t size_ /* Length of the string excluding null-character */;
};

int main(int argc, char const *argv[]) {
  string str_1("hello 1");
  string str_2("hello 2");
  string str_3(str_2); /* Copy constructor is called here */

  str_1.debug_print();
  str_2.debug_print();
  str_3.debug_print();

  string str_4 = str_1; /* Copy constructor is called */
  str_4 = str_1; /* Assignment operator is called */

  /* String concatenation */
  string str_5 = str_1 + str_2;
  str_5.debug_print();

  return 0;
}
