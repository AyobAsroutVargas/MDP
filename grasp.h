#ifndef GRASP_
#define GRASP_

#include "local_search.h"
#include <ctime>
#include <sys/time.h>
#include <climits>
#include <cstdlib>

class Grasp {
 public:
  Grasp(Problem problem, Swap* localSearch_);

  float distance(std::vector<float>, std::vector<float>);
  std::vector<float> center(std::vector<std::vector<float>> set);
  int getFurthestElementIndex(std::vector<std::vector<float>>, std::vector<float>);
  int selectFromRCL(std::vector<std::vector<float>>, std::vector<float>, int lrcSize);
  Solution constructSolution(int m, int lrcSize);
  Solution solve(int m, int iter, int lrcSize);
  Problem problem_;
  Swap* localSearch_;
  int nElements_;
  int dimensionality_;
};

#endif