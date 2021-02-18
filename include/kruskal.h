#pragma once

#include <vector>

// Tipo de datos que representa una estructura de conjuntos disjuntos.
struct conjuntos_disjuntos {
	int elementos;
	int conjuntos;
	std::vector<int> padre;

	// Constructor del tipo, que inicializa la estructura con n elementos.
	conjuntos_disjuntos(int n) {
		elementos = conjuntos = n;
		padre.resize(n);
		for (int i = 0 ; i < n ; i++)
			padre[i] = i;
	}

	// Consigue el representante del elemento dado.
	int representante(int elem) {
		if (padre[elem] == elem)
			return elem;
		return padre[elem] = representante(padre[elem]);
	}

/*
  Intenta unir dos elementos, devolviendo true si la unión reduce el números de conjuntos presentes y false de lo contrario.
*/
	bool unir(int elem1, int elem2) {
		int rep1 = representante(elem1);
		int rep2 = representante(elem2);
		if (rep1 == rep2) // Si los representantes son iguales, los elementos ya pertenecían al mismo conjunto.
			return false;
		padre[rep1] = rep2; // Un representante se vuelve padre del otro.
		conjuntos--; // La cantidad de conjuntos decrece.
		return true;
	}
};

class Kruskal {
  public:
    Kruskal(GrafoConCosto _grafo) : grafo(_grafo) {};

    int correr_kruskal();

  private:
    // Lista de adyacencias que representa al grafo.
    GrafoConCosto grafo;
};
