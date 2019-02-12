#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <utility>
#include <cstdlib>

using namespace std;


bool esValida(vector <int> const&sol, int k, vector <int> const&contadorColores, int sumaDemasColores, int consumo, int consumoMaximo) {

	bool valida = true;
	// No haya MAS de dos luces del mismo color
	if (k > 1 && sol[k] == sol[k - 1] && sol[k] == sol[k- 2]) {
		valida = false;
	}

	// comprobar el consumo aqui asi nos evitamos llamadas recursivas
	if (consumo > consumoMaximo) {
		valida = false;
	}

	// Hay que quitarle los de su color para poder comprarlo con los demas colores
	if (contadorColores[sol[k]] > sumaDemasColores + 1 - contadorColores[sol[k]]) { 
		valida = false;
	}

	return valida;
}

void escribirSolucion(vector <int> const &sol) {

	for (int i = 0; i < sol.size(); i++) {
		cout << sol[i] << " ";
	}
	cout << endl;
}


// Agrupar los datos en structs por datos de entrada, datos actuales, marcaje y solMejor
void resolver(vector <int> const& consumoLuces, int k, int numColores, vector <int> &sol, int &consumo,
			int &consumoMax, vector <int> &contadorColores,int &sumaColores, bool &haySolucion, int &combinaciones) {

	for (int i = 0; i < numColores; i++) {

		sol[k] = i;
		consumo += consumoLuces[i];
		contadorColores[i]++;
		sumaColores++;

		if (esValida(sol, k, contadorColores, sumaColores, consumo, consumoMax)) { // es valida

			if (k == sol.size() - 1) { // es solucion
				combinaciones++;
				haySolucion = true;
			}
			else {
				
				resolver(consumoLuces, k + 1, numColores, sol, consumo, consumoMax, contadorColores, sumaColores, haySolucion, combinaciones);
			}
			
		}
		
		contadorColores[i]--;
		consumo -= consumoLuces[i];
		sumaColores--;	
	}

}


bool resuelveCaso() {
	int longitud, numColores, consumoMax;
	std::cin >> longitud;
	if (!std::cin) return false;
	std::cin >> numColores >> consumoMax;
	std::vector<int> consumoLuces(numColores);
	for (int i = 0; i < numColores; ++i) std::cin >> consumoLuces[i];

	vector <int> sol(longitud);
	vector <int> contadorColores(numColores);
	int consumo = 0;
	bool haySolucion = false;
	int sumaColores = 0;
	int combinaciones = 0;

	resolver(consumoLuces, 0, numColores, sol, consumo, consumoMax, contadorColores, sumaColores, haySolucion, combinaciones);

	cout << combinaciones << endl;

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

