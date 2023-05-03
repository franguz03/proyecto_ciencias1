#ifndef PARTIDO_H
#define PARTIDO_H

#include <iostream>

#include "Ciudad.h"
#include <iomanip>
#include <list>

using namespace std;

struct Partido{
    //Atributos Reglas de negocio:
	string nombre, representanteLegal;
	
    //Atributos Funcionales
    list<Ciudad> ciudadesActivas;
    
    //Constructor
    Partido(string nombre_, string representanteLegal_) : nombre(nombre_), representanteLegal(representanteLegal_) {};

    friend ostream& operator<< (ostream& salida, const Partido& partido) {
    salida << "Nombre: " << partido.nombre<< ", Representante legal: " << partido.representanteLegal;
    return salida;
}

	};

#endif
