#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;


bool resuelveCaso() {
	// leer los datos de la entrada
	int tamTablero, carasDado, numSerpientes, numEscaleras;
	cin >> tamTablero >> carasDado >> numSerpientes >> numEscaleras;

	if (tamTablero == 0 && carasDado == 0
		&& numSerpientes == 0 && numEscaleras == 0)
		return false;

	// resolver
	vector<int> caminos((tamTablero*tamTablero) + 1);

	for (int i = 0; i < caminos.size(); i++) {
		caminos[i] = i;
	}

	int a, b;
	for (int i = 0; i < numSerpientes + numEscaleras; i++) {
		cin >> a >> b;
		caminos[a] = b;
	}

	vector<bool> marked((tamTablero*tamTablero) + 1);
	vector<int> distTo((tamTablero*tamTablero) + 1);

	int s = caminos[1];
	queue<int> q;
	distTo[s] = 0;
	marked[s] = true;
	q.push(s);

	while (!q.empty()) {
		int v = q.front(); q.pop();

		for (int w = 1; w <= carasDado; w++) {

			if (v + w <= tamTablero * tamTablero) {
				if (!marked[caminos[v + w]]) {
					distTo[caminos[v + w]] = distTo[v] + 1;
					marked[caminos[v + w]] = true;
					q.push(caminos[v + w]);
				}
			}
		}
	}

	// escribir sol
	cout << distTo[caminos.size() - 1] << "\n";

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