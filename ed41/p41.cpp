#include <iostream>
#include <fstream>
#include "bintree_eda.h"
#include<math.h>
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

struct tSol {
    bool esBusqueda;   
    int max;
    int min;
};

template <typename T>
tSol esArbolBusqueda(bintree<T>arbol) {
    if (arbol.empty()) {
        return { true,-1,-1 };
    }
    else {
        tSol izq;
        tSol der;
        bool esBusqueda = true;
        int _min, _max;

        if (arbol.left().empty() && arbol.right().empty()) {
            _min = _max = arbol.root();
        }
        else if (arbol.left().empty()) {
            der = esArbolBusqueda(arbol.right());
            _min = min(der.min,arbol.root());
            _max = max(der.max, arbol.root());

            esBusqueda =der.esBusqueda && arbol.root() < der.min;
        }
        else if (arbol.right().empty()) {
            izq = esArbolBusqueda(arbol.left());
            _min = min(izq.min, arbol.root());
            _max = max(izq.max, arbol.root());
            esBusqueda =izq.esBusqueda &&  arbol.root() > izq.max;
        }
        else {
            
            izq = esArbolBusqueda(arbol.left());
            der = esArbolBusqueda(arbol.right());
            _min = min(izq.min, arbol.root());
            _min = min(_min, der.min);
            _max = max(izq.max, arbol.root());
            _max = max(_max,der.max);

            esBusqueda =izq.esBusqueda && der.esBusqueda &&arbol.root() < der.min && arbol.root() > izq.max;

        }
        
        return {esBusqueda,_max,_min};


    }
}


void resuelveCaso() {

    bintree<int>arbol = leerArbol(-1);

    if (esArbolBusqueda(arbol).esBusqueda) {
        cout << "SI\n";
    }
    else
        cout << "NO\n";

}
