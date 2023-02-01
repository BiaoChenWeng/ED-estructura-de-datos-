﻿#include <iostream>
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

int busqueda(vector<Hora>&v,Hora buscar,int ini,int fin) {
    if (ini == fin)
        return -1;
    if (ini + 1 == fin) {
        if (v[ini] >= buscar) {
            return ini;
        }
        else {
            return -1;
        }
    }

    else {
        int m = (ini + fin-1) / 2;
        if (v[m] < buscar) {
            return busqueda(v, buscar, m+1, fin);
        }
        else {
            return busqueda(v, buscar, ini, m + 1);
        }
    }
}

bool resuelveCaso() {

    int entrada,revision;
    cin >> entrada>>revision;
    
    if (entrada==0 && revision==0)
        return false;
    vector<Hora>v(entrada);
    try {
        for (int i = 0; i < entrada; i++) {
            cin >> v[i];
        }
    }
    catch (invalid_argument& invalido) {
        cout << invalido.what() << endl;
    }
    Hora revisar;
    int pos;
    for (int i = 0; i < revision; i++) {
        try {
            cin >> revisar;
            pos = busqueda(v, revisar, 0, v.size());
            if ( pos== -1) {
                cout << "NO\n";
            }
            else {
                cout << v[pos]<<endl;
            }
        }
        catch (invalid_argument &invalido) {
            cout << invalido.what()<<endl;
        }
        
    }
    cout << "---\n";
    
    // escribir sol

    return true;
}
