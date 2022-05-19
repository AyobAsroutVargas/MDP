#include "tree.h"

Tree::Tree(std::vector<std::vector<float>> data, int myM, bool d) {
  myData = data;
  finalDepth = myM;
  currentDepth = 0;
  depth = d;
}

Tree::~Tree() {}

void Tree::initializeTree() {
  currentDepth++;
  for (int i = 0; i < myData.size() - finalDepth + 1; i++) {
    std::vector<float> vectorAdded = myData[i];

    std::vector<std::vector<float>> partialSolution;
    partialSolution.push_back(myData[i]);

    std::vector<std::vector<float>> partialNoInSolution = myData;

    //Delete partialNoInsolution[i]
    std::vector<std::vector<float>>::iterator iter = partialNoInSolution.begin();
    std::advance(iter, i);
    partialNoInSolution.erase(iter);


    Node auxNode(1, i, 0, partialSolution, partialNoInSolution, vectorAdded);
    auxNode.calculateUpperBound(finalDepth);
    generatedNodes.push_back(auxNode);
    expansibleNodes.push_back(auxNode);
  }
}

void Tree::expandNode(Node nodo) {

  for (int i = 0; i < expansibleNodes.size(); i++) {
    if ((expansibleNodes[i].depth == nodo.depth) && (expansibleNodes[i].id == nodo.id) &&
        (expansibleNodes[i].upperBound == nodo.upperBound) &&
        (expansibleNodes[i].partialSolutionValue == nodo.partialSolutionValue)) {
      expansibleNodes[i] = expansibleNodes[expansibleNodes.size() - 1];
      expansibleNodes.pop_back();
      break;
    }

  }
  
  int numberOfNodes = (myData.size() - (finalDepth - nodo.partialSolution.size()) - nodo.id);
  for (int i = nodo.id + 1; i < nodo.id + 1 + numberOfNodes; i++) {
    std::vector<float> vectorAdded = myData[i];
    std::vector<std::vector<float>> partialSolution = nodo.partialSolution;
    partialSolution.push_back(myData[i]);

    std::vector<std::vector<float>> partialNoInSolution = nodo.partialNoInSolution;
    for (int j = 0; j < partialNoInSolution.size(); j++) {
      if (partialNoInSolution[j] == myData[i]) {

        //partialNoInSolution.deleteData(j);
        //Delete partialNoInsolution[j]
        std::vector<std::vector<float>>::iterator iter = partialNoInSolution.begin();
        std::advance(iter, j);
        partialNoInSolution.erase(iter);

      }
    }

    Node auxNode(nodo.depth + 1, i, nodo.partialSolutionValue, partialSolution, partialNoInSolution, vectorAdded);
    auxNode.calculateUpperBound(finalDepth);

    // Comprobamos si el hijo es solución final
    if ((nodo.depth + 1) == finalDepth) {
      if (auxNode.upperBound > bestUpperBound) {
        bestSolution = auxNode.partialSolution;
        bestUpperBound = auxNode.upperBound;
      }
    } else {
      expansibleNodes.push_back(auxNode);
    }
    generatedNodes.push_back(auxNode);
  }
}

void Tree::prune(void) {
  for (int i = 0; i < expansibleNodes.size(); i++) {
    if (expansibleNodes[i].upperBound < bestUpperBound) {
      expansibleNodes[i] = expansibleNodes[expansibleNodes.size() - 1];
      expansibleNodes.pop_back();
    }
  }
}

Node Tree::getNextToExpand(void) {
  int minIndex;

  if (!depth) {
    float min = FLT_MAX;
    for (int i = 0; i < expansibleNodes.size(); i++) {
        if (expansibleNodes[i].upperBound < min) {
        min = expansibleNodes[i].upperBound;
        minIndex = i;
      }
    }
  } else {
    float maxDepth = -1;
    for (int i = 0; i < expansibleNodes.size(); i++) {
        if (expansibleNodes[i].depth > maxDepth) {
        maxDepth = expansibleNodes[i].depth;
        minIndex = i;
      }
    }
  }
  return expansibleNodes[minIndex];
}

// --- MODIFICADO ---
// Tras la modificación este método encuentra el segundo mejor nodo y lo expande. Anteriormente
// seleccionada el mejor nodo

// Node Tree::getNextToExpand(void) {
//   int firstMinIndex = 0;
//   int secondMinIndex = 0;

//   if (!depth) {
//     float firstMin = FLT_MAX;
//     float secondMin = FLT_MAX;
//     for (int i = 0; i < expansibleNodes.size(); i++) {
//       if (expansibleNodes[i].upperBound < firstMin) {
//         secondMinIndex = firstMinIndex;
//         secondMin = firstMin;
//         firstMin = expansibleNodes[i].upperBound;
//         firstMinIndex = i;
//       } else if (expansibleNodes[i].upperBound < secondMin) {
//         secondMin = expansibleNodes[i].upperBound;
//         secondMinIndex = i;
//       }
//     }
//   } else {
//     float firstMaxDepth = -1;
//     float secondMaxDepth = -1;
//     for (int i = 0; i < expansibleNodes.size(); i++) {
//       if (expansibleNodes[i].depth > firstMaxDepth) {
//         secondMinIndex = firstMinIndex;
//         secondMaxDepth = firstMaxDepth;
//         firstMaxDepth = expansibleNodes[i].depth;
//         firstMinIndex = i;
//       } else if (expansibleNodes[i].depth > secondMaxDepth) {
//         secondMinIndex = expansibleNodes[i].depth;
//         secondMaxDepth = i;
//       }
//     }
//   }

//   return expansibleNodes[secondMinIndex];
// }