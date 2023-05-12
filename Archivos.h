#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <list>
#include <stdlib.h>
#include <string.h>
#include <fstream>

#include "Ciudad.h"
#include "Persona.h"
#include "Partido.h"

using namespace std;



void guardar(list<Partido> multilistaPartido){
    
	ofstream archivo("datos.txt");
    int contPartido=0;
    
    for (auto itk =multilistaPartido.begin(); itk != multilistaPartido.end(); ++itk){
        archivo <<*itk<< endl;
     	for (auto it =(*itk).ciudadesActivas.begin(); it != (*itk).ciudadesActivas.end(); ++it){//accede a la multilista de ciudad, utiliza begin como itedaror que se guarda en it
        	archivo << endl <<" "<<*it<< endl;//guarda las propiedades de it en el txt
        	//Empieza a guardar los de la alcaldia
        	for (auto it2 =(*it).CandidatosAlcaldia.begin(); it2 != (*it).CandidatosAlcaldia.end(); ++it2){//accede a la lista de alcaldia del iteraor it y lo guarda en it2
            	archivo<<"  "<<*it2<<endl;//guarda las propiedades de it2(persona) en el txt
        	}
        	
        	archivo << endl; //Empieza a guardar los del consejo
        	for (auto it3 =(*it).CandidatosConsejo.begin(); it3 != (*it).CandidatosConsejo.end(); ++it3){
	            archivo<<"  "<<*it3<<endl;
    	    }
    	    
        	archivo << endl; //Empieza a guardar los habitantes
        	for (auto it4 =(*it).listaHabitantes.begin(); it4 != (*it).listaHabitantes.end(); ++it4){
            	archivo <<"  "<<*it4<<endl;
        	}
     }   
    archivo<<endl;
	}
	
	archivo.close();
}

void leer(list<Partido> multilistaPartido){
	ifstream archivo;
	archivo.open("datos.txt", ios::in);
	
	if(archivo.fail()){
		cout << "Problema al abrir" << endl;	
	}else{
		while(!archivo.eof()){	
			string linea;
            getline(archivo,linea);
			if (!linea.empty() && linea[0] == '@') {
                cout << linea << endl;
            }
		}
		archivo.close();
	}
}

#endif
