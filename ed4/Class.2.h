#ifndef Class_h
#define Class_h
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Polinomio {
	vector<pair<int, int>>v;
	

	int busquedaBinaria(int ini, int fin, int busqueda) {
		if (ini == fin) {
			return 0;
		}
		else if (ini == fin - 1) {
			if (v[ini].second <= busqueda) {
				return ini;
			}
			else {
				return ini + 1;
			}
		}
		else {
			int m = (ini + fin - 1) / 2;
			if (v[m].second < busqueda) {
				return busquedaBinaria(m + 1, fin, busqueda);
			}
			else {
				return busquedaBinaria(ini, m + 1, busqueda);
			}
		}
	}
public:
	Polinomio(){}
	

	void meter(int coeficiente, int exponente) {
		int pos=busquedaBinaria(0, v.size(), exponente);
		if (pos < v.size()) {
			if (v[pos].second != exponente) {
				v.push_back(make_pair(0, 0));
				for (int i = v.size() - 1; i > pos; i--) {
					v[i] = v[i - 1];
				}
				v[pos] = make_pair(coeficiente, exponente);
			}
			else {
				v[pos].first += coeficiente;
			}
		}
		else {
			v.push_back(make_pair(coeficiente, exponente));
		}
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
