#ifndef PARTIDO_H
#define PARTIDO_H

#include <iostream>

#include "Persona.h"
#include <iomanip>
#include <list>

using namespace std;

struct Partido{
    //Atributos inicializados
	string nombre;
	Persona representanteLegal;
	Persona candidatoAlcaldia;
    
	//Atributos pusheables
    list<Persona> listaCandidatosConsejo;
        
    //Constructor
    Partido(string nombre_, Persona representanteLegal_,Persona candidatoAlcaldia_) : nombre(nombre_), representanteLegal(representanteLegal_), candidatoAlcaldia(candidatoAlcaldia_){};

    friend ostream& operator<< (ostream& salida, const Partido& partido) {
 	   salida << partido.nombre << "-" << partido.representanteLegal << "-" << partido.candidatoAlcaldia;
    	return salida;
	}

	};

#endif
