#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector <int> &v) {

	// 2 variables una por cada lado del vector
	int i = 0;
	int j = v.size() - 1;
	int aux;

	while (i <= j) {

		if (v[i] >= 0) //bien colocado paso al siguiente elemento
			i++;
		else if (v[j] < 0) //bien colocado paso al siguiente elemento
			j--;
		else {
			 // Los intercambio
			//------------------
			aux = v[i]; // guardo v[i]
			v[i] = v[j]; // ya lo puedo sobreEscribir
			v[j] = aux;

			// avanzo los punteros
			i++;
			j--;
		}
	}
	return i;
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
	int sol = resolver(v);

	// escribir solucion
	for (int i = 0; i < numElem; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
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