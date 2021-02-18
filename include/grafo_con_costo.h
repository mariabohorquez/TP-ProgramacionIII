#pragma once

#include <iostream>
#include <vector>

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


class GrafoConCosto
{
  public:
    std::vector<conexion> conexiones;
  
    GrafoConCosto(std::vector<conexion> &aristas, int nodos)
    {
      _n = nodos;
      conexiones = aristas;
    }

    void imprimir() 
    {
    }

    inline int len() { return _n; }

    private:
      int _n;
      int _c;
};
