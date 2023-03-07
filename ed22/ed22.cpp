
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
// Introduce más librerías si son necesarias
using namespace std;

const char VOCALES[5] = { 'a','e','i','o','u'};


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


bool noVocal(char l) {
    for (int i = 0; i < 5; i++) {
        if (l == VOCALES[i] || l+32 == VOCALES[i] ) {
            return false;
        }
    }

    return true;
}

bool resuelveCaso() {
    string entrada;
    getline(cin, entrada);
    if (!std::cin)  // fin de la entrada
        return false;

    vector<char> v(entrada.size());
    int tam = entrada.size();
    int i = 0;
    int j = entrada.size()-1;
    if (entrada.size() % 2 == 1) {
        
        v[tam/ 2] = entrada.at(tam-1);
        tam--;
    }
    int k = 0;
    while ( k < tam) {
        v[i++] = entrada.at(k++);
        v[j--] = entrada.at(k++);
        
    }
    i = 0;
    queue<char>cola;
    stack <char>pila;
    while ( i < v.size()) {
        if (noVocal(v[i])) {
            pila.push(v[i]);
            i++;
        }
        else {
            
            while (!pila.empty()) {
                cola.push(pila.top());
                pila.pop();
            }
            
            cola.push(v[i]);
            i++;
        }

    }
    while (!pila.empty()) {
        cola.push(pila.top());
        pila.pop();
    }

    while (!cola.empty()) {
        cout << cola.front();
        cola.pop();
    }
    cout << endl;
    return true;
}

