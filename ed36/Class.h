#ifndef Class_h
#define Class_h
#include <iostream>

#include "bintree_eda.h"
#include<queue>
using namespace std;
template <typename T>
class arbol_plus :public bintree<T>{
    using Link = typename bintree<T>::Link;

    




public :

    arbol_plus():bintree<T>() {}
    arbol_plus(arbol_plus<T> const& l, T const& e, arbol_plus<T> const& r) :
        bintree<T>(l, e, r) {}
    
    int encontrar_en_nivel(T target) {
        int pos = -1;
        int nivel_act;
        int contador = 0;
        if (!this->empty()) {

            queue<pair<int, Link>> cola;
            cola.push({ 1,this->raiz});


            while (!cola.empty() && pos == -1) {

                nivel_act = cola.front().first;

                while (!cola.empty() && cola.front().first == nivel_act && pos == -1) {
                    auto const& it = cola.front().second;
                    if (it->elem == target) {
                        contador++;
                        if (contador == 2) {

                            pos = nivel_act;
                        }
                    }
                    if (it->left!= nullptr) {
                        cola.push({ nivel_act + 1,it->left});
                    }
                    if (it->right!= nullptr) {
                        cola.push({ nivel_act + 1,it->right });
                    }
                    cola.pop();

                }

                contador = 0;
            }


        }



        return pos;
    }

};

template <typename T>
inline arbol_plus<T> leerArbol_plus(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) { // es un árbol vacío
        return {};
    }
    else { // leer recursivamente los hijos
        auto iz = leerArbol_plus(vacio);
        auto dr = leerArbol_plus(vacio);
        return { iz, raiz, dr };
    }
}

#endif