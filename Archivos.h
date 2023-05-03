#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <cstdlib>
#include <iostream>
#include "Ciudad.h"
#include "Persona.h"
#include "Partido.h"
#include <fstream>
#include <list>
using namespace std;

ofstream archivo("datos.txt");

void guardar(list<Partido> multilistaPartido){
    
    int contPartido=0;
    for (auto itk =multilistaPartido.begin(); itk != multilistaPartido.end(); ++itk){
        contPartido++;
        archivo <<"Partido "<< contPartido<<". "<<*itk<< endl;
        int contCiuadad=0;
        cout<<"     ciudades registradas"<<endl;
     for (auto it =(*itk).ciudadesActivas.begin(); it != (*itk).ciudadesActivas.end(); ++it){//accede a la multilista de ciudad, utiliza begin como itedaror que se guarda en it
        contCiuadad++;
        archivo <<"     ciudad "<< contCiuadad<<". "<<*it<< endl;//guarda las propiedades de it en el txt
        archivo<<"          candidatos alcaldia"<<endl;
        int contPersona=0;
        for (auto it2 =(*it).CandidatosAlcaldia.begin(); it2 != (*it).CandidatosAlcaldia.end(); ++it2){//accede a la lista de alcaldia del iteraor it y lo guarda en it2
            contPersona++;
            archivo<<"          "<<"persona "<< contPersona<<". "<<*it2<<endl;//guarda las propiedades de it2(persona) en el txt
        }
        contPersona=0;
        archivo<<"          candidatos Consejo"<<endl;
        for (auto it3 =(*it).CandidatosConsejo.begin(); it3 != (*it).CandidatosConsejo.end(); ++it3){
            contPersona++;
            archivo<<"          "<<"persona "<< contPersona<<". "<<*it3<<endl;
        }
        contPersona=0;
        archivo<<"          habitantes"<<endl;
        for (auto it4 =(*it).listaHabitantes.begin(); it4 != (*it).listaHabitantes.end(); ++it4){
            contPersona++;
            archivo<<"          "<<"persona "<< contPersona<<". "<<*it4<<endl;
        }
        
     }   
    archivo<<"------------------------------------"<<endl;
}
}

#endif