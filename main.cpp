#include <cstdlib>
#include <iostream>
#include "Ciudad.h"
#include "Persona.h"
#include <iomanip>
#include <list>
#include "Archivos.h"

using namespace std;

int main(int argc, char *argv[]){

	struct tm fechaNacimiento = {0, 0, 0, 1, 0, 100};
	Persona p("Juan", "Perez", 123456789, 'M', "Soltero", "Medellin", "Bogota", fechaNacimiento);
	Persona x("Joan", "garzon", 123456789, 'M', "Soltero", "Medellin", "Bogota", fechaNacimiento);
	list<Persona> listaDePersonas;
	listaDePersonas.push_back(p);
	listaDePersonas.push_back(x);
	Ciudad c1("medallo","antioquia",23,2323);
	Ciudad c2("bogota","cundinamarca",23,2323);
	list<Ciudad> listaciudades;
	c1.CandidatosAlcaldia=listaDePersonas;
	c2.CandidatosAlcaldia=listaDePersonas;
	c1.CandidatosConsejo=listaDePersonas;
	c2.CandidatosConsejo=listaDePersonas;
	c1.listaHabitantes=listaDePersonas;
	c2.listaHabitantes=listaDePersonas;
	listaciudades.push_back(c1);
	listaciudades.push_back(c2);
	Partido partido1("conservador",p);
	Partido partido2("liberal",x);
	partido1.ciudadesActivas=listaciudades;
	partido2.ciudadesActivas=listaciudades;
	list<Partido> listaPartidos;
	listaPartidos.push_back(partido1);
	listaPartidos.push_back(partido2);
	
	//guardar(listaPartidos);
	cout << "------------------- lectura -------------------------"<<endl;
	list<Partido> newListaPartidos;
	leer(newListaPartidos);

}

