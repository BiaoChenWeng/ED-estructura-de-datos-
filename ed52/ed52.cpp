#include <iostream>
#include <fstream>
#include <map>
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

// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int num_series;

    cin >> num_series;
    int contador = 0;
    int max = 0;
    int cap;
    map<int, int>mapa;
    for (int i = 0; i < num_series; i++) {
        cin >> cap;
        auto it = mapa.insert({ cap,i });

        if (it.second) {
            contador++;
            if (contador > max)
                max = contador;
        }
        else {
            if (i - contador > it.first->second) {
                contador++;
                if (contador > max)
                    max = contador;

            }
            else {
                contador = i - it.first->second;
            }


            it.first->second = i;
        }

    }

    cout << max << endl;
}





