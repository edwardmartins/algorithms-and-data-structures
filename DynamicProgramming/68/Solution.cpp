#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include "Matriz.h"


using namespace std;

const int INF = 1000000000;

struct moneda {
	int valor;
	int cantidad;
};

bool resuelveCaso() {
	// leer datos
	int N;
	cin >> N;

	if (!cin)
		return false;

	vector<moneda> v(N + 1);


	for (int i = 1; i <= N; i++) {
		cin >> v[i].valor;
	}

	for (int i = 1; i <= N; i++) {
		cin >> v[i].cantidad;
	}

	int precio;
	cin >> precio;

	// resolver
	Matriz<int> monedas(N + 1, precio + 1, INF);
	monedas[0][0] = 0;
	// rellenar la matriz
	for (int i = 1; i <= N; i++) {
		monedas[i][0] = 0;
		for (int j = 1; j <= precio; j++) {

			if (v[i].valor > j) // nos pasamos
				monedas[i][j] = monedas[i - 1][j];
			else {
				for (int k = 0; k <= v[i].cantidad && k*v[i].valor <= j; k++)
					monedas[i][j] = min(monedas[i][j], monedas[i - 1][j - k*v[i].valor] + k); 
			}
		}
	}


	// escribir solucion
	if (monedas[N][precio] != INF)
		cout << "SI " << monedas[N][precio] << "\n";
	else
		cout << "NO\n";

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