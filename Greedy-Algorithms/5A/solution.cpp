
// El coste es O(Max(N* logN, M* logM)

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


bool resuelveCaso() {
   int N, M;
   cin >> N >> M;
   
   if (!cin)
      return false;

   vector <int> tallasJugadores(N);

   for (int i = 0; i < N; i++) {
	   cin >> tallasJugadores[i];
   }

   vector<int> tallasQueTenemos(M);

   for (int i = 0; i < M; i++) {
	   cin >> tallasQueTenemos[i];
   }

   sort(tallasJugadores.begin(), tallasJugadores.end());
   sort(tallasQueTenemos.begin(), tallasQueTenemos.end());


   int i = 0; // jugadores
   int j = 0; // tenemos
   int numEquipaciones = 0;

   while (i < N && j < M) {
	   if (tallasQueTenemos[j] - tallasJugadores[i] >= 0  && 
		   tallasQueTenemos[j] - tallasJugadores[i] <= 1) { // si hay talla
		   i++;
		   j++;
	   }
	   else if (tallasQueTenemos[j] > tallasJugadores[i]) { 
		   i++;
		   numEquipaciones++; 
	   else { 
		   j++;
	   }
   }

   numEquipaciones += tallasJugadores.size() - i; 
   cout << numEquipaciones << "\n";
   return true;
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso());
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
