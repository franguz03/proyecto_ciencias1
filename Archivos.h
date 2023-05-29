#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <algorithm>
#include <cctype>
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



std::string eliminarEspaciosBlanco(const std::string& texto) {//cumple una funcion en la correcta construccion de las estructuras a partir del archivo datos.txt y el metodo leer
    std::string resultado = texto;
    resultado.erase(std::remove_if(resultado.begin(), resultado.end(), [](unsigned char c) {
        return std::isspace(c);
    }), resultado.end());
    return resultado;
}

vector<string> splitString(const string& str, char delimiter) {//Funcion para splitear una cadena dado un delimitador
    vector<string> tokens;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void guardar(list<Ciudad> multilistaCiudad){//ese utiliza para actualizar el archivo datos.txt a partir de las funciones de modificacion
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
	

list<Ciudad> leer(){// construye las estructuras a partir del archivo datos.txt 
	list<Ciudad> multilistaCiudad;
	int numCiudades = 0;
	int numPartidos = 0;
	ifstream archivo;
	archivo.open("datos.txt", ios::in);
	if(archivo.fail()){
		cout << "Problema al abrir el archivo" << endl;	
	}else{
		cout<<"\n"<< "leyendo..." << endl;
		while(!archivo.eof()){
			string linea;
            getline(archivo,linea);
			if(linea[0] != ' ' && !linea.empty()){
				//Codigo para reconstruir una ciudad;
				vector<string> data = splitString(linea,',');
				Ciudad c(eliminarEspaciosBlanco(data[0]),data[1],stoi(data[2]));
				multilistaCiudad.push_back(c);
				numCiudades++;
				numPartidos = 0;
			}else if(linea[1] != ' ' && !linea.empty()){
				//Codigo para reconstruir habitantes
				vector<string> data = splitString(linea,',');
            	Persona p(eliminarEspaciosBlanco(data[0]),data[1],stol(data[5]),data[6][0],data[2],data[3],data[4],data[7]);
           		list<Ciudad>::iterator it = multilistaCiudad.begin();
           		advance(it,numCiudades-1);
           		it->listaHabitantes.push_back(p);
			}else if(linea[2]!= ' ' && !linea.empty()){
				//Codigo para reconstruir partido
				vector<string> data = splitString(linea,'-');
            	vector<string> data2 = splitString(data[1],',');
            	vector<string> data3 = splitString(data[2],',');
            	Persona repre(eliminarEspaciosBlanco(data2[0]),data2[1],stol(data2[5]),data2[6][0],data2[2],data2[3],data2[4],data2[7]);
            	Persona candi(eliminarEspaciosBlanco(data3[0]),data3[1],stol(data3[5]),data3[6][0],data3[2],data3[3],data3[4],data3[7]);
            	Partido p(eliminarEspaciosBlanco(data[0]),repre,candi);
            	list<Ciudad>::iterator it = multilistaCiudad.begin();
            	advance(it,numCiudades-1);
            	it->listaPartidosHabilitados.push_back(p);
				while(!linea.empty()){
					getline(archivo,linea);
					if(!linea.empty()){
						//Codigo para reconstruir candidatos al consejo
						vector<string> data = splitString(linea,',');
						Persona p(eliminarEspaciosBlanco(data[0]) ,data[1],stol(data[5]),data[6][0],data[2],data[3],data[4],data[7]);
						list<Partido>::iterator it2 = it->listaPartidosHabilitados.begin();
						advance(it2,numPartidos);
						it2->listaCandidatosConsejo.push_back(p);
						// cout << "Num: "<< numPartidos << " Consejo: " << linea << endl;	
					}	
				}
				numPartidos++;
			}	
		}
	archivo.close();
	}
	return multilistaCiudad;
}


#endif
