
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

struct actividad {
    int ini;
    int fin;
};

struct asistente {
    int ini;
    int fin;
};

bool operator<(actividad a, actividad b) {
    return(a.ini < b.ini);
}
bool operator<(asistente a, asistente b) {
    return (a.fin < b.fin);
}
bool resuelveCaso() {

    int nActividades;
    cin >> nActividades;
    if (nActividades == 0)
        return false;


    actividad aux;
    PriorityQueue <actividad> actividades;
    for (int i = 0; i < nActividades; i++) {
        cin >> aux.ini >> aux.fin;
        actividades.push(aux);
    }

    PriorityQueue<asistente> asistentes;
    asistente asis;
    asis.ini = actividades.top().ini;
    asis.fin = actividades.top().fin;
    actividades.pop();
    asistentes.push(asis);

    while (!actividades.empty()) {
        if (asistentes.top().fin <= actividades.top().ini) {
            asis.ini = actividades.top().ini;
            asis.fin = actividades.top().fin;
            asistentes.pop();
            asistentes.push(asis);
        }
        else {
            asis.ini = actividades.top().ini;
            asis.fin = actividades.top().fin;
            asistentes.push(asis);
        }
        actividades.pop();
    }
    cout << asistentes.size() - 1 << "\n";
    // resolver el caso posiblemente llamando a otras funciones

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
