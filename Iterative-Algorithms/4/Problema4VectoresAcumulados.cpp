// Nombre del alumno: Eduardo Martínez Martín
// Usuario del Juez: E31


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void resolver(vector <int> const& a, vector <int> &v) {
	/*
	Precondicion y postcondicion
	------------------------------
	requires a != null && a.Length > 0
	ensures v != null && v.Length > 0 && a.Length == v.Length
	ensures forall n :: 0 <= n < v.Length == > v[n] == Sum(a[n..])
	*/

	int x = 0;
	int i = a.size();

	while (i > 0)
		/*
		Invariante
		---------------------------------------------------------------
		invariant 0 <= i <= v.Length
		invariant forall n::i <= n < v.Length == > v[n] == Sum(a[n..])
		invariant x == Sum(a[i..])
		invariant a.Length == v.Length
		decreases i
		*/
	{
		x = x + a[i - 1];
		v[i - 1] = x;
		i = i - 1;
	}
}

bool resuelveCaso() {
	// leer los datos de la entrada
	int scan;
	cin >> scan;

	if (scan == 0) 
		return false;

	vector <int> a;

	while (scan != 0) {
		a.emplace_back(scan);
		cin >> scan;
	}

	vector <int> v(a.size()); // a.Length == v.Length

	//resolver
	resolver(a, v);

	// escribir sol
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i != v.size() - 1)
			cout << " ";
	}
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
