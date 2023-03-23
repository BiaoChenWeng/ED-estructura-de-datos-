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
    int num;
    int suma_total;
};

tSol numNodosAcumuladores(bintree<int>arbol) {

    if (arbol.empty()) {
        return {0,0};
    }
    else {
        tSol izq= numNodosAcumuladores(arbol.left());
        tSol der = numNodosAcumuladores(arbol.right());
        return {(izq.suma_total + der.suma_total== arbol.root())?(izq.num+der.num+1):(izq.num + der.num),izq.suma_total + der.suma_total + arbol.root()};
    }


}

void resuelveCaso() {

    bintree<int>arbol = leerArbol(-1);

    cout << numNodosAcumuladores(arbol).num << endl;

}
