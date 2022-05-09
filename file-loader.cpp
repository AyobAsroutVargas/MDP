#include "file-loader.h"

void loadFromFile(const std::string filename, std::vector<std::vector<float>>& elements, int &nElements , int &dimensionality) {
  std::string line;
  std::ifstream file(filename);

  if (!file.is_open()) {
    std::cout << "Unable to open file";
    return;
  }

  for (int i = 0; i < 2; i++) {
    std::getline(file, line);
    std::istringstream iss (line);
    std::string word;

    while (iss >> word) {
      if (i == 0) {
        nElements = std::stoi(word);
      } else {
        dimensionality = std::stoi(word);
      }
    }
  }

  // while (std::getline(file, line)) {
  //   std::istringstream iss (line);
  //   std::string tmpString;
  //   int tmpX, tmpY;
  //   std::vector<float> tmpPointVector;
  //   while (iss >> tmpString) {
  //     std::stringstream tmpPointString(tmpString);
  //     std::string tmpPointSplitString;
  //     while (std::getline(tmpPointString, tmpPointSplitString, ',')) {
  //       tmpX = std::stoi(tmpPointSplitString);
  //       std::getline(tmpPointString, tmpPointSplitString, ',');
  //       tmpY = std::stoi(tmpPointSplitString);
  //     }
  //     Point tmpPoint(tmpX, tmpY);
  //     tmpPointVector.push_back(tmpPoint);
  //   }
  //   elements.push_back(tmpPointVector);
  // }

  while (std::getline(file, line)) {
    std::istringstream iss (line);
    std::string tmpString;
    float tmpNumber;
    std::vector<float> tmpVector;
    while (iss >> tmpString) {
      std::replace( tmpString.begin(), tmpString.end(), ',', '.');
      std::istringstream tmpstream(tmpString);
      tmpstream >> tmpNumber;
      tmpVector.push_back(tmpNumber);
    }
    elements.push_back(tmpVector);
  }
  file.close();
}