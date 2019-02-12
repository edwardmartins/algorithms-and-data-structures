#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include "PriorityQueue.h"
#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"

using namespace std;

// Coste --> O(E * Log E) --> Siendo E el numero de aristas,
// que representan el numero de puentes

bool resuelveCaso() {
	// leer datos
	int numVertices, numAristas;
	cin >> numVertices >> numAristas; // vertices = islas, aristas = puentes

	if (!cin)
		return false;

	PriorityQueue<Arista<int>> colaAristas;

	int v, w, valor;
	for (int i = 0; i < numAristas; i++) {
		cin >> v >> w >> valor;
		Arista<int> arista(v - 1, w - 1, valor);
		// Relleno cola con las aristas de menor a mayor 
		colaAristas.push(arista);
	}

	queue<Arista<int>> mst; // arbol de recubrimiento minimo
	ConjuntosDisjuntos conjuntos(numVertices); // creo tantos conjuntos como vertices

	while (!colaAristas.empty() && mst.size() < numVertices - 1) {

		Arista<int> arista = colaAristas.top(); colaAristas.pop();
		int v = arista.uno(); int w = arista.otro(v);

		if (!conjuntos.unidos(v, w)) { // si no estaban unidos no crean ciclo
			conjuntos.unir(v, w); // los podemos unir
			mst.push(arista);
		}
	}

	if (conjuntos.num_cjtos() > 1)
		cout << "No hay puentes suficientes" << "\n";
	else {
		int coste = 0;
		for (int i = 0; i < numVertices - 1; i++) {
			coste += mst.front().valor(); mst.pop();
		}
		cout << coste << "\n";
	}
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