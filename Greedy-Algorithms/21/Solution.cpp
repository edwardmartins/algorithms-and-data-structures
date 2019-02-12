#include <iostream>
#include <iomanip>
#include <fstream>
#include "PriorityQueue.h"

struct tUsuario {
	int id;
	int periodo;
	int momento;
};

// Dos formas de redefinir el orden, operador menor o objeto funcion

bool operator <(tUsuario const&us1, tUsuario const&us2) {
	return us1.momento < us2.momento || us1.momento == us2.momento &&
		us1.id < us2.id;
}

class comparaUsuario {
public:
	bool operator()(tUsuario const&us1, tUsuario const&us2) const {
		return us1.momento < us2.momento || us1.momento == us2.momento &&
											us1.id < us2.id;
	}
};

using namespace std;

bool resuelveCaso() {
	// leer datos
	int numUsuarios;
	cin >> numUsuarios;

	if (numUsuarios == 0)
		return false;

	//resolver
	PriorityQueue<tUsuario> colaUsuarios;
	int identificador, period;

	for (int i = 0; i < numUsuarios; i++) { // N * log N --> "N" numero de usuarios
		cin >> identificador >> period;
		colaUsuarios.push({ identificador,period,period });
	}

	int k;
	cin >> k;

	for (int i = 0; i < k; i++) { // K * log N --> "K" numero de consultas
		tUsuario user = colaUsuarios.top(); colaUsuarios.pop();
		cout << user.id << "\n";
		user.momento += user.periodo;
		colaUsuarios.push(user);
	}
	cout << "----\n";
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