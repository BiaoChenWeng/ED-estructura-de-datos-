#ifndef Class_h
#define Class_h
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Polinomio {
	vector<pair<int, int>>v;
	
public:
	Polinomio(){}
	

	void meter(int coeficiente, int exponente) {
		v.push_back(make_pair(coeficiente, exponente));

	}

	int calcular(int x) {
		int suma=0;
		for (int i = 0; i < v.size(); i++) {
			suma += v[i].first * (pow(x, v[i].second));
		}

		return suma;
	}
};

inline istream& operator>>(istream& in, Polinomio& a) {
	
	int coe, exp;
	in >> coe >> exp;
	if (!in)
		return in;

	while ((coe != 0 || exp != 0) && in) {
		a.meter(coe, exp);
		in >> coe >> exp;
	}
	
	 
	return in;
}


#endif // !Class.h



