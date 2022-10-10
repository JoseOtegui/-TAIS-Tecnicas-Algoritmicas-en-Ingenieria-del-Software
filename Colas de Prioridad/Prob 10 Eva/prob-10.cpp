/*
* Alberto Chaves López TAIS20
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
  * Estudiante 1:Alberto Chaves López TAIS20
  * Estudiante 2:Jose Otegui Marin TAIS73
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
using namespace std;
#include "PriorityQueue.h"

/*@ <answer>

Hemos creado un struc instrumento que contiene el numero de instrumentos totales, de partituras 
y la division resultante de dividir el total de instruentos entre las partituras.
Hemos modificado la prioridad con un operator que ordena de mayor a menor por esta division(int grupo)

El coste de insertar en las colas de prioridad es de LogN, al insertarse N veces el coste resultante será
de O(NlogN)

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

struct instrumento {
    int numInstrumentos;
    int numPartituras;
    int grupo;
};
bool operator <(instrumento a, instrumento b) {
        return a.grupo > b.grupo;
}
bool resuelveCaso() {

    // leemos la entrada
    int P, N;
    cin >> P >> N;

    if (!cin)
        return false;

    // leer el resto del caso y resolverlo
    PriorityQueue<instrumento> musicos;
    instrumento aux;
    for (int i = 0; i < N; i++) {
        cin >> aux.numInstrumentos;
        aux.numPartituras = 1;
        aux.grupo = aux.numInstrumentos;
        musicos.push(aux);
    }
    for (int i = 0; i < P-N; i++) {
        aux = musicos.top();
        musicos.pop();
        aux.numPartituras++;
        aux.grupo = aux.numInstrumentos / aux.numPartituras;
        if(aux.numInstrumentos % aux.numPartituras !=0) //Como la division es entera devolveria un numero menos de instrumento por partitura
            aux.grupo++; //se suma uno para compensar estos decimales
        musicos.push(aux);

    }
    cout << musicos.top().grupo << "\n";

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

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
