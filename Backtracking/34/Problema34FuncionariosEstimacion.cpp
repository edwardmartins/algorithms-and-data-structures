// Nombre del alumno: Eduardo Martínez Martín
// Usuario del Juez: E31

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// acumulados

vector <int> acumular(vector <vector <int>> const& matrix) {

	// vector con los minimos de cada fila
	vector <int> minimos(matrix.size());

	for (int i = 0; i < matrix.size(); i++) {
		int min = matrix[i][0];

		for (int j = 0; j < matrix.size(); j++) {
			if (matrix[i][j] <= min) {
				min = matrix[i][j];
				minimos[i] = min;
			}
		}
	}

	// aqui ya tengo el vector de minimos, ahora hay que acumularlo

	for (int i = matrix.size() - 1; i > 0; i--) {
		minimos[i - 1] = minimos[i - 1] + minimos[i]; // el penultimo mas el ultimo y asi sucesivamente,
	    // asi tendremos en K + 1, el acumulado de las mejores soluciones desde el ultimo nivel
	}

	return minimos;
}

// función que resuelve el problema
void sumaMin(vector <vector <int>> const& matrix, vector <bool> & marcas, int k, int n, 
	int &suma, int &sumaMinima, vector <int> const&acumulados) {

	for (int i = 0; i < n; i++) {

		suma = suma + matrix[k][i];

		// Vamos pasando al siguiente nivel "k" que es la siguiente fila, 
		// como en el ejemplo de las reinas al formar la solucion de fila en fila
		// lo unico de lo que nos tenemos que asegurar 
		// es de que no coincida la columna ya que la fila nunca va a coincidir

		if (!marcas[i]) {
			if (k == n - 1) {
				if (suma < sumaMinima) {
					sumaMinima = suma;
				}
			}
			else {
				marcas[i] = true;
				if (suma + acumulados[k + 1] < sumaMinima) {
					sumaMin(matrix, marcas, k + 1, n, suma, sumaMinima,acumulados);
				}
				marcas[i] = false;
			}
		}
		suma = suma - matrix[k][i];
	}
}

bool resuelveCaso() {
	// leer datos
	int N;
	cin >> N;

	if (N == 0)
		return false;

	vector <vector <int>> matrix(N, vector <int>(N));
	int sumaMinima = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];
		}
		sumaMinima += matrix[i][i]; // Le damos un valor inicial cualquiera a la sumaMinima
	}

	//resolver
	int suma = 0;			  //  para ir sumando 
	vector <bool> marcas(N); //   para marcar las columnas ya usadas
	vector <int> acumulados = acumular(matrix);

	sumaMin(matrix, marcas, 0, N, suma, sumaMinima, acumulados);

	// escribir solucion
	cout << sumaMinima << endl;
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