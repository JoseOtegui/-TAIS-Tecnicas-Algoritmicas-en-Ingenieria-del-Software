
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "PriorityQueue.h" // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    int peso;
    cin >> peso;

    if (!std::cin)  // fin de la entrada
        return false;

    int numSillas;
    cin >> numSillas;
    vector<int>sillas(numSillas);
    
    for (int i = 0; i < numSillas; i++) cin >> sillas[i];
    
    sort(sillas.begin(), sillas.end());


    int ini = 0;
    int fin = sillas.size() - 1;
    int sol = 0;
    //el bucle acaba cuando se cruzan los indices (se encuentra ini y fin)
    //30peso 8 10 12 16 20
    while (ini < fin) {
        if (sillas[ini] + sillas[fin] > peso) {
            fin--;
            sol++;
        }
        else {
            ini++;
            fin--;
            sol++;
        }
    }
    if (ini == fin) // no se llega a cruzar (vector impar) está en el medio
        sol++;

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
