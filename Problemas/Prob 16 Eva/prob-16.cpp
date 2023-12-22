/*
* MUY IMPORTANTE: Solo se corregir�n los comentarios y el c�digo
* contenidos entre las etiquetas <answer> y </answer>.
* Toda modificaci�n fuera de esas etiquetas no ser� corregida.
*/

/*@ <answer>
*
* Indicad el nombre completo y usuario del juez de quienes hab�is hecho esta soluci�n:
* Estudiante 1: Jose Otegui, TAIS73
* Estudiante 2: Alberto Chaves, TAIS20 
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
#include "Grafo.h"
using namespace std;


/*@ <answer>

Hemos utilizado el TAD de Maxima Componente Conexa dado que debemos hacer un dfs de cada v�rtice
del grafo dado que podr�a no ser conexo.
Al comienzo de la implementacion decimos que solo el vertice primero es victor y lo ponemos a false
en la primera vez que se pasa por este v�rtice.
Como entendemos que el primero en difundirlo tiene que cobrar ponemos un maximo de 2 personas que cobran
por ello, el que lo difunde y el primero que lo oye, el resto, son gratis para victor.

El coste de dfs es de O(V + A), dado que maxima componente conexa lo hace n vertices ser�a de O(N(V + A))

@ </answer> */


// ================================================================
// Escribe el c�digo completo de tu soluci�n aqu� debajo (despu�s de la marca)
//@ <answer>

class MaximaCompConexa {
public:
	MaximaCompConexa(Grafo const& g, const vector<int> &costes) : visit(g.V(), false), maxim(0), costes(costes), victor(true) {
		for (int v = 0; v < g.V(); ++v) {
			if (!visit[v]) { // se recorre una nueva componente conexa
				personaje = 0;
				int tam = dfs(g, v);
				maxim = max(maxim, tam);
			
			}
		}
	}
	// tama�o m�ximo de una componente conexa
	int maximo() const {
		return maxim;
	}
	int getCostalTotal() {
		return costeTotal;
	}
private:
	vector<bool> visit; // visit[v] = se ha visitado el v�rtice v?
	vector<int> costes;
	bool victor;
	int costeTotal;
	int maxim; // tama�o de la componente mayor
	int personaje;
	int dfs(Grafo const& g, int v) {
		visit[v] = true;
		int tam = 1;
		for (int w : g.ady(v)) {
			if (!visit[w]) {
				if (victor) {
					costeTotal += costes[v];
					victor = false;
				}
				else if (personaje < 1 && !victor) {
					costeTotal += costes[v];
					personaje++;
				}
				tam += dfs(g, w);
			}
		}
		return tam;
	}
};


bool resuelveCaso() {

	// leemos la entrada
	int N, M;
	cin >> N >> M;

	if (!cin)
		return false;

	// leer el resto del caso y resolverlo
	vector<int> costes(N);
	for (int i = 0; i < N; i++) {
		cin >> costes[i];
	}
	Grafo g(N);
	int v1;
	int v2;
	for (int i = 0; i < M; i++) {
		cin >> v1 >> v2; g.ponArista(v1 - 1, v2 - 1);
	}
	MaximaCompConexa componentes(g, costes);
	cout << componentes.getCostalTotal() << "\n";

	

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

	// Resolvemos
	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
