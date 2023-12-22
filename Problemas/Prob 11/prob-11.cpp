
/*@ <answer>
*
* Nombre y Apellidos:
*
*@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Grafo.h" // propios o los de las estructuras de datos de clase

/*@ <answer>

Escribe aquí un comentario general sobre la solución, explicando cómo
se resuelve el problema y cuál es el coste de la solución, en función
del tamaño del problema.

@ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

class CaminosDFS {
private:
	std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
	std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
	int s; // vértice origen
	int nVisitados = 1; //dado el que vertice inicial se visita siempre, comienzo la cuenta en 1
	void dfs(Grafo const& G, int v) {
		visit[v] = true;
		for (int w : G.ady(v)) {
			if (!visit[w]) {
				nVisitados++;
				ant[w] = v;
				dfs(G, w);
			}
		}
	}

public:
	CaminosDFS(Grafo const& g, int s) : visit(g.V(), false),
		ant(g.V()), s(s) {
		dfs(g, s);
	}
	// ¿hay camino del origen a v?
	bool hayCamino(int v) const {
		return visit[v];
	}
	int visitados() {
		return nVisitados;
	}
};

bool resuelveCaso() {

	// leer los datos de la entrada
	int nVertices;
	cin >> nVertices;

	if (!std::cin)  // fin de la entrada
		return false;
	int nAristas;
	cin >> nAristas;
	if (nAristas > 0) {
		int v1, v2;
		Grafo grafo(nVertices);
		for (int i = 0; i < nAristas; i++) {
			cin >> v1 >> v2;
			grafo.ponArista(v1, v2);
		}
		CaminosDFS camino(grafo, 0);
		if (camino.visitados() != nVertices)
			cout << "NO\n";
		else
			cout << "SI\n";
	}
	else
		cout << "NO\n";
	

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
