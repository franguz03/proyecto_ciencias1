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
	
	//Constructor
	Persona(string nombre_, string apellido_, long int identificacion_, char sexo_, string estado_civil_, string ciudad_nacimiento_, string ciudad_residencia_, 
            struct tm fechaNacimiento_) : nombre(nombre_), apellido(apellido_), identificacion(identificacion_), sexo(sexo_), estado_civil(estado_civil_), 
            ciudad_nacimiento(ciudad_nacimiento_), ciudad_residencia(ciudad_residencia_), fechaNacimiento(fechaNacimiento_) {}

   friend ostream& operator<< (ostream& salida, const Persona& persona) {
        salida << "Nombre: " << persona.nombre << ", Apellido: " << persona.apellido;
        return salida;
}         
};

#endif
