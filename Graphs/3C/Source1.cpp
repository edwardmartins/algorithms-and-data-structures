// Nombre del alumno: Eduardo Martínez Martín
// Usuario del Juez: TAIS09


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
	vector<bool> markedCurrent; // un vector de marcados que se vaya actualizando por cada componente conexa
	bool bipartito;
	int guardias;

public:

	solucion(Grafo const&grafo) {

		// Inicializamos atributos
		guardias = 0;
		bipartito = true;
		marked = vector<bool>(grafo.V(),false);
		markedCurrent = vector<bool>(grafo.V(), false);
		colores = vector<bool>(grafo.V(), false);

		// Resolucion, para ir a todas las componentes conexas
		for (int i = 0; i < grafo.V(); i++) {

			// Nueva componente conexa
			if (!marked[i]) {

				dfs(grafo, i, false);

				int blancos = contarBlancos();
				int negros = contarNegros();

				guardias += min(blancos, negros);

				// reinicializamos el vector
				fill(markedCurrent.begin(), markedCurrent.end(), false);

			}

		}
	}


	int contarBlancos() {
		int cont = 0;

		for (int i = 0; i < markedCurrent.size(); i++) {
			if (markedCurrent[i]) {
				if (colores[i]) {
					cont++;
				}
			}
		}
		return cont;
	}

	int contarNegros() {
		int cont = 0;

		for (int i = 0; i < markedCurrent.size(); i++) {
			if (markedCurrent[i]) {
				if (!colores[i]) {
					cont++;
				}
			}
		}
		return cont;
	}


	// busqueda en profundidad, argumentos:
	// - grafo, punto de partida en el grafo(un vertice)
	// ---------------------------------------------------
	void dfs(Grafo const&grafo, int v, bool color) {
		marked[v] = true;
		markedCurrent[v] = true;
		colores[v] = color;

		if (bipartito) {
			for (int adyacente : grafo.ady(v)) {

				if (!marked[adyacente] && bipartito) {
					dfs(grafo, adyacente, !color);
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

	// Desde 0 a numvertices - 1
	// Esto cambia la lectura de la entrada
	Grafo grafo(numVertices);

	// vamos poniendo las aristas
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