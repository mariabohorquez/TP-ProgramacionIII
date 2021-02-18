#pragma once

#include <iostream>
#include <vector>
#include <stack>

#include "grafo.h"

class DFS {
  public:
    DFS(Grafo _grafo) : grafo(_grafo) {
      visitado.resize(grafo.len());
      for (int i = 0 ; i < grafo.len(); ++i)
        visitado[i] = false;
    };

    void correr_dfs(int inicial);

  private:
    // Lista de adyacencias que representa al grafo.
    Grafo grafo;
    // Lista de nodos visitados
    std::vector<bool> visitado;
};
