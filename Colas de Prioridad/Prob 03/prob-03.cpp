
/*@ <answer>
*
* Nombre y Apellidos:
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
using namespace std;


/*@ <answer>

Escribe aquí un comentario general sobre la solución, explicando cómo
se resuelve el problema y cuál es el coste de la solución, en función
del tamaño del problema.

@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int resuelve(PriorityQueue<long long int> cola, int n) {
	long long int esfuerzo = 0;
	long long int suma = cola.top();
	cola.pop();
	while(!cola.empty()){
		suma += cola.top();
		esfuerzo += suma;
		cola.pop();
	}
	
	return esfuerzo;
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int n;
	cin >> n;

	if (n == 0)
		return false;
	
	PriorityQueue<long long int> cola;
	long long int aux;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		cola.push(aux);
	}

	// resolver el caso posiblemente llamando a otras funciones
	cout << resuelve(cola, n) << "\n";

	// escribir la solución

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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
