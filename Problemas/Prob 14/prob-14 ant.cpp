
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

class MaximaCompConexa {
public:
    MaximaCompConexa(Grafo const& g) : visit(g.V(), false), maxim(0) {
        for (int v = 0; v < g.V(); ++v) {
            if (!visit[v]) { // se recorre una nueva componente conexa
                int tam = dfs(g, v);
                cout << tam << " ";
                maxim = max(maxim, tam);
            }
        }
        cout << endl;
    }
    // tama�o m�ximo de una componente conexa
    int maximo() const {
        return maxim;
    }
    
private:
    vector<bool> visit; // visit[v] = se ha visitado el v�rtice v?
    int maxim; // tama�o de la componente mayor
    int dfs(Grafo const& g, int v) {
        visit[v] = true;
        int tam = 1;
        for (int w : g.ady(v)) {
            if (!visit[w])
                tam += dfs(g, w);
        }
        return tam;
    }
};


bool resuelveCaso() {

    // leer los datos de la entrada
    int nPersonas, nGrupos;
    cin >> nPersonas >> nGrupos;

    if (!std::cin)  // fin de la entrada
        return false;
    
    Grafo g(nPersonas);
    for (int i = 0; i < nGrupos; i++) {
        int persGrupo;
        cin >> persGrupo;
        if (persGrupo > 0) {
            int primerVertice;

            cin >> primerVertice;
            primerVertice--;
            for (int j = 1; j < persGrupo; j++) {
                int segundoVertice;
                cin >> segundoVertice;
                segundoVertice--;
                g.ponArista(primerVertice, segundoVertice);
                primerVertice = segundoVertice;
            }
        }
    }
    MaximaCompConexa comp(g);

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
