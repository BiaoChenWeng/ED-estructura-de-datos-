#include <iostream>
#include <fstream>
#include <algorithm>
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


struct tPair {
    int num;
    string nombre;

    tPair(int num,string nombre):num(num),nombre(nombre) {}
    bool operator<(const tPair& b)const {
        return this->num < b.num || (this->num == b.num&&this->nombre>b.nombre);
    }
};

bool resuelveCaso() {
    string entrada;
    cin >> entrada;
    if (!std::cin)  // fin de la entrada
        return false;
    unordered_map<string, int >deporte;// deporte y numero
    unordered_map<string, pair<bool,string> >alumno;// alumno y deporte
    
    string dep_actual;
   
    while (entrada != "_FIN_") {
        if (islower(entrada[0])) {// es un nombre
            auto it = alumno.insert({ entrada,{true,dep_actual} });
            if (!it.second) {
                if (dep_actual != it.first->second.second) {
                    if (it.first->second.first) {
                        it.first->second.first = false;
                        deporte[it.first->second.second]--;
                    }
                }
                
            }
            else
                deporte[dep_actual]++;
            
        }
        else {// es un deporte  
            deporte[entrada];
            dep_actual = entrada;
        }
        cin >> entrada;
    } 

    vector<tPair>lista;
    auto it = deporte.begin();
    while (it != deporte.end()) {
        lista.push_back(tPair(it->second,it->first));
        it++;
    }

    sort(lista.begin(),lista.end());

    for (int i = lista.size()-1; i >= 0; i--)      
        cout << lista[i].nombre << " " << lista[i].num<< endl;
    
    
    cout << "---\n";

    return true;
}

