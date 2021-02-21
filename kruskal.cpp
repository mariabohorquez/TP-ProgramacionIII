// kruskal.cpp:
// ------------
//   Implementación del algoritmo Kruskal.
// 
#include "include/grafo_con_costo.h"
#include "include/kruskal.h"

#include <iostream>
#include <vector>
#include <queue>


/* 
  Aplica krukal y calcula el costo del árbol cobertor mínimo.
*/
int Kruskal::correr_kruskal() {
  // Cola de prioridades, donde organizamos por costo de la conexion.
	std::priority_queue< conexion, std::vector<conexion>, std::greater<conexion> > cola(std::greater<conexion>(), grafo.conexiones);
  // Se declara e inicializa un manejador de conjuntos disjuntos.
	ConjuntosDistintos componentes(grafo.len());
	int costo_total = 0;
	while (!cola.empty() || componentes.conjuntos > 1) {
		conexion actual = cola.top();
		cola.pop();
		if (componentes.unir(actual.origen, actual.destino))
    {
      std::cout << "Unimos al elemento " << actual.origen << " con " << actual.destino << std::endl;
      costo_total += actual.costo;
    }
	}
  std::cout << "El costo total del árbol cobertor mínimo es: " << costo_total;
	return costo_total;
}
