#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "PriorityQueue.h"

using namespace std;

struct tPaciente {
	string nombre;
	int gravedad;
	int tiempo;
};

bool operator <(tPaciente const&pac1, tPaciente const&pac2) {
	return pac1.gravedad > pac2.gravedad 
		|| pac1.gravedad == pac2.gravedad && pac1.tiempo < pac2.tiempo;
}

class comparadorPacientes {
public:
	bool operator()(tPaciente const&pac1, tPaciente const&pac2) {
		return pac1.gravedad > pac2.gravedad
			|| pac1.gravedad == pac2.gravedad && pac1.tiempo < pac2.tiempo;
	}
};

using namespace std;

bool resuelveCaso() {
	// leer datos
	int numEventos;
	cin >> numEventos;

	if (numEventos == 0)
		return false;

	//resolver
	PriorityQueue<tPaciente> pacientes;

	char tipoEvento;
	string nom;
	int grave, time;

	for (int i = 0; i < numEventos; i++) {
		cin >> tipoEvento;

		if (tipoEvento == 'I') {
			cin >> nom >> grave;
			time = i;
			pacientes.push({ nom,grave,time });
		}
		else if (tipoEvento == 'A') {
			tPaciente result = pacientes.top(); pacientes.pop();
			cout << result.nombre << "\n";
		}
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