#ifndef Class_h
#define Class_h
#include <iostream>

#include "bintree_eda.h"
#include<queue>
using namespace std;
template <typename T>
class arbol_plus :public bintree<T> {
    using Link = typename bintree<T>::Link;



public:

    arbol_plus() :bintree<T>() {}
    arbol_plus(arbol_plus<T> const& l, T const& e, arbol_plus<T> const& r) :
        bintree<T>(l, e, r) {}

    vector <T>perfilDerecho() {
        vector<T>v;
        if (this->raiz != nullptr) {
            queue <pair<Link, int>>cola;
            cola.push({ this->raiz ,0});
            Link it;
            int nivel=0;
            while (!cola.empty()) {
                it = cola.front().first;
                nivel = cola.front().second;
                
                v.push_back(it->elem);
                
                while (!cola.empty() && cola.front().second == nivel) {
                    it = cola.front().first;
                    cola.pop();
                    if (it->right != nullptr) {
                        cola.push({ it->right ,nivel+1});
                    }
                    if (it->left != nullptr) {
                        cola.push({ it->left ,nivel+1});
                    }
                    

                }   


            }
            return v;
        }



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