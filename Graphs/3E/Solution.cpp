
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"


using namespace std;

const int INF = 1000000000;

class Solution
{

private:
	vector<AristaDirigida<int>> edgeTo;
	vector<int> distTo;
	IndexPQ<int> pq; 

	void relax(AristaDirigida<int> e)
	{
		int v = e.from(), w = e.to();
		if (distTo[w] > distTo[v] + e.valor())
		{
			distTo[w] = distTo[v] + e.valor();
			edgeTo[w] = e;
			pq.update(w, distTo[w]);
		}
	}


public:

	Solution(GrafoDirigidoValorado<int> const&G, int s) : edgeTo(G.V()), 
		distTo(G.V(), INF), pq(G.V()) {

		distTo[s] = 0;
		pq.push(s, 0);

		while (!pq.empty())
		{
			int v = pq.top().elem; pq.pop();
			for (auto e : G.ady(v))
				relax(e);
		}
	}

	bool hayCamino(int v) {
		return distTo[v] != INF;
	}

	int numRatones(int s, int t) {
		int total = 0;
		for (int i = 0; i < distTo.size(); i++) {
			if (hayCamino(i) && i != s && distTo[i] <= t) {
				total++;
			}
		}
		return total;
	}
};


bool resuelveCaso() {
	// leer datos
	int N, S, T, P;
	cin >> N >> S >> T >> P; 

	if (!cin)
		return false;

	// resolver
	GrafoDirigidoValorado<int> grafo(N);

	int a, b, valor;
	for (int i = 0; i < P; i++) {
		cin >> a >> b >> valor;
		AristaDirigida<int> a(a - 1, b - 1, valor);
		grafo.ponArista(a);
	}

	GrafoDirigidoValorado<int> grafoInverso = grafo.inverso();

	Solution sol(grafoInverso, S - 1);

	// escribir solucion
	int n = sol.numRatones(S - 1, T);
	cout << n << "\n";

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