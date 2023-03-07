#include <iostream>
#include <fstream>
#include <string>
#include "queue_eda.h"
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
    std::string str;
    getline(std::cin, str);
    if (str == ".") return false;
    // lee los datos de entrada en la cola
    queue<char> cola;
    for (int i = 0; i < str.length(); ++i) {
        cola.push(str[i]);
    }
    // Rota los datos de la cola
    for (int i = 0; i < cola.size(); ++i) {
        cola.push(cola.front());
        cola.pop();
    }
    // Duplica los elementos de la cola
    int numElem = (int)cola.size();
    for (int i = 0; i < numElem; ++i) {
        cola.push(cola.front());
        cola.push(cola.front());
        cola.pop();
    }
    // Muestra los elementos de la cola y la deshace
    numElem = (int)cola.size();
    for (int i = 0; i < numElem; i += 2) {
        std::cout << cola.front();
        cola.pop(); cola.pop();
    }
    if (!cola.empty()) std::cout << "ERROR\n";
    std::cout << '\n';
    return true;
}
