// Nombre del alumno: Eduardo Martinez Martin
// Usuario del Juez : E31
// El coste de la solucion obtenida es O(n^3) --> coste cubico

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// suma una columna 
int sumaColumna(vector <vector <int>> const& m, int f, int c, int sizeSubM) {
	int total = 0;

	for (int i = f; i < sizeSubM + f; i++) {
		total += m[i][c]; // columna fija
	}
	return total;
}

// suma una fila 
int sumafila(vector <vector <int>> const& m, int f, int sizeSubM) {
	int total = 0;

	for (int i = 0; i < sizeSubM; i++) {
		total += m[f][i]; // fila fija
	}
	return total;
}

// funcion resolver
int resolver(vector <vector <int>> const& matriz, int sizeSubM) {
	// sumar primer subcuadrante
	int sumaSubcuadrante = 0;

	for (int i = 0; i < sizeSubM; i++) {
		sumaSubcuadrante += sumaColumna(matriz, 0, i, sizeSubM);
	}

	int sumaSubcuadranteInicial = sumaSubcuadrante;
	int subcuadranteMaximo = sumaSubcuadrante;

	for (int j = 0; j <= matriz.size() - sizeSubM; j++) {
		// avance de izquierda a derecha, resto columna izquierda y sumo derecha
		for (int i = 0; i < matriz.size() - sizeSubM; i++) {
			sumaSubcuadrante -= sumaColumna(matriz, j, i, sizeSubM);
			sumaSubcuadrante += sumaColumna(matriz, j, i + sizeSubM, sizeSubM);

			if (sumaSubcuadrante > subcuadranteMaximo)
				subcuadranteMaximo = sumaSubcuadrante;
		}
		// cambio subcuadrante inicial restando fila de arriba y sumando la de abajo
		if (j != matriz.size() - sizeSubM) {
			sumaSubcuadranteInicial -= sumafila(matriz, j, sizeSubM);
			sumaSubcuadranteInicial += sumafila(matriz, j + sizeSubM, sizeSubM);
			sumaSubcuadrante = sumaSubcuadranteInicial;

			if (sumaSubcuadrante > subcuadranteMaximo)
				subcuadranteMaximo = sumaSubcuadrante;
		}
	}
	return subcuadranteMaximo;
}

bool resuelveCaso() {
	// leer datos
	int sizeM;
	int sizeSubM;
	cin >> sizeM;
	cin >> sizeSubM;

	if (!cin)
		return false;

	// matriz
	vector <vector <int>> matriz(sizeM, vector <int>(sizeM));

	for (int i = 0; i < sizeM; i++) {
		for (int j = 0; j < sizeM; j++) {
			cin >> matriz[i][j];
		}
	}

	// resolver
	int sol = resolver(matriz, sizeSubM);

	// escribir sol
	cout << sol << endl;
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