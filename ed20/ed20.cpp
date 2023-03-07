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
    
    cin >> entrada;
    if (entrada==-1 )
        return false;
    linked_list_ed_plus <int>lista;
    linked_list_ed_plus <int>negativo;
    int elem;
    for (int i = 0; i < entrada; i++) {
        cin >> elem;
        lista.push_back(elem);
    }
    lista.separar(negativo);
    lista.mostrar();
    negativo.mostrar();
    return true;
}
