#pragma once

#include <iostream>
#include <vector>
#include <queue>

#include "grafo.h"

class BFS {
  public:
    BFS(Grafo _grafo) : grafo(_grafo) {
      visitado.resize(grafo.len());
      for (int i = 0 ; i < grafo.len(); ++i)
        visitado[i] = false;
    };

    void correr_bfs(int inicial);

  private:
    // Lista de adyacencias que representa al grafo.
    Grafo grafo;
    // Lista de nodos visitados
    std::vector<bool> visitado;
};