
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Grafo.h"

using namespace std;


class solucion {


private:
	vector<bool> marked; // Para marcar los nodos por los que vamos pasando
	vector<bool> colores; // vector de colores para saber de que color es cada vertice
	bool bipartito;
	int guardias;

public:

	solucion(Grafo const&grafo) {

		// Inicializamos atributos
		guardias = 0;
		bipartito = true;
		marked = vector<bool>(grafo.V(),false);
		colores = vector<bool>(grafo.V(), false);

		// Resolucion, para ir a todas las componentes conexas
		for (int i = 0; i < grafo.V(); i++) {

			// Nueva componente conexa
			if (!marked[i]) {
				int blancos = 0;
				int negros = 0;

				dfs(grafo, i, false, blancos, negros); // false = negro, true = blanco
				guardias += min(blancos, negros);

			}
		}
	}


	void dfs(Grafo const&grafo, int v, bool color, int&blancos, int&negros) {
		marked[v] = true;
		colores[v] = color;

		if (color) { blancos++; }
		else { negros++;  }

		if (bipartito) {
			for (int adyacente : grafo.ady(v)) {

				if (!marked[adyacente] && bipartito) {
					dfs(grafo, adyacente, !color,blancos,negros);
				}
				else { // si vuelve a un nodo ya visitado 

					// Y es del mismo color
					if (colores[v] == colores[adyacente]) {
						bipartito = false;
					}
				}
			}
		}
	}

	bool esBipartito() {
		return bipartito;
	}

	int getGuardias() {
		return guardias;
	}

};



bool resuelveCaso() {
	// leer datos
	int numVertices, numAristas;
	cin >> numVertices >> numAristas;

	if (!cin)
		return false;

	Grafo grafo(numVertices);

	int v, w;
	for (int i = 0; i < numAristas; i++) {
		cin >> v >> w;
		grafo.ponArista(v - 1, w - 1);
	}

	// resolver
	solucion sol(grafo); // O( V + E )

	
	// escribir solucion
	if (sol.esBipartito()) {
		cout << sol.getGuardias() << "\n";
	}
	else
		cout << "IMPOSIBLE" << "\n";
	

	return true;

}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	while (resuelveCaso());


#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}