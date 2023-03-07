#ifndef Class_h
#define Class_h
#include <iostream>
#include <string>


using namespace std;

class  Persona{
	int edad;
	string nombre;


public :
   
	Persona():edad(-1),nombre("") {}
	Persona(int edad, string nombre) :edad(edad), nombre(nombre) {

	}

	int getEdad()const  {
		return edad;

	}

	string getNombre() const {
		return nombre;
	}

	bool operator <(const int& n) const {
		return this->edad < n;
	}

	bool operator== (const int& n) const {
		return this->edad == n;
	}

	bool operator>(const int& n) const {
		return !(*this<= n);
	}
	bool operator<=(const int& n) const {
		return (*this < n) || (*this == n);
	}

	bool operator>= (const int& n) const{
		return!(*this < n);
	}

	bool operator==(const Persona& p) const{
		return edad == p.edad && nombre ==p.nombre;
	}

	bool operator!=(const Persona&p) const{
		return !( *this==p);
	}

	Persona &operator=(Persona const  & p) {
		if (*this!= p) {
			this->edad = p.edad;
			this->nombre = p.nombre;
		}

		return *this;
	}


};
template<typename T>
class predicado {
	T max;
	T min;

public:
	predicado() {}

	predicado(T max, T min):max(max),min(min) {}
	template <typename U>
	bool operator()(U val) {
		return val <= max && val >= min;
	}

};

inline ostream& operator<<(ostream& out, const Persona& p) {
	cout <<p.getNombre();
	
	return out;
}

inline istream& operator>>(istream& in, Persona  &p) {
	int edad;
	string nombre;
	cin >> edad;
	getline(in, nombre);

	p = Persona(edad,nombre.substr(1,nombre.size()));
	return in;
}




#endif