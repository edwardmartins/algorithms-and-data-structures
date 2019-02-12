// Nombre del alumno: Eduardo Martinez Martin
// Usuario del Juez : E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector <int> const& v, int ini, int fin) {

	if (ini + 1 == fin)
		return v[ini];
	else {
			int mitad = (ini + fin + 1) / 2;
			
			if (v[mitad] < v[ini])
				resolver(v, mitad, fin);
			else 
				resolver(v, ini, mitad);
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
	int sol = resolver(v,0,v.size());

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