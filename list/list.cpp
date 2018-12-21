#include <iostream> // for std::cout
#include <cstdio> // for printf

class link {
public:
  link(int value, link *ptr) {
    this->value = value;
    this->ptr = ptr;
  }

  int value;
  link *ptr;
};

class list {
public:
  list() {
    first_ = nullptr;
    last_ = nullptr;
  }

  list(const list &other) {
    first_ = nullptr;
    last_ = nullptr;

    link *current = other.first_;
    while (current) {
      this->push_back(current->value);
      current = current->ptr;
    }
  }

  ~list() {
    link *current = first_;
    while (current) {
      link *tmp = current;
      current = current->ptr;
      delete tmp;
    }
  }

  bool empty() const {
    return first_ == nullptr;
  }

  void push_front(int value) {
    if (empty()) {
      return push_back(value);
    }

    first_ = new link(value, first_);
    // The same:
    // link *new_link = new link(value, nullptr);
    // new_link->ptr = first_;
    // first_ = new_link;
  }

  void push_back(int value) {
    if (first_ == nullptr) {
      first_ = new link(value, nullptr);
      last_ = first_;
      return;
    }

    link *new_link = new link(value, nullptr);
    last_->ptr = new_link;
    last_ = new_link;
  }

  void remove_first() {
    if (empty()) return;

    link *tmp = first_;
    first_ = first_->ptr;
    delete tmp;
  }

  void remove_last() {
    if (empty()) return;

    link *current = first_;
    while (current->ptr != last_) {
      current = current->ptr;
    }
    delete last_;
    last_ = current;
    last_->ptr = nullptr;
  }

  void print() {
    link *current = first_;
    while(current != nullptr) {
      // std::cout << current->value << " ";
      printf("%d ", current->value);
      current = current->ptr;
    }
    // std::cout << std::endl;
    printf("\n");
  }

  list reverse() {
    if (empty()) return list();

    list result;

    link *current = first_;
    while (current) {
      result.push_front(current->value);
      current = current->ptr;
    }

    return result;
  }

private:
  link *first_;
  link *last_;
};

int main(int argc, char const *argv[]) {
  list my_list;

  for (int i = 0; i < 10; i++) {
    my_list.push_back(i);
  }
  my_list.print();

  printf("After remove first\n");
  my_list.remove_first();
  my_list.print();

  printf("After remove last\n");
  my_list.remove_last();
  my_list.print();

  printf("Reverse\n");
  my_list.reverse().print();

  return 0;
}



list *func() {
  list *my_list = new list();
  my_list->push_back(10);
  return my_list;
}


void work() {
  list *source_list = func();
  list copy_of_list(*source_list);
  delete source_list;
}
