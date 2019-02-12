#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Matriz.h"

using namespace std;

/*


cubos[i][j] = cantidad maxima que podemos comer si disponemos de los cubos de la i a la j

cubos[i][j] = 
			
			si cojo v[i] -> comoi = cubos[i + 1][j - 1] + v[i]		si v[j] > v[i + 1]
							comoi =	cubos[i + 2][j] + v[i]			e.o.c

			si cojo v[j] -> comj = cubos[i + 1][j - 1] + v[j]		si v[j - 1] < v[i]
								   cubos[i][j - 2] + v[j] )			e.o.c

			max(comoi,comoj)

caso base:
		cubos[i][i+1] = max(v[i],v[i+1])
		cubos[i][i] = v[i]

i <= j --> si se cruzan ya hemos acabado --> recorrido por diagonales

*/

bool resuelveCaso() {
	// leer datos
	int N;
	cin >> N;

	if (N == 0)
		return false;

	vector<int> v(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}

	// resolver
	Matriz<int> cubos(N + 1, N + 1, 0);

	// casos base
	for (int i = 1; i < N; i++) {
		cubos[i][i + 1] = max(v[i], v[i + 1]);
	}

	for (int i = 1; i <= N; i++) {
		cubos[i][i] = v[i];
	}

	// caso recursivo
	for (int d = 2; d <= N - 1; d++) {
		for (int i = 1; i <= N - d; i++) {
			int j = i + d;

			int comoi; // si yo como I

			if (v[j] > v[i + 1]) { // si el ultimo es mayor que el primero
				comoi = cubos[i + 1][j - 1] + v[i]; // deboradora come j
			}
			else {
				comoi = cubos[i + 2][j] + v[i]; // deboradora come i
			}

			int comoj; // si yo como J
			if (v[j - 1] > v[i] ) { // si el ultimo es mayor que el primero
				comoj = cubos[i][j - 2] + v[j];// deboradora come j
			}
			else {
				comoj = cubos[i + 1][j - 1] + v[j]; //deboradora come i
			}

			cubos[i][j] = max(comoi, comoj);
		}
	}

	// escribir solucion
	cout << cubos[1][N] << "\n";


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