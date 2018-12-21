#include <iostream> // for std::cout
#include <cstdio> // for printf

class double_link {
public:
  double_link(int value, double_link *prev_ptr,
                         double_link *next_ptr) {
    this->value = value;
    this->prev_ptr = prev_ptr;
    this->next_ptr = next_ptr;
  }

  int value;
  double_link *prev_ptr;
  double_link *next_ptr;
};

class double_list {
public:
  double_list() {
    first_ = nullptr;
    last_ = nullptr;
  }

  void push_back(int value) {
    if (first_ == nullptr) {
      first_ = new double_link(value, nullptr,
                                      nullptr);
      last_ = first_;
      return;
    }

    double_link *new_link =
      new double_link(value, nullptr, nullptr);
    new_link->prev_ptr = last_;
    last_->next_ptr = new_link;
    last_ = new_link;
  }

  void print() {
    double_link *current = first_;
    while(current != nullptr) {
      printf("%d ", current->value);
      current = current->next_ptr;
    }
    printf("\n");
  }

private:
  double_link *first_;
  double_link *last_;
};

int main(int argc, char const *argv[]) {
  double_list list;

  for (size_t i = 0; i < 100; i++) {
    list.push_back(i);
  }
  list.print();

  return 0;
}
