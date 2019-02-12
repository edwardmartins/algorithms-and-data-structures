// Nombre del alumno:Eduardo Martínez Martín
// Usuario del Juez: E31

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tSolucion {
	bool balanceado = false;
	int pesoTotal = 0;
};

// función que resuelve el problema
tSolucion resolver() {
	tSolucion sol;
	int p1, d1, p2, d2; // peso y distancia de ambos lados del movil
	cin >> p1 >> d1 >> p2 >> d2;

	// si no tiene submoviles
	if (p1 != 0 && p2 != 0) {
		sol.balanceado = (p1 * d1 == p2 * d2);
		sol.pesoTotal = p1 + p2;
	}
	else {// si tiene algun submovil --> 3 posibles casos
		
		if (p1 == 0 && p2 == 0) {  // submovil en ambas partes
			tSolucion solIzq = resolver(); 
			tSolucion solDer = resolver(); 
			// balanceado
			sol.balanceado = (solIzq.balanceado && solDer.balanceado
				&& solIzq.pesoTotal * d1 == solDer.pesoTotal * d2);
			// pesoTotal
			sol.pesoTotal = solIzq.pesoTotal + solDer.pesoTotal;
		
		}
		else if (p1 == 0 & p2 != 0) { // submovil en la parte izquierda
			tSolucion solIzq = resolver();
			// balanceado
			sol.balanceado = (solIzq.balanceado
				&& solIzq.pesoTotal * d1 == p2 * d2);
			// pesoTotal
			sol.pesoTotal = solIzq.pesoTotal + p2;

		}
		else { // submovil en la parte derecha
			tSolucion solDer = resolver();
			// balanceado
			sol.balanceado = (solDer.balanceado 
				&& solDer.pesoTotal * d2 == p1 * d1);
			// pesoTotal
			sol.pesoTotal = solDer.pesoTotal + p1;
		}
	}
	return sol;
}

void resuelveCaso() {
	// resolver
	tSolucion s = resolver();

	// escribir solucion
	if (s.balanceado)
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
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}