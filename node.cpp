#include "node.h"

Node::Node(int d, int newId, float psValue,  std::vector<std::vector<float>> ps, std::vector<std::vector<float>> pns, std::vector<float> added){
  depth = d;
  id = newId;
  partialSolutionValue = psValue;
  partialSolution = ps;
  partialNoInSolution = pns;
  vectorAdded = added;
}

Node::~Node(){}

float Node::distBetVect(std::vector<float> first, std::vector<float> second) {
  float totalSum = 0;

  for (int i = 0; i < first.size(); i++) {
    totalSum += pow ((first[i] - second[i]), 2.0);
  }
  return(sqrt(totalSum));
}

float Node::diversityFromAdd(std::vector<std::vector<float>> solution, std::vector<float> added, float oldValue) {
  float newValue = oldValue;

  for (int i = 0; i < solution.size(); i++) {
    if (solution[i] != added)
      newValue += distBetVect(solution[i], added);
  }
  return (newValue);
}

float Node::getBestDistance() {
  float bestOut = -1;

  for (int i = 0; i < partialNoInSolution.size(); i++) {
    for (int j = i + 1; j < partialNoInSolution.size(); j++) {
      float currentDistance = distBetVect(partialNoInSolution[i], partialNoInSolution[j]);
      if (currentDistance > bestOut) {
        bestOut = currentDistance;
      }
    }
  }
  for (int i = 0; i < partialSolution.size(); i++) {
    for (int j = 0; j < partialNoInSolution.size(); j++) {
      float currentDistance = distBetVect(partialSolution[i], partialNoInSolution[j]);

      if (currentDistance > bestOut) {
        bestOut = currentDistance;
      }
    }
  }
  return bestOut;
}

void Node::calculateUpperBound(int m) {
  partialSolutionValue = diversityFromAdd(partialSolution, vectorAdded, partialSolutionValue);
  
  int weightsToAdd = (partialSolution.size() * (m - partialSolution.size()));
  weightsToAdd += ((m - partialSolution.size()) * ((m - partialSolution.size()) - 1)) / 2;
  float maxDist = getBestDistance();

  upperBound = (weightsToAdd * maxDist) + partialSolutionValue;
}