#include <iostream>
#include <fstream>
#include "bintree_eda.h"
// Introduce más librerías si son necesarias
using namespace std;
void resuelveCaso();




int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("datos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    std::ofstream out("datos.out");
    auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    system("PAUSE");
#endif
    return 0;
}

struct tEnano {
    string lider;
    int num;
    tEnano(string nombre,int num):lider(nombre),num(num) {};
    bool operator<(const tEnano &a) const {
        return this->num < a.num || (this->num == a.num && this->lider > a.lider);
    }
    bool operator == (const tEnano& a)const {
        return this->num == a.num && this->lider == a.lider;
    }
    bool operator<=(const tEnano& a) {
        return *this < a || *this == a;
    }
    bool operator>(const tEnano& a) {
        return !(*this<=a);
    }
    bool operator>=(const tEnano& a) {
        return !(*this < a);
    }
    bool operator!=(const tEnano& a) {
        return !(*this == a);
    }
};

tEnano enanos(const bintree<string>&arbol) {

    if (arbol.empty()) {
        return tEnano("", 0);
    }
    else {
        tEnano izq = enanos(arbol.left());
        tEnano der = enanos(arbol.right());
        tEnano result = tEnano(max(izq, der).lider, izq.num + der.num);


        if (arbol.root() == "Orcos") {
            result.num /= 2;
        }
        else if (arbol.root() != "-") {
            tEnano nuevo = tEnano(arbol.root(), 1);
            result = tEnano(max(result, nuevo).lider, nuevo.num + result.num);
        }
        return result;
    }


}


// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<string>arbol = leerArbol<string>(".");
    tEnano result =enanos(arbol);
    if (result.num == 0) {
        cout << "Ninguno\n";
    }
    else {
        cout << result.lider << " " << result.num << endl;
    }

}
