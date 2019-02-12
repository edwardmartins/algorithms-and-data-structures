#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;



struct pelicula {
	int inicio;
	int fin;
};


bool operator < (pelicula const&p1, pelicula const&p2) {
	return (p1.fin < p2.fin);
}

bool resuelveCaso() {
	// leer datos
	int N;
	cin >> N;

	if (N == 0)
		return false;

	vector<pelicula> peliculas(N);
	int hora, min; char c;
	int duracion;

	for (int i = 0; i < N; i++) {
		cin >> hora >> c >> min;
		peliculas[i].inicio = hora * 60 + min;
		cin >> duracion;
		peliculas[i].fin = hora * 60 + min + duracion + 10;
	}

	sort(peliculas.begin(), peliculas.end(), less<pelicula>());

	// resolver
	int numPeliculas = 1;
	int finaliza = peliculas[0].fin;

	for (int i = 1; i < N; i++) {
		if (finaliza <= peliculas[i].inicio) { // No hay solapamiento
			numPeliculas++;
			finaliza = peliculas[i].fin;
		}
	}
	// escribir solucion
	cout << numPeliculas << "\n";
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