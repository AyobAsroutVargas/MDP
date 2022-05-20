#include "branch_bound.h"

BranchBound::BranchBound(std::vector<std::vector<float>> myVectors, int m, bool depth) {
  int size = myVectors.size();
  int dimensionality = myVectors[0].size();

  Problem problem(myVectors, size, dimensionality);
  
  greedy = new Greedy(problem);
  
  Swap* localSearch = new Swap();
  graspAlg = new Grasp(problem, localSearch);

  myTree = new Tree(myVectors, m, depth);

  vectorsData = myVectors;
  stopNumber = m;
}

BranchBound::~BranchBound() {}

float BranchBound::solve() {
  //Solution initialSolution = greedy->constructSolution(stopNumber);
  Solution initialSolution = graspAlg->solve(stopNumber, 20, 3);
  myTree->bestUpperBound = initialSolution.diversity();
  myTree->bestSolution = initialSolution.elements_;
  std::cout << "cota: " << myTree->bestUpperBound << "\n";
  myTree->initializeTree();
  
  while (myTree->expansibleNodes.size() != 0) {
    Node currentNode = myTree->getNextToExpand();
    myTree->expandNode(currentNode);
    myTree->prune();
  }
  bestSolutionValue = myTree->bestUpperBound;
  //myTree->writeTree(std::cout);
  return (myTree->bestUpperBound);
}