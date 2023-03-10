#include <iostream>
#include <fstream>
#include <string>
#include "bintree_eda.h"
// Introduce más librerías si son necesarias
using namespace std;
void resuelveCaso();




int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("datos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    std::ofstream out("datos.out");
    auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    system("PAUSE");
#endif
    return 0;
}

struct tSol{
    bool izq;
    int nodo;
};

// configuración, y escribiendo la respuesta

template <class T>
tSol recorrerArbol(const bintree<T>& arbol) {
    if (arbol.empty()) {
        return {true,0};
    }
    else {
        tSol izq, der;
        izq = recorrerArbol(arbol.left());
        der = recorrerArbol(arbol.right());
        bool esIzq;
        if (izq.nodo> der.nodo) {
            esIzq = izq.izq && der.izq;
        }
        else  {
            esIzq = izq.nodo == der.nodo && izq.nodo == 0;
        }
        
        return { esIzq,izq.nodo+der.nodo + 1};
    }
}


void resuelveCaso() {


    bintree<char>arbol = leerArbol('.');

    tSol resultado = recorrerArbol(arbol);

    if (resultado.izq) {
        cout << "SI\n";
    }
    else {
        cout << "NO\n";
    }

}
