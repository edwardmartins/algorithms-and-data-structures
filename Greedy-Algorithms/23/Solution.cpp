#include <iostream>
#include <iomanip>
#include <fstream>
#include "PriorityQueue.h"

using namespace std;

struct tarea {
	int ini;
	int fin;
	int periodo = 0;
};

bool operator <(tarea const &t1, tarea const &t2) {
	return(t1.ini < t2.ini);
}


bool resuelveCaso() {
	// leer datos
	int Nunicas, Mperiodicas, tiempo;
	cin >> Nunicas >> Mperiodicas >> tiempo;

	if (!cin)
		return false;


	PriorityQueue<tarea> tareas;

	// Unicas
	int c, f;
	tarea t;

	for (int i = 0; i < Nunicas; i++) {
		cin >> c >> f;
		t.ini = c;
		t.fin = f;
		tareas.push(t);
	}

	// Repetitivas
	int per;

	for (int i = 0; i < Mperiodicas; i++) {
		cin >> c >> f >> per;
		t.ini = c;
		t.fin = f;
		t.periodo = per;
		tareas.push(t);
	}

	// resolver
	int momento = 0;
	bool conflicto = false;
	int ultTime;
	tarea t2;

	t2 = tareas.top(); tareas.pop();
	ultTime = t2.fin; // ultimo tiempo donde no ha habido conflictos

	if (t2.periodo > 0) {
		t2.ini += t2.periodo;
		t2.fin += t2.periodo;
		tareas.push(t2);
	}

	while (!conflicto && momento < tiempo && tareas.size() > 0) {

		t2 = tareas.top(); tareas.pop();
		momento = t2.ini;

		if (momento < tiempo) {
			if (ultTime > t2.ini) {
				conflicto = true;
			}
		}

		ultTime = t2.fin; // actualizo el ultimo tiempo sin conflictos

		if (t2.periodo > 0) {
			t2.ini += t2.periodo;
			t2.fin += t2.periodo;
			tareas.push(t2);
		}

	}

	// escribir solucion
	if (conflicto)
		cout << "SI\n";
	else
		cout << "NO\n";


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