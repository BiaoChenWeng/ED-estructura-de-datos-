#include <iostream>
#include <fstream>
#include <stack>
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

template <typename T>
// se puede quitar el ultimo arbol.root() ya que el enunciado te asegura de que los nodos son 0 ;
T sumarHojas(bintree<T>const & arbol,stack<T>&pila  ) {

    if (arbol.empty()) {
        return 0;
    }
    else {       
        pila.push(sumarHojas(arbol.right(),pila) + sumarHojas(arbol.left(),pila) + arbol.root());
        return pila.top();
    }



}




void resuelveCaso() {
    
    bintree<int>tree;
    tree = leerArbol(-1);
    
    stack <int>result;


    sumarHojas(tree, result);

    while (!result.empty()) {
        cout << result.top() << " ";
        result.pop();
    }
    cout << endl;
}
