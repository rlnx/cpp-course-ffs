#include <iostream>

class string {
public:

  string() {
    size_ = 0;
    str_ = nullptr;
  }

  /* Constructor */
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

  ~string() {
    delete[] str_;
    size_ = 0;
    std::cout << "[DEBUG]: Destructor called" << std::endl;
  }

  /* Asigment operator */
  string &operator=(const string &other) {
    /* Self asigment check */
    /* Avoid self asigment!!! */
    if (this != &other) {
      delete[] this->str_;
      this->size_ = other.size_;
      this->str_ = copy_string(other.str_, size_);
    }
    std::cout << "[DEBUG]: Asigment operator" << std::endl;
    return *this;
  }

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
  size_t string_length(const char *source) {
    size_t i = 0;
    while (source[i] != '\0') {
      i++;
    }
    return i;
  }

  char *copy_string(const char *source, size_t length) {
    char *copy = new char[length + 1];
    for (size_t i = 0; i < length; i++) {
      copy[i] = source[i];
    }
    copy[length] = '\0';
    return copy;
  }

  char *str_;
  size_t size_;
};

/*
size_t string_len(const char *source) {
  size_t i = 0;
  while (source[i] != '\0') {
    i++;
  }
  return i;
}

void concat_strings() {
  const char *lhs_str = "beg";
  const char *rhs_str = "end";
  size_t lhs_size = string_len(lhs_str);
  size_t rhs_size = string_len(rhs_str);
  char *concat = new char[lhs_size + rhs_size + 1];
  for (size_t i = 0; i < lhs_size; i++) {
    concat[i] = lhs_str[i];
  }
  for (size_t i = 0; i < rhs_size; i++) {
    concat[lhs_size + i] = rhs_str[i];
  }

  // do something with concat ...

  delete[] concat;
}

void concat_oop() {
  string str_1("hello 1");
  string str_2("hello 2");
  string str_3 = str_1 + str_2;
}
*/

int main(int argc, char const *argv[]) {
  string str_1("hello 1");
  string str_2("hello 2");
  string str_3(str_2); // Copy constructor is called here

  str_1.debug_print();
  str_2.debug_print();
  str_3.debug_print();

  string str_4;
  str_4 = str_1; // Asigment operator
  str_1 = str_1;

  string str_5 = str_1 + str_2;
  str_5.debug_print();

  return 0;
}
