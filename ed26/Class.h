#ifndef Class_h
#define Class_h
#include <iostream>
#include <string>
#include "list_eda.h"

using namespace std;
template <typename T>
class lista_plus :public list<T>{
	using Nodo = typename list<T>::Nodo;

protected:


    
    class RevIterador{
        Nodo* act;
        Nodo* fan;
    public:

        RevIterador():act(nullptr),fan(nullptr) {

        }
        T& operator*() const {
            if (act == fan) throw std::out_of_range("fuera de la lista");
            return act->elem;
        }
        RevIterador& operator++() { // ++ prefijo (recomendado)
            if (act == fan) throw std::out_of_range("fuera de la lista");
            act = act->ant;
            return *this;
        }
        bool operator!=(RevIterador const& that) const {
            return !(*this == that);
        }
        bool operator==(RevIterador const& that) const {
            return act == that.act && fan == that.fan;
        }
    private:
        // para que list pueda construir objetos del tipo iterador
        friend class lista_plus;

        RevIterador(Nodo* ac, Nodo* fa) : act(ac), fan(fa) {}
    };
public:
	
    using iterator = RevIterador;

    iterator advance(iterator &it) {
        it= ++it;
        return it;


    }

    T elem(iterator& it) {
        return *it;
    }

    iterator rend() {
        return iterator(this->fantasma, this->fantasma);
    }
    iterator rbegin() {
        return iterator(this->fantasma->ant, this->fantasma);
    }

};

#endif