
#include <iostream>
#include <fstream>
#include <vector>
#include<stack>




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



void solucion(vector<pair<string, int>>&v) {

    stack<int>pila;

    for (int i = 0; i < v.size(); i++) {
        while (!pila.empty() && v[i].second >= v[pila.top()].second) {
            pila.pop();
        }
        
        if (pila.empty() ) {  
            cout << "NO HAY" << endl;
        }
        else {
            cout << v[pila.top()].first << endl;
        }
        pila.push(i);

    }


    cout <<"---" << endl;
}


bool resuelveCaso() {
    int entrada;
    cin >> entrada;
    if (!std::cin)  // fin de la entrada
        return false;


    vector<pair<string,int>>fechas;
    int victima;
    string fecha;
    for (int i = 0; i < entrada;i++) {
        cin >> fecha;
        cin >> victima;
        fechas.push_back(make_pair(fecha, victima));

    }

    solucion(fechas);



    return true;
}

