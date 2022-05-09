#ifndef GREEDY
#define GREEDY

#include "problem.h"
#include "solution.h"
#include <cmath>
#include <climits>
#include <algorithm>

class Greedy {
 public:
  Greedy(Problem problem);
  float distance(std::vector<float>, std::vector<float>);
  std::vector<float> center(std::vector<std::vector<float>> set);
  int getFurthestElementIndex(std::vector<std::vector<float>>, std::vector<float>);
  Solution constructSolution(int m);
  Problem problem_;
  int nElements_;
  int dimensionality_;
};

#endif