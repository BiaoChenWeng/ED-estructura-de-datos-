#include <iostream>
#include <fstream>
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

template <class T>
T Mysearch(T const& ini1, T const& fin1, T const& ini2, T const& fin2) {
    auto it = ini1;
    auto it2 = ini2;
    
    while (it != fin1 && it2!= fin2) {
        if (*it== *ini2) {
            auto almacen = it;
            it2 = ini2;
            while (almacen!= fin1 &&it2 != fin2 && *almacen == *it2) {
                almacen++;
                it2++;
            }
            if (it2 != fin2) {
                it++;
            }
            
        }
        else {
            it++;
        }
    }

    
    return it;
}



bool resuelveCaso() {

    int entrada;
    cin >> entrada;
    if (entrada==0)
        return false;
    int tam2;
    cin >> tam2;
    list<int>a, b;
    int valor;
    for (int i = 0; i < entrada; i++) {
        cin >> valor;
        a.push_back(valor);
    }

    // escribir sol

    for (int i = 0; i < tam2; i++) {
        cin >> valor;
        b.push_back(valor);
    }

    auto p1 = a.begin();
    
    while (p1 != a.end()) {
        p1=Mysearch(p1, a.end(), b.begin(), b.end());
        
        if (p1 != a.end()) {
            for (int i = 0; i < tam2; i++) {
                p1=a.erase(p1);
            }
        }
    }

    p1 = a.begin();
    while (p1 != a.end()) {
        cout << *p1 << " ";
        p1++;
    }
    cout << endl;

    return true;
}
