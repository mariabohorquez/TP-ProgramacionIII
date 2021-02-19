# Programacion-III

Resolucion del TP de programacion III del grupo 21

Profesor:
  Rodríguez, Guillermo

Grupo 21:
Bohorquez, Maria Gabriela – LU: 1127427
Calveti Brzezinski, Bruno William – LU:1064872

## ¿Como se corre?

Desde repl.it, presionar el boton de Run, el programa deberia correr de inmediato, dando algunas opciones para correr los ejemplos disponibles.

Tiene un output basico de los nodos del grafo y sus conexiones.

# Introducción
Escogimos aplicar los algoritmos BFS (Breadth-First Search), DFS (Depth-First Search) y Kruskal, con nuestra propia clase de grafo.

## Descripción de los algoritmos

### Algoritmo BFS: 
Método de exploración de grafo basado en anchura(Breadth-First-Search), se selecciona un nodo como raíz  para luego explorar todos los vecinos de este nodo.
Los vértices se recorren primero en ancho o por niveles.
Para cada vértice v alcanzable desde el vértice origen, BFS obtiene el camino más corto desde origen hasta v.
Los resultados de la búsqueda en ancho dependen del orden en el que tomemos los vértices adyacentes a un vértice dado.

### Algoritmo DFS: 
Método de exploración de grafo basado en profundidad (Depth-First-Search).
Recorrido sistemático de un grafo. 
Parte desde un vértice fuente explorando recursivamente sus sucesores.  
Desde el último vértice descubierto v explora en profundidad cada arco.
Cuando todos los arcos desde v han sido explorados, la búsqueda retrocede al vértice desde el cual v fue descubierto.
El proceso continúa hasta que todos lo vértices alcanzables desde el vértice fuente original han sido descubiertos.
Si restan vértices sin descubrir, uno de ellos es seleccionado como nuevo vértice fuente y la búsqueda se repite.


### Algoritmo Kruskal: 
Es un algoritmo para árboles de recubrimiento de costo mínimo, es aquel árbol cuyo costo es el menor que cualquier otro árbol de recubrimiento para el grafo. Utiliza la técnica de Greedy incorporando una arista en cada paso, mediante un criterio de selección basado en una medida de optimización.
Interpretación del criterio de selección:
Comienza con un bosque cuyos árboles son los vértices del grafo. 
En cada paso, selecciona la arista de mínimo costo que conecta dos arboles distintos. 
Termina cuando el bosque tiene un solo árbol.
