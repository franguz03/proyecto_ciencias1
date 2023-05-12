#ifndef PARTIDO_H
#define PARTIDO_H

#include <iostream>

#include "Ciudad.h"
#include "Persona.h"
#include <iomanip>
#include <list>

using namespace std;

struct Partido{
    //Atributos Reglas de negocio:
	string nombre;
	Persona representanteLegal;
	
    //Atributos Funcionales
    list<Ciudad> ciudadesActivas;
    
    //Constructor
    Partido(string nombre_, Persona representanteLegal_) : nombre(nombre_), representanteLegal(representanteLegal_) {};

    friend ostream& operator<< (ostream& salida, const Partido& partido) {
 	   salida << partido.nombre << " " << partido.representanteLegal;
    	return salida;
	}

	};

#endif
