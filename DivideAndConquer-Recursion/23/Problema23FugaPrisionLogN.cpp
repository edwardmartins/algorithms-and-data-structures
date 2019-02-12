// Nombre del alumno:Eduardo Martínez Martín
// Usuario del Juez: E31
/*

Coste de la solucion obtenida = O(log N)

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

char buscarLetra(vector <char> const& v, int ini, int fin) {

	if (ini + 2 == fin) {
		return v[ini] + 1;
	}
	else {
		int mitad = (ini + fin) / 2; // ini + fin + 1 no funciona en este caso

		if (v[mitad] - v[0] != mitad)
			return buscarLetra(v, ini, mitad + 1);
		else
			return buscarLetra(v, mitad, fin);
	}
}

void resuelveCaso() {
	// leer datos
	char letraInicial, letraFinal;
	cin >> letraInicial >> letraFinal;

	int numLetras = letraFinal - letraInicial;
	vector <char> v(numLetras);

	for (int i = 0; i < numLetras; i++) {
		cin >> v[i];
	}

	//resolver
	char sol;
	if (v[0] != letraInicial)
		sol = letraInicial;
	else if (v[v.size() - 1] != letraFinal)
		sol = letraFinal;
	else
		sol = buscarLetra(v, 0, v.size());

	// escribir sol
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