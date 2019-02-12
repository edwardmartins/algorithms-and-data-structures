// Nombre del alumno: Eduardo Martinez Martin
// Usuario del Juez : E31

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tSolucion {
	int maxSecuencia = 0;
	int numLlanos = 0; // num de secuencias 
	vector <int> comienzoLLano; // depende del numero de llanos
};

// función que resuelve el problema
tSolucion resolver(vector <int> const& v, int tamSecuencia) {
	tSolucion sol;
	int ultLast = v.size() - 1;
	int last = 0;
	int maximo = v[v.size() - 1];

	// resolver
	for (int i = v.size() - 1; i > 0; i--) {
		if (v[i] == v[i - 1]) {
			if (v[i] >= maximo && ultLast - i + 2 > sol.maxSecuencia) { // secuencia maxima que cumple
				sol.maxSecuencia = ultLast - i + 2;
			}
			if (v[i] >= maximo && ultLast - i + 2 == tamSecuencia) { // secuencia que cumple
				last = ultLast;
				sol.numLlanos++;
				sol.comienzoLLano.push_back(last); // posicion del llano desde la derecha
			}
		}
		else {
			ultLast = i - 1;
		}
		// calculo maximo
		if (v[i - 1] > maximo)
			maximo = v[i - 1];
	}
	if (sol.maxSecuencia < tamSecuencia)
		sol.maxSecuencia = 0;

	return sol;
}

bool resuelveCaso() {
	// leer datos
	int numDatos;
	int tamSecuencia;
	cin >> numDatos;
	cin >> tamSecuencia;

	if (!cin)
		return false;

	vector <int> v(numDatos);

	for (int i = 0; i < v.size(); i++) {
		cin >> v[i];
	}

	// resolver
	tSolucion sol = resolver(v, tamSecuencia);

	// escribir solucion
	cout << sol.maxSecuencia << " " << sol.numLlanos << " ";
	for (int i = 0; i < sol.comienzoLLano.size(); i++) {
		cout << sol.comienzoLLano[i] << " ";
	}
	cout << endl;

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