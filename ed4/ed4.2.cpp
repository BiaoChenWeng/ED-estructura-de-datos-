
#include <iostream>
#include <fstream>
#include <vector>
#include "Class.2.h"
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
    Polinomio pol;
    cin >> pol;
    if (!std::cin)  // fin de la entrada
        return false;


    

    int vuelta, x;
    cin >> vuelta;

    for (int i = 0; i < vuelta; i++) {
        cin >> x;
        cout << pol.calcular(x) << " ";
    }
    cout << endl;
    return true;
}

