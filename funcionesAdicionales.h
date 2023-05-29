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
#include "Consultas.h"


using namespace std;

Persona crearPersona();

Persona crearPersona(){// crea una estructura de tipo persona usando entradas por consola
    string nombre, apellido, estado_civil, ciudad_nacimiento, ciudad_residencia, fechaNacimiento;
    long int identificacion;
    char sexo;
    cout << "Ingrese nombre: ";
    cin>>nombre;
    cout << "Ingrese apellido: ";
    cin>>apellido;
    cout << "Ingrese estado civil: ";
    cin>>estado_civil;
    cout << "Ingrese ciudad de nacimiento: ";
    cin>>ciudad_nacimiento;
    cout << "Ingrese ciudad de residencia: ";
    cin>>ciudad_residencia;
    cout << "Ingrese fecha de nacimiento (dd/mm/aaaa): ";
    cin>>fechaNacimiento;
    cout << "Ingrese identificacion: ";
    cin >> identificacion;
    cout << "ingrese sexo (M/F)";
    cin >> (cin, sexo);
    Persona p(nombre,apellido,identificacion,sexo,estado_civil,ciudad_nacimiento,ciudad_residencia,fechaNacimiento);
    return p;
}

Partido crearPartido(){// crea una estructura de tipo partido usando entradas por consola
    string nombre;
    cout << "Ingrese nombre del partido: ";
    cin>>nombre;

    cout<<"ingrese datos del representante"<<"\n";
    Persona representante= crearPersona();

    cout<<"ingrese datos del candidato-alcaldia"<<"\n";
    Persona representantealcaldia= crearPersona();

    return Partido(nombre,representante,representantealcaldia);
}

Ciudad crearCiudad(){// crea una estructura de tipo ciudad usando entradas por consola
    string nombre, departamento;
    int tamanioConsejo; 
    cout << "Ingrese nombre: ";
    cin>>nombre;
    cout << "Ingrese departamento: ";
    cin>>departamento;
    cout << "Ingrese tamaño del consejo: ";
    cin>>tamanioConsejo;

    return Ciudad(nombre,departamento,tamanioConsejo);
}

int calcularEdad(const std::string& fechaNacimiento) {// calcula la edad de persona, se usa para saber quienes estan habilitados para votar en la lista de habitantes
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

void ordenarPorIdentificacion(list<Persona>& listaPersonas) {//funcion que ordena una lista de persona usando el metodo propio de list sort
    listaPersonas.sort();
}

void agregarPersonaOrdenada(list<Persona>& listaPersonas, const Persona& nuevaPersona) {// agrega una persona de manera ordenada
    auto it = lower_bound(listaPersonas.begin(), listaPersonas.end(), nuevaPersona);
    listaPersonas.insert(it, nuevaPersona);
}

bool eliminarPorIdentificacion(list<Persona>& listaPersonas, long int identificacion) {// elimina una persona de una lista por identificaion
    auto it = lower_bound(listaPersonas.begin(), listaPersonas.end(), Persona{"","", identificacion,'x',"","","",""});
    if (it != listaPersonas.end() && it->identificacion == identificacion) {
        listaPersonas.erase(it);
        return true;
    }
    return false;
}

void agregar_candidato_alcaldia(list<Ciudad>& multilistaCiudad, string nombre_ciudad, string nombre_partido) {//agregar candidato a alcaldia a una ciudad en un partido (1 candidato por partido, si ya lo tiene lo cambia)
    for (auto& ciudad : multilistaCiudad) {
        if (ciudad.nombre == nombre_ciudad) {
            for (auto& partido : ciudad.listaPartidosHabilitados) {
                if (partido.nombre == nombre_partido) {
                    cout<<"Ingrese los datos del candidato------"<<"\n";
                    partido.candidatoAlcaldia = crearPersona();
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

void agregar_candidato_consejo(list<Ciudad>& multilistaCiudad, string nombre_ciudad, string nombre_partido) {//agregar candidato a consejo a una ciudad en un partido
    for (auto& ciudad : multilistaCiudad) {
        if (ciudad.nombre == nombre_ciudad) {
            for (auto& partido : ciudad.listaPartidosHabilitados) {
                if (partido.nombre == nombre_partido) {
                    cout<<"Ingrese los datos del candidato------"<<"\n";
                    partido.listaCandidatosConsejo.push_back(crearPersona());
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

void eliminar_candidato_consejo(list<Ciudad>& multilistaCiudad, string nombre_ciudad, string nombre_partido, string nombre_candidato) {// elimina un candidato al consejo a partir del nombre de este, la ciudad y el partido al que pertenece
    for (auto& ciudad : multilistaCiudad) {
        if (ciudad.nombre == nombre_ciudad) {
            for (auto& partido : ciudad.listaPartidosHabilitados) {
                if (partido.nombre == nombre_partido) {
                    auto it = std::find_if(partido.listaCandidatosConsejo.begin(), partido.listaCandidatosConsejo.end(), [&nombre_candidato](const Persona& candidato) {
                        return candidato.nombre == nombre_candidato;
                    });

                    if (it != partido.listaCandidatosConsejo.end()) {
                        partido.listaCandidatosConsejo.erase(it);
                        guardar(multilistaCiudad);
                        return;
                        
                    } else {
                        cout << "Candidato no encontrado en el partido" << endl;
                        return;
                    }
                }
            }
            cout << "Partido no encontrado en la ciudad" << endl;
            
        }
    }
    cout << "Ciudad no encontrada" << endl;
    // No es necesario el return en una funci�n void
}

void agregar_partido(list<Ciudad>& multilistaCiudad, string nombre_ciudad) {//agregar un partido en una ciudad (las ciudades tienen partidos habilitados)
    for (auto& ciudad : multilistaCiudad) {
        if (ciudad.nombre == nombre_ciudad) {
            cout<<"Ingrese los datos del partido------"<<"\n";
            ciudad.listaPartidosHabilitados.push_back(crearPartido());
            guardar(multilistaCiudad);
            return;
        }
    }
    cout << "Ciudad no encontrada";
}

void eliminar_partido(list<Ciudad>& multilistaCiudad, string nombre_ciudad, string nombre_partido) { // elimina un partido usando el nombre de este y la ciudad al que pertenece
    for (auto& ciudad : multilistaCiudad) {
        if (ciudad.nombre == nombre_ciudad) {
            auto it = std::find_if(ciudad.listaPartidosHabilitados.begin(), ciudad.listaPartidosHabilitados.end(), [&nombre_partido](const Partido& partido) {
                return partido.nombre == nombre_partido;
            });

            if (it != ciudad.listaPartidosHabilitados.end()) {
                ciudad.listaPartidosHabilitados.erase(it);
                guardar(multilistaCiudad);
                return;
            } else {
                cout << "Partido no encontrado en la ciudad" << "\n";
                return;
            }
        }
    }
    cout << "Ciudad no encontrada" << "\n";
}

void agregar_ciudad(list<Ciudad>& multilistaCiudad) {//agrega una ciduad a la lista principal
    cout<<"Ingrese los datos de la ciudad------"<<"\n";
    multilistaCiudad.push_back(crearCiudad());
    guardar(multilistaCiudad);
}

void eliminar_ciudad(list<Ciudad>& multilistaCiudad, const string& nombreCiudad) {// elimina una ciudad de la lista principal usando su nombre
    auto it = std::find_if(multilistaCiudad.begin(), multilistaCiudad.end(), [&nombreCiudad](const Ciudad& ciudad) {
        return ciudad.nombre == nombreCiudad;
    });
    
    if (it != multilistaCiudad.end()) {
        multilistaCiudad.erase(it);
        guardar(multilistaCiudad);
        return;
    } else {
        cout << "Ciudad no encontrada" << endl;
    }
}

int censoParticular(Ciudad ciudad){// calcula el numero de votantes habilitados e una ciudad usando la funcion calcular edad
	int votantes = 0;
	for(const auto& persona : ciudad.listaHabitantes){
		if(calcularEdad(persona.fechaNacimiento)>18){
			votantes++;
		}
	}
	return votantes;
}

#endif




