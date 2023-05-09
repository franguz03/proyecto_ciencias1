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

void leer(){
	ifstream data;
	data.open("datos.txt",ios::in);
	
	if(data.fail()){
		cout << "problema al abrir";
	}else{
		cout << "Todo bien, El archivo comienza aqui: " << endl;
		while(!data.eof()){
			string x;
			getline(data,x);
			int num_tabs = 0;
    		size_t pos = x.find("@");
    		while(pos == 0){
        		num_tabs++;
        		pos = x.find("@", pos+1); // Busca la siguiente ocurrencia de una tabulación
    		}

    		if(num_tabs == 1){ 
        		cout << x << endl;
        		cout << "..." << endl;
			}	
			archivo.close();
		}
	}
}
#endif
