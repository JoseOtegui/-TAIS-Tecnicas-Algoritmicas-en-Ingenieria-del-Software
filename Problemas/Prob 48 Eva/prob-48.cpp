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
#include <string>
#include "Matriz.h"
using namespace std;


/*@ <answer>

subsecuencia(i,j) : nº caracteres de la secuencia más larga.
caso base:
subsecuencia (0,j )=0 <- para todo j
subsecuencia(i,0) =0 <- para todo i
caso recursivo :
subsecuencia(i,j) = subsecuencia(i-1,j-1) +1  si palabra1[i -1] = palabra2[j -1]
subsecuencia(i,j) max(subsecuencia(i-1,j),(subsecuencia(i,j-1))   si palabra1[i - 1] != palabra2[j - 1]

@ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
//@ <answer>



string resolver(const string &c1, const string &c2) {
	string cadena, subcadena;
	int tam1 = c1.size();
	int tam2 = c2.size();
	Matriz<int> cadenas(tam1 + 1, tam2 + 1, 0);
	for (int i = 1; i <= tam1; i++) {
		for (int j = 1; j <= tam2; j++) {
			if (c1[i - 1] == c2[j - 1]) {
				cadenas[i][j] = cadenas[i - 1][j - 1] + 1;
			}
			else {
				cadenas[i][j] = max(cadenas[i - 1][j], cadenas[i][j - 1]);
			}
		}
	}
	int tamAux = cadenas[tam1][tam2];

	while (tamAux > 0) {
		if (c1[tam1 - 1] == c2[tam2 - 1]) {
			subcadena += c1[tam1 - 1];
			tamAux--;
			tam1--;
			tam2--;

		}
		else {
			if (cadenas[tam1][tam2] == cadenas[tam1][tam2 - 1]) {
				tam2--;
			}
			else {
				tam1--;
			}
		}
	}
	for (int i = subcadena.size(); i > 0; i--) {
		cadena += subcadena[i - 1];
	}
	return cadena;
}

bool resuelveCaso() {

	// leemos la entrada
	string X, Y;
	cin >> X >> Y;

	if (!cin)
		return false;

	// resolver el caso
	cout << resolver(X, Y) << "\n";

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
