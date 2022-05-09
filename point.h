#ifndef POINT
#define POINT

#include <iostream>

class Point {
 public:
  Point(int x, int y);
  Point(){};
  void Print();
  int x_;
  int y_;
};

#endif