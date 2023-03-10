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


// primer parametro altura del arbol, segundo diametro actual
template <typename T>
tPares diametroArbol(const bintree<T> &arbol) {
    if (arbol.empty()) {
        return {0,0};
    }
    else {
        tPares izq = diametroArbol(arbol.left());
        tPares der = diametroArbol(arbol.right());
        int diametro = max(izq.second, der.second);
        diametro= max(izq.first + der.first + 1,diametro);
        
        return {max(izq.first,der.first)+1,diametro};
    }


}


void resuelveCaso() {

    bintree<char>arbol = leerArbol('.');


    cout << diametroArbol(arbol).second<<endl;

}
