// Nombre del alumno : Eduardo Martínez Martín
// Usuario del Juez : E31


#include <iostream>
#include <fstream>

using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numero, maximo, tam, cont = 1;
	cin >> tam;
	cin >> maximo;

	for (int i = 1; i < tam; i++) {
		cin >> numero;
		if (numero > maximo) {
			maximo = numero;
			cont = 1;
		}
		else if(numero == maximo)
				cont++;	
	}
	cout << maximo << " " << cont << endl;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}