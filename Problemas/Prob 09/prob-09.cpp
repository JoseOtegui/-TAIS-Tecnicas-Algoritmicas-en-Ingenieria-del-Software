
/*@ <answer>
*
* Nombre y Apellidos:
*
*@ </answer> */

#include <iostream>
#include <fstream>

using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
del tama�o del problema.

@ </answer> */


// ================================================================
// Escribe el c�digo completo de tu soluci�n aqu� debajo
// ================================================================
//@ <answer>

struct pila {
	int voltios;
};

bool operator <(pila a, pila b) {
	return a.voltios > b.voltios;
}

bool resuelveCaso() {

	// leer los datos de la entrada
	int nDrones, nA, nB;
	cin >> nDrones >> nA >> nB;

	if (!std::cin)  // fin de la entrada
		return false;

	int aux;
	pila pilaAux;
	PriorityQueue<pila> pilasA;
	PriorityQueue<pila> pilasB;
	for (int i = 0; i < nA; i++) {
		cin >> pilaAux.voltios;
		pilasA.push(pilaAux);
	}
	/*for (int i = 0; i < nA; i++) {
		cout << pilasA.top().voltios;
		pilasA.pop();
	}*/
	for (int i = 0; i < nB; i++) {
		cin >> pilaAux.voltios;
		pilasA.push(pilaAux);
	}
	
	while (!pilasA.empty() && !pilasB.empty()) {

	}
	// resolver el caso posiblemente llamando a otras funciones

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
