#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Matriz.h"


using namespace std;


struct pelicula {
	int inicio;
	int fin;
	int duracion;
};

bool operator <(pelicula p1, pelicula p2) {
	return p1.inicio < p2.inicio;
}

bool resuelveCaso() {
	// leer datos
	int N;
	cin >> N;

	if (N == 0)
		return false;

	vector<pelicula> peliculas(N);

	int h, m, d;
	char c;
	for (int i = 0; i < N; i++) {
		cin >> h >> c >> m;
		h = h * 60;
		peliculas[i].inicio = h + m;
		cin >> d;
		peliculas[i].duracion = d;
		peliculas[i].fin = peliculas[i].inicio + d + 10;
	}

	sort(peliculas.begin(), peliculas.end());
	int n = peliculas.size();
	vector<int> tiempo(24*60+11, 0);

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j <= 24*60; j++){
			if (peliculas[i].inicio >= j) { // no solapan
				tiempo[j] = max(tiempo[j], tiempo[peliculas[i].fin] + peliculas[i].duracion);
			}
		}
	}

	// escribir solucion
	cout << tiempo[0] << "\n";
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