#ifndef Class_h
#define Class_h
#include <iostream>
#include "linked_list_ed.h"
using namespace std;
template <typename T>
class linked_list_ed_plus :public linked_list_ed<T> {
	using Nodo = typename linked_list_ed<T>::Nodo;




public :
	void mostrar(ostream & out = std::cout )const  {
		Nodo* aux = this->prim;
		while (aux != nullptr) {
			out << aux->elem << " ";
			aux = aux->sig;
		}
		out << endl;
	}

	void invertir() {
		if (this->prim!= this->ult) {
			Nodo* aux = this->prim->sig;
			Nodo* almacen;
			this->ult = this->prim;
			
			this->ult->sig = nullptr;
			
			while (aux != nullptr) {
				almacen = aux->sig;// almacen guarda el puntero de siguiente elemento de la lista original
				aux->sig = this->prim;// prim apunta al primer elemento de la nueva lista, enlazamos el nuevo elemento delante de la nueva lista
				this->prim = aux;// ponemos prim a la posicion del nuevo elemento de la lista nueva
				aux = almacen;// auxiliar recorre la vieja lista

			}



		}

	}



};
template <typename T>
inline ostream& operator <<(ostream& out, linked_list_ed_plus <T> const& lista) {
	lista.mostrar();
	return out;
}
#endif