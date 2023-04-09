#include <iostream> 
#include <fstream> 
#include "Class.h"



// Prioridad de los valores enteros
class mult {
private:
    int n;
public:
    mult(int k) : n(k) {}
    bool operator() (int x) {
        return x % n == 0;
    }
};

// Prioridad de los caracteres
class vocal {
public:
    bool operator() (char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

bool resuelveCaso() {
    int ops; std::cin >> ops;
    if (ops == 0) return false;
    char tipo; std::cin >> tipo;
    // Cola de enteros
    if (tipo == 'I') {
        mult prioridad(2);
        queue_plus<int, mult> q(prioridad);
        for (int i = 0; i < ops; ++i) {
            try {
                char x; int n;
                std::cin >> x;
                if (x == 'E') { std::cin >> n; q.push(n); }
                else if (x == 'D') q.pop();
                else if (x == 'P') std::cout << q.front() << '\n';
            }
            catch (std::domain_error& e) {
                std::cout << "ERROR: Cola vacia" << '\n';
            }
        }
    }
    else { // Cola de caracteres
        vocal v;
        queue_plus<char, vocal> q(v);
        for (int i = 0; i < ops; ++i) {
            try {
                char x; char n;
                std::cin >> x;
                if (x == 'E') { std::cin >> n; q.push(n); }
                else if (x == 'D') q.pop();
                else if (x == 'P') std::cout << q.front() << '\n';
            }
            catch (std::domain_error& e) {
                std::cout << "ERROR: Cola vacia" << '\n';
            }
        }
    }
    std::cout << "---\n";
    return true;
}


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