#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// coste total --> // O(N * Log N) siendo N el numero de pilas

void resuelveCaso() {
	// leer datos
	int numPilas, voltaje;
	cin >> numPilas >> voltaje;


	vector<int> pilas(numPilas);
	for (int i = 0; i < numPilas; i++) {
		cin >> pilas[i];
	}

	sort(pilas.begin(), pilas.end()); // O(N * Log N) siendo N el numero de pilas

	int numCoches = 0;
	int i = 0;
	int j = pilas.size() - 1;

	// Si el mayor con el mas pequeño encienden el coche aumenta el numero de coches
	while (i < j) {
		if (pilas[i] + pilas[j] >= voltaje) {
			i++;
			j--;
			numCoches++;
		}
		else { // En otro caso buscamos el siguiente menor que mas se aproxime al voltaje
			i++; 
		}
	}

	// escribir solucion
	cout << numCoches << "\n";
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}