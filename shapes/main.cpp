#include <cstdio>
#include <list>
#include "base.hpp"
#include "circle.hpp"
#include "rect.hpp"

int main(int argc, char const *argv[]) {
  std::list<Shape *> shapes;

  shapes.push_back(new Circle(2.0));
  shapes.push_back(new Circle(3.0));
  shapes.push_back(new Rect(2.0, 3.0));
  shapes.push_back(new Rect(1.0, 5.0));

  for (Shape *shape : shapes) {
    std::printf("shape.area = %f\n",
                shape->area());
  }

  for (Shape *shape : shapes) {
    delete shape;
  }

  return 0;
}
