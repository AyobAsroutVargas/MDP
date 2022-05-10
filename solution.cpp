#include "solution.h"

Solution::Solution(std::vector<std::vector<float>> elements, std::vector<std::vector<float>> elementsOutside){
  elements_ = elements;
  elementsOutside_ = elementsOutside;
}

void Solution::Print(){
  for (int i = 0; i < elements_.size(); i++) {
    std::cout << "(";
    for(int j = 0; j < elements_[0].size(); j++) {
      std::cout << elements_[i][j] << "  ";
    }
    std::cout  << ")" << "\n";
  }
  std::cout << "Diversity: " << diversity();
}

float Solution::distance(std::vector<float> element1, std::vector<float> element2){
  float sum = 0;
  for (int j = 0; j < element1.size(); j++) {
    float tmpSub = element1[j] - element2[j];
    tmpSub *= tmpSub;
    sum += tmpSub;
  }
  return sqrt(sum);
}

float Solution::diversity(){
  float sum = 0;
  for (int i = 0; i < elements_.size() - 1; i++) {
    for(int j = i + 1; j < elements_.size(); j++) {
      sum += distance(elements_[i], elements_[j]);
    }
  }
  return sum;
}
