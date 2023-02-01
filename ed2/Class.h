#ifndef horas
#define horas
#include <iostream>
#include<vector>
#include<string>
#include<stdexcept>
using namespace std;


class Hora {
private:
	const int HORA_MAX=24;
	const int MINUTO_MAX=60;
	const int SEGUNDO_MAX=60;
	int hora;
	int minuto;
	int segundo;
	
	string toString(int num) const{
		if (num < 10) {
			return to_string(0) + to_string(num);
		}
		else
			return to_string(num);
	}

public:
	Hora(){}
	Hora(int hora,int minuto,int segundo): hora(hora),minuto(minuto),segundo(segundo){
		if (hora < 0 || hora>=HORA_MAX) {
			throw invalid_argument("ERROR");
		}
		else if(minuto<0 || minuto>=MINUTO_MAX)
			throw invalid_argument("ERROR");
		else if (segundo < 0 || segundo>=SEGUNDO_MAX)
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
	Hora operator +(Hora const & t)const  {
		int hour=hora+t.hora;
		int minute=minuto+t.minuto;
		int sec=segundo+t.segundo;
		if (sec>= SEGUNDO_MAX) {
			minute ++;
			sec = sec % SEGUNDO_MAX;
		}
		if (minute >= MINUTO_MAX) {
			hour++;
			minute %= MINUTO_MAX;
		}
		if (hour >= HORA_MAX)
			throw invalid_argument("ERROR");
		
		return Hora(hour,minute,sec);
	}
	Hora& operator =(Hora const& time) {
		if (*this != time) {
			hora = time.hora; minuto = time.minuto; segundo = time.segundo; 
		}
		return *this;
	}



};

class Pelicula {
	Hora horario;
	string nombre;
	Hora duracion;
public:
	Pelicula(){}
	Pelicula(string nombre, Hora hora,Hora duracion) : horario(hora),nombre(nombre),duracion(duracion) {
	
	}


	bool operator<(Pelicula const& pel) {
		Hora a=horario+duracion;
		Hora b=pel.horario+pel.duracion;
		if (a == b) {
			return nombre<pel.nombre;
		}
		else {
			return a < b;
		}	
	}
	string toString() const {
		
		return (horario+duracion).toString() + nombre;
	}
};
inline ostream& operator<<(ostream& out, Hora const& hora) {
	out << hora.toString();
	
	return out;
}
inline istream& operator>>(istream& in, Hora & hora) {
	int hour, segundo, minuto;
	char espacio;
	string nombre;
	in >> hour>> espacio >> minuto >> espacio >> segundo;
	hora = Hora(hour, minuto, segundo);

	return in;
}

inline ostream& operator<<(ostream& out, Pelicula const& p) {
	out << p.toString();

	return out;
}
inline istream& operator>>(istream& in, Pelicula& p) {
	Hora ini;
	Hora dur;
	string nombre;
	in >> ini >> dur ;
	getline(in,nombre);
	
	p = Pelicula(nombre, ini ,dur);
	return in;
}
#endif // !horas

