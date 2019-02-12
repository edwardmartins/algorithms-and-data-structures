#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm> // min
#include "Matriz.h"


using namespace std;

/* Complejidad:
------------------------------------------------------------------------------------

	Tiempo:		O(n * L) 
	Espacio:	O(L)

	Siendo "n" la cantidad de varilla disponibles 
	y "L" la longitud de la varilla total a conseguir

*/

/*

Definicion Funcion
------------------------------------------------------------------------------------

Posible(i,j):
       si es posible obtener una varilla de longitud total "j" con la varillas del 1 al i



Definicion Recursiva
------------------------------------------------------------------------------------

Posible(i,j):
		
		Posible(i-1,j)										si l[i] > j			

		Posible(i-1,j) || Posible(i-1, j- l[i])				si l[i] <= j


casos basicos:
		Posible(i,0) = true		-->	si no cojemos ninguna varilla se alcanza la longitud 0
		Posible(0,j) = false	-->	es imposible alzanzar la longitud "j" sin ningun tipo de varilla

*/

bool esPosible(vector<int> const&l, int L) { 

	int n = l.size() - 1;
	vector<bool> posible(L + 1, false);
	posible[0] = true;

	for (int i = 1; i <= n; i++) {  // i tipos de varilla
		for (int j = L; j >= li[i]; j--) {   // j lonigtudes
			posible[j] = posible[j] || posible[j - l[i]];
		}
	}
	return posible[L];
}

/*

Definicion Funcion
------------------------------------------------------------------------------------

maneras(i,j):
	numero total de maneras de obtener una varilla de longitud total "j"
	considerando las varillas de la 1 a la i 



Definicion Recursiva
------------------------------------------------------------------------------------

maneras(i,j):
	maneras(i-1,j)										si l[i] > j

	maneras(i-1,j) + maneras(i-1, j- l[i])				si l[i] <= j


casos basicos:
	maneras(i,0) = 1		
	maneras(0,j) = 0		

*/

int totalManeras(vector<int> const&l, int L) {

	int n = l.size() - 1;
	vector<int> maneras(L + 1, 0);
	maneras[0] = 1;

	for (int i = 1; i <= n; i++) { // i tipos de varilla
		for (int j = L; j >= l[i]; j--) { // j lonigtudes
				maneras[j] = maneras[j] + maneras[j - l[i]];
		}
	}
	return maneras[L];
}

/*

Definicion Funcion
------------------------------------------------------------------------------------

minVarillas(i,j):
	minimo numero de varillas necesario para obtener una varilla de longitud total "j"
	considerando las varillas de la 1 a la i



Definicion Recursiva
------------------------------------------------------------------------------------

minVarillas(i,j):
	minVarillas(i-1,j)													si l[i] > j

	min(minVarillas(i-1,j), minVarillas(i-1, j- l[i]) + 1)				si l[i] <= j


casos basicos:
	minVarillas(i,0) = 0		
	minVarillas(0,j) = INF		

*/

const int INF = 1000000000;

int minimoVarillas(vector<int> const&l, int L) {

	int n = l.size() - 1;
	vector<int> minVar(L + 1, INF);
	minVar[0] = 0;

	for (int i = 1; i <= n; i++) { // i tipos de varilla
		for (int j = L; j >= l[i]; j--) { // j lonigtudes
			minVar[j] = min(minVar[j], minVar[j - l[i]] + 1);
		}
	}

	return minVar[L];
}

/*

Definicion Funcion
------------------------------------------------------------------------------------

minCoste(i,j):
	minimo coste necesario para obtener una varilla de longitud total "j"
	considerando las varillas de la 1 a la i



Definicion Recursiva
------------------------------------------------------------------------------------
minCoste(i,j):
	minCoste(i-1,j)													si l[i] > j

	min(minCoste(i-1,j), minCoste(i-1, j- l[i]) + c[i])				si l[i] <= j


casos basicos:
	minCoste(i,0) = 0		
	minCoste(0,j) = INF		

*/

int minimoCoste(vector<int> const&l, vector<int> const&c, int L) {

	int n = l.size() - 1;
	vector<int> minCoste(L + 1, INF);
	minCoste[0] = 0;

	for (int i = 1; i <= n; i++) { // i tipos de varilla
		for (int j = L; j >= l[i]; j--) { // j lonigtudes
			minCoste[j] = min(minCoste[j], minCoste[j - l[i]] + c[i]);
		}
	}

	return minCoste[L];
}


bool resuelveCaso() {
	// leer datos
	int numVarillas, L;
	cin >> numVarillas >> L;

	if (!cin)
		return false;

	vector<int> longitudes(numVarillas + 1);
	vector<int> costes(numVarillas + 1);

	for (int i = 1; i <= numVarillas; i++) {
		cin >> longitudes[i] >> costes[i];
	}

	// resolver
	bool ok = esPosible(longitudes, L);
	

	// escribir solucion
	if (ok) {
		cout << "SI " <<
			totalManeras(longitudes, L) << " " <<
			minimoVarillas(longitudes, L) << " " <<
			minimoCoste(longitudes, costes, L) << "\n";
	}
	else
		cout << "NO" << "\n";

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