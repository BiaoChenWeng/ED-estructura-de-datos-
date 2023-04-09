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
using tPair = pair<int, int>;
// 1º camino , 2º altura mas largo 
template<typename T, class pred>
tPair camino(bintree <T>arbol,const  pred&  p) {
    if (arbol.empty())
        return {0,0};
    else {
        tPair izq = camino(arbol.left(), p);
        tPair der = camino(arbol.right(), p);
        if (p(arbol.root())) {
            int cam_largo = max(izq.first, der.first);
            cam_largo = max(cam_largo, der.second + izq.second + 1);
            return { cam_largo,max(izq.second,der.second) + 1 };
        }
        else {
            
            return { max(izq.first,der.first),0 };
        }

        

    }


}

class divisible {
    int num;
public:

    divisible(int i) :num(i) {}
    divisible():num(0){}

    bool operator()(int val)const  {
        return val % num==0;
    }



};

void resuelveCaso() {
    
    bintree<int>arbol = leerArbol(-1);
    cout << camino(arbol, divisible(2)).first<<endl;
}
