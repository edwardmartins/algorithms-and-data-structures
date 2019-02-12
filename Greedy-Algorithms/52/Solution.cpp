#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>  
#include <algorithm>  // std::sort
#include <functional>   // std::greater

using namespace std;

// Funcion de seleccion --> vamos seleccionando los puntos de los broncos de mayor a menor
// y los puntos de sus rivales de menor a mayor para maximizar la diferencia de puntos 

// Test de factibilidad --> que los broncos hayan ganado el partido, es decir que bi > ri

// El coste es O(N * Log N) --> por el coste de ordenar, siendo N el numero de partidos

bool resuelveCaso() {

	// leer datos
	int numPartidos;
	cin >> numPartidos;

	if (numPartidos == 0)
		return false;

	// ri ( puntos conseguidos por los rivales )
	vector<int> r(numPartidos);
	for (int i = 0; i < numPartidos; i++) {
		cin >> r[i];
	}

	// bi ( puntos conseguidos por los broncos )
	vector<int> b(numPartidos);
	for (int i = 0; i < numPartidos; i++) {
		cin >> b[i];
	}

	// resolver
	sort(b.begin(), b.end(), greater<int>()); // O(N*Log N) 
	sort(r.begin(), r.end(), less<int>()); // O(N*Log N) 

	int total = 0;
	for (int i = 0; i < numPartidos; i++) { // O(N) 
		if (b[i] > r[i]) { // test de factibilidad
			total += b[i] - r[i];
		}
	}

	// escribir solucion
	cout << total << "\n";
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