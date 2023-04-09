﻿#include <iostream>
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

template<typename T>
void comando(stack_plus<T>&pila,int vuelta) {
    char command;
    T val;
    for (int i = 0; i < vuelta; i++) {
        cin >> command;
        try {
            
        
            if (command == 'A') {
                cin >> val;
                pila.push(val);
            }
            else if (command == 'D') 
                pila.pop();
            
            
            else if (command == 'C')
                cout << pila.top() << endl;
            else
                cout << pila.minimo() << endl;
        }
        catch (domain_error) {
            cout << "ERROR: Pila vacia" << endl;
        }
    }
    
    

}


bool resuelveCaso() {

    int entrada;
    cin >> entrada;
    if (entrada==0)
        return false;
    char type;
    cin >> type;
    if (type == 'I') {
        stack_plus<int>pila;
        comando(pila, entrada);
    }
    else {
        stack_plus<char>pila;
        comando(pila, entrada);
    }
    cout << "---\n";
    return true;
}
