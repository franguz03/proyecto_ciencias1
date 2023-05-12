#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>

using namespace std;

struct Persona 
{
    //Atributos Reglas de negocio:
    string nombre, apellido, estado_civil, ciudad_nacimiento, ciudad_residencia;
    long int identificacion;
    char sexo;
	struct tm fechaNacimiento;
	int votos;
	
	//Constructor
	Persona(string nombre_, string apellido_, long int identificacion_, char sexo_, string estado_civil_, string ciudad_nacimiento_, string ciudad_residencia_, 
            struct tm fechaNacimiento_) : nombre(nombre_), apellido(apellido_), identificacion(identificacion_), sexo(sexo_), estado_civil(estado_civil_), 
            ciudad_nacimiento(ciudad_nacimiento_), ciudad_residencia(ciudad_residencia_), fechaNacimiento(fechaNacimiento_) {votos = 0;}

   friend ostream& operator<< (ostream& salida, const Persona& persona) {
        salida << persona.nombre << "," << persona.apellido << "," << persona.estado_civil << "," << persona.ciudad_nacimiento << "," << persona.ciudad_residencia << "," << persona.identificacion<< "," 
		<< persona.sexo; //<< "," << persona.fechaNacimiento;
        return salida;
}         
};

#endif
