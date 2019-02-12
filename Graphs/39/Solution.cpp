#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"

using namespace std;

const int INFINITO = 1000000000;

class solution {

private:

	vector<AristaDirigida<int>> edgeTo;
	vector<int> distTo;
	IndexPQ<int> pq;

	void relax(AristaDirigida<int> e) {
		int v = e.from(), w = e.to();

		if (distTo[w] > distTo[v] + e.valor()) {
			distTo[w] = distTo[v] + e.valor();
			edgeTo[w] = e;
			pq.update(w, distTo[w]);
		}
	}


public:

	solution(GrafoDirigidoValorado<int> const&G, int s) : edgeTo(G.V()), 
		distTo(G.V(),INFINITO), pq(G.V()) {

		distTo[s] = 0;
		pq.push(s, 0);

		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();

			for (auto e : G.ady(v)) {
				relax(e);
			}
		}
	}

	int valorTo(int v) {
		return distTo[v];
	}

	bool hayCamino(int v) {
		return (distTo[v] != INFINITO);
	}

};


bool resuelveCaso() {
	// leer los datos de la entrada
	int vertices, aristas;
	cin >> vertices >> aristas;

	if (!std::cin)
		return false;

	GrafoDirigidoValorado<int> grafo(vertices);
	int a, b, valor;

	for (int i = 0; i < aristas; i++) {
		cin >> a >> b >> valor;
		AristaDirigida<int> arista(a - 1, b - 1, valor);
		grafo.ponArista(arista);
	}

	int oficina, numPaquetes;
	cin >> oficina >> numPaquetes;

	solution sol(grafo, oficina - 1);
	GrafoDirigidoValorado<int> grafoInverso = grafo.inverso();
	solution solInv(grafoInverso, oficina - 1);

	bool imposible = false;
	int totalIda = 0;
	int totalVuelta = 0;
	int casa;

	for (int i = 0; i < numPaquetes; i++) {

		// Costes de Ida
		cin >> casa;
		if (sol.hayCamino(casa - 1)) {
			totalIda += sol.valorTo(casa - 1);
		}
		else
			imposible = true;

		// Costes de vuelta
		if (solInv.hayCamino(casa - 1)) {
			totalVuelta += solInv.valorTo(casa - 1);
		}
		else
			imposible = true;
	}
	
	// escribir sol
	if (!imposible) {
		cout << totalIda + totalVuelta << "\n";
	}
	else {
		cout << "Imposible" << "\n";
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