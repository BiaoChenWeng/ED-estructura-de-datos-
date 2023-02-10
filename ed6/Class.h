#ifndef Class_h
#define Class_h
#include <iostream>
#include <math.h>
#include <vector>
#include "linked_list_ed.h"
using namespace std;
template <typename T>
class linked_list_ed_plus :public linked_list_ed<T> {
	using Nodo = typename linked_list_ed<T>::Nodo;


public:

	void mostrar(std::ostream& out = std::cout) const {
		Nodo* aux = this->prim;
		while (aux != nullptr) {

			out << aux->elem << " ";
			aux = aux->sig;
		}

		out << endl;

	}
	void duplicar() {
		Nodo* recorrer = this->prim;
		Nodo* aux=this->prim;


		while (recorrer != nullptr) {
			aux = recorrer;
			recorrer = recorrer->sig;
			aux->sig = new Nodo(aux->elem, recorrer);
		}
		if (aux!= nullptr && aux->sig != nullptr) {
			this->ult = aux->sig;

		}
		

	}
};




#endif