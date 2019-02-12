// Eduardo Martínez Martín
// E31

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(vector <int> const& v, int p) {

	int mayor = v[0];
	int cont = p + 1;

	for (int i = 1; i <= p; i++) {
		if (v[i] > mayor) // saco el mayor la la parte izquierda
			mayor = v[i];
	}

	while (cont < v.size() && v[cont] > mayor) {
		cont++;
	}

	return (cont == v.size());
}

void resuelveCaso() {
	// leer los datos de la entrada
	int p;
	int numElementos;
	cin >> numElementos;
	cin >> p;


	vector <int> v(numElementos); // inicializamos el vector

	for (int i = 0; i < v.size(); i++) // leemos vector
		cin >> v[i];

	// resolver
	bool valido = resolver(v, p);

	//escribir solucion
	if (valido)
		cout << "SI" << endl;
	else
		cout << "NO" << endl;


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