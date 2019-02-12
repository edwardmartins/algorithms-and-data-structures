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

// struct
struct tSolucion {
	bool degradado = true;
	int suma = 0;
};

// función que resuelve el problema
tSolucion resolver(vector <int> const& v,int ini, int fin) {
	// variables
	tSolucion sol;
	int mitad;

	// caso base 1 elemento
	if (ini + 1 == fin) {
		sol.suma = v[ini];
		sol.degradado = true;

	}// > 1 elemento
	else {
		mitad = (ini + fin + 1) / 2;

		tSolucion solIz = resolver(v, ini, mitad);
		tSolucion solDer = resolver(v, mitad, fin);

		sol.suma = solIz.suma + solDer.suma;
		sol.degradado = (solIz.suma < solDer.suma && solIz.degradado && solDer.degradado);
	}
	return sol;
}

bool resuelveCaso() {
	// leer datos
	int numLineas;
	int numDatos;
	tSolucion s;
	bool matrizDegradada = true;

	cin >> numLineas;
	cin >> numDatos;

	if (!cin)
		return false;

	vector <int> v(numDatos);

	for (int i = 0; i < numLineas; i++) {
		for (int j = 0; j < numDatos; j++) {
			cin >> v[j];
		}
		// resolver
		s = resolver(v, 0, v.size());
		if (!s.degradado)
			matrizDegradada = false;
	}
	// escribir solucion
	if (matrizDegradada)
		cout << "SI" << endl;
	else
		cout << "NO" << endl;

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