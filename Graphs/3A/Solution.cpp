
#include <iostream>
#include <iomanip>
#include <fstream>
#include "GrafoDirigido.h"

using namespace std;

class solution {

private:
	vector<bool> marked;
	bool arb;
	int visitados;

public:

	solution(GrafoDirigido const&GF) {
		marked = vector<bool> (GF.V(), false);
		visitados = 0;
		arb = true;
	}

	void dfs(GrafoDirigido const& GF, int v) {
		marked[v] = true;
		visitados++;

		if (arb) {
			for (int w : GF.ady(v)) {

				if (arb) {
					if (!marked[w]) {
						dfs(GF, w);
					} 
					else
						arb = false;
				}
			}
		}
	}

	int getVisitados() {
		return visitados;
	}

	bool getArborescencia() {
		return arb;
	}

};



bool resuelveCaso() {

	int vertices, aristas;
	cin >> vertices >> aristas;

	if (!cin)
		return false;

	GrafoDirigido gf(vertices);
	int v1, v2;

	for (int i = 0; i < aristas; i++) {
		cin >> v1 >> v2;
		gf.ponArista(v1, v2);
	}

	GrafoDirigido gfInverso = gf.inverso();
	int numRaices = 0;
	int raizSol;
	bool arborescencia = true;

	for (int i = 0; i < vertices && arborescencia; i++) {

		if (gfInverso.ady(i).empty()) { // Si hay solo una raiz
			numRaices++;
			raizSol = i;
		}
	}

	if (numRaices == 1) { // Una unica raiz
		solution sol(gf);
		sol.dfs(gf, raizSol);

		if (!(sol.getVisitados() == gf.V()) || !sol.getArborescencia()) {
			arborescencia = false;
		}
	}
	else {
		arborescencia = false;
	}
			
	
	// escribir sol
	if (arborescencia) {
		cout << "SI " << raizSol << "\n";
	}
	else {
		cout << "NO\n";
	}


	return true;

}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 


	while (resuelveCaso())
		;

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}