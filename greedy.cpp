#include "greedy.h"

Greedy::Greedy(Problem problem){
 problem_ = problem;
 nElements_ = problem.nElements_;
 dimensionality_ = problem.dimensionality_;
}

float Greedy::distance(std::vector<float> element1, std::vector<float> element2){
  float sum = 0;
  for (int j = 0; j < element1.size(); j++) {
    float tmpSub = element1[j] - element2[j];
    tmpSub *= tmpSub;
    sum += tmpSub;
  }
  return sqrt(sum);
}

std::vector<float> Greedy::center(std::vector<std::vector<float>> set){
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

int Greedy::getFurthestElementIndex(std::vector<std::vector<float>> tmpElements, std::vector<float> centroid) {
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

Solution Greedy::constructSolution(int m) {
  std::vector<std::vector<float>> tmpElements(problem_.elements_);
  std::vector<std::vector<float>> solution;
  std::vector<float> centroid(center(tmpElements));
  int count = 0;
  while(count < m) {
    int index = getFurthestElementIndex(tmpElements, centroid);
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
