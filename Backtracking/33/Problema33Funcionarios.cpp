// Nombre del alumno: Eduardo Martínez Martín
// Usuario del Juez: E31

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void sumaMin(vector <vector <int>> const& matrix,vector <bool> & marcas, int k, int n, int &suma, int &sumaMinima) {

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
				sumaMin(matrix, marcas, k + 1, n, suma, sumaMinima);
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

	sumaMin(matrix, marcas, 0, N, suma, sumaMinima);

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