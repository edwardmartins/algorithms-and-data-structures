#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <string>
#include "Matriz.h"


using namespace std;

const int INF = 1000000000;

/*
	 C,k (i, j) = coste mínimo para ir de i a j pudiendo utilizar
				como vértices intermedios aquellos entre 1 y k.

	C,k=0 (i, j) = G[i, j]

	Ck (i, j) = mín( Ck−1(i, j), Ck−1(i, k) + Ck−1(k, j))
	Coste(O(n^3) en tiempo y en espacio O(n^2))

*/

void Floyd(Matriz<int> &G) {
	int n = G.numfils() - 1;

	// actualizaciones de la matriz
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				int temp = G[i][k] + G[k][j];
				if (temp < G[i][j]) { // es mejor pasar por k
					G[i][j] = temp;
				}
			}
		}
	}
}
bool resuelveCaso() {
	// leer datos
	int numVertices, numAristas;
	cin >> numVertices >> numAristas;

	if (!cin)
		return false;

	Matriz<int> grafo(numVertices + 1, numVertices + 1, INF);

	for (int i = 1; i <= numVertices; i++) {
		grafo[i][i] = 0;
	}

	unordered_map<string,int> nombres;
	string u, v;
	int cont = 1;

	for (int i = 0; i < numAristas; i++) {
		cin >> u >> v;
		auto itU = nombres.find(u); auto itV = nombres.find(v);

		if (itU == nombres.end()) { // no esta el nombre
			nombres[u] = cont;
			cont++;
		}
		if (itV == nombres.end()) { // no esta el nombre
			nombres[v] = cont;
			cont++;
		}
		grafo[nombres[u]][nombres[v]] = 1;
		grafo[nombres[v]][nombres[u]] = 1;
	}

	// resolver
	Floyd(grafo);
	
	int max = 0;
	int n = grafo.numfils() - 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (grafo[i][j] > max) {
				max = grafo[i][j];
			}
		}
	}

	// escribir solucion
	if (max != INF)
		cout << max << "\n";
	else
		cout << "DESCONECTADA" << "\n";
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