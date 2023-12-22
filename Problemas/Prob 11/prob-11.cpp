
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

Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
del tama�o del problema.

@ </answer> */


// ================================================================
// Escribe el c�digo completo de tu soluci�n aqu� debajo
// ================================================================
//@ <answer>

class CaminosDFS {
private:
	std::vector<bool> visit; // visit[v] = �hay camino de s a v?
	std::vector<int> ant; // ant[v] = �ltimo v�rtice antes de llegar a v
	int s; // v�rtice origen
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
	// �hay camino del origen a v?
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
