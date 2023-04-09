#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <deque>
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

    map<string , deque<int>> repeticion;
    string texto;
    string palabra;
    
    getline(cin,texto);
    for (int i = 0; i < entrada; i++) {
        getline(cin, texto);
        stringstream ss(texto);
        while (ss) {
            ss >> palabra;
            if (palabra.length() > 2) {
                for (char& x : palabra) {
                    if (x - 'A' < 26) {
                        x = x + 32;
                    }
                }

                if (repeticion[palabra].empty()|| repeticion[palabra].back()!= i+1) {
                    repeticion[palabra].push_back(i+1);
                }
            }
            

        }

    }

    auto it = repeticion.begin();
    while (it != repeticion.end()) {
        cout << it->first ;
        while (!it->second.empty()) {
            cout << " " << it->second.front();
            it->second.pop_front();
        }
        it++;
        cout << endl;
    }
        
    cout << "---\n";
    return true;
}
