#ifndef CIUDAD_H
#define CIUDAD_H
#include "Persona.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
//#include <iomanip>
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
	list<Persona> CandidatosAlcaldia;
	list<Persona> listaHabitantes;
	
	//Constructor
	Ciudad(string nombre_, string departamento_, int tamanioConsejo_, int habitantes_) : nombre(nombre_), departamento(departamento_), tamanioConsejo(tamanioConsejo_){
		srand(time(NULL));
  		int minimo = 1;
  		int maximo = 100;
  		habitantes = 100 + rand() % (2000 - 100 + 1); // 100 min hab, 2000 max hab
	}

    friend ostream& operator<< (ostream& salida, const Ciudad& ciudad) {
    salida << ciudad.nombre << "," << ciudad.departamento << "," << ciudad.tamanioConsejo << "," << ciudad.habitantes;
    return salida;
}
};



#endif
