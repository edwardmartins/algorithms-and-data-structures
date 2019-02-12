// Nombre del alumno: Eduardo Martinez Martin
// Usuario del Juez : E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// struct
struct tJugador {
	string nombre;
	int numCanicas = 0;
};

// función que resuelve el problema
tJugador resolver (vector <tJugador> const& v, int ini, int fin) { // fin esta fuera del vector

	tJugador sol;

	// 1 elemento
	if (ini + 1 == fin) {
		sol.nombre = v[ini].nombre;
		sol.numCanicas = v[ini].numCanicas;
	}
	else { // > 1 elemento
		int mitad = ( ini + fin + 1) / 2;

		tJugador solIz = resolver(v, ini, mitad);
		tJugador solDer = resolver(v, mitad, fin);

		if (solIz.numCanicas >= solDer.numCanicas) {
			sol.nombre = solIz.nombre;
			sol.numCanicas = solIz.numCanicas + solDer.numCanicas / 2;
		}
		else {
			sol.nombre = solDer.nombre;
			sol.numCanicas = solDer.numCanicas + solIz.numCanicas / 2;
		}
	}
	return sol;
}

bool resuelveCaso() {
	// leer datos
	int numElem;
	cin >> numElem;

	if (!cin)
		return false;

	vector <tJugador> v(numElem);

	for (int i = 0; i < v.size(); i++) {
		cin >> v[i].nombre;
		cin >> v[i].numCanicas;
	}
	// resolver
	
	tJugador s = resolver(v, 0, v.size());

	// escribir solucion
	cout << s.nombre << " " << s.numCanicas << endl;

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