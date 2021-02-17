// kruskal.cpp:
// ------------
//   Implementación del algoritmo Kruskal.
// 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Cantidad de nodos del grafo.
int n;

// Cantidad de conexiones del grafo.
int m;

// Tipo de datos que representa una conexión.
struct conexion {
	int origen;
	int destino;
	int costo;

	// Compara una conexión con otra por su costo.
	bool operator>(const conexion &otra) const {
		return costo > otra.costo;
	}
};

vector< conexion > conexiones;

// Tipo de datos que representa una estructura de conjuntos disjuntos.
struct conjuntos_disjuntos {
	int elementos;
	int conjuntos;
	vector<int> padre;

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

/* 
  Lee un grafo de la entrada, con el siguiente formato:
  Primero habrá un número n (correspondiente a la cantidad de nodos del grafo).
  Luego habrá un número m (correspondiente a la cantidad de conexiones del grafo).
  Siguen m líneas (una por cada conexión). Cada línea tendrá:
  Tres números a, b y c, que dictan que hay una conexión entre el nodo a y el nodo b, con costo c.
*/
void leer_grafo() {
	conexiones.clear();
	cin >> n;
	cin >> m;
	conexiones.resize(m);
	for (int i = 0 ; i < m ; i++)
  {
		conexion c;
		cin >> c.origen >> c.destino >> c.costo; 
		conexiones.push_back(c);
	}
}

/* 
  Aplica krukal y calcula el costo del árbol cobertor mínimo.
*/
int kruskal() {
	priority_queue< conexion, vector<conexion>, greater<conexion> > cola
  // Cola de prioridades (usada como un min-heap) de conexiones.
  (greater<conexion>(), conexiones);
  // Se declara e inicializa un manejador de conjuntos disjuntos.
	conjuntos_disjuntos componentes(n);
	int costo_total = 0;
	while (!cola.empty() || componentes.conjuntos > 1) {
		conexion actual = cola.top();
		cola.pop();
		if (componentes.unir(actual.origen, actual.destino))
			costo_total += actual.costo;
	}
	return costo_total;
}

/* 
  El programa principal lee un grafo de la entrada y luego aplica kruskall.
*/
int main () {
	leer_grafo();
	cout << kruskal() << endl;

	return 0;
}
