#ifndef Class_h
#define Class_h
#include <iostream>
#include <string>
#include "bintree_eda.h"

using namespace std;
template <typename T>
class arbol_plus :public bintree<T>{
    using Link = typename bintree<T>::Link;

    T menor(Link r) {
        if (r==nullptr) {
            throw invalid_argument("Error");
        }
        else if(r->left== nullptr&& r->right== nullptr) {
            return r->elem;
        }
        else if (r->left == nullptr) {
            return min(menor(r->right),r->elem);
        }
        else if (r->right == nullptr) {
            return min(menor(r->left), r->elem);
        }
        else {
            T izq = menor(r->left);
            T der = menor(r->right);
            T dev = min(izq, der);
            dev = min(dev, r->elem);
            return dev;
        }
    }


public :

    arbol_plus():bintree<T>() {}
    arbol_plus(arbol_plus<T> const& l, T const& e, arbol_plus<T> const& r) :
        bintree<T>(l, e, r) {}
    
    T menor() {
        return this->menor(this->raiz);
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