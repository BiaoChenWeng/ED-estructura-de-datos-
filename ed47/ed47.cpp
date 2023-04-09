
#include <iostream>
#include <fstream>

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



int becario(int min,int nivel) {
    int num_sub;
    int alt = 0;
    cin >> num_sub;
    if (num_sub == 0) {
        alt = (min <=nivel) ? (1) : (0);
    }
    else {
        for (int i = 0; i < num_sub; i++) {
            alt += becario(min, nivel + 1);
        }
    }
    return alt;
}


bool resuelveCaso() {
    int entrada;
    cin >> entrada;
    if (!std::cin)  // fin de la entrada
        return false;

    cout << becario(entrada,0)<<endl;



    return true;
}

