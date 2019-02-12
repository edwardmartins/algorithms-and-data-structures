#include <iostream>
#include <iomanip>
#include <fstream>
#include "PriorityQueue.h"

using namespace std;

struct atril {
	int numInstrumentos;
	int numPartituras = 1; //  Se garantiza una partitura para cada tipo de instrumento
	int grupoMayor;
};

bool operator <(atril const& a, atril const &b) {
	return (a.grupoMayor > b.grupoMayor);
}

bool resuelveCaso() {

	// leer datos
	int partituras, instrumentos;
	cin >> partituras >> instrumentos;

	if (!cin)
		return false;

	PriorityQueue<atril> atriles;
	atril auxAtril;

	for (int i = 0; i < instrumentos; i++) {
		cin >> auxAtril.numInstrumentos;
		auxAtril.grupoMayor = auxAtril.numInstrumentos;
		atriles.push(auxAtril);
	}

	// resolver
	int aRepartir = partituras - instrumentos; // le damos una a cada instrumento

	for (int i = 0; i < aRepartir; i++) {

		auxAtril = atriles.top(); atriles.pop();
		auxAtril.numPartituras++;
		int n = auxAtril.numInstrumentos / auxAtril.numPartituras;

		// Si el resto es diferente de cero el reparto no es exacto y habra grupos mas grandes
		if (auxAtril.numInstrumentos % auxAtril.numPartituras != 0)
			auxAtril.grupoMayor = n + 1;
		else
			auxAtril.grupoMayor = n;

		// Volvemos a meterlo a la cola para seguir repartiendo al grupo mas grande
		atriles.push(auxAtril);
	}

	// escribir solucion
	cout << atriles.top().grupoMayor << "\n";
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