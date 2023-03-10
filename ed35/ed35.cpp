#include <iostream>
#include <fstream>
#include "bintree_eda.h"
// Introduce más librerías si son necesarias
using namespace std;
void resuelveCaso();

using tPares= pair <int, int>;


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


// primer parametro num de socorrista, segundo num de perdidos

tPares planRescate(const bintree<int> &arbol) {
    if (arbol.empty()) {
        return {0,0};
    }
    else {
        tPares izq = planRescate(arbol.left());
        tPares der = planRescate(arbol.right());


        return {(izq.first+der.first==0 && arbol.root() != 0) ? (1) : (izq.first + der.first),max(izq.second,der.second) + arbol.root()};
    }


}


void resuelveCaso() {

    bintree<int>arbol = leerArbol(-1);
    tPares sol = planRescate(arbol);
    cout << sol.first << " " << sol.second << endl;
    

}
