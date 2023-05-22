#ifndef CIUDAD_H
#define CIUDAD_H
#include "Persona.h"
#include "Partido.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>	


using namespace std;
 
struct Ciudad
{
    //Atributos Inicializados
    string nombre, departamento;
    int tamanioConsejo; 
    
    //Atributos pusheables
	list<Persona> listaHabitantes;
	list<Partido> listaPartidosHabilitados;
	
	//Constructor
	Ciudad(string nombre_, string departamento_, int tamanioConsejo_) : nombre(nombre_), departamento(departamento_), tamanioConsejo(tamanioConsejo_) {}

    friend ostream& operator<< (ostream& salida, const Ciudad& ciudad) {
    salida << ciudad.nombre << "," << ciudad.departamento << "," << ciudad.tamanioConsejo;
    return salida;
}
};



#endif
