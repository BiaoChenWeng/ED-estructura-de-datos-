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

    int entrada;
    int salto;
    cin >> entrada>>salto;
    if (entrada==0 && salto == 0)
        return false;

    linked_list_ed_plus <int>lista;
    for (int i = 0; i < entrada; i++) {
        lista.push_back(i + 1);
    }

    cout <<lista.elegir(salto)<<endl;
    // escribir sol

    return true;
}
