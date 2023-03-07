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

struct info {
    int altura;
    int nodo;
    int hoja;
};

// configuración, y escribiendo la respuesta

template <class T>
info recorrerArbol(const bintree<T> & arbol) {
    if (arbol.empty()) {
        
        return {0,0,0};
    }
    else {
        info izq, der;
        izq = recorrerArbol(arbol.left());
        der = recorrerArbol(arbol.right());
        
        return { max(izq.altura, der.altura) + 1,izq.nodo+der.nodo+1,(izq.hoja==der.hoja && der.hoja==0)?(1):(izq.hoja+der.hoja)};

    }
}


void resuelveCaso() {

    
    bintree<char>arbol = leerArbol('.');
    
    info resultado = recorrerArbol(arbol);

    cout << resultado.nodo << " " << resultado.hoja<<" " << resultado.altura << endl;

}
