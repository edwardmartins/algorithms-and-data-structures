// El coste de la solucion obtenida es O(log n)

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// fin esta fuera del vector
int buscar(vector <int> const& v, int ini, int fin, int numeroCantado) {
	
	if (ini == fin) // vector vacio
		return -1; // no encontrado
	else if (ini + 1 == fin) { // 1 elemento
		if (v[ini] == ini + numeroCantado)
			return v[ini];
		else
			return -1;
	}
	else { // > 1 elemento
		int mitad = (ini + fin) / 2;

		if (v[mitad] == mitad + numeroCantado)
			return v[mitad];
		else if (v[mitad] > mitad + numeroCantado )
			 return buscar(v, ini, mitad, numeroCantado);
		else
			return buscar(v, mitad + 1, fin, numeroCantado);
	}
}


void resuelveCaso() {
	// leer datos
	int cantidadNum;
	int numeroCantado;
	cin >> cantidadNum;
	cin >> numeroCantado;

	vector <int> v(cantidadNum);

	for (int i = 0; i < cantidadNum; i++) {
		cin >> v[i];
	}
	// resolver
	int n = buscar(v, 0, v.size(), numeroCantado);

	// escribir solucion
	if (n != -1)
		cout << n << endl;
	else
		cout << "NO" << endl;

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