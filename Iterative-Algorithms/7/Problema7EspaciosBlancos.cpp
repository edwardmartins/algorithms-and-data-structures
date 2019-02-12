// Nombre del alumno: Eduardo Martinez Martin
// Usuario del Juez : E31

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// función que resuelve el problema
void resolver(vector <string> const& linea, int &ini, int &fin) {
	int maxLong = 0;
	int ultimoIni = 0;
	ini = 0;
	fin = 0;

	for (int i = 0; i < linea.size(); i++) {
		if (linea[i] == "FFFFFF") {
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

bool resuelveCaso() {
	// leer los datos de la entrada
	int numLineas;
	int numPixels;
	int ini;
	int fin;
	string elem;

	cin >> numLineas;
	cin >> numPixels;

	if (!cin)
		return false;

	vector <string> linea;

	for (int i = 0; i < numLineas; ++i) {
		for (int j = 0; j < numPixels; ++j) {
			cin >> elem;
			linea.push_back(elem);
		}
		resolver(linea, ini, fin);
		// escribir sol
		cout << ini << " " << fin << endl;
		// una vez resuelto lo vacia
		linea.clear();
	}
	cout << endl;
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