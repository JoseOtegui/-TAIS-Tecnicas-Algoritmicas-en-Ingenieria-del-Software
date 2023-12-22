
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

coste total teniendo en cuenta la lectura de datos 3N, si no, N en el peor de los casos
ya que se recorre las priorityQueue N veces hasta quedarse vacias.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {
    int n;
    cin >> n;
    if (!std::cin)  // fin de la entrada
        return false;

    PriorityQueue<int>enemigos;
    PriorityQueue<int>defensas;
    int aux;
    for (int i = 0; i < n; i++) { //coste N
        cin >> aux;
        enemigos.push(aux);
    }
    for (int i = 0; i < n; i++) { //coste N
        cin >> aux;
        defensas.push(aux);
    }
    int sol = 0;
    while (!enemigos.empty() && !defensas.empty()) { //coste N
        if (defensas.top() >= enemigos.top()) {
            defensas.pop(); enemigos.pop();
            sol++;
        }
        else 
            defensas.pop();
    }
 
    cout << sol << "\n";
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
