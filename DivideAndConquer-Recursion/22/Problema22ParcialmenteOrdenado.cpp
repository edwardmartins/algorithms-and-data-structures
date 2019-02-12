// Nombre del alumno: Eduardo Martínez Martín
// Usuario del Juez: E31
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

//struct
struct tSolucion {
	int minimo = 0;
	int maximo = 0;
	bool parcOrdenado = true;
};

// función que resuelve el problema
// fin esta fuera del vector
tSolucion resolver(vector <int> const& v, int ini, int fin) {
	tSolucion sol; 
	int mitad;

	// 1 elemento
	if (ini + 1 == fin) {
		sol.minimo = v[ini];
		sol.maximo = v[ini];
		sol.parcOrdenado = true;

	} // > 1 elemento
	else {

		mitad = ((ini + fin + 1) / 2);
		tSolucion solIz = resolver(v, ini, mitad);  // parte izquierda del vector
		tSolucion solDer = resolver(v, mitad, fin); // parte derecha del vector 
	
		// minimo del vector total
		if (solIz.minimo < solDer.minimo)
			sol.minimo = solIz.minimo;
		else
			sol.minimo = solDer.minimo;

		// maximo del vector total
		if (solIz.maximo > solDer.maximo)
			sol.maximo = solIz.maximo;
		else
			sol.maximo = solDer.maximo;

		// si el vector total esta parcialmente ordenado
		sol.parcOrdenado = (solIz.parcOrdenado && solDer.parcOrdenado
			&& solDer.maximo >= solIz.maximo && solIz.minimo <= solDer.minimo);
	}

	return sol;
}


bool resuelveCaso() {
	// leer los datos de la entrada
	int elem;
	vector <int> v;

	cin >> elem;
	if (elem == 0)
		return false;

	v.push_back(elem);

	while (elem != 0) {
		cin >> elem;
		v.push_back(elem);
	}

	// resolver
	tSolucion s = resolver(v, 0, v.size() - 1);

	// escribir sol
	if (s.parcOrdenado)
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