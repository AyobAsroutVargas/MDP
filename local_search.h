#ifndef LOCAL_SEARCH_
#define LOCAL_SEARCH_

#include "problem.h"
#include "solution.h"
#include <cmath>
#include <climits>
#include <algorithm>

class Swap {
 public:
  Swap();
  Solution Apply(Solution initialSolution);
  Solution search(Solution initialSolution);
  float distance(std::vector<float>, std::vector<float>);
  std::vector<float> center(std::vector<std::vector<float>> set);
  int getFurthestElementIndex(std::vector<std::vector<float>>, std::vector<float>);
  Problem problem_;
  int nElements_;
  int dimensionality_;
};

#endif