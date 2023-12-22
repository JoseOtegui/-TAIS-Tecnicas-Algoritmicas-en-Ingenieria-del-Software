
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

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct paciente {
    string nombre;
    int gravedad;
    int tiempoLlegada;
};

bool operator<(paciente a, paciente b) {
    if (a.gravedad == b.gravedad)
        return a.tiempoLlegada < b.tiempoLlegada;
    else
        return a.gravedad > b.gravedad;
}

bool resuelveCaso() {
    int eventos;
    cin >> eventos;
    if (eventos == 0)  // fin de la entrada
        return false;

    PriorityQueue<paciente> listaEspera;
    char evento;
    paciente p;
    int tiempo = 0;
    for (int i = 0; i < eventos; i++) {
        cin >> evento;
        if (evento == 'I') {
            cin >> p.nombre;
            cin >> p.gravedad;
            p.tiempoLlegada = tiempo;
            listaEspera.push(p);
        }
        else {
            cout << listaEspera.top().nombre << "\n";
            listaEspera.pop();
        }
        tiempo++;
    }
    cout << "---\n";

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