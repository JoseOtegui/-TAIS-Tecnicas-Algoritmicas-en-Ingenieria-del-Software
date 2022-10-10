
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

Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
del tama�o del problema.

@ </answer> */


// ================================================================
// Escribe el c�digo completo de tu soluci�n aqu� debajo
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

	// escribir la soluci�n

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
