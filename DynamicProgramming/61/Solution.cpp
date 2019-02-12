#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm> // max
#include "Matriz.h"



using namespace std;

/*
	cofres(i,j) = maxima cantidad de oro que podemos obtener
				  con j segundos de aire considerando los cofes del 1 al i

	cofres(i,0) = 0  --> con j segundos de aire conseguimos 0 oro --> 0 <= i <= n
	cofres(0,j) = 0  --> si no hay ningun cofre conseguimos 0 oro --> 0 <= j <= T

	cofres(i,j) = cofes(i-1,j)  si 3*prof[i] > j --> (descenso + ascenso) > hasta donde nos lleva el aire de la botella --> no podemos coger el cofre
				= max(cofres(i-1,j), cofres(i - 1, j - 3*prof[i]) + cant[i])  e.o.c
*/



// Necesito dos vectores, uno con las profundidades a la que se encuentra cada cofre
// y  otro con las cantidades de oro que contiene cada cofre

// El numero de cofres diferentes(n) que hay representa el alto de la matriz,
// la profundidad a la que podemos llegar(T) representa el ancho de la matriz


// Complejidad O(n*T) tanto en tiempo como en espacio 

void maximaCantidadOro(vector<int> const&prof, vector<int> const&cant, int T) {

	int n = prof.size() - 1;
	Matriz<int> cofres(n + 1, T + 1, 0);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= T; j++) {

			if (prof[i] > j) {
				cofres[i][j] = cofres[i - 1][j];
			}
			else {
				cofres[i][j] = max(cofres[i - 1][j],
								   cofres[i - 1][j - prof[i]] + cant[i]);
			}
		}
	}

	cout << cofres[n][T] << "\n";

	int resto = T;
	vector <bool> cuales(n + 1);

	for (int i = n; i >= 1; i--) {
		// no hemos cogido el cofre i ya que la cantidad maxima es igual en ambas filas
		if (cofres[i][resto] == cofres[i - 1][resto]) { 
			cuales[i] = false;
		}
		else { // hemos cogido el cofre i
			cuales[i] = true;
			resto = resto - prof[i];
		}
	}

	cout << count(cuales.begin(), cuales.end(), true) << "\n";

	for (int i = 1; i <= n; i++) {
		if (cuales[i] == true) {
			cout << prof[i]/3 << " " << cant[i] << "\n";
		}
	}
}


bool resuelveCaso() {
	// leer datos

	int T; // segundos que permite la botella estar debajo del agua
	cin >> T;

	if (!cin)
		return false;

	int numCofres;
	cin >> numCofres;

	vector<int> profundidades(numCofres + 1);
	vector<int> cantidades(numCofres + 1);

	int prof;
	for (int i = 1; i < numCofres + 1; i++) {
		cin >> prof;
		prof = 3 * prof;
		profundidades[i] = prof;
		cin >> cantidades[i];
	}

	// resolver
	maximaCantidadOro(profundidades, cantidades, T);
	cout << "----\n";
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