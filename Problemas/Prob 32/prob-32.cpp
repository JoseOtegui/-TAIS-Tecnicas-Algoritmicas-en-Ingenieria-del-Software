
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int nJugadores, mEquipaciones;
    cin >> nJugadores >> mEquipaciones;
    if (!std::cin)  // fin de la entrada
        return false;
    PriorityQueue<int, greater<int>> tallasChico;
    PriorityQueue<int, greater<int>> tallaEquipaciones;
    int aux;
    for (int i = 0; i < nJugadores; i++) {
        cin >> aux; tallasChico.push(aux);
    }
    for (int i = 0; i < mEquipaciones; i++) {
        cin >> aux; tallaEquipaciones.push(aux);
    }

    int comprar = 0;
    while (!tallaEquipaciones.empty() && !tallasChico.empty()) {
        if (tallaEquipaciones.top() == tallasChico.top() || tallaEquipaciones.top() == tallasChico.top() + 1) {
            tallasChico.pop();
            tallaEquipaciones.pop();
        }
        else if (tallasChico.top() > tallaEquipaciones.top()) {
            tallasChico.pop();
            comprar++;
        }
        else 
            tallaEquipaciones.pop();
        
    }
   
    cout << comprar + tallasChico.size() << "\n";
        
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
