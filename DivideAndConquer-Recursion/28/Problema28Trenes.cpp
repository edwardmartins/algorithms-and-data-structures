// Nombre del alumno: Eduardo Martinez Martin
// Usuario del Juez : E31
/*
Recurrencia utilizada
---------------------------------------
			C0               --> n = 1
T(n) =
			C1 + 2T(N/2)     --> n > 1
---------------------------------------
Coste de la solucion obtenida = O(N)

*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// struct
struct tSolucion {
	double media = 0;
	double maximo = 0;
	double minimo = 0;
	bool pendienteOK = false;
};

// función que resuelve el problema
tSolucion resolver(vector <int> const& v, int ini, int fin) {
	tSolucion sol;

	if (ini + 1 == fin) { // 1 elemento 
		sol.media = v[ini];
		sol.maximo = v[ini];
		sol.minimo = v[ini];
		sol.pendienteOK = true;
	}
	else { // > 1 elemento
		int mitad = (ini + fin + 1) / 2;

		tSolucion solIz = resolver(v, ini, mitad);
		tSolucion solDer = resolver(v, mitad, fin);

		// maximo
		if (solIz.maximo < solDer.maximo)
			sol.maximo = solDer.maximo;
		else
			sol.maximo = solIz.maximo;
		//minimo
		if (solIz.minimo < solDer.minimo)
			sol.minimo = solIz.minimo;
		else
			sol.minimo = solDer.minimo;

		//media
		sol.media = (solIz.media + solDer.media) / 2;

		sol.pendienteOK = ((solIz.pendienteOK && solDer.pendienteOK)
			&& (sol.maximo - sol.media) <= (sol.media / 2)
			&& (sol.media - sol.minimo) <= (sol.media / 2));
	}
	return sol;
}

bool resuelveCaso() {
	// leer datos
	int numElem;
	cin >> numElem;

	if (!cin)
		return false;

	vector <int> v(numElem);

	for (int i = 0; i < numElem; i++) {
		cin >> v[i];
	}

	// resolver
	tSolucion sol = resolver(v,0,v.size());

	// escribir solucion
	if (sol.pendienteOK)
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