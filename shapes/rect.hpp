#ifndef RECT_HPP
#define RECT_HPP

#include "base.hpp"

class Rect : public Shape {
  /* data */
public:
  explicit Rect(double width,
                double height)
    : width_(width),
      height_(height) { }

  double area() override {
    return width_ * height_;
  }

private:
  double width_;
  double height_;
};

#endif // RECT_HPP
