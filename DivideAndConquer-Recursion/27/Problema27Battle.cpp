#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
/*
Recurrencia utilizada
------------------------------------------
			C0               --> n = 0, 1
T(n) =
			C1 + 2T(N/2)     --> n > 1
------------------------------------------
Coste de la solucion obtenida = O(N)

*/


using namespace std;

int battle(vector <int> &v, int ini, int fin) {

	if (ini + 1 >= fin)
		return 0;
	else {

		int m = (ini + fin + 1) / 2;

		int InvIz = battle(v, ini, m);
		int InvDer = battle(v, m, fin);

		int inv = 0; int i = ini; int j = m;

		while (i < m && j < fin) {
			if (v[i] > v[j]) {
				inv = inv + (m - i);
				j++;
			}
			else { i++; }
		}
		vector <int> aux(fin - ini);

		sort(v.begin() + ini, v.begin() + m);
		sort(v.begin() + m, v.begin() + fin);
		merge(v.begin() + ini, v.begin() + m, v.begin() + m, v.begin() + fin, aux.begin());

		for (int i = 0; i < aux.size(); i++) {
			v[ini + i] = aux[i];
		}
		return (inv + InvIz + InvDer);
	}
}




bool resuelveCaso() {
	// leer datos
	int size;
	cin >> size;

	if (!cin)
		return false;

	vector <int> v(size);

	for (int i = 0; i < v.size(); i++) {
		cin >> v[i];
	}

	// resolver
	int sol = battle(v, 0, v.size());

	// escribir solucion
	cout << sol << endl;
	
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