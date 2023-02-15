#ifndef Class_h
#define Class_h
#include <iostream>

#include "double_linked_list_ed.h"
using namespace std;
template <typename T>
class linked_list_ed_plus :public double_linked_list_ed<T> {
	using Nodo = typename double_linked_list_ed<T>::Nodo;

	void eliminarSig(Nodo* aux ) {
		Nodo* sig = aux->sig;
		aux->sig = sig->sig;
		sig->sig->ant = aux;
		delete sig;
	}
	
public:
	
	void mostrar() const{
		Nodo* auxiliar = this->fantasma->sig;

		while (auxiliar != this->fantasma) {
			cout << auxiliar->elem<<" ";
			auxiliar = auxiliar->sig;
		}
		cout << endl;
	}

	
	template <typename predicado>
	void eliminar(predicado pred) {
		Nodo* aux = this->fantasma->sig;
		if (aux != this->fantasma) {
			while (aux->sig != this->fantasma) {
				if (pred(aux->elem,aux->sig->elem)) {
					this->eliminarSig(aux);
				}
				else {
					aux = aux->sig;
				}
			}
		}

	}
};


class decreciente {
public:
	decreciente(){}

	template<typename T>
	bool operator()(T a, T b) {
		return a > b;
	}

};

template <typename T>
inline ostream& operator <<(ostream& out, linked_list_ed_plus<T> const& lista) {
	lista.mostrar();
	
	return out;
}
#endif