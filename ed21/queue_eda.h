//
//  queue_eda.h
//
//  Implementación del TAD cola con nodos enlazados
//  y punteros al primero y al último nodo
//
//  Estructuras de Datos
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2020 Alberto Verdejo
//

#ifndef queue_eda_h
#define queue_eda_h

#include <stdexcept>  // std::domain_error

template <class T>
class queue {
protected:

    /*
     Nodo que almacena internamente el elemento (de tipo T),
     y un puntero al nodo siguiente, que puede ser nullptr si
     el nodo es el último de la lista enlazada.
     */
   
    // punteros al primer y último elemento
    int prim;
    int ult;
    const static int TAM_INICIAL=10;
    T *lista;
    int tam;
    // número de elementos en la cola
    int nelems;

public:

    // constructor: cola vacía
    queue():nelems(0),tam(TAM_INICIAL),lista(new T[TAM_INICIAL]),prim(-1), ult(0) {
    }

    // destructor
    ~queue() {
        libera();
    }

    // constructor por copia
    queue(queue<T> const& other) {
        copia(other);
    }

    // operador de asignación
    queue<T>& operator=(queue<T> const& other) {
        if (this != &other) {
            libera();
            copia(other);
        }
        return *this;
    }

    // añadir un elemento al final de la cola
    void push(T const& elem) {
        if (nelems == 0)
            this->prim = this->ult =0;
        this->lista[ult] = elem;
        ult = (ult + 1) % this->tam;
        
        ++nelems;
        if (nelems == tam) {
            this->ampliar();
        }
    }

    // consultar el primero de la cola
    T const& front() const {
        if (empty())
            throw std::domain_error("la cola vacia no tiene primero");
        return this->lista[this->prim];
    }

    // eliminar el primero de la cola
    void pop() {
        if (empty())
            throw std::domain_error("eliminando de una cola vacia");
        
        prim= (prim+1)%tam;
        --nelems;
    }

    // consultar si la cola está vacía
    bool empty() const {
        return nelems == 0;
    }

    // consultar el tamaño de la cola
    int size() const {
        return nelems;
    }

protected:

    void ampliar() {
        this->tam *= 2;
        T* nuevo = new T[tam];
        
        for (int i = 0; i < nelems; i++) {
            nuevo[i] = this->lista[prim];
            prim = (prim + 1) % nelems;
        }          
        
        libera();
        this->lista = nuevo;
        this->prim = 0;
        this->ult = this->nelems;
    }

    void libera() {
        delete[] this->lista;
    }

    // this está sin inicializar
    void copia(queue const& other) {
        if (other.empty()) {
            this->prim = 0;
            this->ult = 1;
            nelems = 0;
        }
        else {
            this->prim = 0;
            this->ult = other.nelems;
            int recorrer= other.prim;
            T* nuevo= new T [other.nelems];

            for (int i = 0; i < other.nelems; i++) {
                nuevo[i] = other.lista[recorrer];
                recorrer = (recorrer + 1) % other.tam;
            }
            this->libera();
            
            this->lista = nuevo;
            nuevo = nullptr;

        }
    }
};

#endif // queue_eda_h#pragma once
