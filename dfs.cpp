// dfs.cpp:
// --------
//   Implementación de algoritmo Depth-First Search (DFS)
// 

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Cantidad de nodos del grafo.
int n;

// Lista de adyacencias que representa al grafo.
vector< vector<int> > ady;

// Lista de nodos visitados. Si visitados[i] es true, entonces el nodo i ya fue visitado.
vector<bool> visitado;

/* 
  Lee un grafo de la entrada, con el siguiente formato:
  Primero habrá un número n (correspondiente a la cantidad de nodos del grafo).
  Luego habrá un número m (correspondiente a la cantidad de conexiones del grafo).
  Siguen m líneas (una por cada conexión). Cada línea tendrá:
  Dos números a y b, que dictan que hay una conexión entre el nodo a y el nodo b.
*/
void leer_grafo() {
	ady.clear();
	cin >> n;
	ady.resize(n);

	int m;  // Cantidad de conexiones.
	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		ady[a].push_back(b);
		ady[b].push_back(a);
	}
}

/* 
  Aplica dfs partiendo desde el nodo inicial, imprimiendo cada nodo que visita.
*/
void dfs(int inicial) {
	visitado.resize(n);
	for (int i = 0 ; i < n ; i++)
		visitado[i] = false;

	stack<int> pila;
	pila.push(inicial); // El único alcanzable hasta el momento es el inicial.
	while (!pila.empty()) {
		int actual = pila.top();
		pila.pop();
		if (visitado[actual]) 
      continue;
		visitado[actual] = true;
		cout << "Visite el nodo " << actual << endl;
		for (int i = 0 ; i < ady[actual].size() ; i++)
			pila.push(ady[actual][i]);
	}
}

/*
  El programa principal lee un grafo de la entrada y luego aplica dfs desde el nodo 0.
*/
int main ()
{
	leer_grafo();
	dfs(0);
	return 0;
}