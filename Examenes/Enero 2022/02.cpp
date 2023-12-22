
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

using namespace std;

#include "GrafoValorado.h" // propios o los de las estructuras de datos de clase
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class ARM_Kruskal {
private:
    std::vector<Arista<int>> _ARM;
    int coste;
    int arista;
    int verticesVisitados;

public:
    int costeARM() const {
        return coste;
    }
    std::vector<Arista<int>> const& ARM() const {
        return _ARM;
    }
    ARM_Kruskal(GrafoValorado<int> const& g) : coste(0), arista(0), verticesVisitados(1) {
        PriorityQueue<Arista<int>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                _ARM.push_back(a); coste += a.valor();
                verticesVisitados++;
                if(a.valor() > arista)
                    arista = a.valor();
                if (_ARM.size() == g.V() - 1) break;
            }
        }
    }
    int getArista() {
        return arista;
    }
    int getVerticesVisitados(){
        return verticesVisitados;
    }
};

bool resuelveCaso() {

    int nCiudades, nCarreteras;
    cin >> nCiudades;
    if (!std::cin)  // fin de la entrada
        return false;
    cin >> nCarreteras;

    GrafoValorado<int> g(nCiudades);
    
    int c1, c2, longitud;
    for (int i = 0; i < nCarreteras; i++) {
        cin >> c1 >> c2 >> longitud;
        g.ponArista({ c1 - 1, c2 - 1, longitud});
    }

    ARM_Kruskal camino(g);
    if (camino.getVerticesVisitados() < nCiudades)
        cout << "Imposible\n";
    else
        cout << camino.getArista() << "\n";


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
