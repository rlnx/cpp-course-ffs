#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <cmath>
#include "base.hpp"

class Circle : public Shape {
public:
  explicit Circle(double radius)
    : radius_(radius) { }

  // The same:
  // explicit Circle(double radius) {
  //   radius_ = radius;
  // }

  double area() override {
    return M_PI * radius_ * radius_;
  }

private:
  double radius_;
};

#endif // CIRCLE_HPP
