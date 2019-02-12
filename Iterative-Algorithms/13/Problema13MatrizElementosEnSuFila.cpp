// Nombre del alumno: Eduardo Martinez Martin
// Usuario del Juez : E31

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// funcion resolver
int resolver(vector <vector <int>> const& matriz) {
	int cont = 0;

	for (int i = 0; i < matriz.size(); i++) {
		for (int j = 0; j < matriz[i].size() ; j++) {
			if (matriz[i][j] == i)
				cont++;
		}
	}
	return cont;
}


bool resuelveCaso() {
	// leer datos
	int numFilas;
	int numColumnas;

	cin >> numFilas;
	cin >> numColumnas;

	if (!cin) 
		return false;

	// matriz
	vector <vector <int>> matriz(numFilas, vector <int>(numColumnas));

	for (int i = 0; i < numFilas; i++) {
		for (int j = 0; j < numColumnas; j++){
			cin >> matriz[i][j];
		}
	}

	// resolver
	int sol = resolver(matriz);

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