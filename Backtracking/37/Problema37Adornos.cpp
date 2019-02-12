// Nombre del alumno: Eduardo Martinez Martin
// Usuario del Juez : E31


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
void resolver(vector <int> const& costesObjetos, vector <int> const& superficiesObjetos,
	int k, int n, int presupuesto,int coste, int superficie, int &superficieMaxima, vector <bool> &objetos) {

	// arbol binario
	objetos[k] = true; // cojo el objeto
	coste += costesObjetos[k]; // le sumo su coste
	superficie += superficiesObjetos[k]; // le sumo su superficie

	if (coste <= presupuesto) {
		if (k == n - 1) { // si ha recorrido el array de objetos completo
			if (superficie > superficieMaxima)
				superficieMaxima = superficie;
		}
		else { // si no, paso al siguiente objeto

			resolver(costesObjetos, superficiesObjetos, k + 1, n, presupuesto, coste, superficie, superficieMaxima, objetos);
		}
	}

	// si el coste supera el presupuesto desmarcamos

	objetos[k] = false; // no cojo el objeto
	coste -= costesObjetos[k]; // le resto su coste
	superficie -= superficiesObjetos[k]; // le resto su superficie

	if (coste <= presupuesto) {
		if (k == n - 1) { // si ha recorrido el array de objetos completo
			if (superficie > superficieMaxima)
				superficieMaxima = superficie;
		}
		else { // si no, paso al siguiente objeto

			resolver(costesObjetos, superficiesObjetos, k + 1, n, presupuesto, coste, superficie, superficieMaxima, objetos);
		}
	}
	
}

bool resuelveCaso() {
	// leer datos
	int numObjetos;
	int presupuesto;

	cin >> numObjetos;
	cin >> presupuesto;

	if (!cin)
		return false;

	// costes
	vector <int> costesObjetos(numObjetos);

	for (int i = 0; i < numObjetos; i++) {
		cin >> costesObjetos[i];
	}

	// superficies
	vector <int> superficiesObjetos(numObjetos);

	for (int i = 0; i < numObjetos; i++) {
		cin >> superficiesObjetos[i];
	}

	// resolver
	int superficie = 0;
	int superficieMaxima = 0;
	int coste = 0;
	vector <bool> objetos(numObjetos);

	resolver(costesObjetos, superficiesObjetos, 0, numObjetos, presupuesto, coste, superficie, superficieMaxima, objetos);

	// escribir solucion
	cout << superficieMaxima << endl;

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