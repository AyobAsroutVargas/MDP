#include "file-loader.h"
#include "problem.h"
#include "greedy.h"
#include "local_search.h"

int main(int argc, char* argv[]) {
  std::string filename = "max_div_15_2.txt";
  if (argc == 2) {
    filename = argv[1];
  }
  int nElements = 0, dimensionality = 0;
  std::vector<std::vector<float>> elements;
  loadFromFile(filename, elements, nElements, dimensionality);
  Problem problem(elements, nElements, dimensionality);
  //problem.Print();
  Greedy greedy(problem);
  Swap swap(problem);
  // int kk = 1;
  // std::vector<std::vector<float>> elementsTest;
  // elementsTest.push_back(greedy.center(problem.elements_));

  // Problem problemTest(elementsTest, kk, dimensionality);
  // std::cout << "center: "; problemTest.Print();
  // std::cout << "distance: " << greedy.distance(problem.elements_[0], problem.elements_[1]) << "\n";

  std::cout << "Greedy:\n";
  Solution greedySolution_2(greedy.constructSolution(2));
  std::cout << "m = 2:\n";
  greedySolution_2.Print();
  std::cout << "\n\n";

  Solution greedySolution_3(greedy.constructSolution(3));
  std::cout << "m = 3:\n";
  greedySolution_3.Print();
  std::cout << "\n\n";

  Solution greedySolution_4(greedy.constructSolution(4));
  std::cout << "m = 4:\n";
  greedySolution_4.Print();
  std::cout << "\n\n";

  Solution greedySolution_5(greedy.constructSolution(5));
  std::cout << "m = 5:\n";
  greedySolution_5.Print();
  std::cout << "\n\n";

  std::cout << "///Local search(swap)///:\n";
  Solution swapSolution_2(swap.search(greedySolution_2));
  std::cout << "m = 2:\n";
  swapSolution_2.Print();
  std::cout << "\n\n";

  Solution swapSolution_3(swap.search(greedySolution_3));
  std::cout << "m = 3:\n";
  swapSolution_3.Print();
  std::cout << "\n\n";

  Solution swapSolution_4(swap.search(greedySolution_4));
  std::cout << "m = 4:\n";
  swapSolution_4.Print();
  std::cout << "\n\n";

  Solution swapSolution_5(swap.search(greedySolution_5));
  std::cout << "m = 5:\n";
  swapSolution_5.Print();
  std::cout << "\n\n";
}