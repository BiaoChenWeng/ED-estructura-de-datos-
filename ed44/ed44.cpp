
#include <iostream>
#include <fstream>
#include "Class.h"
#include<vector>
#include <sstream>
#include<string>
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
    string entrada;
    getline(cin, entrada);
    if (!std::cin)  // fin de la entrada
        return false;

    vector<int>preorden;
    //int pos_ini=0;
    int i ;

    stringstream ss(entrada);

    while (ss) {
        ss >> i;
        preorden.push_back(i);
    }
    preorden.pop_back();// no se porque se copia dos veces el ultimo elemento

    arbol_plus<int>arbol = leerArbol_plus(preorden, 0, preorden.size());

    vector<int>v = arbol.postorder();
    for (int& k : v)
        cout << k << " ";
    cout << endl;
    return true;
}

