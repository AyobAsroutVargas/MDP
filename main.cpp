#include "file-loader.h"
#include "problem.h"
#include "greedy.h"
#include "local_search.h"
#include "grasp.h"

int main(int argc, char* argv[]) {
  std::string filename = "max_div_15_2.txt";
  if (argc == 2) {
    filename = argv[1];
  }
  int nElements = 0, dimensionality = 0;
  std::vector<std::vector<float>> elements;
  loadFromFile(filename, elements, nElements, dimensionality);
  Problem problem(elements, nElements, dimensionality);
  Greedy greedy(problem);
  Swap* swap = new Swap();
  Grasp grasp(problem, swap);

  // std::cout << "Greedy:\n";
  // Solution greedySolution_2(greedy.constructSolution(2));
  // std::cout << "m = 2:\n";
  // greedySolution_2.Print();
  // std::cout << "\n\n";

  // Solution greedySolution_3(greedy.constructSolution(3));
  // std::cout << "m = 3:\n";
  // greedySolution_3.Print();
  // std::cout << "\n\n";

  // Solution greedySolution_4(greedy.constructSolution(4));
  // std::cout << "m = 4:\n";
  // greedySolution_4.Print();
  // std::cout << "\n\n";

  // Solution greedySolution_5(greedy.constructSolution(5));
  // std::cout << "m = 5:\n";
  // greedySolution_5.Print();
  // std::cout << "\n\n";

  // std::cout << "///Local search(swap)///:\n";
  // Solution swapSolution_2(swap->search(greedySolution_2));
  // std::cout << "m = 2:\n";
  // swapSolution_2.Print();
  // std::cout << "\n\n";

  // Solution swapSolution_3(swap->search(greedySolution_3));
  // std::cout << "m = 3:\n";
  // swapSolution_3.Print();
  // std::cout << "\n\n";

  // Solution swapSolution_4(swap->search(greedySolution_4));
  // std::cout << "m = 4:\n";
  // swapSolution_4.Print();
  // std::cout << "\n\n";

  // Solution swapSolution_5(swap->search(greedySolution_5));
  // std::cout << "m = 5:\n";
  // swapSolution_5.Print();
  // std::cout << "\n\n";

  std::cout << "Grasp:\n";

  Solution greedySolution_2_10_2(grasp.solve(2, 10, 2));
  std::cout << "m = 2, iter 10 lrc = 2:\n";
  greedySolution_2_10_2.Print();
  std::cout << "\n\n";

  Solution greedySolution_2_10_3(grasp.solve(2, 10, 3));
  std::cout << "m = 2, iter 10 lrc = 3:\n";
  greedySolution_2_10_3.Print();
  std::cout << "\n\n";

  Solution greedySolution_2_20_2(grasp.solve(2, 20, 2));
  std::cout << "m = 2, iter 20 lrc = 2:\n";
  greedySolution_2_20_2.Print();
  std::cout << "\n\n";

  Solution greedySolution_2_20_3(grasp.solve(2, 20, 3));
  std::cout << "m = 2, iter 20 lrc = 3:\n";
  greedySolution_2_20_3.Print();
  std::cout << "\n\n";
  std::cout << "\n\n";


  Solution greedySolution_3_10_2(grasp.solve(3, 10, 2));
  std::cout << "m = 3, iter 10 lrc = 2:\n";
  greedySolution_3_10_2.Print();
  std::cout << "\n\n";

  Solution greedySolution_3_10_3(grasp.solve(3, 10, 3));
  std::cout << "m = 3, iter 10 lrc = 3:\n";
  greedySolution_3_10_3.Print();
  std::cout << "\n\n";

  Solution greedySolution_3_20_2(grasp.solve(3, 20, 2));
  std::cout << "m = 3, iter 20 lrc = 2:\n";
  greedySolution_3_20_2.Print();
  std::cout << "\n\n";

  Solution greedySolution_3_20_3(grasp.solve(3, 20, 3));
  std::cout << "m = 3, iter 20 lrc = 3:\n";
  greedySolution_3_20_3.Print();
  std::cout << "\n\n";
  std::cout << "\n\n";


  Solution greedySolution_4_10_2(grasp.solve(4, 10, 2));
  std::cout << "m = 4, iter 10 lrc = 2:\n";
  greedySolution_4_10_2.Print();
  std::cout << "\n\n";

  Solution greedySolution_4_10_3(grasp.solve(4, 10, 3));
  std::cout << "m = 4, iter 10 lrc = 3:\n";
  greedySolution_4_10_3.Print();
  std::cout << "\n\n";

  Solution greedySolution_4_20_2(grasp.solve(4, 20, 2));
  std::cout << "m = 4, iter 20 lrc = 2:\n";
  greedySolution_4_20_2.Print();
  std::cout << "\n\n";

  Solution greedySolution_4_20_3(grasp.solve(4, 20, 3));
  std::cout << "m = 4, iter 20 lrc = 3:\n";
  greedySolution_4_20_3.Print();
  std::cout << "\n\n";
  std::cout << "\n\n";


  Solution greedySolution_5_10_2(grasp.solve(5, 10, 2));
  std::cout << "m = 5, iter 10 lrc = 2:\n";
  greedySolution_5_10_2.Print();
  std::cout << "\n\n";

  Solution greedySolution_5_10_3(grasp.solve(5, 10, 3));
  std::cout << "m = 5, iter 10 lrc = 3:\n";
  greedySolution_5_10_3.Print();
  std::cout << "\n\n";

  Solution greedySolution_5_20_2(grasp.solve(5, 20, 2));
  std::cout << "m = 5, iter 20 lrc = 2:\n";
  greedySolution_5_20_2.Print();
  std::cout << "\n\n";

  Solution greedySolution_5_20_3(grasp.solve(5, 20, 3));
  std::cout << "m = 5, iter 20 lrc = 3:\n";
  greedySolution_5_20_3.Print();
  std::cout << "\n\n";
}