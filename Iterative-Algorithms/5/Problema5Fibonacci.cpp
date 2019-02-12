// Nombre del alumno: Eduardo Martínez Martín
// Usuario del Juez: E31


#include <iostream>
#include <fstream>

using namespace std;


long long int Fibonacci(int n) {

	/*
	Precondicion y postcondicion
	-----------------------------
	requires n >= 0
	ensures f == Fib(n)
	*/
	long long int temp;
	int i = 0;
	long long int f = 0; // f(0)
	long long int a = 1; // f(1)

	while (i < n)
		/*
		Invariante
		------------------------
		invariant 0 <= i <= n
		invariant f == Fib(i)
		invariant a == Fib(i + 1)
		decreases n - i
		*/
	{
		temp = a;
		a = f + a;
		f = temp;
		i = i + 1;
	}

	return f;
}

bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	long long int f;
	cin >> n;

	if (n == -1)
		return false;

	//resolver
	int long long resultado = Fibonacci(n);

	// escribir sol
	cout << resultado << endl;

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
