#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

// Si  no se puede garantizar la victoria con el equipo 
// mas pequeño en la ciudad con menos enemigos descartamos el equipo
// en caso contrario si se puede garantizar la victoria

// Coste --> O(N * log N) que es el coste de ordenar siendo N el numero equipos

bool resuelveCaso() {
	// leer datos
	int N;
	cin >> N;

	if (!cin)
		return false;

	vector <int> enemigos(N);
	vector <int> defensores(N);

	for (int i = 0; i < N; i++) {
		cin >> enemigos[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> defensores[i];
	}

	sort(enemigos.begin(), enemigos.end());
	sort(defensores.begin(), defensores.end());

	// resolver
	int i = 0; // enemigos
	int j = 0; // defensores
	int victorias = 0;

	while (j < N) {
		if (defensores[j] < enemigos[i]) { // no se garantiza la victoria
			j++; // descartamos el equipo
		}
		else {
			i++;
			j++;
			victorias++;
		}
	}
	// escribir solucion
	cout << victorias << "\n";
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