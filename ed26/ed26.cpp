#include <iostream>
#include <fstream>
#include "Class.h"
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

// configuración, y escribiendo la respuesta


void resuelveCaso() {

    int entrada;
    cin >> entrada;
    
    lista_plus<int> a;

    while (entrada != 0) {
        a.push_back(entrada);
        cin >> entrada;
    }
    
    auto it = a.rbegin();


    while (it != a.rend()) {
        cout <<a.elem(it)<<" ";
        it = a.advance(it);
    }
    cout << endl;

}
