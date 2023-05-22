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


vector<string> splitString(const string& str, char delimiter) {//Funcion para splitear una cadena dado un delimitador
    vector<string> tokens;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void guardar(list<Ciudad> multilistaCiudad){
	ofstream archivo("datos.txt");
    for (auto itk = multilistaCiudad.begin(); itk != multilistaCiudad.end(); ++itk){// Entra a la multilista de ciudades y guarda los valores inicializables
        archivo <<*itk<< endl;
        for(auto it =(*itk).listaHabitantes.begin(); it != (*itk).listaHabitantes.end(); ++it){// Por cada ciudad, entra a la lista de habitantes y los guarda
        		archivo << " "<<*it<< endl;
		}
		for(auto it2 =(*itk).listaPartidosHabilitados.begin(); it2 != (*itk).listaPartidosHabilitados.end(); ++it2){// Por cada ciudad entra a la lista de partidos habilitados y guarda los valores inicializables de estos
        	archivo << endl <<"  "<<*it2<< endl;
        	for(auto it3 = (*it2).listaCandidatosConsejo.begin(); it3 != (*it2).listaCandidatosConsejo.end(); ++it3){//Por cada partido entra a la lista de candidatos al consejo y los guardo
        		archivo << "   "<<*it3<< endl;
			}
		}
		archivo << endl;
    }   
	archivo.close();
}
	

void leer(list<Ciudad> multilistaCiudad){
	ifstream archivo;
	archivo.open("datos.txt", ios::in);
	if(archivo.fail()){
		cout << "Problema al abrir el archivo" << endl;	
	}else{
		while(!archivo.eof()){
			string linea;
            getline(archivo,linea);
			//cout << linea << endl;
			if(linea[0] != ' ' && !linea.empty()){
				//Codigo para reconstruir una ciudad;
				
				//
				cout << "Ciudad: " << linea << endl;
			}else if(linea[1] != ' ' && !linea.empty()){
				//Codigo para reconstruir habitantes
				
				//
				cout << "Habitante: " << linea << endl;
			}else if(linea[2]!= ' ' && !linea.empty()){
				//Codigo para reconstruir partido
				
				//
				cout << "Partido: " << linea << endl;
				while(!linea.empty()){
					getline(archivo,linea);
					if(!linea.empty()){
						//Codigo para reconstruir candidatos al consejo
					
						//
					cout << "Consejo: " << linea << endl;	
					}
				}
			}
		}	
	}
	archivo.close();
}
#endif
