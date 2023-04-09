#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include<sstream>
#include <queue>
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
    string entrada;
    int numCasos;
    getline(cin, entrada);
    stringstream ss(entrada);

    ss>> numCasos;
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



void initDic(map<string, int>&map) {
    string info;
    getline(cin, info);
    stringstream ss(info);
    string key;
    int value;
    if(info!= "")
        while (ss) {
            ss >> key;
            ss >> value;
            map[key] = value;
        }

}
template<typename T>
void print(char sign , queue<T>&cola) {
    if (!cola.empty()) {
        cout << sign;
        while (!cola.empty()) {
            cout << " " << cola.front();
            cola.pop();
        }
        cout << endl;
    }


}


// configuración, y escribiendo la respuesta
void resuelveCaso() {
    map <string, int >dic1,dic2;
    initDic(dic1);
    initDic(dic2);
    
    auto it1 = dic1.begin();
    auto it2 = dic2.begin();

    queue<string>add;
    queue<string>minus;
    queue<string>change;


    while (it1 != dic1.end() && it2 != dic2.end()) {
        if (it1->first == it2->first) {
            if (it1->second != it2->second)
                change.push(it1->first);
            it1++;
            it2++;
        }
        else if (it1->first > it2->first) {
            add.push(it2->first);
            it2++;
        }
        else {
            minus.push(it1->first);
            it1++;
        }


    }

    while (it1 != dic1.end()) {
        minus.push(it1->first);
        it1++;
    }
    while (it2 != dic2.end()) {
        add.push(it2->first);
        it2++;
    }


    if (add.empty() && minus.empty() && change.empty())
        cout << "Sin cambios\n";
    else {
        print('+',add);
        print('-', minus);
        print('*', change);
    }
    cout << "---\n";
}
