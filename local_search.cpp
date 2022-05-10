#include "local_search.h"

Swap::Swap(Problem problem) {
  problem_ = problem;
}

float Swap::distance(std::vector<float> element1, std::vector<float> element2){
  float sum = 0;
  for (int j = 0; j < element1.size(); j++) {
    float tmpSub = element1[j] - element2[j];
    tmpSub *= tmpSub;
    sum += tmpSub;
  }
  return sqrt(sum);
}

std::vector<float> Swap::center(std::vector<std::vector<float>> set){
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

int Swap::getFurthestElementIndex(std::vector<std::vector<float>> tmpElements, std::vector<float> centroid) {
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

Solution Swap::Apply(Solution initialSolution) {
  float maxDiversity = initialSolution.diversity();
  int extractIndex = -1;
  int insertIndex = -1;
  Solution bestSolution(initialSolution);

  for (int i = 0; i < initialSolution.elements_.size(); i++) {
    std::vector<std::vector<float>> tmpElements(initialSolution.elements_);
    float currentDiversity = maxDiversity;

    for (int j = 0; j < initialSolution.elements_.size(); j++) {
      if (i == j) {
        continue;
      }
      currentDiversity -= distance(initialSolution.elements_[i], initialSolution.elements_[j]);
    }

    auto it = tmpElements.begin() + i;
    std::rotate(it, it+1, tmpElements.end());
    tmpElements.pop_back();

    for (int j = 0; j < initialSolution.elementsOutside_.size(); j++) {
      float tmpCurrentDiversity = currentDiversity;
      for (int k = 0; k < tmpElements.size(); k++) {
        tmpCurrentDiversity += distance(tmpElements[k], initialSolution.elementsOutside_[j]);
      }

      if (tmpCurrentDiversity > maxDiversity) {
        maxDiversity = tmpCurrentDiversity;
        extractIndex = i;
        insertIndex = j;
      }
    }
  }
  if (maxDiversity != initialSolution.diversity()) {
    std::vector<float> tmpSwap(initialSolution.elements_[extractIndex]);
    bestSolution.elements_[extractIndex] = initialSolution.elementsOutside_[insertIndex];
    bestSolution.elementsOutside_[insertIndex] = tmpSwap;
  }


  return bestSolution;
}

Solution Swap::search(Solution initialSolution) {
  Solution currentSolution(initialSolution);
  Solution BestSolution(Apply(initialSolution));
  while (BestSolution.diversity() < currentSolution.diversity()) {
    currentSolution = BestSolution;
    BestSolution = Apply(BestSolution);
  }
  return BestSolution;
}