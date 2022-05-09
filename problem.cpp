#include "problem.h"

Problem::Problem(std::vector<std::vector<float>> elements, int &nElements , int &dimensionality) {
  elements_ = elements;
  nElements_ = nElements;
  dimensionality_ = dimensionality;
}

Problem::Problem() {
  elements_ = std::vector<std::vector<float>>{};
  nElements_ = 0;
  dimensionality_ = 0;
}

void Problem::Print() {
  for (int i = 0; i < nElements_; i++) {
    for(int j = 0; j < dimensionality_; j++) {
      std::cout << elements_[i][j] << " ";
    }
    std::cout << "\n";
  }
}