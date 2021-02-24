#include "include/grafo.h"
#include "include/grafo_con_costo.h"

#include "include/bfs.h"
#include "include/dfs.h"
#include "include/kruskal.h"

#include <iostream>

void bfs_ejemplo() {
	std::vector<arista> aristas = {
		{0, 4}, {1, 0}, {1, 2}, {2, 1}, {2, 4}, {3, 1}, {3, 2}, {4, 3}};
	int numero_de_nodos = 5;
	bool es_dirigido = true;
	Grafo grafo(aristas, numero_de_nodos, es_dirigido);

	BFS bfs = BFS(grafo);
	grafo.imprimir();
	bfs.correr_bfs(0);
}

void dfs_ejemplo() {
	std::vector<arista> aristas = {
		{0, 4}, {1, 0}, {1, 2}, {2, 1}, {2, 4}, {3, 1}, {3, 2}, {4, 3}};
	int numero_de_nodos = 5;
	bool es_dirigido = true;
	Grafo grafo(aristas, numero_de_nodos, es_dirigido);

	DFS dfs = DFS(grafo);
	grafo.imprimir();
	dfs.correr_dfs(0);
}

void kruskal_ejemplo() {
	// https://www.gatevidyalay.com/kruskals-algorithm-kruskals-algorithm-example/
	std::vector<conexion> aristas = {{1, 2, 28},
									 {2, 3, 16},
									 {3, 4, 12},
									 {4, 5, 22},
									 {5, 6, 25},
									 {6, 1, 10},
									 {5, 7, 24},
									 {2, 7, 14},
									 {4, 7, 18}};
	int numero_de_nodos = 7;
	GrafoConCosto grafo = GrafoConCosto(aristas, numero_de_nodos);
	Kruskal kruskal = Kruskal(grafo);
	kruskal.correr_kruskal();
}

void ejemplo_diferencia_bfs_dfs() {
	std::cout;
}

int main() {
	std::cout << "Escoja el ejemplo a correr:" << std::endl
			  << "[1] BFS" << std::endl
			  << "[2] DFS" << std::endl
			  << "[3] Kruskal" << std::endl;
	int opcion;
	std::cin >> opcion;
	std::cout << "Se correra el ejemplo escojido, para ver imagenes de los "
				 "grafos, ver README.md."
			  << std::endl;

	if (opcion == 1) {
		bfs_ejemplo();
	} else if (opcion == 2) {
		dfs_ejemplo();
	} else if (opcion == 3) {
		kruskal_ejemplo();
	} else {
		std::cout << "Opcion invalida, intenta de nuevo";
	}
}
