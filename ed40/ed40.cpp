
#include <iostream>
#include <fstream>
#include "Class.h"
#include<vector>
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
    int pos_ini = 0;
    int i = 0;
    while (i < entrada.size()) {
        if (entrada[i] != ' ') {
            pos_ini = i;
            i++;
            while (i < entrada.size() && entrada[i] != ' ') {
                i++;
            }
            preorden.push_back(stoi(entrada.substr(pos_ini, i)));
        }
        else {
            i++;
        }

    }

    vector<int>inorden(preorden.size());
    for (int& k : inorden)
        cin >> k;
    getline(cin, entrada);
    
    arbol_plus<int>arbol = leerArbol_plus(preorden, inorden, 0, inorden.size(), 0);

    vector<int>v = arbol.postorder();

    for (const int& k : v)
        cout << k<<" ";
    cout << endl;
    return true;
}

/*

bool resuelveCaso() {
    string entrada;
    getline(cin, entrada);
    if (!std::cin)  // fin de la entrada
        return false;

    vector<int>preorden;
    int pos_ini=0;
    int i = 0;
    while(i<entrada.size()) {
        if (entrada[i] != ' ') {
            pos_ini = i;
            i++;
            while (i < entrada.size() && entrada[i] != ' ') {
                i++;
            }
            preorden.push_back(stoi(entrada.substr(pos_ini, i)));
        }
        else {
            i++;
        }

    }

    arbol_plus<int>arbol = leerArbol_plus(preorden, 0, preorden.size());

    vector<int>v = arbol.postorder();
    for (int& k : v)
        cout << k << " ";
    cout << endl;
    return true;
}

*/