/*
* MUY IMPORTANTE: Solo se corregirán los comentarios y el código
* contenidos entre las etiquetas <answer> y </answer>.
* Toda modificación fuera de esas etiquetas no será corregida.
*/

/*@ <answer>
*
* Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
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

Para la lectura de datos habrá que crear las estructuras ordenadas, cuya creación tiene un coste de O(log n) por cada insercción
al insertar cada elemento, que se repite n veces, por lo que el coste de creación de las estructuras es O(nlog n)

20	30	40	80
50	40	30	30

30	10	0	0 = 40

@ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
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
	// escribir la solución
	cout << sol << "\n";
	return true;
}
//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

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