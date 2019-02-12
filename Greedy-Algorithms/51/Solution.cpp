// Nombre del alumno: Eduardo Martínez Martín
// Usuario del Juez: TAIS09

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Complejidad --> O( N * log N) por el coste de ordenar

bool resuelveCaso() {
	// leer datos
	int N;
	cin >> N;

	if (N == 0)
		return false;

	//resolver
	vector<int> alturas(N);
	for (int i = 0; i < N; i++) { // O(N)
		cin >> alturas[i];
	}

	sort(alturas.begin(), alturas.end(), less<int>()); // O(N * log N)
	
	vector<int> esquis(N);
	for (int i = 0; i < N; i++) { // O(N)
		cin >> esquis[i];
	}

	sort(esquis.begin(), esquis.end(), less<int>()); // O(N * log N)

	int total = 0;
	for (int i = 0; i < N; i++) { // O(N)
		total += abs(alturas[i] - esquis[i]);
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