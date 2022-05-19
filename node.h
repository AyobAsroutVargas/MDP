#ifndef NODE_
#define NODE_

#include <vector>
#include <cfloat>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

class Node {
 public:
  Node(int depth, int id, float partialSolutionValue, std::vector<std::vector<float>> partialSolution, std::vector<std::vector<float>> pns, std::vector<float> addedNode);
  ~Node();
  float partialSolutionValue; // Valor de la función objetivo de la solución parcial
  float upperBound; // Cota superior del nodo
  int depth;  // Profundidad del nodo
  int id; // id del nodo
  std::vector<std::vector<float>> partialSolution;  // Solución parcial
  std::vector<std::vector<float>> partialNoInSolution;  // Elementos que no están en la solución parcial

  std::vector<float> vectorAdded; // Vector que se ha añadido en la generación de este nodo

  // Método que obtiene la mejor distancia que no esté incluida en la solución
  float getBestDistance();

  // Funciones para recalcular el valor de la función objetivo
  float diversityFromAdd(std::vector<std::vector<float>>, std::vector<float>, float);
  float distBetVect(std::vector<float> first, std::vector<float> second);

  // Función para calcular la cota superior
  void calculateUpperBound(int m);
};

#endif