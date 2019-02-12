// Nombre del alumno:Eduardo Martínez Martín
// Usuario del Juez: E31
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void costeMin(vector <vector<int>> const& matrix, int k, int n, vector <int> &contadores, int &coste, int &costeMinimo, bool &haySolucion) {

	for (int i = 0; i < n; i++) {

		coste = coste + matrix[i][k]; // voy cambiando de producto con k y miro su precio en todos los supers
		contadores[i]++;

		if (contadores[i] <= 3) {

			if (k == matrix[0].size() - 1) {
				haySolucion = true;

				if (coste < costeMinimo) {
					costeMinimo = coste;
				}
			}
			else {
				costeMin(matrix, k + 1, n, contadores, coste, costeMinimo, haySolucion);
			}
		}
		coste = coste - matrix[i][k];
		contadores[i]--;
	}
}


void resuelveCaso() {
	// leer datos
	int numMercados;
	int numProductos;

	cin >> numMercados;
	cin >> numProductos;

	vector <vector<int>> matrix(numMercados, vector <int>(numProductos));
	int costeMinimo = 0;

	for (int i = 0; i < numMercados; i++) {
		for (int j = 0; j < numProductos; j++) {
			cin >> matrix[i][j];
			costeMinimo = costeMinimo + matrix[i][j];
		}
	}

	// resolver
	int coste = 0;
	vector <int> contadores(numMercados); // < 3 todos los contadores
	bool haySolucion = false;

	costeMin(matrix, 0, numMercados, contadores, coste, costeMinimo, haySolucion);


	// escribir solucion
	if (haySolucion)
		cout << costeMinimo << endl;
	else
		cout << "Sin solucion factible" << endl;

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