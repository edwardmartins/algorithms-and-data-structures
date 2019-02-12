// Nombre del alumno: Eduardo Martinez Martin
// Usuario del Juez : E31
/*
Recurrencia utilizada
----------------------------------
		C0               --> n = 1
T(n) =
		C1 + 2T(N/2)     --> n > 1
----------------------------------
Coste de la solucion obtenida = O(N)

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int minimo(vector <int> const& v, int ini, int fin) {
	if (ini + 1 == fin) { // 1 elemetno
		return v[ini];
	}
	else { // > 1 elemento
		int mitad = (ini + fin + 1) / 2;

		int minIzq = minimo(v, ini, mitad);
		int minDer = minimo(v, mitad, fin);

		if (minIzq < minDer)
			return minIzq;
		else
			return minDer;
	}
}

bool resuelveCaso() {
	// leer datos
	int numElem;
	cin >> numElem;

	if (!cin)
		return false;

	vector <int> v(numElem);

	for (int i = 0; i < v.size(); i++) {
		cin >> v[i];
	}

	// resolver
	int sol = minimo(v,0,v.size());

	// escribir solucion
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