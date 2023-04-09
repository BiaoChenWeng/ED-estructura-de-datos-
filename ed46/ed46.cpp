#include <iostream>
#include <fstream>

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


int altura() {
    int num_hijos;
    int alt = 0;
    cin >>num_hijos;
    if (num_hijos != 0){
      for (int i = 0; i < num_hijos; i++) {
          alt = max(altura(), alt);
      }  
    }
    return alt + 1;
}


void resuelveCaso() {
    cout << altura()<<endl;
}
