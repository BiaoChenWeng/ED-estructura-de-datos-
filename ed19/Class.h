#ifndef Class_h
#define Class_h
#include <iostream>

#include "linked_list_ed.h"
using namespace std;
template <typename T>

class linked_list_ed_plus :public linked_list_ed<T> {
	using Nodo = typename linked_list_ed<T>::Nodo;

	void eleminarSig(Nodo * aux) {
		
		Nodo* sig= aux->sig;
		if (this->ult == sig) {
			this->ult = aux;
		}
		if (this->prim == sig) {
			this->prim = sig->sig;
		}
		aux->sig = sig->sig;
		delete sig;
		
	}

public:


	T elegir(int salto) {
		
		if (this->prim == nullptr) {
			return 1;
		}
		if (salto == 0)
			return this->ult->elem;

		this->ult->sig = this->prim;
		Nodo* aux = this->ult;

		while (this->ult != this->prim) {
			for (int i = 0; i < salto ; i++){
				aux = aux->sig;
			}
			eleminarSig(aux);
			
		}

		this->ult->sig = nullptr;

		return this->prim->elem;
	}



};

#endif