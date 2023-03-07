#ifndef Class_h
#define Class_h
#include <iostream>

#include "double_linked_list_ed.h"
using namespace std;
template <typename T>
class linked_list_ed_plus :public double_linked_list_ed<T> {
	using Nodo = typename double_linked_list_ed<T>::Nodo;

	
	
	void enlazar(Nodo* pivote, Nodo * poner_delante) {
		poner_delante->ant->sig = poner_delante->sig;
		poner_delante->sig->ant = poner_delante->ant;
		poner_delante->ant = pivote->ant;
		poner_delante->sig = pivote;
		poner_delante->sig->ant = poner_delante;
		poner_delante->ant->sig = poner_delante;

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

	void particion(T pivote) {

		Nodo* recorrer= this->fantasma->sig;
		Nodo* aux;
		Nodo* almacen;
		
		while (recorrer != this->fantasma && recorrer->elem <= pivote) {
			recorrer = recorrer->sig;
		}
		aux = recorrer;
		while (recorrer != this->fantasma) {
			
			if (recorrer->elem <= pivote) {
				almacen = recorrer->ant;
				enlazar(aux,recorrer);
				recorrer = almacen;

			}
			
			recorrer = recorrer->sig;
		}

	}

};



template <typename T>
inline ostream& operator <<(ostream& out, linked_list_ed_plus<T> const& lista) {
	lista.mostrar();
	
	return out;
}
#endif