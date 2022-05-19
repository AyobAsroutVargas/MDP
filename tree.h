#ifndef TREE_
#define TREE_

#include "node.h"

class Tree {
 public:
  Tree(std::vector<std::vector<float>> myData, int, bool);
  ~Tree();
  std::vector<Node> generatedNodes; // Vector de nodos generados
  std::vector<std::vector<float>> myData; // Datos del problema a resolver

  int currentDepth;
  int finalDepth; //Profundidad máxima del arbol
  bool depth; // Flag que indica si queremos seleccionar el siguiente nodo a expandir
              // por profundidad o por cota mínima

  float bestUpperBound; // Mejor cota superior actual
  std::vector<std::vector<float>> bestSolution; // Mejor solución encontrada
  std::vector<Node> expansibleNodes;  // Vector de nodos a expandir

  // Método que expande un nodo
  void expandNode(Node nodo);
  // Método que inicializa el árbol
  void initializeTree();
  // Método que calcula la cota superior de un nodo
  void calculateUpperBound(Node);
  // Método que devuelve el siguiente nodo a expandir
  Node getNextToExpand(void);
  // Método que poda los nodos con una cota superior inferior a la mejor cota actual
  void prune(void);
};

#endif