// Nombre del alumno:Eduardo Martínez Martín
// Usuario del Juez: E31
/*Recurrencia utilizada
-----------------------------------------------
			C0					si n = 1
T(n) =
			C1 + T(N/2)			si n > 1
----------------------------------------------
Coste de la solucion obtenida = O(log N)
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
// fin esta fuera del vector
int resolver(vector <int> const& v, int ini, int fin) {

	if (ini + 1 == fin)
		return ini;
	else {
		int mitad = (ini + fin) / 2;

		if (v[mitad] != v[mitad + 1] && v[mitad] != v[mitad - 1])
			return mitad;
		else if (mitad % 2 == 0) { // si mitad es par

			if (v[mitad] == v[mitad - 1])
				return resolver(v, ini, mitad);
			else
				return resolver(v, mitad + 2, fin);

		}else{ // si mitad es impar
			if (v[mitad] == v[mitad - 1])
				return resolver(v, mitad + 1, fin);
			else
				return resolver(v, ini, mitad);
		}
	}
}


void resuelveCaso() {
	// leer datos
	int numElem;
	cin >> numElem;

	vector <int> v(numElem);

	for (int i = 0; i < numElem; i++) {
		cin >> v[i];
	}


	// resolver
	int sol = resolver(v,0,v.size());

	// escribir solucion
	cout << sol << endl;


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