#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>
#include "Matriz.h"

using namespace std;


bool resuelveCaso() {
	// leer datos
	string pal;
	cin >> pal; 

	if (!cin)
		return false;

	// resolver
	Matriz<int> letras(pal.size() + 1, pal.size() + 1, 0);

	// caso basico, cada letra consigo misma forman un palindromo de 1
	for (int i = 1; i <= pal.size(); i++) {
		letras[i][i] = 1;
	}

	for (int i = pal.size(); i >= 1; i--) {
		for (int j = i + 1; j <= pal.size(); j++) {
			if (pal[i - 1] != pal[j - 1]) { // si las letras son distintas
				letras[i][j] = max(letras[i + 1][j],
					letras[i][j - 1]);
			}
			else { // si son iguales
				letras[i][j] = 2 + letras[i + 1][j - 1];
			}
		}
	}


	// Saco la subsecuencia comun
	int i = 1;
	int j = pal.size();
	int tam = letras[i][pal.size()];
	string result(tam, ' ');
	int a = 0;
	int b = tam - 1;

	while (tam > 0) {

		if (pal[i - 1] != pal[j - 1]) {
			if (letras[i + 1][j] >= letras[i][j - 1]) {
				i++;
			}
			else { // en caso de empate elimino letras de la izquierda
				j--;
			}
		}
		else if (tam == 1) {
			result[a] = pal[j - 1];
			tam -= 1;
		}
		else {
			result[a] = pal[i - 1];
			result[b] = pal[j - 1];
			tam -= 2;
			a++;
			i++;
			j--;
			b--;
		}
	}

	cout << result << "\n";
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