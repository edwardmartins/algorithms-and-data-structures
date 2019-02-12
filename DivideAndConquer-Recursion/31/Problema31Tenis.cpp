// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct tSolucion {
	bool presentado = false;
	int numPartidos = 0;
};

// función que resuelve el problema
// ronda = nivel de las llamadas recursivas
tSolucion resolver(vector <string> const&v, int ini, int fin, int round, int& ronda) {  
	tSolucion sol;

	if (ini + 2 == fin) { // 2 jugadores
		if (v[ini] == "NP" && v[ini + 1] == "NP")
			sol.presentado = false;
		else if (v[ini] == "NP" || v[ini + 1] == "NP") 
			sol.presentado = true;
		else 
		{
			sol.presentado = true;
			sol.numPartidos++;
		}
		ronda = 1;
	}
	else { // > 2 jugadores

		int mitad = (ini + fin + 1) / 2;

		tSolucion solIz = resolver(v, ini, mitad, round, ronda);
		tSolucion solDer = resolver(v, mitad, fin, round, ronda);
		// ronda
		ronda = ronda + 1;
		// partidos
		sol.numPartidos = solIz.numPartidos + solDer.numPartidos;
		
		if (solIz.presentado && solDer.presentado) {
			if(ronda <= round)
				sol.numPartidos++;

			sol.presentado = true;
		}
		else if(solIz.presentado || solDer.presentado)
			sol.presentado = true;	
		else if (!solIz.presentado && !solDer.presentado)
			sol.presentado = false;

	}
	return sol;
}


bool resuelveCaso() {
	// leer los datos de la entrada
	int numElem;
	int round;

	cin >> numElem >> round;

	if (!std::cin)
		return false;

	vector <string> v(numElem);

	for (int i = 0; i < v.size(); i++) {
		cin >> v[i];
	}
	int ronda = 0;

	tSolucion s = resolver(v, 0, v.size(), round, ronda);

	// escribir sol
	cout << s.numPartidos << endl;

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}