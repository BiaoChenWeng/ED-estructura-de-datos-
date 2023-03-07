//
//  queue_eda.h
//
//  Implementaci�n del TAD cola con nodos enlazados
//  y punteros al primero y al �ltimo nodo
//
//  Estructuras de Datos
//  Facultad de Inform�tica
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2020 Alberto Verdejo
//

#ifndef queue_eda_h
#define queue_eda_h

#include <stdexcept>  // std::domain_error
#include <stack>
#include <iostream>

using namespace std;
template <class T>
class queue {
protected:

    /*
     Nodo que almacena internamente el elemento (de tipo T),
     y un puntero al nodo siguiente, que puede ser nullptr si
     el nodo es el �ltimo de la lista enlazada.
     */
   
    // punteros al primer y �ltimo elemento
    stack<T>pila1;
    stack<T>pila2;
    
    int nelems;
public:

    // constructor: cola vac�a
    queue():nelems(0) {
    }

    // destructor
    ~queue() {
        libera();
    }

    // constructor por copia
    queue(queue<T> const& other) {
        copia(other);
    }

    // operador de asignaci�n
    queue<T>& operator=(queue<T> const& other) {
        if (this != &other) {
            libera();
            copia(other);
        }
        return *this;
    }

    // a�adir un elemento al final de la cola
    void push(T const& elem) {
        pila1.push(elem);
        nelems++;

    }

    // consultar el primero de la cola
    T const& front() {
        if (pila1.empty() &&pila2.empty())
            throw std::domain_error("la cola vacia no tiene primero");
        
        if (pila2.empty()) {
            while (!pila1.empty()) {
                
                pila2.push(pila1.top());

                pila1.pop();
            }
        }
        
        
        return pila2.top();
    }

    // eliminar el primero de la cola
    void pop() {
        if (pila1.empty() && pila2.empty())
            throw std::domain_error("eliminando de una cola vacia");
        
        if (pila2.empty()) {
            while (!pila1.empty()) {
                pila2.push(pila1.top());
                
                pila1.pop();
            }
        }
        nelems--;
        pila2.pop();
        
    }

    // consultar si la cola est� vac�a
    bool empty() const {
        return pila1.empty() && pila2.empty();
    }

    // consultar el tama�o de la cola
    int size() const {
        return nelems;
    }

protected:

    

    void libera() {
        while (!pila1.empty()) {
            pila1.pop();
        }
        while (!pila2.empty()) {
            pila2.pop();
        }
        nelems = 0;
    }

    // this est� sin inicializar
    void copia(queue const& other) {
        libera();
        if (!other.empty()) {
            // falta por hacer
        }
        
    }
};

#endif // queue_eda_h#pragma once
