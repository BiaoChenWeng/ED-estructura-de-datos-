
#include <iostream>
#include <fstream>
#include "Class.h"
// Introduce más librerías si son necesarias
using namespace std;

bool resuelveCaso();
int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("datos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    std::ofstream out("datos.out");
    auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    system("PAUSE");
#endif
    return 0;
}




bool resuelveCaso() {
    char entrada;
    cin >> entrada;
    if (!std::cin)  // fin de la entrada
        return false;


    if (entrada == 'N') {
        arbol_plus<int>arbol= leerArbol_plus<int>(-1);
        cout << arbol.menor() << endl;
    }
    else {
        arbol_plus<string>arbol= leerArbol_plus<string>("#");    
        cout << arbol.menor()<<endl;
    }

    


    return true;
}

