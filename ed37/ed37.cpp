#include <iostream>
#include <fstream>
#include <queue>
#include "bintree_eda.h"
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

bool Primo(int num) {
    int i = 2;
    if (num == 0 || num == 1)
        return true;
    bool primo = true;
    while (i < num && primo) {
        primo = num % i != 0;
        i++;
    }
        

    return primo;
}

// first nivel second el valor de la raiz
pair<int, int> encontrar_valor(bintree <int>const &  arbol) {
    pair<int, int>result={-1,0};
    int val;
    if (!arbol.empty()) {
        queue <pair<int, bintree<int>>>cola;
        cola.push({1,arbol});
        while (!cola.empty() && result.first==-1) {
            auto const it = cola.front().second;
            if (!Primo(it.root())) {
                if (it.root() % 7 == 0) 
                    result = { cola.front().first ,it.root() };
                
                else {
                    if (!it.left().empty())                         
                        cola.push({ cola.front().first + 1, it.left() });

                    if (!it.right().empty()) 
                        cola.push({ cola.front().first + 1, it.right() });                        
                }
                
            }
            cola.pop();

        }

    }

    return result;
}

void resuelveCaso() {
    
    bintree<int>tree;
    tree = leerArbol(-1);
    

    pair<int, int> result = encontrar_valor(tree);
    
    if (result.first == -1) {
        cout << "NO HAY\n";
    }
    else {
        cout << result.second << " " << result.first << endl;
    }

}
