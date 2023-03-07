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
template<typename T>
void eliminarHorario(list<T>&lista) {
    auto p1 = lista.begin();

    while (p1 != lista.end()) {
        p1++;
        if(p1!= lista.end())
            p1= lista.erase(p1);
    }


}


bool resuelveCaso() {

    int entrada;
    cin >> entrada;
    if (entrada==0)
        return false;

    list<Hora>horario;
    Hora val;
    for (int i = 0; i < entrada; i++) {
        cin >> val;
        horario.push_back(val);
    }


    eliminarHorario(horario);
    for (Hora h : horario)
        cout << h<<" ";

    cout << endl;
    return true;
}
