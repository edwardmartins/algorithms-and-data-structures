
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm> // max and min function
#include "Grafo.h"

using namespace std;

class GrafoBipartito {

private:
	vector<bool> marked; // v[i] = si ha visitado el vertice "i" o no
	vector<bool> colores; // v[i] = true es de un color, false del otro
	bool _bipartito = true; 

public:

	GrafoBipartito(Grafo const&G) : marked(G.V(), false), colores(G.V()) {

		for (int v = 0; v < G.V(); ++v) {
			if (!marked[v]) { 
				busquedaEnProfundidad(G, v, false);
			}
		}
	}
	

	void busquedaEnProfundidad(Grafo const&G, int v, bool color) { 
		marked[v] = true;
		colores[v] = color;

		for (int w : G.ady(v)) {
			
			if (!marked[w]) {
				busquedaEnProfundidad(G, w, !color);
			}
			else {
				if (colores[v] == colores[w]) {
					_bipartito = false;
				}
			}
		}
	}

	bool bipartito() {
		return _bipartito;
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
		grafo.ponArista(v, w);
	}

	// resolver
	GrafoBipartito gbip(grafo); // O( V + E )

	// escribir solucion
	if (gbip.bipartito())
		cout << "SI";
	else
		cout << "NO";
	cout << "\n";

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