#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// coste --> O(N * logN) por el coste de ordenar

bool resuelveCaso() {
	// leer datos
	int maxPesoSilla, totalUsuarios;
	cin >> maxPesoSilla >> totalUsuarios;

	if (!cin)
		return false;

	vector <int> pesos(totalUsuarios);

	for (int i = 0; i < totalUsuarios; i++) {
		cin >> pesos[i];

	}

	sort(pesos.begin(), pesos.end());
	
	// resolver
	int i = 0; // el menor peso
	int j = totalUsuarios - 1; // el mayor peso
	int numViajes = 0;

	while (i <= j) {

		// Si la silla soporta el peso mayor y el menor, hacen el viaje
		if (pesos[j] + pesos[i] <= maxPesoSilla) {
			i++;
			j--;
			numViajes++;
		} // si no sube solo la persona de mayor peso
		else {
			j--;
			numViajes++;
		}
	}

	// escribir solucion
	cout << numViajes << "\n";
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