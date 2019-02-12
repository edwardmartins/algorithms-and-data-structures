#include <iostream>
#include <vector>
#include "PriorityQueue.h"
#include "EdgeWeightedGraph.h"
#include "DisjointSets.h"

using namespace std;


class Kruskal {

private:
	PriorityQueue<Arista<int>> edges;
	int vertexSize;

public:
	Kruskal(PriorityQueue<Arista<int>> &edges, int v) : edges(edges), vertexSize(v) {

		vector<Arista<int>> minimalSpaninTree;
		ConjuntosDisjuntos disjointSets(vertexSize);

		while (!edges.empty() && minimalSpaninTree.size() < vertexSize - 1) {

			Arista<int> arista = edges.top(); edges.pop();
			int v = arista.uno(); int w = arista.otro(v);

			if (!disjointSets.unidos(v, w)) { // if both vertex are not in the same set
				disjointSets.unir(v, w); // we put them in the same set
				minimalSpaninTree.push_back(arista);
			}
		}
	}

};
