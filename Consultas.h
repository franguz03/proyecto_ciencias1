#ifndef CONSULTAS_H
#define CONSULTAS_H
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <list>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>

#include "Ciudad.h"
#include "Persona.h"
#include "Partido.h"

using namespace std;

// lista de candidatos al consejo y alcaldia segun ciudad y partido
void candidatos_ciudad_partido(list<Ciudad> multilistaCiudad,string nombre_ciudad, string nombre_partido){
       
    for (const auto& ciudad : multilistaCiudad) {
        if (ciudad.nombre == nombre_ciudad) {
            for(const auto& partido : ciudad.listaPartidosHabilitados){
                if (partido.nombre == nombre_partido) {  

                    cout<<"ciudad: "<<ciudad.nombre<<"- partido: "<<partido.nombre<<"\n";
                    cout<<"representante alcaldia: "<< partido.candidatoAlcaldia<<"\n";
                    cout<<"lista consejo"<<"\n";
                    for(const auto& Persona : partido.listaCandidatosConsejo){
                        cout<<Persona<<"\n";
                    }
                    return;
                }
            }
            cout<<"partido no encontrado";
        }
        return;  
    }
cout<<"ciudad no encontrada";
}


//mostrar candidatos a alcaldia de un partido por cada ciudad

void alcaldia_ciudad(list<Ciudad> multilistaCiudad,string nombre_partido){
    bool c=false;
    cout<<"partido "<<nombre_partido<<"\n";
    for (const auto& ciudad : multilistaCiudad) {
        cout<<ciudad.nombre<<"\n";
        for(const auto& partido : ciudad.listaPartidosHabilitados){
            if (partido.nombre == nombre_partido) {
                cout<<partido.candidatoAlcaldia<<"\n";
                c=true;      
        }
        
    }
    if(c==false){
          cout<<"la ciudad "<<ciudad.nombre<<" no tiene representantes de este partido"<<"\n";  
        }
        c=false;

}
}

//mostrar candidatos a consejo de un partido por cada ciudad

void consejo_ciudad(list<Ciudad> multilistaCiudad,string nombre_partido){
    bool c=false;
    cout<<"partido "<<nombre_partido<<"\n";
    for (const auto& ciudad : multilistaCiudad) {
        cout<<ciudad.nombre<<"\n";
        for(const auto& partido : ciudad.listaPartidosHabilitados){
            if (partido.nombre == nombre_partido) {
                for(const auto& Persona : partido.listaCandidatosConsejo){
                    cout<<Persona<<"\n";
                } 
                c=true;  
        }
        
    }
    if(c==false){
          cout<<"la ciudad "<<ciudad.nombre<<" no tiene representantes de este partido"<<"\n";  
        }
        c=false;

}
}


//agregar candidato a alcaldia a una ciudad en un partido (1 candidato por partido, si ya lo tiene lo cambia)
void agregar_candidato_alcaldia(list<Ciudad>& multilistaCiudad, string nombre_ciudad, string nombre_partido, Persona candidato) {
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

//agregar candidato a consejo a una ciudad en un partido

void agregar_candidato_consejo(list<Ciudad>& multilistaCiudad, string nombre_ciudad, string nombre_partido, Persona candidato) {
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

//agregar un partido en una ciudad (las ciudades tienen partidos habilitados)

void agregar_partido(list<Ciudad>& multilistaCiudad, string nombre_ciudad, Partido Partido) {


    for (auto& ciudad : multilistaCiudad) {
        if (ciudad.nombre == nombre_ciudad) {
            ciudad.listaPartidosHabilitados.push_back(Partido);
            guardar(multilistaCiudad);
            return;
        }
    }
    cout << "Ciudad no encontrada";
}

//agregar una ciudad

#endif