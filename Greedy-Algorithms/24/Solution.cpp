#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "PriorityQueue.h"

using namespace std;


bool resuelveCaso() {
	// leer datos
	int n;
	cin >> n;

	if (n == 0)
		return false;

	// Los menores que la mediana ordenados de mayor a menor
	PriorityQueue<int, greater<int>> menores; 

	// Los mayores que la mediana ordenados de menor a mayor
	PriorityQueue<int> mayores;

	// La diferencia de tamaño entre las colas de prioridad 
	// tiene que ser como mucho 1, si es > 1 hay que sacar un elemento 
	// de una de las colas y meterla en la otra 

	int primer,valor;
	cin >> primer;
	if (n == 1)
		cout << primer * 2;
	else
		cout << primer * 2 << " ";

	for (int i = 1; i < n; i++) { 
		cin >> valor;

		// Ambas colas estan vacias
		if (i == 1) { 
			if (primer < valor) {
				menores.push(primer);
				mayores.push(valor);
			}
			else {
				menores.push(valor);
				mayores.push(primer);
			}
		}
		else {

			// Vemos en que cola iria el valor
			if (valor > menores.top()) 
				mayores.push(valor);
			else 
				menores.push(valor);
		
			// Diferencia de tamaños
			if (mayores.size() - menores.size() > 1) {
				menores.push(mayores.top());
				mayores.pop();
			}
			else if (menores.size() - mayores.size() > 1) {
				mayores.push(menores.top());
				menores.pop();
			}
		}

		// Calculamos mediana
		if (mayores.size() == menores.size())
			cout << mayores.top() + menores.top();
		else if (mayores.size() > menores.size())
			cout << mayores.top() * 2;
		else 
			cout << menores.top() * 2;

		if (i != n - 1)
			cout << " ";

	}

	cout << "\n";
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