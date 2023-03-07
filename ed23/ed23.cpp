#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
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
    if (entrada==0)
        return false;
    int repartir;
    cin >> repartir;
    deque<pair<int,int>>cola;
    int valor;


    cin >> valor;
    
    cola.push_front({0,valor});
    for (int i = 1; i < repartir; i++) {
        cin >> valor;
        while (!cola.empty() && valor >= cola.back().second) {
            cola.pop_back();

        }
        cola.push_back({ i,valor });
    }
    cout << cola.front().second ;

    for (int i = repartir; i < entrada; i++) {
        cin >> valor;
        if (cola.front().first==i-repartir) {
            cola.pop_front();
        }

        while (!cola.empty() && valor >= cola.back().second) {
            cola.pop_back();

        }
        cola.push_back({ i,valor });
        cout <<" " << cola.front().second;
    }
    cout << endl;
    // escribir sol

    return true;
}
