#ifndef CIUDAD_H
#define CIUDAD_H
#include <iostream>
#include "Persona.h"
#include <iomanip>
#include <list>

using namespace std;
 
struct Ciudad
{
    //Atributos Reglas de negocio:
    string nombre, departamento;
    int tamanioConsejo; //Suceptible de definici�n
    int habitantes;//Habitantes o censo de habilitados para votar, Generado al azar
    
    //Atributos Funcionales
	list<Persona> CandidatosConsejo;
	list<Persona> CandidatosAlcaldia;
	list<Persona> Habitantes;
	
	//Constructor
	Ciudad(string nombre_, string departamento_, int tamanioConsejo_, int habitantes_) : nombre(nombre_), departamento(departamento_), tamanioConsejo(tamanioConsejo_), habitantes(habitantes_) {}
};

#endif
