#include <iostream>
#include <fstream>
#include "Class.h"
#include <list>
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

template <class T,class Predicate>
void remove_if(list<T>& lista, Predicate pred) {
    auto p1 = lista.begin();
    
    while (p1 != lista.end()) {
        if (!pred(*p1)) {
            p1=lista.erase(p1);
        }
        else {
            p1++;
        }

        
    }

}


bool resuelveCaso() {

    int entrada;
    cin >> entrada;
    if (entrada==0)
        return false;

    int max, min;
    cin >> min >> max;
    list <Persona> lista;


    Persona a;
    for (int i = 0; i < entrada; i++) {
        cin >> a;
        lista.push_back(a);
    }

    
    remove_if(lista, predicado<int>(max,min));
    auto it= lista.begin();
    while (it != lista.end()) {
        cout << *it << endl;
        it++;
    }
    
    cout << "---" << endl;

    return true;
}
