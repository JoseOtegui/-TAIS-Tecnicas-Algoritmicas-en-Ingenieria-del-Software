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
using namespace std;

#include "Matriz.h"

/*@ <answer>
Hemos creado un struct conciertos con la informacion de la entrada que contiene nGrupos y el precio de la entrada y creado
un vector con esta informacion.
Para resolver el problema hemos creado una Matriz de tama�o de la lista de conciertos * presupuesto de de entrada de Sergio.
Esta matriz se rellena de forma que se escribe el maximo de grupos que van a ese concierto menos el precio de la entrada 
comparado con el "presupuesto" anterior, de forma que se va mejorando la solucion.
La solucion al problema es la ultima posicion de esta matriz que tiene la mejor solucion al problema.

@ </answer> */

// ================================================================
// Escribe el c�digo completo de tu soluci�n aqu� debajo (despu�s de la marca)
//@ <answer>



struct concierto {
	int nGrupos;
	int precioEntrada;
};

int resolver(vector<concierto> &conciertos, int P) {
	int tam = conciertos.size();
	Matriz<int> matriz(tam + 1, P + 1, 0);

	for (int i = 1; i <= tam; i++) {
		for (int j = 1; j <= P; j++) {
			if (conciertos[i - 1].precioEntrada > j) {
				matriz[i][j] = matriz[i - 1][j];
			}
			else {
				matriz[i][j] = max(matriz[i - 1][j], matriz[i - 1][j - conciertos[i - 1].precioEntrada] + conciertos[i - 1].nGrupos);
			}
		}
	}
	return matriz[tam][P];
}


bool resuelveCaso() {

	int P, N;
	cin >> P >> N;  // presupuesto y n�mero de festivales

	if (!cin)
		return false;

	// leer el resto del caso y resolverlo

	vector<concierto> conciertos(N + 1);
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		conciertos[i] = { a,b };
	}

	cout << resolver(conciertos, P) << "\n";

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
