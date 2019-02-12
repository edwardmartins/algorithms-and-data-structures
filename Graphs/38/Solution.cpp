#include <iostream>
#include <iomanip>
#include <fstream>
#include "IndexPQ.h"
#include "GrafoDirigidoValorado.h"

using namespace std;

class solution {

private:
 
	vector<int> valueTo; // vector de valores
	int ultimaPagina;
	bool alcanzable;
	IndexPQ<int> pq;

	void relax(AristaDirigida<int> arista) {
	
		int v = arista.from(); int w = arista.to();

		if (valueTo[w] > valueTo[v] + arista.valor()) {
			valueTo[w] = valueTo[v] + arista.valor();
			pq.update(w, valueTo[w]);
		}
	}

public:

	solution(GrafoDirigidoValorado<int> const&G, int s, int ultima): 
		valueTo(G.V(),1000000000),
		ultimaPagina(ultima),
		alcanzable(false), 
		pq(G.V()) {


		valueTo[s] = 0;
		pq.push(s, 0); // pos, valor

		while (!pq.empty()) {

			int v = pq.top().elem; pq.pop();

			if (v == ultimaPagina)
				alcanzable = true;

			for (auto arista : G.ady(v)) {
				relax(arista);
			}
		}
	}

	int getCoste() {
		return valueTo[ultimaPagina];
	}

	bool esAlcanzable() {
		return alcanzable;
	}
	
};


bool resuelveCaso() {
	// leer datos
	int numPaginas;
	cin >> numPaginas; // de 1 a numPaginas

	if (numPaginas == 0)
		return false;

	vector<int> tiempoCarga(numPaginas);
	int t;

	for (int i = 0; i < numPaginas; i++) {
		cin >> t;
		tiempoCarga[i] = t;
	}
	
	int numEnlaces;
	cin >> numEnlaces;
	GrafoDirigidoValorado<int> G(numPaginas);

	int a, b, valor;
	for (int i = 0; i < numEnlaces; i++) {
		cin >> a >> b >> valor;
		valor += tiempoCarga[a - 1]; // le añado el tiempo de carga de la pagina de la que parto
		AristaDirigida<int> arista(a - 1, b - 1, valor);
		G.ponArista(arista);
	}

	// resolver
	solution sol(G, 0, numPaginas - 1);

	// escribir solucion
	if (sol.esAlcanzable()) {
		// el coste de llegar mas el tiempo de carga de la ultima pagina
		cout << sol.getCoste() + tiempoCarga[numPaginas - 1] << "\n"; 
	}
	else {
		cout << "IMPOSIBLE" << endl;
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