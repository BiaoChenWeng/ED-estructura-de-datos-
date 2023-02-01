#ifndef Class_h
#define Class_h
#include <iostream>
#include <math.h>
using namespace std;

class Complejo {
	float real;
	float imaginario;
	

public:
	Complejo():real(0),imaginario(0) {}
	Complejo(float real,float imaginario):real(real),imaginario(imaginario) {}

	Complejo operator+(const Complejo& c) const {
		float part_real = real + c.real;
		float part_imag = imaginario + c.imaginario;
		return Complejo(part_real, part_imag);
	}
	
	Complejo operator *(const Complejo& c) const {
		float part_real = (real * c.real) -(imaginario*c.imaginario);
		float part_imag = (real * c.imaginario) + (imaginario * c.real);
		return Complejo(part_real, part_imag);
	}
	double mod(const Complejo&  a)const {
		return sqrt(pow(a.real, 2) + pow(a.imaginario, 2));
	}

	

	bool Mandelbrot(int vuelta) {
		int i = 0;
		Complejo resultado = Complejo();
		bool converge=true;
		while (i < vuelta && converge) {// en el punto i calcula z i+1
			resultado = resultado * resultado + *this;
			converge = mod(resultado) <= 2;
			i++;
		}

		return converge;
	}

};

inline istream& operator>>(istream& in, Complejo& a) {
	float p_real, p_imag;
	in >> p_real >> p_imag;
	a = Complejo(p_real, p_imag);
	return in;
}


#endif // !Class.h



