#include <iostream>
#include <iomanip>
#include <fstream>
#include "Matriz.h"

using namespace std;

bool resuelveCaso() {
	// leer datos
	int n;
	cin >> n;

	if (n == 0)
		return false;

	Matriz<char> mapa(n + 1, n + 1);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> mapa[i][j];

	//resolver
	Matriz<int> formas(n + 1, n + 1, 0);

	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i == 1 && j == 1) {
				formas[i][j] = 1;
			}
			else if (mapa[i][j] == '.') {
				formas[i][j] = formas[i - 1][j] + formas[i][j - 1];
			}
			else {
				formas[i][j] = 0;
			}
		}

	// escribir solucion
	cout << formas[n][n] << "\n";
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