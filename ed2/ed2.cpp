#include <iostream>
#include <fstream>
#include <vector>
#include "Class.h"
#include <algorithm>
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

int busqueda(vector<Hora>&v,Hora buscar,int ini,int fin) {
    if (ini == fin)
        return -1;
    if (ini + 1 == fin) {
        if (v[ini] >= buscar) {
            return ini;
        }
        else {
            return -1;
        }
    }

    else {
        int m = (ini + fin-1) / 2;
        if (v[m] < buscar) {
            return busqueda(v, buscar, m+1, fin);
        }
        else {
            return busqueda(v, buscar, ini, m + 1);
        }
    }
}



bool resuelveCaso() {

    int entrada;
    cin >> entrada;
    
    if (entrada==0 )
        return false;
    vector<Pelicula>v(entrada);
    
    
    Hora hora_ini;
    Hora duracion;
    string nombre;
    for (int i = 0; i < entrada; i++) {
        try {
            
            cin >> v[i];
            
            
        }
        catch (invalid_argument &invalido) {
            cout << invalido.what()<<endl;
        }
        
    }
    sort(v.begin(), v.end());
    
    for (const Pelicula& k : v)
        cout << k<<endl;
    cout << "---\n";
    
    // escribir sol

    return true;
}
