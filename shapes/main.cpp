#include <cstdio>
#include "base.hpp"
#include "circle.hpp"

int main(int argc, char const *argv[]) {
  Shape *abstract_shape;
  Circle *circle = new Circle(2.0);

  std::printf("circle.area = %f\n",
              circle->area());

  abstract_shape = circle;
  std::printf("abstract_shape.area = %f\n",
              abstract_shape->area());


  return 0;
}
