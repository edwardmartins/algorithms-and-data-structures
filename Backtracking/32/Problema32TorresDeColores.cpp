// Nombre del alumno: Eduardo Martínez Martín
// Usuario del Juez: E31

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tcubos {
	int azul; // 0
	int rojo; // 1
	int verde; // 2
};


bool esValida(vector <int> const& sol, int k, tcubos const &cubos, tcubos &cubosUsados) {
	bool valida = true;

	// Queden colores
	if (sol[k] == 0) {
		if (cubosUsados.azul > cubos.azul)
			valida = false;
	}
	else if (sol[k] == 1) {
		if (cubosUsados.rojo > cubos.rojo)
			valida = false;
	}
	else if (sol[k] == 2) {
		if (cubosUsados.verde > cubos.verde)
			valida = false;
	}

	// Dos piezas verde juntas
	if (sol[k] == 2 && sol[k - 1] == 2)
		valida = false;

	// No mas verdes que azules
	if (sol[k] == 2 && cubosUsados.verde > cubosUsados.azul)
		valida = false;

	return valida;
}

void escribirSolucion(vector <int> const& sol) {
	for (int i = 0; i < sol.size(); i++) {
		if (sol[i] == 0)
			cout << "azul" << " ";
		else if (sol[i] == 1)
			cout << "rojo" << " ";
		else if (sol[i] == 2)
			cout << "verde" << " ";
	}
	cout << endl;
}

// función que resuelve el problema, "K" empezara en 1 porque hemos metido ya el rojo
void resolver(vector <int> &sol, int k, tcubos const& cubos, tcubos &cubosUsados, bool& haySolucion) {
	for (int i = 0; i < 3; i++) {
		sol[k] = i; // i es el color

		if (sol[k] == 0)
			cubosUsados.azul++;
		else if (sol[k] == 1)
			cubosUsados.rojo++;
		else if (sol[k] == 2)
			cubosUsados.verde++;

		if (esValida(sol, k, cubos, cubosUsados)) {
			if (k == sol.size() - 1) {
				if (cubosUsados.rojo > cubosUsados.azul + cubosUsados.verde) {
					escribirSolucion(sol);
					haySolucion = true;
				}
			}
			else { 
				resolver(sol, k + 1, cubos, cubosUsados, haySolucion);
			}
		}

		if (sol[k] == 0)
			cubosUsados.azul--;
		else if (sol[k] == 1)
			cubosUsados.rojo--;
		else if (sol[k] == 2)
			cubosUsados.verde--;
	}
}

bool resuelveCaso() {
	// leer datos
	int alturaTorre;
	cin >> alturaTorre;

	vector <int> sol(alturaTorre);
	tcubos cubos;
	tcubos cubosUsados;

	// Cubos Usados
	cubosUsados.azul = 0;
	cubosUsados.rojo = 0;
	cubosUsados.verde = 0;

	// Cubos
	cin >> cubos.azul;
	cin >> cubos.rojo;
	cin >> cubos.verde;

	if (alturaTorre == 0 && cubos.azul == 0 && cubos.rojo == 0 && cubos.verde == 0)
		return false;

	// El primero siempre es uno rojo
	sol[0] = 1;
	cubosUsados.rojo++;


	//resolver
	bool haySolucion = false;

	 

	if (cubos.rojo > 1) { // el caso en que solo haya un rojo.
		if (cubos.azul + cubos.rojo + cubos.verde >= alturaTorre) // casos en que no hay cubos suficientes 
			resolver(sol, 1, cubos, cubosUsados, haySolucion);
	}
	
	if (!haySolucion)
		cout << "SIN SOLUCION" << endl;

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