﻿
#include <iostream>
#include <fstream>
#include <vector>

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
    cin >> entrada;
    if (!std::cin)
        return false;
    if (entrada != 0) {

    }
    linked_list_ed_plus < int> lista;

    while (entrada != 0) {
        lista.push_back(entrada);
        cin >> entrada;
    }

    lista.duplicar();
    lista.mostrar();




    return true;
}

