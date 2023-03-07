
#include <iostream>
#include <fstream>
#include<string>
#include<stack>
// Introduce más librerías si son necesarias
using namespace std;

const int TAM_ARRAY = 6;
const char SIMBOLO [TAM_ARRAY] = {'(','[','{',')',']','}' };

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


int caracterEspecial(char entrada) {
    for (int i = 0; i < TAM_ARRAY;i++) {
        if (entrada == SIMBOLO[i])
            return i;
    }
    return -1;
}



bool resuelveCaso() {
    string entrada;
    getline(cin ,entrada);
    if (!std::cin)  // fin de la entrada
        return false;

    stack<char>pila;

    int i = 0;
    int pos;
    bool correcto = true;
    while (correcto && i<entrada.size()) {
        pos = caracterEspecial(entrada.at(i));
        if (pos != -1) {
            if ( pos<TAM_ARRAY/2) {
                //abre
                pila.push(entrada.at(i));

            }
            else {
                //cierra
                if (!pila.empty()) {
                    correcto = pila.top() == SIMBOLO[pos % 3];
                    if (correcto)
                        pila.pop();
                }
                else
                    correcto = false;
                
            }
        }
        i++;
    }
    if (correcto)
        correcto = pila.empty();

    if (correcto) {
        cout << "SI\n";
    }
    else {
        cout <<"NO\n";
    }


    return true;
}

