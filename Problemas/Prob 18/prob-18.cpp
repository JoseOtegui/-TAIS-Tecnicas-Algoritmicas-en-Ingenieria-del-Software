
/*@ <answer>
*
* Nombre y Apellidos:
*
*@ </answer> */

#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

#include "Digrafo.h"// propios o los de las estructuras de datos de clase

/*@ <answer>

Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
del tama�o del problema.

@ </answer> */


// ================================================================
// Escribe el c�digo completo de tu soluci�n aqu� debajo
// ================================================================
//@ <answer>

class OrdenTopologico {
public:
	// g es DAG
	OrdenTopologico(Digrafo const& g) : visit(g.V(), false) {
		for (int v = 0; v < g.V(); ++v)
			if (!visit[v])
				dfs(g, v);
	}
	// devuelve la ordenaci�n topol�gica
	std::deque<int> const& orden() const {
		return _orden;
	}
private:
	std::vector<bool> visit;
	std::deque<int> _orden; // ordenaci�n topol�gica
	void dfs(Digrafo const& g, int v) {
		visit[v] = true;
		for (int w : g.ady(v))
			if (!visit[w])
				dfs(g, w);
		_orden.push_front(v);
	}
};


bool resuelveCaso() {

	// leer los datos de la entrada
	int v, a;
	cin >> v >> a;

	if (!std::cin)  // fin de la entrada
		return false;

	int v1, v2;
	Digrafo g(v);
	for (int i = 0; i < a; i++) {
		cin >> v1 >> v2;
		g.ponArista(v1 - 1, v2 - 1);
	}
	OrdenTopologico o(g);
	deque<int> sol = o.orden();
	for (int i = 0; i < sol.size(); i++) {
		cout << sol[i] + 1 << " ";
	}
	cout << "\n";
	
	//falta detectar cilos.
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
