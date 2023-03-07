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

		aux->sig = sig->sig;
		delete sig;
		
	}

public:

	void mostrar() {
		Nodo* aux = this->prim;

		while (aux != nullptr) {
			cout << aux->elem << " ";


			aux = aux->sig;
		}
		cout << endl;

	}
	
	void separar(linked_list_ed_plus& negativo) {
		Nodo* iteratorA = this->prim;
		Nodo* iteratorB = negativo.prim;
		
		if (iteratorA != nullptr) {			
			while (iteratorA->sig != nullptr ) {
				
				
				if (iteratorA->sig->elem > 0) {
					iteratorA = iteratorA->sig;
				}
				else if (iteratorA->sig->elem < 0) {
					if (iteratorB != nullptr) {
						iteratorB->sig = iteratorA->sig;
						iteratorB = iteratorB->sig;
						negativo.ult = iteratorB;
					}
					else {
						negativo.prim=negativo.ult = iteratorA->sig;
						iteratorB = iteratorA->sig;
						
					}
					iteratorA->sig = iteratorB->sig;
					iteratorB->sig = nullptr;
				}
				else {
					this->eleminarSig(iteratorA);
				}

				
			}
			Nodo* aux;
			if (this->prim->elem == 0) {
				aux = this->prim;
				this->prim = this->prim->sig;

				delete aux;
				
			}
			else if (this->prim->elem < 0) {
				aux = this->prim->sig;
				this->prim->sig = negativo.prim;
				negativo.prim = this->prim;
				this->prim = aux;
			}
		}



		





	}


};

#endif