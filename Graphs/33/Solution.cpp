#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>


using namespace std;

using Mapa = vector<string>;


class Ovejas {


private:

	// Atributos 
	int numFilas, numColumnas;
	vector<vector<bool>> marked;
	int _numero = 0;

	// Para no salirse de los limites de la matriz
	bool correcta(int i, int j) const {
		return 0 <= i && i < numFilas && 0 <= j && j < numColumnas;
	}

	// Vector de direcciones para ir moviendose en la matriz en vertical u horizontal
	const vector<pair<int, int>> dirs = { {1,0}, {0,1},{-1,0}, {0,-1} };


	void dfs(Mapa const&mapa, int i, int j) {

		marked[i][j] = true;
	
		for (auto nuevaDir : dirs) {
			int ni = i + nuevaDir.first; int nj = j + nuevaDir.second;

			if (correcta(ni, nj) && mapa[ni][nj] == '.' && !marked[ni][nj]) {
				dfs(mapa, ni, nj); 

			}
		}
	}

public:

	Ovejas(Mapa const& mapa) : numFilas(mapa.size()), numColumnas(mapa[0].size()),

		marked(numFilas,vector<bool>(numColumnas,false)){

		for (int i = 0; i < numFilas; i++) {
			for (int j = 0; j < numColumnas; j++) {

				// Nueva componente conexa
				if (mapa[i][j] == '.' && !marked[i][j]) {
					++_numero;
					dfs(mapa, i, j);
				}
			}
		}
	}

	// Solo me intera el numero de componentes conexas de "."
	// y teniendo en cuenta que una es el fondo
	int numero() const {
		return _numero - 1;
	}

};

bool resuelveCaso() {
	// leer datos
	int ancho, alto;
	cin >> ancho >> alto;

	if (!cin)
		return false;

	Mapa mapa(alto); 


	for (string &fila : mapa) { 
		cin >> fila;
	}

	// resolver
	Ovejas ovejas(mapa);

	// escribir solucion
	cout << ovejas.numero() << "\n";

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