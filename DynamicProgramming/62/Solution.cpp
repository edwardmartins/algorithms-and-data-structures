#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "Matriz.h"

using namespace std;

/*

tablero(i,j) = maximo valor que se puede obtener en un tablero de i filas y j columnas

tablero(i,0) = 0
tablero(0,j) = 0


tablero(i,j) = max( 
					tablero(i,j) + tablero(i-1, j-1),   --> diagonal iz
					tablero(i,j) + tablero(i-1, j),		--> vertical
					tablero(i,j) + tablero(i-1, j+1))	--> diagonal derecha


O(N*N) tanto en tiempo como en espacio

*/


bool resuelveCaso() {
	// leer datos
	int N;
	cin >> N;

	if (!cin)
		return false;

	Matriz<int> tablero(N + 2, N + 2, 0);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> tablero[i][j];
		}
	}

	// resolver
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int aux = max(tablero[i][j] + tablero[i - 1][j - 1], 
						tablero[i][j] + tablero[i - 1][j]);

			tablero[i][j] = max(aux, 
								tablero[i][j] + tablero[i - 1][j + 1]);
		}
	}


	// buscar pos
	int pos;
	int max = 0;
	for (int i = 1; i <= N ; i++) {
		if (tablero[N][i] > max) {
			max = tablero[N][i];
			pos = i;
		}
	}
	
	// escribir solucion
	cout << max << " " << pos << "\n";
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