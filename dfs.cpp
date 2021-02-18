// dfs.cpp:
// --------
//   Implementación de algoritmo Depth-First Search (DFS)
// 
#include "include/dfs.h"

#include <iostream>
#include <vector>
#include <stack>

/* 
  Aplica dfs partiendo desde el nodo inicial, imprimiendo cada nodo que visita.
*/
void DFS::correr_dfs(int inicial) {
	std::stack<int> pila;
	pila.push(inicial);

  std::cout << "Impresion del recorrido del grafo empezando por: " << inicial << std::endl;
	while (!pila.empty()) {
		int actual = pila.top();
		pila.pop();
		if (visitado[actual]) 
      continue;
		visitado[actual] = true;
		std::cout << "Visite el nodo " << actual << std::endl;
		for (int i = 0 ; i < grafo.ady[actual].size() ; i++)
			pila.push(grafo.ady[actual][i]);
	}
}
