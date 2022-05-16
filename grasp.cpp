#include "grasp.h"

Grasp::Grasp(Problem problem, Swap* localSearch) {
 problem_ = problem;
 nElements_ = problem.nElements_;
 dimensionality_ = problem.dimensionality_;
 localSearch_ = localSearch_;
}

float Grasp::distance(std::vector<float> element1, std::vector<float> element2) {
  float sum = 0;
  for (int j = 0; j < element1.size(); j++) {
    float tmpSub = element1[j] - element2[j];
    tmpSub *= tmpSub;
    sum += tmpSub;
  }
  return sqrt(sum);
}

std::vector<float> Grasp::center(std::vector<std::vector<float>> set) {
  std::vector<float> center;
  for (int i = 0; i < set[0].size(); i++) {
    float tmpComponent = 0.0;
    for (int j = 0; j < set.size(); j++) {
      tmpComponent += set[j][i];
    }
    tmpComponent /= set.size();
    center.push_back(tmpComponent);
  }
  return center;
}

int Grasp::getFurthestElementIndex(std::vector<std::vector<float>> tmpElements, std::vector<float> centroid) {
  float maxDsitance = INT_MIN;
  int index = -1;
  for (int i = 0; i < tmpElements.size(); i++) {
    float tmpDistance = distance(tmpElements[i], centroid);
    if (tmpDistance > maxDsitance) {
      maxDsitance = tmpDistance;
      index = i;
    }
  }
  return index;
}

int Grasp::selectFromRCL(std::vector<std::vector<float>> elements, std::vector<float> centroid, int lrcSize) {
  std::vector<int> rcl;
  std::vector<std::vector<float>> tmpElements(elements);
  struct timeval time;
  gettimeofday(&time,NULL);
  srand((time.tv_sec * 1000) + (time.tv_usec / 1000));
  int size = tmpElements.size() - 1;
  for (int i = 0; i < lrcSize && i < size ; i++) {
    int furthestElementIndex = getFurthestElementIndex(tmpElements, centroid);
    rcl.push_back(furthestElementIndex);

    auto it = tmpElements.begin() + furthestElementIndex;
    std::rotate(it, it+1, tmpElements.end());
    tmpElements.pop_back();
  }
  int randIndex = rand() % rcl.size();
  int returnResultIndex = rcl[randIndex];
  return returnResultIndex;
}

Solution Grasp::constructSolution(int m, int lrcSize) {
  std::vector<std::vector<float>> tmpElements(problem_.elements_);
  std::vector<std::vector<float>> solution;
  std::vector<float> centroid(center(tmpElements));
  int count = 0;
  while(count < m) {
    int index = selectFromRCL(tmpElements, centroid, lrcSize);
    solution.push_back(tmpElements[index]);

    auto it = tmpElements.begin() + index;
    std::rotate(it, it+1, tmpElements.end());
    tmpElements.pop_back();

    centroid = center(solution);
    count++;
  }
  Solution result(solution, tmpElements);
  return result;
}

Solution Grasp::solve(int m, int iter, int lrcSize) {
  Solution bestSolution(constructSolution(m, lrcSize));
  for (int i = 0; i < iter; i++) {
    Solution tmpSolution(constructSolution(m, lrcSize));
    Solution neighborSolution(localSearch_->search(tmpSolution));
    if (neighborSolution.diversity() > bestSolution.diversity()) {
      bestSolution = neighborSolution;
    }
  }
  return bestSolution;
}