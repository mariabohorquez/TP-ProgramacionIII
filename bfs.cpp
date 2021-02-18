// bfs.cpp:
// --------
//   Implementación de algoritmo Breadth-First Search (BFS)
// 
#include "include/bfs.h"

/* 
  Aplica bfs partiendo desde el nodo inicial, imprimiendo cada nodo que visita.
*/
void BFS::correr_bfs(int inicial)
{
	std::queue<int> cola;
	cola.push(inicial);

  std::cout << "Impresion del recorrido del grafo empezando por: " << inicial << std::endl;
	while (!cola.empty())
  {
		int actual = cola.front() ;
		cola.pop();
		if (visitado[actual])
      continue;
		visitado[actual] = true;
		std::cout << "Visite el nodo " << actual << std::endl;
		for (int i = 0 ; i < grafo.ady[actual].size() ; i++)
			cola.push(grafo.ady[actual][i]);
	}
}
