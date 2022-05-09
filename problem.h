#ifndef PROBLEM
#define PROBLEM

#include "point.h"
#include <vector>
#include <iostream>

class Problem {
 public:
  Problem(std::vector<std::vector<float>> elements, int &nElements , int &dimensionality);
  Problem();
  void Print();
  std::vector<std::vector<float>> elements_;
  int nElements_;
  int dimensionality_;
};

#endif