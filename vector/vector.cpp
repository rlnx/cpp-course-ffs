#include <iostream>

template<typename Type>
class vector {
public:
  vector() {
    buffer_ = nullptr;
    size_ = 0;
  }

  /* Allocates vector of length n */
  vector(int n) {
    buffer_ = new Type[n];
    size_ = n;
  }

  /* Copy constructor */
  vector(const vector &other) {
    size_ = other.size_;
    buffer_ = copy_vector(other.buffer_, size_);
  }

  ~vector() {
    delete[] buffer_;
  }

  int size() const {
    return size_;
  }

  Type operator [](int index) const {
    return buffer_[index];
  }

  Type &operator [](int index) {
    return buffer_[index];
  }

  void push_back(const Type &value) {
    Type *new_buffer = new Type[size_ + 1];
    for (size_t i = 0; i < size_; i++) {
      new_buffer[i] = buffer_[i];
    }
    new_buffer[size_] = value;
    delete[] buffer_;
    size_ = size_ + 1;
    buffer_ = new_buffer;
  }

  /* Assignment operator */
  vector &operator=(const vector &other) {
    /* Self assignment check */
    /* Avoid self assignment!!! */
    if (this != &other) {
      delete[] this->buffer_;
      this->size_ = other.size_;
      this->buffer_ = copy_vector(other.buffer_, size_);
    }
    return *this;
  }

  void reverse() {
    T *temp_array = new T[size_];
    for (int i = 0; i < size_; i++) {
      temp_array[i] = buffer_[size_ - i - 1];
    }
    delete buffer_;
    buffer_ = temp_array;
  }

  void reverse_2() {
    for (int i = 0; i < size_ / 2; i++) {
      int j = size_ - i - 1;
      T tmp = buffer_[i];
      buffer_[i] = buffer_[j];
      buffer_[j] = tmp;
    }
  }

private:
  Type *copy_vector(const Type *buffer, int size) {
    Type *new_buffer = new Type[size];
    for (int i = 0; i < size; i++) {
      new_buffer[i] = buffer[i];
    }
    return new_buffer;
  }

  Type *buffer_;
  int size_;
};

int main(int argc, char const *argv[]) {
  vector<double> v(100);
  vector<double> v_copy = v;

  for (size_t i = 0; i < v.size(); i++) {
    v[i] = i;
  }

  auto &v0 = v[0];
  v0 = -100;

  std::cout << "v.size() = " << v.size() << std::endl;
  for (size_t i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }

  return 0;
}
