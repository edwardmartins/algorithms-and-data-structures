#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Matriz.h"

using namespace std;

/*

esfuerzo(i,j) = minimo esfuerzo a realizar 
				para cortar un tablon de longitud j considerando los ptos de corte del 1 al i

si i > j  no tiene sentido, el corte es mayor que el tablon
si i <= j si tiene sentido

esfuerzo(i,j) = min(esfuerzo(i,k) + esfuerzo(k, j) + 2 * (c[j] - c[i])) desde i + 1 a j - 1

caso base:
	si i = j  --> esfuerzo(i,i) = 0  

	--> el esfuerzo a realizar es cero 
	--> ya que el corte a realizar es igual a la longitud del tablon

*/

const int INF = 1000000000;

int minEsfuerzo(vector<int> const& cortes) {
	int n = cortes.size() - 1;
	// inicialización
	Matriz<int> esfuerzo(n + 1, n + 1 , 0);

	for (int d = 1; d <= n - 1; d++) // recorre diagonales
		for (int i = 1; i <= n - d; i++) { // recorre elementos de diagonal

			int j = i + d; // columna que le corresponde

			// calcular mínimo
			int min = INF;
			for (int k = i + 1; k <= j - 1; k++) { // desde i + 1 ya que i es el inicio hasta j - 1, j es el final
				int temp = esfuerzo[i][k] + esfuerzo[k][j] + 2*(cortes[j] - cortes[i]);
				if (temp < min) { // es mejor pasar por k
					esfuerzo[i][j] = temp;
					min = temp;
				}
			}
			
		}

	return esfuerzo[1][n];
}


bool resuelveCaso() {
	// leer datos
	int L, N;
	cin >> L >> N;

	if (L == 0 && N == 0)
		return false;

	vector<int> ptosCorte(N + 2);

	int pto;
	for (int i = 1; i <= N; i++) {
		cin >> ptosCorte[i + 1];
	}
	ptosCorte.push_back(L);

	//resolver
	int res = minEsfuerzo(ptosCorte);


	// escribir solucion
	cout << res << "\n";

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