// Nombre del alumno: Eduardo Martinez Martin
// Usuario del Juez : E31
// El coste de la solucion obtenida es O(n^2) + O(n) = O(n^2)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// funcion resolver
int resolver(vector <vector <int>> const& matriz, int ancho, int y, int x) {
	// contador de ceros por columna
	int contCeros;
	// vector auxiliar que nos dice si una columna tiene >=  que "x" ceros
	vector <bool> auxColumna(matriz[0].size());

	for (int i = 0; i < matriz[0].size(); i++) {
		contCeros = 0;
		for (int j = 0; j < matriz.size(); j++) {
			if (matriz[j][i] == 0) // se mueve por las filas por eso es [j][i]
				contCeros++;
		}
		if (contCeros >= x)
			auxColumna[i] = true;
	}

	int numFranjas = 0; // cuenta las franjas que cumplen
	int contCumplen = 0; // cuenta las columnas que cumplen

	for (int i = 0; i < ancho; i++) {
		if (auxColumna[i])
			contCumplen++;
	}

	if (contCumplen >= y)
		numFranjas++;

	for (int i = 0; i < auxColumna.size() - ancho; i++) {
		// si la columna de la izquierda tiene mas de "x" ceros se disminuye el contador
		if (auxColumna[i])
			contCumplen--;
		// se mira si la columna de la derecha tiene mas de "x" ceros
		if (auxColumna[i + ancho]) 
			contCumplen++;
		// se vuelve a evaluar si la nueva franja sumple la condicion
		if (contCumplen >= y)
			numFranjas++;
	}
	
	return numFranjas;
}


bool resuelveCaso() {
	// leer datos
	int numFilas, numColumnas, ancho, y, x;
	cin >> numFilas >> numColumnas >> ancho >> y >> x;

	if (!cin)
		return false;

	// matriz
	vector <vector <int>> matriz(numFilas, vector <int>(numColumnas));

	for (int i = 0; i < numFilas; i++) {
		for (int j = 0; j < numColumnas; j++) {
			cin >> matriz[i][j];
		}
	}

	// resolver
	int sol = resolver(matriz,ancho,y,x);

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