#ifndef SOLUTION
#define SOLUTION

#include <vector>
#include <iostream>
#include <cmath>

class Solution {
 public:
  Solution(std::vector<std::vector<float>> elements, std::vector<std::vector<float>> elementsOutside);
  Solution(){};
  void Print();
  float distance(std::vector<float>, std::vector<float>);
  float diversity();
  std::vector<std::vector<float>> elements_;
  std::vector<std::vector<float>> elementsOutside_;
};

#endif