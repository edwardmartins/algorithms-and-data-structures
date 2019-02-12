// Nombre del alumno:Eduardo Martínez Martín
// Usuario del Juez: E31

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


enum piedrasPreciosas { diamante, rubi, esmeralda, zafiro, jade };

const int N_PIEDRAS = 5;

struct tipoSecuencia {
	piedrasPreciosas tipo1, tipo2;
	int numtipo1, numtipo2;
};


istream& operator>> (istream& entrada, piedrasPreciosas& p) {
	char num;
	entrada >> num;
	switch (num) {
	case 'd': p = diamante; break;
	case 'r': p = rubi; break;
	case 'e': p = esmeralda; break;
	case 'z': p = zafiro; break;
	case 'j': p = jade; break;
	}
	return entrada;
}

// resolver
int resolver(vector <piedrasPreciosas> const& v, int longSecuencia, tipoSecuencia const& t) {
	// numero de subsecuencias que cumplen
	int cumple = 0;
	// arrray de contadores de tipos de piedra
	vector <int> contadores(N_PIEDRAS);

	for (int i = 0; i < longSecuencia; i++) {
		contadores[v[i]]++; // v[i] tiene el tipo de piedra 
	}

	if (contadores[t.tipo1] >= t.numtipo1 && contadores[t.tipo2] >= t.numtipo2)
		cumple++;

	for (int i = 0; i < v.size() - longSecuencia; i++) {
		contadores[v[i]]--; // resto 1 al tipo de piedra de la izquierda
		contadores[v[i + longSecuencia]]++; // añado 1 al tipo de piedra de la derecha

		if (contadores[t.tipo1] >= t.numtipo1 && contadores[t.tipo2] >= t.numtipo2)
			cumple++;
	}

	return cumple;
}


void resuelveCaso() {
	// leer datos
	int numPiedras;
	int longSecuencia;
	tipoSecuencia ts;

	cin >> numPiedras >> longSecuencia
		>> ts.tipo1 >> ts.numtipo1 >> ts.tipo2 >> ts.numtipo2;

	// secuencia de piedras
	vector <piedrasPreciosas> v(numPiedras);

	for (piedrasPreciosas& i : v) {		cin >> i;	}
	// resolver
	int sol = resolver(v, longSecuencia, ts);

	// escribir sol
	cout << sol << endl;

}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}