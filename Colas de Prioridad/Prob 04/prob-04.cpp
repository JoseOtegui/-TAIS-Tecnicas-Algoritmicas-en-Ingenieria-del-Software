
/*@ <answer>
*
* Nombre y Apellidos:
*
*@ </answer> */

#include <iostream>
#include <fstream>

using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

struct usuario {
	int id;
	int periodo;
	int periodoSig;
};

bool operator <(usuario a, usuario b) {
	if (a.periodoSig == b.periodoSig)
		return a.id < b.id;
	else
		return a.periodoSig < b.periodoSig;
}
/*@ <answer>

He hecho un struct que contiene la informacion de cada usuario con su id su periodo y el 
siguiente que le toca, que este se calcula sumando su periodo correspondiente al siguiente
Ej: 200 + 200; 400 + 200; 600 + 200... 
Los usuarios están ordenados en una cola cuya prioridad está ordenada de menor a mayor segun
el periodo siguiente que le toca "turno" y en caso de ser iguales su id de menor tamaño.

@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>


bool resuelveCaso() {

	// leer los datos de la entrada
	int numUsuarios;
	cin >> numUsuarios;
	if (numUsuarios == 0)
		return false;

	PriorityQueue<usuario> cola;
	int id, periodo;
	usuario aux;
	for (int i = 0; i < numUsuarios; i++) {
		cin >> aux.id >> aux.periodo;
		aux.periodoSig = aux.periodo;
		cola.push(aux);
	}
	// resolver el caso posiblemente llamando a otras funciones
	int envios;
	cin >> envios;
	usuario usu;
	while (envios > 0) {
		cout << cola.top().id << "\n";
		usu.id = cola.top().id;
		usu.periodo = cola.top().periodo;
		usu.periodoSig = cola.top().periodo + cola.top().periodoSig;
		cola.pop();
		cola.push(usu);
		envios--;
	}
	// escribir la solución
	cout << "---\n";
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
