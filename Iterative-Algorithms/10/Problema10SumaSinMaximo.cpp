// Nombre del alumno:Eduardo Martínez Martín
// Usuario del Juez: E31

// La solucion obtenida tiene un coste O(n), siendo "n" la longitud del vector

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector <int> const& v) {
	int maximo = v[0];
	int numMaximos = 1;

	// Calculo del maximo y numero de veces que aparece
	for (int i = 1; i < v.size(); i++) {
		if (v[i] > maximo) {
			maximo = v[i];
			numMaximos = 1;
		}
		else if (v[i] == maximo)
			numMaximos++;
	}

	// Suma de todo
	int sumaVector = 0;

	for (int i = 0; i < v.size(); i++) {
		sumaVector = sumaVector + v[i];
	}

	// Suma sin maximo
	return (sumaVector - (maximo * numMaximos));
}


void resuelveCaso() {
	// leer los datos de la entrada
	int size;
	cin >> size;

	vector <int> v(size);

	for (int i = 0; i < v.size(); i++) {
		cin >> v[i];
	}

	// resolver
	int p = resolver(v);

	// escribir sol
	cout << p << endl;

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