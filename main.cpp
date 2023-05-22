#include <cstdlib>
#include <iostream>
#include "Ciudad.h"
#include "Persona.h"
#include <iomanip>
#include <list>
#include "Archivos.h"

using namespace std;

int main(int argc, char *argv[]){
	Persona p("Juan", "Perez", 123456789, 'M', "Soltero", "Medellin", "Bogota", "10/08/2020");
	Persona x("Pedro", "garzon", 123456789, 'M', "Soltero", "Medellin", "Bogota", "10/08/2020");
	Partido partido1("conservador",p,p);
	Partido partido2("liberal",x,x);
	Ciudad c1("medallo","antioquia",2);
	Ciudad c2("bogota","cundinamarca",2);
	
	partido1.listaCandidatosConsejo.push_back(p);
	partido1.listaCandidatosConsejo.push_back(x);
	partido2.listaCandidatosConsejo.push_back(p);
	partido2.listaCandidatosConsejo.push_back(x);
	
	c1.listaHabitantes.push_back(p);
	c1.listaHabitantes.push_back(x);
	c1.listaPartidosHabilitados.push_back(partido1);
	c1.listaPartidosHabilitados.push_back(partido2);
	
	c2.listaHabitantes.push_back(p);
	c2.listaHabitantes.push_back(x);
	c2.listaPartidosHabilitados.push_back(partido1);
	c2.listaPartidosHabilitados.push_back(partido2);
	
	list<Ciudad> listaCiudades;
	listaCiudades.push_back(c1);
	listaCiudades.push_back(c2);
	
	//guardar(listaCiudades);
	
	list<Ciudad> listaLecturaCiudades;
	leer(listaLecturaCiudades);

}

