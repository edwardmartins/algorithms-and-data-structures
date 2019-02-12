

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm> // max and min function
#include "Grafo.h"

using namespace std;

class MaximaComponenteConexa {

private:
	vector<bool> marked; // v[i] = si ha visitado el vertice "i" o no
	int maximo; // maximo numero de vertices en una componente conexa

public:

	MaximaComponenteConexa(Grafo const&G) : marked(G.V(), false), maximo(0) {
		maxComponenteConexa(G);
	}

	void busquedaEnProfundidad(Grafo const&G, int v, int &tam) { 
		marked[v] = true;
		++tam;

		for (int w : G.ady(v)) {
		
			if (!marked[w]) {
				busquedaEnProfundidad(G, w, tam);
			}
		}
	}

	void maxComponenteConexa(Grafo const&G) {

		for (int v = 0; v < G.V(); v++) {
			if (!marked[v]) {
				int tam = 0;
				busquedaEnProfundidad(G, v, tam);
				maximo = max(tam, maximo);
			}
		}
	}

	int getMaximo() const {
		return maximo;
	}


};


void resuelveCaso() {
	// leer datos
	int numVertices, numAristas;
	cin >> numVertices >> numAristas;

	Grafo grafo(numVertices); 

	// vamos poniendo las aristas
	int v, w;
	for (int i = 0; i < numAristas; i++) {
		cin >> v >> w;
		grafo.ponArista(v - 1, w - 1);
	}

	// resolver
	MaximaComponenteConexa mcc(grafo);

	// escribir solucion
	cout << mcc.getMaximo() << "\n";

}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}