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

void menu_principal(){
    list<Ciudad> listaLecturaCiudades = leer();
    cout<<"programa de simulacion"<<"\n";
    cout<<"1. agregar un partido en una ciudad"<<"\n"<<"2. agregar candidato a consejo a una ciudad en un partido"<<"\n"<<"3. agregar candidato a alcaldia a una ciudad en un partido"<<"\n"<<"4. mostrar candidatos a consejo de un partido por cada ciudad"<<"\n"<<"5. mostrar candidatos a alcaldia de un partido por cada ciudad"<<"\n"<<"6.  lista de candidatos al consejo y alcaldia segun ciudad y partido"<<"\n"<<"7.  realizar simulación"<<"\n";
    int opcion;
    cout<<"ingrese su opcion: ";
    cin>>opcion;
    switch (opcion) {

        case 1:
            cout<<"opcion 1";
            menu_principal();
        case 2:cout<<"opcion 2";menu_principal();
        case 3:cout<<"opcion 3";menu_principal();
        case 4:cout<<"opcion 4";menu_principal();
        case 5:cout<<"opcion 5";menu_principal();
        case 6:cout<<"opcion 6";menu_principal();
        case 7:cout<<"opcion 7";menu_principal();
        default:
            std::cout << "Opción inválida" << std::endl;
            menu_principal();
       


    }
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




