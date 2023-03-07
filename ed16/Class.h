#ifndef Class_h
#define Class_h
#include <iostream>
#include "linked_list_ed.h"
using namespace std;
template <typename T>
class linked_list_ed_plus :public linked_list_ed<T> {
	using Nodo = typename linked_list_ed<T>::Nodo;


	void eliminarSig(Nodo* aux) {
		Nodo* sig = aux->sig;
		aux->sig = sig->sig;
		if (sig == this->prim) {
			this->prim = sig->sig;
		}
		delete sig;
	}

public:
	void mostrar(ostream& out = std::cout)const {
		Nodo* aux = this->prim;
		while (aux != nullptr) {
			out << aux->elem << " ";
			aux = aux->sig;
		}
		out << endl;
	}
	template <typename predicado>
	void suma(const linked_list_ed_plus &a,predicado pred) {

		

		Nodo* aux1, * aux2;
		aux1 = this->prim;
		aux2 = a.prim;

		T resultado;
		if (aux1 != nullptr) {
			resultado = aux1->elem + aux2->elem;
			if (pred(resultado)) {
				aux1->elem = resultado;
			}
			else {
				this->prim = aux1->sig;
			}
			while (aux1->sig != nullptr) {
				resultado = aux1->sig->elem + aux2->sig->elem;
				if (pred(resultado)) {
					aux1->sig->elem = resultado;
					aux1 = aux1->sig;
					
				}
				else {
					eliminarSig(aux1);
				}
				aux2 = aux2->sig;
				
			}

		}
		

		
	}



};

class diferente_cero {

public:
	diferente_cero(){}
	bool operator ()(int valor) {
		return valor != 0;
	}

};
	

template <typename T>
inline ostream& operator <<(ostream& out, linked_list_ed_plus <T> const& lista) {
	lista.mostrar();
	return out;
}
#endif