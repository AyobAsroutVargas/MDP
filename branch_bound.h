#ifndef BRANCH_BOUND_
#define BRANCH_BOUND_

#include "greedy.h"
#include "grasp.h"
#include "tree.h"

class BranchBound {
 public:
  BranchBound(std::vector<std::vector<float>> myVectors, int m, bool depth);
  ~BranchBound();

  std::vector<std::vector<float>> vectorsData;  // Datos del problema (vectores)
  std::vector<std::vector<float>> noInSolution; // Elementos no pertenecientes a la solución
  std::vector<std::vector<float>> bestSolution; // Solución actual del problema
  int stopNumber; // Número de iteraciones ha realizar
  float bestSolutionValue;  // Valor de la función objetivo

  Tree* myTree; // Árbol para ejecutar el algoritmo
  // Algoritmos auxiliares para obtener las cotas inicialles
  Greedy* greedy;
  Grasp* graspAlg;

  // // Método que obtiene le centro de un conjunto de vectores
  // std::vector<float> getCenter(std::vector<std::vector<float>> currentVectors);

  // // Método que calcula la distancia entre dos vectores
  // float distBetVect(std::vector<float> first, std::vector<float> second);

  float solve(); // Método de resolución del problema
};

#endif