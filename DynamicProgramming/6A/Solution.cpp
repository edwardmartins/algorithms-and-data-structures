#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include "Matriz.h"

using namespace std;

/*

trim(i,j) = numero minimo de llamadas 
			a trim para consumir una palabra 
			con letras que van desde la i a la j(i...j)

casos base:
		- cuando i = j solo queda una letra 
		y hay que hacer una unica llamada a trim

		trim(i,i) = 1

		- cuando i > j ==> trim(i,j) = 0

caso recursivo:

		ki ==> primer caracter distinto a letra[i]
		kj ==> primer caracter distinto a letra[j]
		
		trim(i,j) =	trim(ki,kj) + 1			si letra[i] == letra[j]

					min(trim(ki,j) + 1, trim(i,kj) + 1)

*/



bool resuelveCaso() {
	// leer datos
	string letras;
	cin >> letras;
	letras.insert(letras.begin(), ' ');

	if (!cin)
		return false;

	// resolver
	int n = letras.size() - 1;
	Matriz<int> trim(n + 1, n + 1, 0);

	// casos base
	for (int i = 0; i <= n; i++) {
		trim[i][i] = 1;
	}

	// caso recursivo
	for (int d = 1; d <= n - 1; d++) {
		for (int i = 1; i <= n - d; i++) {
			int j = i + d;

			int ki = i + 1;
			while (letras[i] == letras[ki] && ki < letras.size() - 1)
				ki++;

			int kj = j - 1;
			while (letras[j] == letras[kj] && kj >= ki)
				kj--;

			if (letras[i] == letras[j]) {

				trim[i][j] = trim[ki][kj] + 1;
		
			}
			else {
				trim[i][j] = min(trim[ki][j] + 1, trim[i][kj] + 1 );
			}
		}
	}

	// escribir solucion
	cout << trim[1][n] << "\n";

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