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
	
	void duplicar() {
		Nodo *auxiliar=this->fantasma->sig;
		Nodo* almacen;
		while (auxiliar != this->fantasma) {
			almacen = auxiliar->sig;
			auxiliar->sig = new Nodo(auxiliar->elem, auxiliar, auxiliar->sig);
			almacen->ant = auxiliar->sig;
			auxiliar->sig->ant = auxiliar;
			auxiliar = almacen;
		}



	}

};


template <typename T>
inline ostream& operator <<(ostream& out, linked_list_ed_plus<T> const& lista) {
	lista.mostrar();
	lista.mostrarInv();
	return out;
}
#endif