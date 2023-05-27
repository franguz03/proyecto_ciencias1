#ifndef FUNCIONESADICIONALES_H
#define FUNCIONESADICIONALES_H

#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <list>

#include "Archivos.h"
#include "Ciudad.h"
#include "Persona.h"


using namespace std;
/*
void menu_principal(){
    list<Ciudad> listaLecturaCiudades = leer();
    cout<<"programa de simulacion"<<"\n";
    cout<<"1. modificar datos"<<"\n"<<"2. consultar datos"<<"\n"<<"3. simular votaciones"<<"\n";
    int opcion;
    cout<<"ingrese su opcion: ";
    cin>>opcion;
    switch (opcion) {

        case 1:
        cout<<"ingrese ciudad: ";
            menu_modificacioines(listaLecturaCiudades);
            menu_principal();
        case 2:
            menu_consultas(listaLecturaCiudades);
            menu_principal();
        case 3:
            simulacion();
            menu_principal();
        default:
            std::cout << "Opción inválida" << std::endl;
            menu_principal();
       


    }
}


void menu_consultas(list<Ciudad> multilistaCiudad){
    cout<<"1. DADO UN PARTIDO Y UNA CIUDAD MOSTRAR LA LISTA DE SUS CANDIDATOS AL CONSEJO Y EL CANDIDATO A LA ALCALDIA"<<"\n"<<"2. DADO UN PARTIDO MOSTRAR LA LISTA DE CANDIDATOS A ALCALDIAS DE CADA UNA DE LAS DIFERENTES CIUDADES"<<"\n"<<"3. DADO UN PARTIDO MOSTRAR LAS LISTAS DE CANDIDATOS A CADA UNO DE DIFERENTES LOS CONSEJOS"<<"\n"<<"4. DADA UNA CIUDAD MOSTRAR POR CADA PARTIDO EL CANDIDATO A LA ALCALDIA Y LOS CANDIDATOS AL CONSEJO"<<"\n"<<"5. DADA UNA CIUDAD MOSTRAR EL TARJETON DE CANDIDATOS A LA ALCALDIA INCLUYENDO EL VOTO EN BLANCO"<<"\n"<<"6.  DADA UNA CIUDAD MOSTRAR EL TARJETON DE CANDIDATOS AL CONSEJO INCLUYENDO EL VOTO EN BLANCO"<<"\n"<<"7.  POR CADA CIUDAD MOSTRAR LA CANTIDAD DE PERSONAS HABILITADAS PARA VOTAR"<<"\n"<<"8. Volver atras"<<"\n";
    int opcion;
    cin>>opcion;
    string ciudad;
    string partido;
    switch (opcion)
    {
    case 1:
        cout << "Introduce la partido: ";
        getline(std::cin, partido);
        cout << "Introduce la ciudad: ";
        getline(std::cin, ciudad);
        candidatos_ciudad_partido(multilistaCiudad,ciudad,partido);
        menu_consultas(multilistaCiudad);

    case 2:
        cout << "Introduce la partido: ";
        getline(std::cin, partido);
        alcaldia_ciudad(multilistaCiudad,partido);
        menu_consultas(multilistaCiudad);

    case 3:
        cout << "Introduce la partido: ";
        getline(std::cin, partido);
        consejo_ciudad(multilistaCiudad,partido);
        menu_consultas(multilistaCiudad);
    
    case 4:
        cout << "Introduce la ciudad: ";
        getline(std::cin, ciudad);
        alcaldia_consejo_ciudad(multilistaCiudad,ciudad);
        menu_consultas(multilistaCiudad);

    case 5:
        cout << "Introduce la ciudad: ";
        getline(std::cin, ciudad);
        tarjeton_Ciudad_Alcaldia(multilistaCiudad,ciudad);
        menu_consultas(multilistaCiudad);

    case 6:
        cout << "Introduce la ciudad: ";
        getline(std::cin, ciudad);
        tarjeton_Ciudad_Consejo(multilistaCiudad,ciudad);
        menu_consultas(multilistaCiudad);

    case 7:
        censo_Electoral(multilistaCiudad);
        menu_consultas(multilistaCiudad);

    case 8:
        menu_principal();

    default:
        cout<<"opcioin no valida";
        menu_consultas(multilistaCiudad);
        
    }
}

void menu_modificacioines(list<Ciudad> multilistaCiudad){

    cout<<"1. AGREGAR UN CANDIDATO-ALCALDIA SEGUN CIUDAD Y PARTIDO"<<"\n"<<"2. AGREGAR UN CANDIDATO-CONSEJO SEGUN CIUDAD Y PARTIDO"<<"\n"<<"3. AGREGAR UN PARTIDO SEGUN CIUDAD"<<"\n";
    int opcion;
    cin>>opcion;
    string ciudad;
    string partido;
    switch (opcion)
    {
    case 1:
        cout << "Introduce la partido: ";
        getline(std::cin, partido);
        cout << "Introduce la ciudad: ";
        getline(std::cin, ciudad);
        agregar_candidato_alcaldia(multilistaCiudad,ciudad,partido,crearPersona());
        menu_modificacioines(multilistaCiudad);
    case 2:
        cout << "Introduce la partido: ";
        getline(std::cin, partido);
        cout << "Introduce la ciudad: ";
        getline(std::cin, ciudad);
        agregar_candidato_consejo(multilistaCiudad,ciudad,partido,crearPersona());
        menu_modificacioines(multilistaCiudad);
    case 3:
        cout << "Introduce la ciudad: ";
        getline(std::cin, ciudad);
        agregar_partido(multilistaCiudad,ciudad,crearPartido());
        menu_modificacioines(multilistaCiudad);
    
    default:
        cout<<"opcion no valida";
        menu_modificacioines(multilistaCiudad);
    }


}*/
Persona crearPersona(){
    string nombre, apellido, estado_civil, ciudad_nacimiento, ciudad_residencia, fechaNacimiento;
    long int identificacion;
    char sexo;

    cout << "Ingrese nombre: ";
    getline(cin, nombre);
    cout << "Ingrese apellido: ";
    getline(cin, apellido);
    cout << "Ingrese estado civil: ";
    getline(cin, estado_civil);
    cout << "Ingrese ciudad de nacimiento: ";
    getline(cin, ciudad_nacimiento);
    cout << "Ingrese ciudad de residencia: ";
    getline(cin, ciudad_residencia);
    cout << "Ingrese fecha de nacimiento (dd/mm/aaaa): ";
    getline(cin, fechaNacimiento);
    cout << "Ingrese identificacion: ";
    cin >> identificacion;
    cout << "ingrese sexo (M/F)";
    cin >> (cin, sexo);
    Persona p(nombre,apellido,identificacion,sexo,estado_civil,ciudad_nacimiento,ciudad_residencia,fechaNacimiento);
    return p;
}

Partido crearPartido(){
    string nombre;
    cout << "Ingrese nombre del partido: ";
    getline(cin, nombre);

    cout<<"ingrese datos del representante";
    Persona representante= crearPersona();

    cout<<"ingrese datos del candidato";
    Persona representantealcaldia= crearPersona();

    return Partido(nombre,representante,representantealcaldia);
}

int calcularEdad(const std::string& fechaNacimiento) {
    std::tm tmFechaNacimiento = {};
    std::istringstream issFechaNacimiento(fechaNacimiento);
    char delimiter;
    issFechaNacimiento >> tmFechaNacimiento.tm_mday >> delimiter
                       >> tmFechaNacimiento.tm_mon >> delimiter
                       >> tmFechaNacimiento.tm_year;
    tmFechaNacimiento.tm_year -= 1900;  // Ajuste del año

    std::time_t tiempoNacimiento = std::mktime(&tmFechaNacimiento);
    std::time_t tiempoActual = std::time(nullptr);
    std::tm* tmActual = std::localtime(&tiempoActual);

    int edad = tmActual->tm_year - tmFechaNacimiento.tm_year;
    if (tmActual->tm_mon < tmFechaNacimiento.tm_mon ||
        (tmActual->tm_mon == tmFechaNacimiento.tm_mon && tmActual->tm_mday < tmFechaNacimiento.tm_mday)) {
        edad--;
    }

    return edad;
}

void ordenarPorIdentificacion(list<Persona>& listaPersonas) {
    listaPersonas.sort();
}

void agregarPersonaOrdenada(list<Persona>& listaPersonas, const Persona& nuevaPersona) {
    auto it = lower_bound(listaPersonas.begin(), listaPersonas.end(), nuevaPersona);
    listaPersonas.insert(it, nuevaPersona);
}

bool eliminarPorIdentificacion(list<Persona>& listaPersonas, long int identificacion) {
    auto it = lower_bound(listaPersonas.begin(), listaPersonas.end(), Persona{"","", identificacion,'x',"","","",""});
    if (it != listaPersonas.end() && it->identificacion == identificacion) {
        listaPersonas.erase(it);
        return true;
    }
    return false;
}

void agregar_candidato_alcaldia(list<Ciudad>& multilistaCiudad, string nombre_ciudad, string nombre_partido, Persona candidato) {//agregar candidato a alcaldia a una ciudad en un partido (1 candidato por partido, si ya lo tiene lo cambia)
    for (auto& ciudad : multilistaCiudad) {
        if (ciudad.nombre == nombre_ciudad) {
            for (auto& partido : ciudad.listaPartidosHabilitados) {
                if (partido.nombre == nombre_partido) {
                    partido.candidatoAlcaldia = candidato;
                    guardar(multilistaCiudad);
                    return;
                }
            }
            cout << "Partido no encontrado";
            return;
        }
    }
    cout << "Ciudad no encontrada";
}

void agregar_candidato_consejo(list<Ciudad>& multilistaCiudad, string nombre_ciudad, string nombre_partido, Persona candidato) {//agregar candidato a consejo a una ciudad en un partido
    for (auto& ciudad : multilistaCiudad) {
        if (ciudad.nombre == nombre_ciudad) {
            for (auto& partido : ciudad.listaPartidosHabilitados) {
                if (partido.nombre == nombre_partido) {
                    partido.listaCandidatosConsejo.push_back(candidato);
                    guardar(multilistaCiudad);
                    return;
                }
            }
            cout << "Partido no encontrado";
            return;
        }
    }
    cout << "Ciudad no encontrada";
}

void agregar_partido(list<Ciudad>& multilistaCiudad, string nombre_ciudad, Partido Partido) {//agregar un partido en una ciudad (las ciudades tienen partidos habilitados)
    for (auto& ciudad : multilistaCiudad) {
        if (ciudad.nombre == nombre_ciudad) {
            ciudad.listaPartidosHabilitados.push_back(Partido);
            guardar(multilistaCiudad);
            return;
        }
    }
    cout << "Ciudad no encontrada";
}

int censoParticular(Ciudad ciudad){
	int votantes = 0;
	for(const auto& persona : ciudad.listaHabitantes){
		if(calcularEdad(persona.fechaNacimiento)>18){
			votantes++;
		}
	}
	return votantes;
}
#endif




