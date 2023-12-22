/*
* MUY IMPORTANTE: Solo se corregir�n los comentarios y el c�digo
* contenidos entre las etiquetas <answer> y </answer>.
* Toda modificaci�n fuera de esas etiquetas no ser� corregida.
*/

/*@ <answer>
*
* Indicad el nombre completo y usuario del juez de quienes hab�is hecho esta soluci�n:
* Estudiante 1: Alberto Chaves TAIS20
* Estudiante 2: Jose Otegui TAIS73
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

#include "PriorityQueue.h"



/*@ <answer>

Para optimizar la diferencia de los resultados hemos ordenado mediante una PriorityQueue de menor a mayor
los resultados de los contrarios y de mayor a menor los resultados de los Broncos, de esta forma, compara
la mayor puntuacion de los Broncos y la menor de los contrarios haciendo que la diferencia de estos resultados
sea la maxima posible en caso de ser mayor el resultado de los broncos que de los contrarios (b > c).

Para la lectura de datos habr� que crear las estructuras ordenadas, cuya creaci�n tiene un coste de O(log n) por cada insercci�n
al insertar cada elemento, que se repite n veces, por lo que el coste de creaci�n de las estructuras es O(nlog n)

20	30	40	80
50	40	30	30

30	10	0	0 = 40

@ </answer> */

// ================================================================
// Escribe el c�digo completo de tu soluci�n aqu� debajo (despu�s de la marca)
//@ <answer>


bool resuelveCaso() {

	// leer los datos de la entrada
	int nPartidos;
	cin >> nPartidos;
	if (nPartidos == 0)
		return false;


	PriorityQueue<int> contrarios;
	int aux;
	for (int i = 0; i < nPartidos; i++) {
		cin >> aux; contrarios.push(aux);
	}
	PriorityQueue<int, greater<int>> broncos;
	for (int i = 0; i < nPartidos; i++) {
		cin >> aux; broncos.push(aux);
	}

	int sol = 0;
	int c, b;
	for (int i = 0; i < nPartidos; i++) { // O(N)
		if (broncos.top() > contrarios.top())
			sol += broncos.top() - contrarios.top();

		contrarios.pop(); // O(1)
		broncos.pop(); // O(1)
	}
	// escribir la soluci�n
	cout << sol << "\n";
	return true;
}
//@ </answer>
//  Lo que se escriba debajo de esta l�nea ya no forma parte de la soluci�n.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	// Resolvemos
	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}