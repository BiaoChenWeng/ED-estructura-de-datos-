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
 

};

template <typename T>
int busquedaBinaria(const vector<T> &v,T target, int ini,int fin) {
    if (ini == fin)
        return fin;
    else if (ini + 1 == fin)
        return ini;

    else {
        int m = (ini + fin-1) / 2;
        if (v[m] < target) {
            return busquedaBinaria(v,target,m+1,fin);
        }
        else {
            return busquedaBinaria(v,target,ini,m+1);
        }


    }

}


template <typename T>
inline arbol_plus<T> leerArbol_plus(const vector<T>&v,int ini,int fin) {

    if (ini>= fin) {
        return {};
    }
    else {
        
        T raiz;
        raiz = v[ini];
        int i ;
        i = busquedaBinaria(v, raiz, ini+1, fin);



        auto izq = leerArbol_plus(v, ini + 1, i);
        auto der = leerArbol_plus(v, i, fin);


        return { izq,raiz,der };
    }
}

template <typename T>
inline arbol_plus<T> leerArbol_plus(const vector<T>& preorden, const vector<T>& inorden, int ini, int fin,int pre_pos) {

    if (ini == fin) {
        return {};
    }
    else {

        T raiz;
        raiz = preorden[pre_pos];
        int i = ini;
        while (i < fin&&inorden[i]!= preorden[pre_pos]) {
            i++;
        }


        auto izq = leerArbol_plus(preorden,inorden,ini,i,pre_pos+1);
        auto der = leerArbol_plus(preorden, inorden,i+1,fin, pre_pos +i-ini+1);


        return { izq,raiz,der };
    }
}

#endif