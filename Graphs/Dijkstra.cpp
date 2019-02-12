#include <iostream>
#include <vector>
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"

using namespace std;


class Dijkstra {

private:

	vector<AristaDirigida<int>> edgeTo;
	vector<int> distTo;
	IndexPQ<int> pq;

	void relax(AristaDirigida<int> e) {
		int v = e.from(), w = e.to();

		if (distTo[w] > distTo[v] + e.valor()){ 
			distTo[w] = distTo[v] + e.valor();
			edgeTo[w] = e;
			pq.update(w, distTo[w]);
		}
	}


public:

	Dijkstra(GrafoDirigidoValorado<int> const&G, int s) : edgeTo(G.V()),
		distTo(G.V(), INT_MAX), pq(G.V()) {

		distTo[s] = 0;
		pq.push(s, 0);

		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();

			for (auto e : G.ady(v)) {
				relax(e);
			}
		}
	}

};