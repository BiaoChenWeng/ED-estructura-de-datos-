#include <iostream>
#include <fstream>
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

using tPares= pair<int, int>;

// tramo navegable y caudal total
tPares tramoNavegable(bintree<int>arbol) {

    if (arbol.empty())
        return {0,0};
    
    if (arbol.left().empty() && arbol.right().empty()) {
        return { 0,1 };
    }


    else {
        tPares izq= tramoNavegable(arbol.left());
        tPares der = tramoNavegable(arbol.right());
        tPares total;
        total = { izq.first + der.first,izq.second + der.second - arbol.root() };

        if (total.second >= 3)
            total.first++;
        else if (total.second < 0)
            total.second = 0;


        return total;
    }

}




// configuración, y escribiendo la respuesta
void resuelveCaso() {


    bintree<int>arbol= leerArbol(-1);

    tPares result = tramoNavegable(arbol);
    if (result.second >= 3) {
        result.first--;
    }
    cout << result.first<<endl;
}
