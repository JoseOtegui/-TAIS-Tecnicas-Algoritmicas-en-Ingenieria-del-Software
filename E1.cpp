
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>      
#include <vector>
#include "PriorityQueue.h"
using namespace std;


/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>
struct actividad {
    int ini;
    int fin;
};
struct participante {
    int ini;
    int fin;
};

bool operator <(actividad a, actividad b) {
    return a.ini < b.ini;
}

bool operator <(participante a, participante b) {
    return a.fin < b.fin;
}


bool resuelveCaso() {

    // leer los datos de la entrada
    int nActividades;
    cin >> nActividades;
    if (nActividades == 0)
        return false;

    PriorityQueue<actividad> actividades;
    PriorityQueue<participante> participantes;

 
    for (int i = 0; i < nActividades; i++) {
        int ini, fin;
        actividad a;
        cin >> ini >> fin;
        a.ini = ini;
        a.fin = fin;
        actividades.push(a);
    }
    participante p;
    p.ini = actividades.top().ini;
    p.fin = actividades.top().fin;
    participantes.push(p);
    actividades.pop();


    while (!actividades.empty()) {
        if (actividades.top().ini < participantes.top().fin){
            participante p;
            p.ini = actividades.top().ini;
            p.fin = actividades.top().fin;
            participantes.push(p);
        }
        else {
            participantes.pop();
            participante p;
            p.ini = actividades.top().ini;
            p.fin = actividades.top().fin;
            participantes.push(p);
        }
        actividades.pop();
    }

    cout << participantes.size() - 1 << endl;
    
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
