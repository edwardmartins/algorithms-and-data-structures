#include <iostream>
#include <iomanip>
#include <fstream>
#include "PriorityQueue.h"

using namespace std;

struct caja {
	int id;
	int tiempo = 0;
};

bool operator <(caja const&c1, caja const&c2) {
	return (c1.tiempo < c2.tiempo || c1.tiempo == c2.tiempo && c1.id < c2.id);
}

bool resuelveCaso() {
	// leer datos
	int numCajas, numClientes;
	cin >> numCajas >> numClientes;

	if (numCajas == 0 && numClientes == 0)
		return false;

	PriorityQueue<caja> cajas;

	caja aux;
	for (int i = 0; i < numCajas; i++) { // O( N * log N(cajas))
		aux.id = i + 1;
		cajas.push(aux);
	}


	// resolver
	int tiempo;

	while (numClientes--) { // O( C(clientes) * log N(cajas))
		cin >> tiempo;
		caja auxcaja = cajas.top(); cajas.pop();
		auxcaja.tiempo += tiempo;
		cajas.push(auxcaja);
	}
	cout << cajas.top().id << "\n";

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