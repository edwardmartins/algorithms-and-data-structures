
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

using Mapa = vector<string>;


class solution {

private:
	int F; // filas
	int C; // columnas
	vector<vector<bool>> marked;
	vector<vector<int>> distTo;
	int caminoMinimo = 0;

	bool posCorrecta(int i, int j) { // i fila, j columna
		return 0 <= i && i < F && 0 <= j && j < C;
	}

	const vector<pair<int,int>> dirs = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };

	int convertirCoordenada(int i, int j) {
		return ((i * C) + j);
	}

	void bfs(Mapa const&M, int i, int j) { // i, j es la posicion de partida
		queue<pair<int,int>> q;
		marked[i][j] = true;
		distTo[i][j] = 0;
		q.push({ i,j });

		if (M[i][j] != '#') {
			while (!q.empty()) {
				auto v = q.front(); q.pop();

				for (auto d : dirs) { 

					int ni = v.first + d.first, nj = v.second + d.second;

					if (posCorrecta(ni, nj) && !marked[ni][nj] && (M[ni][nj] == '.' || M[ni][nj] == 'P')) {
						distTo[ni][nj] = distTo[v.first][v.second] + 1;
						marked[ni][nj] = true;
						if (M[ni][nj] == 'P') {
							caminoMinimo = distTo[ni][nj];
						}
						q.push({ ni,nj });
					}
				}
			}
		}
	}

	

public:

	solution(Mapa const&M, int a, int b):F(M.size()),C(M[0].size()),
			marked(F, vector<bool>(C, false)),distTo(F,vector<int>(C)){
			bfs(M, a, b);	
	}

	int getCaminoMinimo() {
		return caminoMinimo;
	}
};

void rangoCamara(int a,int b, int k, Mapa &M, bool &posible) {

	M[a][b] = 'c';

	// A la derecha
	for (int i = 1; i <= k && b + i != M[0].size(); i++) {
		if (M[a][b + i] == '.') {
			M[a][b + i] = 'c';
		}
		else if (M[a][b + i] == 'E' || M[a][b + i] == 'P') {
			posible = false;
		}
		else if(M[a][b + i] == '#') { break; }
	}

	// A la izquierda
	for (int i = 1; i <= k &&  b - i >= 0 ; i++) {
		if (M[a][b - i] == '.')
			M[a][b - i] = 'c';
		else if (M[a][b - i] == 'E' || M[a][b - i] == 'P') {
			posible = false;
		}
		else if (M[a][b - i] == '#') { break; }
	}

	// abajo
	for (int i = 1; i <= k && a + i != M.size(); i++) {
		if (M[a + i][b] == '.')
			M[a + i][b] = 'c';
		else if (M[a + i][b] == 'E' || M[a + i][b] == 'P') {
			posible = false;
		}
		else if (M[a + i][b] == '#') { break; }
	}

	// arriba
	for (int i = 1; i <= k && a - i >= 0 ; i++) {
		if (M[a - i][b] == '.')
			M[a - i][b] = 'c';
		else if (M[a - i][b] == 'E' || M[a - i][b] == 'P') {
			posible = false;
		}
		else if (M[a - i][b] == '#') { break; }
	}
}

void resuelveCaso() {
	// leer datos
	int C, F;
	cin >> C >> F;

	Mapa mapa(F);

	// leemos la imagen
	for (string & linea : mapa) {
		cin >> linea;
	}

	// leemos el mapa para saber donde estan los sensores y el origen
	int o1, o2, f1, f2;
	vector<pair<int, int>> sensores;

	for (int i = 0; i < F; i++) {
		for (int j = 0; j < C; j++) {
			if (isdigit(mapa[i][j])) {
				sensores.push_back({ i,j });
			}
			
			if (mapa[i][j] == 'E') {
				o1 = i;
				o2 = j;
			}
		}
	}

	// Reconfiguramos el mapa
	bool posible = true;
	for (int i = 0; i < sensores.size(); i++) {
		int a = sensores[i].first; int b = sensores[i].second;
		int k = mapa[a][b] - '0';
		rangoCamara(a, b, k, mapa, posible);
	}

	// resolver
	if (posible) {
		solution sol(mapa, o1, o2);
		int s = sol.getCaminoMinimo();

		// escribir solucion
		if (s != 0)
			cout << s << "\n";
		else
			cout << "NO\n";
	}
	else {
		cout << "NO\n";
	}

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