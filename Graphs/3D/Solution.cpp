
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "IndexPQ.h"
#include "GrafoDirigidoValorado.h"

using namespace std;


// Coste --> O(A * Log V) --> siendo A el numero de aristas y V el numero de vertices

const int INF = 1000000000;

class Dijkstra {

private:

	vector<int> distTo;
	IndexPQ<int> pq;
	vector<unsigned long int> caminos; 

	void relax(AristaDirigida<int> e) {
		int v = e.from(), w = e.to();

		if (distTo[w] > distTo[v] + e.valor()) {
			distTo[w] = distTo[v] + e.valor();
			pq.update(w, distTo[w]);

			caminos[w] = caminos[v]; 
		}
		else if (distTo[w] == distTo[v] + e.valor()) {
			
			caminos[w] += caminos[v];
		}
	}


public:

	Dijkstra(GrafoDirigidoValorado<int> const&G, int s) : 
		distTo(G.V(),INF), pq(G.V()), caminos(G.V(), 0) {

		caminos[s] = 1;
		distTo[s] = 0;
		pq.push(s, 0);

		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();

			for (auto e : G.ady(v)) {
				relax(e);
			}
		}

		cout << caminos[G.V() - 1] << "\n";
	}

};


bool resuelveCaso() {
	// leer datos
	int V, A;
	cin >> V >> A;

	if (!cin)
		return false;

	int a, b, valor;
	AristaDirigida<int> arista;
	GrafoDirigidoValorado<int> grafo(V);

	for (int i = 0; i < A; i++) { 
		cin >> a >> b >> valor;
		AristaDirigida<int> arista(a - 1, b - 1, valor);
		AristaDirigida<int> aristaInv(b - 1, a - 1, valor);
		grafo.ponArista(arista);
		grafo.ponArista(aristaInv);
	}

	// resolver
	Dijkstra sol(grafo, 0);
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