#include <iostream>
#include <fstream>
#include"Class.h"
// Introduce más librerías si son necesarias
using namespace std;
void resuelveCaso();

using tPares= pair <int, int>;


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
int encontrar_en_nivel(T target,bintree <T>const &  arbol) {    
    int pos = -1;
    int nivel_act;
    int contador = 0;
    if (!arbol.empty()) {

        queue<pair<int,bintree<T>>> cola;
        cola.push({ 1,arbol });
        
        
        while (!cola.empty() && pos== -1) {
            
            nivel_act = cola.front().first;
            
            while (!cola.empty() &&cola.front().first ==nivel_act && pos==-1) {
                auto const& it = cola.front().second;
                if (it.root() == target) {
                    contador++;
                    if (contador == 2) {
                        
                        pos = nivel_act;
                    }
                }
                if (!it.left().empty() ) {
                    cola.push({nivel_act+1,it.left() });
                }
                if (!it.right().empty()) {
                    cola.push({nivel_act+1,it.right() });
                }
                cola.pop();
                
            }

            contador = 0;
        }


    }
    


    return pos;
}

void resuelveCaso() {
    char entrada;
    int pos;
    cin >> entrada;
    if (entrada == 'N') {
        int value;
        cin >> value;
        //bintree<int>arbol;
        arbol_plus<int> arbol;
        arbol = leerArbol_plus(-1);
        pos = arbol.encontrar_en_nivel(value);
    }
    else {
        char target;
        cin >> target;
        arbol_plus<char>arbol;
        arbol = leerArbol_plus('.');
        pos = arbol.encontrar_en_nivel(target);
    }

    if (pos == -1) {
        cout << "NO EXISTE\n";
    }
    else {
        cout << pos<<endl;
    }
    

}
