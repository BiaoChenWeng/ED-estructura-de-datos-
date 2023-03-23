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
    if (entrada==0)
        return false;
   
    int val;
    user_set<int>set;
    for (int i = 0; i < entrada; i++) {
        cin >> val;
        set.insert(val);
    }
    cin >> entrada;
    for (int i = 0; i < entrada; i++) {
        cin >> val;
        auto result = set.lower_bound(val);
        if (result.first) {
            cout << result.second << endl;
        }
        else {
            cout << "NO HAY\n";
        }

    }
    cout << "---\n";


    return true;
}
