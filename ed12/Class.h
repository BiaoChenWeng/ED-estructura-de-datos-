#ifndef Class_h
#define Class_h
#include <iostream>
#include <math.h>
#include "double_linked_list_ed.h"
using namespace std;
template <typename T>
class linked_list_ed_plus :public double_linked_list_ed<T> {
	using Nodo = typename double_linked_list_ed<T>::Nodo;

	
public:
	
	void mostrar() const{
		Nodo* auxiliar = this->fantasma->sig;

		while (auxiliar != this->fantasma) {
			cout << auxiliar->elem<<" ";
			auxiliar = auxiliar->sig;
		}
		cout << endl;
	}
	void mostrarInv()const {
		Nodo* auxiliar = this->fantasma->ant;

		while (auxiliar != this->fantasma) {
			cout << auxiliar->elem << " ";
			auxiliar = auxiliar->ant;
		}
		cout << endl;
	}
	void intercambiar() {
		Nodo* aux = this->fantasma->sig;
		Nodo* aux2;
		
		while (aux!= this->fantasma &&aux->sig != this->fantasma) {
			aux2 = aux->sig;
			aux->ant->sig = aux2;
			aux2->sig->ant = aux;
			aux->sig = aux2->sig;
			aux2->ant = aux->ant;
			aux->ant = aux2;
			aux2->sig = aux;
			aux = aux->sig;

		
		}

	}


};


template <typename T>
inline ostream& operator <<(ostream& out, linked_list_ed_plus<T> const& lista) {
	lista.mostrar();
	
	return out;
}
#endif