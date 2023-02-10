#ifndef Class_h
#define Class_h
#include <iostream>
#include "linked_list_ed.h"
using namespace std;
template <typename T>
class linked_list_ed_plus :public linked_list_ed<T> {
	using Nodo = typename linked_list_ed<T>::Nodo;


	void elminarSig(Nodo* nodo) {
		if (nodo->sig!= nullptr) {
			Nodo* sig = nodo->sig;
			nodo->sig = sig->sig;
			delete sig;
		}
		else {
			
		}
	}

public :
	void mostrar(ostream & out = std::cout )const  {
		Nodo* aux = this->prim;
		while (aux != nullptr) {
			out << aux->elem << " ";
			aux = aux->sig;
		}
		out << endl;
	}

	void delete_dobles() {
		char letra;
		if (this->prim != this->ult) {
			Nodo* aux = this->prim;
			letra = aux->elem;
			this->ult = this->prim;

			while (aux->sig != nullptr) {			
				if (letra != aux->sig->elem) {
					letra= aux->sig->elem;
					aux = aux->sig;
					this->ult = aux;
				}
				else {
					this->elminarSig(aux);
				}
			}


		}
		cout << this->ult->elem;
	}



};
template <typename T>
inline ostream& operator <<(ostream& out, linked_list_ed_plus <T> const& lista) {
	lista.mostrar();
	return out;
}
#endif