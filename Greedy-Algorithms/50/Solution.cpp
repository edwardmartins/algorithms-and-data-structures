#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



using namespace std;

// funcion de seleccion --> calcula hasta donde llegara el parche partiendo del siguiente agujero mas cercano no cubierto

// mientras los agujeros siguientes esten cubiertos por el parche no hacemos nada
// en caso contrario recalculamos el tamaño del parche desde el siguiente agujero no cubierto

// El coste es lineal O(N) siendo N el numero de agujeros de la mangera


bool resuelveCaso() {
	// leer datos
	int numAgujeros, longParche;
	cin >> numAgujeros >> longParche;

	if (!cin)
		return false;

	int agujero;
	vector<int> agujeros;
	for (int i = 0; i < numAgujeros; i++) {
		cin >> agujero;
		agujeros.push_back(agujero);
	}

	// resolver
	int numParches = 1;
	int maxLong = agujeros[0] + longParche;

	for (int i = 0; i < agujeros.size(); i++) {

		if (maxLong < agujeros[i]){ // parche no tapado
			numParches++;
			maxLong = agujeros[i] + longParche;
		}
	}
	
	// escribir solucion
	cout << numParches << "\n";
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