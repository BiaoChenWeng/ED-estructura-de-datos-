#ifndef Class_h
#define Class_h
#include <iostream>
#include <math.h>
#include <vector>
#include<string>
#include "linked_list_ed.h"
using namespace std;
template <typename T>
class linked_list_ed_plus :public linked_list_ed<T> {
	using Nodo = typename linked_list_ed<T>::Nodo;

	void eleminarElemento(Nodo* aux) {
		if (aux->sig == this->ult)
			this->ult = aux;
		Nodo* nudoDelete = aux->sig;
		aux->sig = nudoDelete->sig;
		delete nudoDelete;
	}
public:

	void mostrar(std::ostream& out = std::cout) const {
		Nodo* aux = this->prim;
		while (aux != nullptr) {

			out << aux->elem << " ";
			aux = aux->sig;
		}

		out << endl;

	}

	void eleminar() {

		Nodo* aux = this->prim;
		while (aux != nullptr && aux->sig != nullptr) {
			this->eleminarElemento(aux);

			aux = aux->sig;
		}


	}

};

class Hora {
private:

	int hora;
	int minuto;
	int segundo;

	string toString(int num) const {
		if (num < 10) {
			return to_string(0) + to_string(num);
		}
		else
			return to_string(num);
	}

public:
	Hora() {}
	Hora(int hora, int minuto, int segundo) : hora(hora), minuto(minuto), segundo(segundo) {
		if (hora < 0 || hora>23) {
			throw invalid_argument("ERROR");
		}
		else if (minuto < 0 || minuto>59)
			throw invalid_argument("ERROR");
		else if (segundo < 0 || segundo>59)
			throw invalid_argument("ERROR");
	}


	string toString()const {

		return toString(hora) + ":" + toString(minuto) + ":" + toString(segundo);
	}


	bool operator==(Hora const& t) {
		return t.hora == hora && t.minuto == minuto && t.segundo == segundo;
	}

	bool operator <(Hora const& t) {
		if (hora != t.hora) {
			return hora < t.hora;
		}
		else if (minuto != t.minuto)
			return minuto < t.minuto;
		else {
			return segundo < t.segundo;
		}
	}
	bool operator <=(Hora const& t) {
		return *this == t || *this < t;
	}
	bool operator >(Hora const& t) {
		return !(*this <= t);
	}
	bool operator >=(Hora const& t) {
		return !(*this < t);
	}
	bool operator !=(Hora const& t) {
		return !(*this == t);
	}

	Hora& operator =(Hora const& time) {
		if (*this != time) {
			hora = time.hora; minuto = time.minuto; segundo = time.segundo;
		}
		return *this;
	}
};

inline ostream& operator<<(ostream& out, Hora const& hora) {
	out << hora.toString();

	return out;
}
inline istream& operator>>(istream& in, Hora& hora) {
	int hour, segundo, minuto;
	char espacio;
	in >> hour >> espacio >> minuto >> espacio >> segundo;
	hora = Hora(hour, minuto, segundo);

	return in;
}
template <typename T>
inline ostream& operator <<(ostream& out, linked_list_ed_plus<T> const& lista) {
	lista.mostrar();
	return out;
}
#endif