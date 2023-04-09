#ifndef Class_h
#define Class_h
#include <iostream>
#include <deque>
#include "queue_eda.h"

using namespace std;
template <typename T,typename pred>
class queue_plus:public queue<T>{
    using Nodo = typename queue<T>::Nodo;

    pred prioridad;
    Nodo* ultPrioritario;

public :
    queue_plus(pred predicado) :queue<T>() , prioridad(predicado),ultPrioritario(nullptr) {
        
    }

    
    void push(T const& elem) {
        Nodo* nuevo = new Nodo(elem);
        if (prioridad(elem)) {
            if (ultPrioritario != nullptr) {// si hay mas elemento prioritario
                nuevo->sig = ultPrioritario->sig;// engachamos el nuevo entre el primer no prioritario que puede ser nullptr
                ultPrioritario->sig = nuevo;// engachamos el penultimo prioritario con el nuevo prioritario
            }
            else {// ponemos al prioritario como primero de la lista si no hay prioritario
                nuevo->sig = this->prim;
                this->prim = nuevo;
            }
            if (this->ult == ultPrioritario)// en caso de que la lista solo tenga prioritario entonces el ultPrioritario tmb sería el ultimo de la lista
                this->ult = nuevo;
            ultPrioritario = nuevo;// recolocamos la posicion del ultimoprioritario
        }
        else {
            if (this->ult != nullptr)// si no es prioritario movemos el ult al nuevo elemento 
                this->ult->sig = nuevo;
            this->ult = nuevo;
        }
        
        if (this->prim == nullptr) // la cola estaba vacía
            this->prim = nuevo;
        this->nelems++;
    }

    // eliminar el primero de la cola
    void pop() {
        if (this->empty())
            throw std::domain_error("ERROR: Cola vacia");
        Nodo* a_borrar = this->prim;
        this->prim = this->prim->sig;
        if (this->prim == nullptr) // la cola se ha quedado vacía
            this->ult = nullptr;
        if (ultPrioritario == a_borrar)// si es el ultimo Prioritario es eliminado lo dejamos a nullptr
            ultPrioritario = nullptr;
        delete a_borrar;
        this->nelems--;
    }
    
};



#endif