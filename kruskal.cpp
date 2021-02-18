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
	std::priority_queue< conexion, std::vector<conexion>, std::greater<conexion> > cola
  // Cola de prioridades (usada como un min-heap) de conexiones.
  (std::greater<conexion>(), grafo.conexiones);
  // Se declara e inicializa un manejador de conjuntos disjuntos.
	conjuntos_disjuntos componentes(grafo.len());
	int costo_total = 0;
	while (!cola.empty() || componentes.conjuntos > 1) {
		conexion actual = cola.top();
		cola.pop();
		if (componentes.unir(actual.origen, actual.destino))
			costo_total += actual.costo;
	}
	return costo_total;
}
