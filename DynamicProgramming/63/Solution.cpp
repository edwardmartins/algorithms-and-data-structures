#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>
#include "Matriz.h"

using namespace std;

/*

letras(i,j) = maxima longitud de la subsecuencia mas larga
			  entre dos palabras con letras de 1 a i 
			  y letras de 1 a j respectivamente


letras(i,0) = 0  -->  0 <= i <= pal1.size()
letras(0,j) = 0	 -->  0 <= j <= pal2.size()

letras(i,j) = max(letras[i - 1][j],letras[i][j-1])  --> si las letras no coinciden, el maximo de entre avanzar el puntero en una palabra o en otra
			  letras[i - 1][j -1] + 1				--> si las letras coinciden


Complejidad--> O(pal1.size() * pal2.size()) tanto en tiempo como en espacio
*/


bool resuelveCaso() {
	// leer datos
	string pal1, pal2;
	cin >> pal1 >> pal2;

	if (!cin)
		return false;

	// resolver
	Matriz<int> letras(pal1.size() + 1, pal2.size() + 1, 0);

	for (int i = 1; i <= pal1.size(); i++) {
		for (int j = 1; j <= pal2.size(); j++) {
			if (pal1[i - 1] != pal2[j - 1]) { // si las letras son distintas
				letras[i][j] = max(letras[i - 1][j],
								   letras[i][j - 1]);
			}
			else { // si son iguales
				letras[i][j] = letras[i - 1][j - 1] + 1;
			}
		}
	}

	cout << letras[pal1.size()][pal2.size()]<< "\n";
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