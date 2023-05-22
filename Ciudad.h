#ifndef CIUDAD_H
#define CIUDAD_H
#include "Persona.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>	


using namespace std;
 
struct Ciudad
{
    //Atributos Reglas de negocio:
    string nombre, departamento;
    int tamanioConsejo; //Suceptible de definici�n
    int habitantes;
    
    //Atributos Funcionales
	list<Persona> CandidatosConsejo;
	Persona CandidatoAlcaldia;
	list<Persona> listaHabitantes;
	
	//Constructor
	Ciudad(string nombre_, string departamento_, int tamanioConsejo_, int habitantes_,Persona CandidatoAlcaldia_) : nombre(nombre_), departamento(departamento_), tamanioConsejo(tamanioConsejo_),CandidatoAlcaldia(CandidatoAlcaldia_) {
  		habitantes = 100;
	}

    friend ostream& operator<< (ostream& salida, const Ciudad& ciudad) {
    salida << ciudad.nombre << "," << ciudad.departamento << "," << ciudad.tamanioConsejo << "," << ciudad.habitantes;
    return salida;
}
};



#endif
