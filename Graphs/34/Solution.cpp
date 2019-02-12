#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "ConjuntosDisjuntos.h"
#include <algorithm>

using namespace std;
using Mapa = vector<string>;

// O(V + E) = O(numFilas * numColumnas)

// Para no salirse de los limites de la matriz
bool correcta(int i, int j, int numFilas, int numColumnas) {
	return 0 <= i && i < numFilas && 0 <= j && j < numColumnas;
}

// Vector de direcciones para ir moviendose en la matriz 
const vector<pair<int, int>> dirs = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 },
									{ -1,1 },{ 1,1 },{ -1,-1 },{ 1,-1 } };


// Comprueba si hay manchas contiguas a una dada
void comprobarManchasContiguas(Mapa const&mapa, ConjuntosDisjuntos &conjuntos, 
							   int &maximo, int i, int j) {

	// Comprobamos si hay otra en las 8 direcciones
	for (auto dir : dirs) {

		int ni = i + dir.first, nj = j + dir.second;

		// Si no se sale del mapa y hay mancha, pertenecen al mismo cjt
		if (correcta(ni, nj, mapa.size(), mapa[0].size()) 
			&& mapa[ni][nj] == '#') {

			int v = i * mapa[0].size() + j;
			int w = ni * mapa[0].size() + nj;

			if (conjuntos.buscar(v) != conjuntos.buscar(w)) {
				conjuntos.unir(v, w);
				maximo = max(maximo, conjuntos.tam(v));
			}
		}
		
	}
}

bool resuelveCaso() {
	// leer datos
	int nFilas, nColumnas;
	cin >> nFilas >> nColumnas;
	cin.get();

	if (!cin)
		return false;

	Mapa mapa(nFilas);

	// leemos la imagen
	for (string &fila : mapa) {
		getline(cin, fila);
	}

	ConjuntosDisjuntos conjuntos(nFilas * nColumnas);
	int maximo = 0;
	bool primerPixel = true;

	// Recorro la matriz
	for (int i = 0; i < mapa.size(); i++) { // tam filas
		for (int j = 0; j < mapa[0].size(); j++) { // tam columnas mapa[0].size

			// Si hay una mancha
			if (mapa[i][j] == '#') {

				if (primerPixel) {
					maximo = 1;
					primerPixel = false;
				}

				comprobarManchasContiguas(mapa, conjuntos, maximo, i, j);
			}
		}
	}

	cout << maximo << " ";

	// Numero de img adicionales
	int numImg, x, y;
	cin >> numImg;

	for (int i = 0; i < numImg; i++) {
		cin >> x >> y;
		mapa[x - 1][y - 1] = '#';

		if (primerPixel) {
			maximo = 1;
			primerPixel = false;
		}

		comprobarManchasContiguas(mapa, conjuntos, maximo, x-1, y-1 );

		if (i != numImg - 1)
			cout << maximo << " ";
		else
			cout << maximo << "\n";
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