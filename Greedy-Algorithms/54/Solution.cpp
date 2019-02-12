#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct edificio {
	int ini;
	int fin;
};

bool operator <(edificio const&a, edificio const&b) {
	return a.fin < b.fin;
}


// El coste total es O(n Log N ) que es el coste de ordenar ya que las demas operaciones son O(N)


bool resuelveCaso() {
	// leer datos
	int numEdificios;
	cin >> numEdificios;

	if (numEdificios == 0)
		return false;

	vector<edificio> edificios(numEdificios);

	for (int i = 0; i < numEdificios; i++) {
		cin >> edificios[i].ini;
		cin >> edificios[i].fin;
	}

	sort(edificios.begin(), edificios.end());

	//resolver
	int numTuneles = 1;
	int primeroEnAcabar = edificios[0].fin;


	for (int i = 1; i < numEdificios; i++) {
		if (edificios[i].ini >= primeroEnAcabar) {
			numTuneles++;
			primeroEnAcabar = edificios[i].fin;
		}
	}

	// escribir solucion
	cout << numTuneles << "\n";

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