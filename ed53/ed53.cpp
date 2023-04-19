
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
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
    if (!std::cin)  // fin de la entrada
        return false;
    unordered_map<int, vector<int> >mapa;
    int pregunta;
    cin >> pregunta;
    int val;
    for (int i = 0; i < entrada; i++) {
        cin >> val;
        mapa[val].push_back(i+1);
    }
    int k; 
    int num;

    for (int i = 0; i < pregunta; i++) {
        cin >> k >> num;
        if (mapa[num].size()>=k) {
            cout << mapa[num][k-1]<<endl;
        }
        else {
            cout << "NO HAY\n";
        }
    }


    cout << "---\n";
    return true;
}

