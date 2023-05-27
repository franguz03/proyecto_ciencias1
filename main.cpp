#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <list>

#include "Ciudad.h"
#include "Persona.h"
#include "Archivos.h"
#include "Simulacion.h"
#include "funcionesAdicionales.h"

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
	list<Ciudad> listaLecturaCiudades = leer();
	
	
/*for (auto& ciudad : listaLecturaCiudades) {
		ordenarPorIdentificacion(ciudad.listaHabitantes);
		for(auto& persona: ciudad.listaHabitantes){
			cout << "Nombre: " << persona.nombre << ", Identificacion: " << persona.identificacion << endl;
		}
		eliminarPorIdentificacion(ciudad.listaHabitantes, 639814725);	
	}
	cout << "------------" << endl;
	for (auto& ciudad : listaLecturaCiudades) {
		ordenarPorIdentificacion(ciudad.listaHabitantes);
		for(auto& persona: ciudad.listaHabitantes){
			cout << "Nombre: " << persona.nombre << ", Identificacion: " << persona.identificacion << endl;
		}
	}
	guardar(listaLecturaCiudades);

	//cambia el candidato a alcaldia de mellado-conservador
	agregar_candidato_alcaldia(listaLecturaCiudades,"medallo","conservador",p2);

	//agrega candidato a consejo de mellado-conservador
	agregar_candidato_consejo(listaLecturaCiudades,"medallo","conservador",p3);

	// lista de candidatos al consejo y alcaldia segun ciudad y partido
	
	candidatos_ciudad_partido(listaLecturaCiudades,"medallo","conservador");
	cout<<"-------------------------------"<<"\n";

	//mostrar candidatos a alcaldia de un partido por cada ciudad
	alcaldia_ciudad(listaLecturaCiudades,"conservador");

	cout<<"-------------------------------"<<"\n";

	//mostrar candidatos a consejo de un partido por cada ciudad
	consejo_ciudad(listaLecturaCiudades,"conservador");
*/
	
	//menu_principal();
	
	simulacion();
    return 0;
}

	

