#include <iostream>
#include <fstream>
#include<string>
#include <unordered_map>
#include<algorithm>
#include <vector>
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


struct tDato {
    unordered_map<string,pair<bool,int>>problemas;
    int tiempo;
    int correcto;
    tDato() :tiempo(0), correcto(0) {};
    bool operator<(tDato a)const  {
        if (this->correcto < a.correcto) 
            return true;
        else if (this->correcto == a.correcto) {
            if (this->tiempo > a.tiempo)
                return true;
        }
        return false;
    }
    bool operator==(tDato a)const {
        return this->tiempo == a.tiempo && this->correcto == a.correcto;
    }
};

struct tPair {
    string nombre;
    tDato dato;

    tPair(string nombre,tDato data) :nombre(nombre),dato(data) {};
    bool operator<(tPair a) {
        return this->dato < a.dato || (this->dato == a.dato&& this->nombre>a.nombre);
    }
};


// configuración, y escribiendo la respuesta
void resuelveCaso() {
    string entrada;
    unordered_map<string, tDato> ranking;// nombre del problema y minuto tardado
    cin >> entrada;
    string grupo;
    int tiempo;
    string calificacion;
    string problema;
    while (entrada != "FIN") {
           
        grupo = entrada;
        cin >> problema;
        cin >> tiempo;
        cin >> calificacion;
        tDato* equip = &ranking[grupo];
        if (calificacion == "AC") {
            auto it = equip->problemas.insert({ problema, {true,0 } });
            if (!it.second) {
                if (!it.first->second.first) {
                    it.first->second.first = true;
                    equip->tiempo += tiempo + (20 * it.first->second.second);
                    equip->correcto++;
                }
            }
            else {
                equip->tiempo += tiempo;
                equip->correcto++;
            }


        }
        else {
            auto it = equip->problemas.insert({ problema, {false,1 } });
            if (!it.second) {
                if (!it.first->second.first)
                    it.first->second.second++;
            }
        }
        cin >> entrada;
    }

    vector<tPair > orden;
    auto it = ranking.begin();
    while (it != ranking.end()) {
        orden.push_back(tPair(it->first, it->second));
        it++;
    }
    sort(orden.begin(),orden.end());

    for(int i = orden.size() - 1; i >= 0; i--)
        cout << orden[i].nombre << " " << orden[i].dato.correcto << " " << orden[i].dato.tiempo << endl;
    cout <<"---" << endl;
}
