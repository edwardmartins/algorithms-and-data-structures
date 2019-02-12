// Nombre del alumno: Eduardo Martinez Martin
// Usuario del Juez : E31
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// struct
struct tSol {
	int suma = 0;
	int ini = - 1;
	int longitud = 0;
};

// función que resuelve el problema
tSol resolver(vector <int> const& v) {
	int maximaSuma = 0, lastIni = 0, sumaAcumulada = 0;
	tSol sol;

	for (int i = 0; i < v.size(); i++) {
		sumaAcumulada = sumaAcumulada + v[i];
		if (sumaAcumulada > 0) {
			if (sumaAcumulada > maximaSuma ) {
				maximaSuma = sumaAcumulada;
				sol.ini = lastIni;
				sol.longitud = i - lastIni + 1;
			}
			else if (sumaAcumulada == maximaSuma
				&& i - lastIni + 1 < sol.longitud) {
				maximaSuma = sumaAcumulada;
				sol.ini = lastIni;
				sol.longitud = i - lastIni + 1;
			}
		}
		else{ lastIni = i + 1; sumaAcumulada = 0;}
	}
	sol.suma = maximaSuma;
	return sol;
}

bool resuelveCaso() {
	// leer datos
	int numElem;
	cin >> numElem;

	if (!cin)
		return false;

	vector <int> v(numElem);

	for (int i = 0; i < numElem; i++) {
		cin >> v[i];
	}

	// resolver
	tSol sol = resolver(v);

	// escribir solucion
	cout << sol.suma << " " << sol.ini << " " << sol.longitud << endl;

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