#ifndef Class_h
#define Class_h
#include <iostream>
#include <deque>
#include "stack_eda.h"

using namespace std;
template <typename T>
class stack_plus:public stack<T>{

	deque<int> menores;

public :
	void pop() {
		if (this->empty())
			throw std::domain_error("desapilando de la pila vacia");

		

		this->nelems--;
		
		if (menores.back() == this->nelems)
			menores.pop_back();

	}

	void push(T const& elem) {
		if (menores.empty() || this->array[menores.back()] > elem) {
			menores.push_back(this->nelems);
		}
		this->array[this->nelems] = elem;
		this->nelems++;
		if (this->nelems == this->capacidad)
			this->amplia();
		
	}



	T minimo()  {
		if(this->empty())
			throw std::domain_error("la pila vacia no tiene minimo");
		
		return this->array[this->menores.back()];
	}

};



#endif