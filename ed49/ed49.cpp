#include <iostream>
#include <fstream>
#include <map>
#include <string>
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

    int entrada;
    cin >> entrada;
    if (entrada == 0)
        return false;

    map<string , int > lista_alumno;
    string nombre;
    string resultado;
    for (int i = 0; i < entrada; i++) {
        getline(cin, nombre);
        getline(cin, nombre);
        cin >>resultado;// quitar el endl creado por el getline
        if (resultado == "CORRECTO")
            lista_alumno[nombre]++;
        else
            lista_alumno[nombre]--;
    }

    auto it = lista_alumno.begin();

    while (it != lista_alumno.end()) {
        if (it->second != 0)
            cout << it->first << ", " << it->second<<endl;
        it++;
    }

    cout << "---\n";

    // escribir sol

    return true;
}
