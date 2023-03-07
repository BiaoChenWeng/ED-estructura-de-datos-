#ifndef Class_h
#define Class_h
#include <iostream>
#include <string>
#include "bintree_eda.h"

using namespace std;
template <typename T>
class arbol_plus :public bintree<T>{
    using Link = typename bintree<T>::Link;

    int alturaArbol(Link r) {
        if (r == nullptr)
            return 0;
        else {
            return max(alturaArbol(r->left) , alturaArbol(r->right))+1;
        }

    }

    int num_hoja(Link r) {
        if (r == nullptr)
            return 0;
        else {
            int hoja_der = num_hoja(r->right);
            int hoja_izq = num_hoja(r->left);
            return (hoja_der == 0 && hoja_der == hoja_izq) ? (1) : (hoja_der + hoja_izq);
        }
    }

    int num_nodos(Link r) {
        if (r == nullptr)
            return 0;
        else {
            return num_nodos(r->right) + num_nodos(r->left)+1;
        }
    }
public :

    arbol_plus():bintree<T>() {}
    arbol_plus(arbol_plus<T> const& l, T const& e, arbol_plus<T> const& r) :
        bintree<T>(l, e, r) {}
    
    int alturaArbol() {
        return alturaArbol(this->raiz);
    }

    int numHoja() {
        return num_hoja(this->raiz);
    }

    int numNudos() {
        return num_nodos(this->raiz);
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