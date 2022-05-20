#include "file-loader.h"
#include "problem.h"
#include "greedy.h"
#include "local_search.h"
#include "grasp.h"
#include "branch_bound.h"

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

  // Greedy:

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

  // Grasp:

  // std::cout << "Grasp:\n";

  // Solution greedySolution_2_10_2(grasp.solve(2, 10, 2));
  // std::cout << "m = 2, iter 10 lrc = 2:\n";
  // greedySolution_2_10_2.Print();
  // std::cout << "\n\n";

  // Solution greedySolution_2_10_3(grasp.solve(2, 10, 3));
  // std::cout << "m = 2, iter 10 lrc = 3:\n";
  // greedySolution_2_10_3.Print();
  // std::cout << "\n\n";

  // Solution greedySolution_2_20_2(grasp.solve(2, 20, 2));
  // std::cout << "m = 2, iter 20 lrc = 2:\n";
  // greedySolution_2_20_2.Print();
  // std::cout << "\n\n";

  // Solution greedySolution_2_20_3(grasp.solve(2, 20, 3));
  // std::cout << "m = 2, iter 20 lrc = 3:\n";
  // greedySolution_2_20_3.Print();
  // std::cout << "\n\n";
  // std::cout << "\n\n";


  // Solution greedySolution_3_10_2(grasp.solve(3, 10, 2));
  // std::cout << "m = 3, iter 10 lrc = 2:\n";
  // greedySolution_3_10_2.Print();
  // std::cout << "\n\n";

  // Solution greedySolution_3_10_3(grasp.solve(3, 10, 3));
  // std::cout << "m = 3, iter 10 lrc = 3:\n";
  // greedySolution_3_10_3.Print();
  // std::cout << "\n\n";

  // Solution greedySolution_3_20_2(grasp.solve(3, 20, 2));
  // std::cout << "m = 3, iter 20 lrc = 2:\n";
  // greedySolution_3_20_2.Print();
  // std::cout << "\n\n";

  // Solution greedySolution_3_20_3(grasp.solve(3, 20, 3));
  // std::cout << "m = 3, iter 20 lrc = 3:\n";
  // greedySolution_3_20_3.Print();
  // std::cout << "\n\n";
  // std::cout << "\n\n";


  // Solution greedySolution_4_10_2(grasp.solve(4, 10, 2));
  // std::cout << "m = 4, iter 10 lrc = 2:\n";
  // greedySolution_4_10_2.Print();
  // std::cout << "\n\n";

  // Solution greedySolution_4_10_3(grasp.solve(4, 10, 3));
  // std::cout << "m = 4, iter 10 lrc = 3:\n";
  // greedySolution_4_10_3.Print();
  // std::cout << "\n\n";

  // Solution greedySolution_4_20_2(grasp.solve(4, 20, 2));
  // std::cout << "m = 4, iter 20 lrc = 2:\n";
  // greedySolution_4_20_2.Print();
  // std::cout << "\n\n";

  // Solution greedySolution_4_20_3(grasp.solve(4, 20, 3));
  // std::cout << "m = 4, iter 20 lrc = 3:\n";
  // greedySolution_4_20_3.Print();
  // std::cout << "\n\n";
  // std::cout << "\n\n";


  // Solution greedySolution_5_10_2(grasp.solve(5, 10, 2));
  // std::cout << "m = 5, iter 10 lrc = 2:\n";
  // greedySolution_5_10_2.Print();
  // std::cout << "\n\n";

  // Solution greedySolution_5_10_3(grasp.solve(5, 10, 3));
  // std::cout << "m = 5, iter 10 lrc = 3:\n";
  // greedySolution_5_10_3.Print();
  // std::cout << "\n\n";

  // Solution greedySolution_5_20_2(grasp.solve(5, 20, 2));
  // std::cout << "m = 5, iter 20 lrc = 2:\n";
  // greedySolution_5_20_2.Print();
  // std::cout << "\n\n";

  // Solution greedySolution_5_20_3(grasp.solve(5, 20, 3));
  // std::cout << "m = 5, iter 20 lrc = 3:\n";
  // greedySolution_5_20_3.Print();
  // std::cout << "\n\n";

  // Branch and bound:

  // std::cout << "Branch and bound:\n";
  // branchBound.solve();
  // std::cout << "Valor de la solucion: " << branchBound.bestSolutionValue << "\n";
  // Solution babSol(branchBound.myTree->bestSolution, branchBound.noInSolution);
  // babSol.Print();
  // std::cout << "\n" << branchBound.myTree->generatedNodes.size() << "\n\n";
  // std::cout << "\n\n";

  std::cout << "Branch and bound:\n";

  BranchBound branchBound_2(problem.elements_, 2, true);

  clock_t t2 = clock();
  branchBound_2.solve();
  long double time2 = (long double)(clock() - t2);
  long double bab_time_2 = time2 / CLOCKS_PER_SEC;

  Solution babSol_2(branchBound_2.myTree->bestSolution, branchBound_2.noInSolution);
  babSol_2.Print();
  std::cout << "\n" << "Generated notes:" << branchBound_2.myTree->generatedNodes.size();
  std::cout << "\n" << "CPU:" << bab_time_2 << "\n\n";
  std::cout << "\n\n";



  BranchBound branchBound_3(problem.elements_, 3, true);

  clock_t t3 = clock();
  branchBound_3.solve();
  long double time3 = (long double)(clock() - t3);
  long double bab_time_3 = time3 / CLOCKS_PER_SEC;

  Solution babSol_3(branchBound_3.myTree->bestSolution, branchBound_3.noInSolution);
  babSol_3.Print();
  std::cout << "\n" << "Generated notes:" << branchBound_3.myTree->generatedNodes.size();
  std::cout << "\n" << "CPU:" << bab_time_3 << "\n\n";
  std::cout << "\n\n";



  BranchBound branchBound_4(problem.elements_, 4, true);

  clock_t t4 = clock();
  branchBound_4.solve();
  long double time4 = (long double)(clock() - t4);
  long double bab_time_4 = time4 / CLOCKS_PER_SEC;

  Solution babSol_4(branchBound_4.myTree->bestSolution, branchBound_4.noInSolution);
  babSol_4.Print();
  std::cout << "\n" << "Generated notes:" << branchBound_4.myTree->generatedNodes.size();
  std::cout << "\n" << "CPU:" << bab_time_4 << "\n\n";
  std::cout << "\n\n";



  BranchBound branchBound_5(problem.elements_, 5, true);

  clock_t t5 = clock();
  branchBound_5.solve();
  long double time5 = (long double)(clock() - t5);
  long double bab_time_5 = time5 / CLOCKS_PER_SEC;

  Solution babSol_5(branchBound_5.myTree->bestSolution, branchBound_5.noInSolution);
  babSol_5.Print();
  std::cout << "\n" << "Generated notes:" << branchBound_5.myTree->generatedNodes.size();
  std::cout << "\n" << "CPU:" << bab_time_5 << "\n\n";
  std::cout << "\n\n";
}