// Nombre del alumno:Eduardo Martínez Martín
// Usuario del Juez: E31

// La solucion obtenida tiene un coste O(n), siendo "n" la longitud del vector

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(vector <int> const& edificios, int &ini, int&fin, int alturaTransporte) {

	int maxLong = 0;
	int ultimoIni = 0;
	ini = 0;
	fin = 0;

	for (int i = 0; i < edificios.size(); i++) {
		if (edificios[i] > alturaTransporte) {
			if (maxLong < i - ultimoIni + 1) {
				maxLong = i - ultimoIni + 1;
				ini = ultimoIni;
			}

		}
		else {
			ultimoIni = i + 1;
		}
	}
	fin = ini + maxLong - 1;
}


void resuelveCaso() {
	// leer los datos de la entrada
	int numeroEdificios;
	int alturaTransporte;
	int ini;
	int fin;

	cin >> numeroEdificios;
	cin >> alturaTransporte;

	vector <int> edificios(numeroEdificios);

	for (int i = 0; i < edificios.size(); i++) {
		cin >> edificios[i];
	}

	// resolver
	resolver(edificios,ini,fin,alturaTransporte);

	// escribir sol
	cout << ini << " " << fin << endl;

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