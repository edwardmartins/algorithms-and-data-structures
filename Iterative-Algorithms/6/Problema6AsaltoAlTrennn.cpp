// Nombre del alumno:Eduardo Martínez Martín
// Usuario del Juez: E31
// El coste de la solucion obtenida es O ( n )
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Función que resuelve el problema
int resolver(vector <int> const& vagones,int ventana, int &sumaMayor) {
	int sumaParcial = 0;
	// Suma de la primera ventana
	for (int i = 0; i < ventana; i++) { 
		sumaParcial = sumaParcial + vagones[i];
	}
	// Recorro el array comparando ventanas y sacando la mayor
	sumaMayor = sumaParcial;
	int posMayor = 0;

	for (int j = 0; j < vagones.size() - ventana; j++) {
		sumaParcial = sumaParcial + vagones[ventana + j];
		sumaParcial = sumaParcial - vagones[j];

		if (sumaParcial >= sumaMayor) {
			sumaMayor = sumaParcial;
			posMayor = j + 1;
		}
	}
	return posMayor;



}


void resuelveCaso() {
	// leer los datos de entrada
	int numeroVagones;
	int ventana;
	int sumaMayor = 0;

	cin >> numeroVagones;
	cin >> ventana;

	vector <int> vagones(numeroVagones);

	for (int i = 0; i < vagones.size(); i++) {
		cin >> vagones[i];
	}

	// resolver
	int sol = resolver(vagones,ventana,sumaMayor);

	// escribir sol
	cout << sol << " " << sumaMayor << endl;

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