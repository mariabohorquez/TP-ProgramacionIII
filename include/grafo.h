#pragma once

#include <iostream>
#include <vector>

struct arista {
    int origen, destino;
};

class Grafo
{
  public:
    std::vector<std::vector<int>> ady;
  
    Grafo(std::vector<arista> const &aristas, int nodos, bool es_dirigido = false)
    {
        _n = nodos;
        _es_dirigido = es_dirigido;
        ady.resize(nodos);
        for (auto &arista: aristas) {
            ady[arista.origen].push_back(arista.destino);
            if (!es_dirigido) {
              ady[arista.destino].push_back(arista.origen);
            }
        }
    }

    void imprimir() 
    {
      std::cout << "Impresion de las conexiones del grafo" << std::endl;
      for (int i = 0; i < len(); ++i)
      {
        std::cout << "El nodo " << i << " esta conectado con -> "; 
        for ( auto x  : ady[i] ) std::cout << x << ' ';
        std::cout << std::endl;
      }
    }

    inline int len() { return _n; }

    private:
      int _n;
      bool _es_dirigido;
};
