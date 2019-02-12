#include <iostream>
#include <iomanip>
#include <fstream>
#include "GrafoValorado.h"

using namespace std;

class solution {

private:
	vector<bool> marked;

public:

	solution(GrafoValorado<int> const& G) {
		marked = vector<bool>(G.V(), false);
	}

	bool hayCamino(int v) const {
		return marked[v];
	}

	void dfs(GrafoValorado<int> const& G, int origen, int anchura) {
		marked[origen] = true;

		for (auto w : G.ady(origen)) {
			int x = w.otro(origen);

			if (!marked[x]) {
				if (w.valor() >= anchura)
					dfs(G, x, anchura);
			}
		}
				
	}
};


bool resuelveCaso() {
	// leer datos
	// Calles
	int numVertices, numAristas;
	cin >> numVertices >> numAristas;

	if (!cin)
		return false;

	GrafoValorado<int> grafoValorado(numVertices);

	int v, w, valor;
	for (int i = 0; i < numAristas; i++) {
		cin >> v >> w >> valor;
		Arista<int> arista(v - 1, w - 1, valor);
		grafoValorado.ponArista(arista);
	}

	// Camiones
	int numCamiones;
	int origen, destino, anchura;

	cin >> numCamiones;

	for (int i = 0; i < numCamiones; i++) {
		cin >> origen >> destino >> anchura;

		// resolver
		solution sol(grafoValorado);
		sol.dfs(grafoValorado, origen - 1, anchura);

		// escribir solucion
		if (sol.hayCamino(destino - 1))
			cout << "SI" << "\n";
		else
			cout << "NO" << "\n";

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