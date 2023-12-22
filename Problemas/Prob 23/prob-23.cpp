
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

#include "GrafoValorado.h" // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>
class CaminoCamion {

public:
    CaminoCamion(GrafoValorado<int> const& g, int s, int f, int ancho) : visit(g.V(), false),
        ant(g.V()), s(s) {
        dfs(g, s, f, ancho);
    }
    // �hay camino del origen a v?
    bool hayCamino(int v) const {
        return visit[v];
    }


private:
    std::vector<bool> visit; // visit[v] = �hay camino de s a v?
    std::vector<int> ant; // ant[v] = �ltimo v�rtice antes de llegar a v
    int s;
    // visita los v�rtices alcanzables desde v respetando el umbral
    // visita los nodos alcanzables desde v respetando el umbral
    void dfs(GrafoValorado<int> const& G, int v, int f, int ancho) {
        visit[v] = true;
        for (auto a : G.ady(v)) {
            if (a.valor() >= ancho) {
                int w = a.otro(v);
                if (!visit[w]) {
                    visit[w] = true;
                    if (f == w)
                        return;
                    dfs(G, w, f, ancho);
                }
            }
        }
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int v, a;
    cin >> v;
    if (!std::cin)  // fin de la entrada
        return false;

    cin >> a;
    int v1, v2, valor;
    GrafoValorado<int> g(v);
    for (int i = 0; i < a; i++) {
        cin >> v1 >> v2 >> valor;
        g.ponArista({ v1 - 1, v2 - 1, valor });
    }
    int k, ini, fin, anchoCamion;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> ini >> fin >> anchoCamion;
        CaminoCamion c(g, ini - 1, fin - 1, anchoCamion);
        if (c.hayCamino(fin - 1))
            cout << "SI\n";
        else
            cout << "NO\n";
    }
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
