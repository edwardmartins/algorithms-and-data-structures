// Eduardo Martínez Martín
// E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(vector <int> &v) {
	int cont = 0;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] % 2 == 0) { // old( v [ i ]) % 2 == 0
			v[cont] = v[i];  // old( v [ i ]) in v [..]
			cont++;
		}
	}
	v.resize(cont);
}

void resuelveCaso() {
	// leer los datos de la entrada
	int numElementos;
	cin >> numElementos;

	if (numElementos > 0) { // v != null
		vector <int> v(numElementos); // inicializamos el vector
		bool entrada = true;

		for (int i = 0; i < v.size(); i++) {
			cin >> v[i];
			if (v[i] <= 0) //  para todo "i" ==> v[i] > 0
				entrada = false;
			else if (i > 0 && v[i - 1] >= v[i]) // se teien que cumplir que EstricCreciente(v[..])
				entrada = false;
		}
		// resolver
		if (entrada) {
			resolver(v);
			//escribir solucion
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << " ";
			}
		}
	}
	cout << endl;

}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}