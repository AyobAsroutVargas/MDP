#include "point.h"

Point::Point(int x, int y) {
  x_ = x;
  y_ = y;
}

void Point::Print() {
  std::cout << "x: " << x_ << " y: " << y_ << " ";
}