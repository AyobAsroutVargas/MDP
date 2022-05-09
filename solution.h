#ifndef SOLUTION
#define SOLUTION

#include <vector>
#include <iostream>
#include <cmath>

class Solution {
 public:
  Solution(std::vector<std::vector<float>> elements);
  void Print();
  float distance(std::vector<float>, std::vector<float>);
  float diversity();
  std::vector<std::vector<float>> elements_;
};

#endif