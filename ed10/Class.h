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
	
	void mezclaCombinada(linked_list_ed_plus& lista) {
		Nodo* a, *b,*sig, *aux;		
		if (this->empty()) {
			this->prim = lista.prim;
			this->ult = lista.ult;
		}
		else if(!lista.empty()) {
			a = this->prim;
			b = lista.prim;
			if (this->prim->elem > lista.prim->elem) {
				this->prim = lista.prim;
				b = b->sig;
			}
			else {
				a = a->sig;
			}
			lista.prim = nullptr;
			aux = this->prim;
			while (a != nullptr && b != nullptr) {
				if (a->elem < b->elem) {
					aux -> sig = a;				
					a = a->sig;
				}
				else{
					aux->sig = b;
					b = b->sig;
				}
				aux = aux->sig;
				
			}
			if (a == nullptr) {
				this->ult = lista.ult;
				aux->sig = b;
			}			
			else 
				aux->sig = a;
				
		}
		lista.prim= lista.ult = nullptr;
		 

	}


};
template <typename T>
inline ostream& operator <<(ostream& out, linked_list_ed_plus <T> const& lista) {
	lista.mostrar();
	return out;
}
template <typename T>
inline istream& operator >>(istream& in, linked_list_ed_plus<T>& lista) {
	T fin=0;
	T entrada;
	cin >> entrada;
	while (entrada != fin) {
		lista.push_back(entrada);
		cin >> entrada;
	}
	return in;
}
#endif