#ifndef ARCHIVOS_H
#define ARCHIVOS_H

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


vector<string> splitString(const string& str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void guardar(list<Partido> multilistaPartido){
    
	ofstream archivo("datos.txt");
    int contPartido=0;
    
    for (auto itk =multilistaPartido.begin(); itk != multilistaPartido.end(); ++itk){
        archivo <<*itk<< endl;
     	for (auto it =(*itk).ciudadesActivas.begin(); it != (*itk).ciudadesActivas.end(); ++it){//accede a la multilista de ciudad, utiliza begin como itedaror que se guarda en it
        	archivo << endl << " "<<*it<< endl;//guarda las propiedades de it en el txt
        	
        	archivo << "  " << (*it).CandidatoAlcaldia << endl;//Guarda el candidato a la alcaldia
        	
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
            if(linea[0] != ' ' && !linea.empty()){
				vector<string> Split1 = splitString(linea,'-');
            	vector<string> Split2 = splitString(Split1[1],',');
				long int x = stol(Split2[5]);
				char y = Split2[6][0];
            	Persona p(Split2[0],Split2[1],stol(Split2[5]),Split2[6][0],Split2[2],Split2[3],Split2[4],Split2[7]);
            	Partido pa(Split1[0],p);
				multilistaPartido.push_back(pa);
				cout << "Partido: "<< linea << endl;
			} else if(linea[1] != ' '){
				if(!linea.empty()){
					//CODIGO PARA PUSHEAR CIUDAD
					vector<string> Split1 = splitString(linea,'-');	
					//
					cout << "Ciudad: "<< linea << endl;
				}
			} else if(linea[2] != ' '){
				while(!linea.empty()){
					// CODIGO PARA PUSHEAR CANDIDATOS ALCALDIA
					
					//
    				cout << "Alcaldia: " << linea << endl;
					getline(archivo,linea);
				}
				getline(archivo,linea);
				while(!linea.empty()){
					// CODIGO PARA PUSHEAR CANDIDATOS CONSEJO
					
					//
    				cout << "Consejo: " << linea << endl;
					getline(archivo,linea);
				}
				getline(archivo,linea);
				while(!linea.empty()){ 				
					// CODIGO PARA PUSHEAR PERSONAS 
					
					//
    				cout << "Persona: " << linea << endl;
					getline(archivo,linea);
				}
			}
    	}
	}
		archivo.close();
}




#endif
