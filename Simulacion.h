#ifndef SIMULACION_H
#define SIMULACION_H
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <list>

#include "Ciudad.h"
#include "Persona.h"
#include "Archivos.h"
#include "Consultas.h"

using namespace std;

void generarVotos(vector<Persona> listaCandidatos, int votantes){//simula de manera aleatoria el umero de votos por candidato usando el numero de votantes habilitados por ciudad
	int votantesRestantes = votantes;
	for(auto& persona : listaCandidatos){
			if (votantesRestantes == 0) {
            	persona.votos = 0;
        	} else {
            	int voto = std::rand() % (votantesRestantes + 1);
            	persona.votos = voto;
            	votantesRestantes -= voto;
        	}
		}
}

void estadisticas(list<Ciudad> listaCiudades){// una vez hecha la simulacion muestra las estadisticas de los votos por porcentaje y sexo
	cout << endl << endl << "-----------------------------------  ESTADISTICAS  -----------------------------------"<< endl << endl;
	struct aux{
		string nombre;
		int TotalNacional = 0, TotalNacionalF = 0, TotalNacionalM = 0;
		
		aux(const string& nom) : nombre(nom) {}
	};
	int poblacionNacional = 0;
	vector<aux> partidos;
	for(const auto& ciudad : listaCiudades){
		int votantes = censoParticular(ciudad);
		poblacionNacional += votantes;
		cout << ciudad.nombre << ": " << endl;
		for(auto& partido : ciudad.listaPartidosHabilitados){
			string nom = partido.nombre;  
			auto it = std::find_if(partidos.begin(), partidos.end(), [&partido, &nom](aux& a) {
        		nom = a.nombre;
				return a.nombre == partido.nombre;
    		});
    		if (it != partidos.end()) {
    				for(auto& persona : partido.listaCandidatosConsejo){
						it->TotalNacional += persona.votos;
						if(persona.sexo == 'F'){
							it->TotalNacionalF += persona.votos;
						}else{
							it->TotalNacionalM += persona.votos;
						}
					}
    		} else {
        		aux nuevoAux{partido.nombre};
        		for(auto& persona : partido.listaCandidatosConsejo){
						nuevoAux.TotalNacional += persona.votos;
						if(persona.sexo == 'F'){
							nuevoAux.TotalNacionalF += persona.votos;
						}else{
							nuevoAux.TotalNacionalM += persona.votos;
						}
					}
        		partidos.push_back(nuevoAux);
    		}
			
			int totalPartido = 0, totalM = 0, totalF = 0;
			cout << " - " << partido.nombre << ": ";
			for(auto& persona : partido.listaCandidatosConsejo){
				totalPartido += persona.votos;
				if(persona.sexo == 'F'){
					totalF += persona.votos;
				}else{
					totalM += persona.votos;
				}
			}
			cout << "Total votos: " << totalPartido << " / " << (static_cast<float>(totalPartido) * 100) / votantes << "%, ";
			cout << "Total M: " << totalM << " -> " << (static_cast<float>(totalM) * 100) / votantes << "%, ";
			cout << "Total F: " << totalF << " -> " << (static_cast<float>(totalF) * 100) / votantes << "%" << endl;
		}
	}cout << endl << endl << "-----------------------------------  ESTADISTICA NACIONAL -----------------------------------" << endl << endl;
		for (const auto& partido : partidos) {
        	cout << "Nombre: " << partido.nombre << std::endl;
        	cout << "Total votos: " << partido.TotalNacional << " -> " << (static_cast<float>(partido.TotalNacional) * 100) / poblacionNacional << "%, ";
			cout << "Total M: " << partido.TotalNacionalM << " -> " << (static_cast<float>(partido.TotalNacionalM) * 100) / poblacionNacional << "%, ";
			cout << "Total F: " << partido.TotalNacionalF << " -> " << (static_cast<float>(partido.TotalNacionalF) * 100) / poblacionNacional << "%" << endl;
    	}	
}

void simulacion(){// funcion principal que simula el proceso, muestra al final los resultados y las estadisticas
	srand(time(0));
	list<Ciudad> data = leer();
	for( auto& ci : data){
		Persona* ganador = nullptr;
		//POR CADA CIUDAD...
		vector<Persona> candidatosAlcaldiaCiudad, candidatosConsejoCiudad;
		int votantes = censoParticular(ci);
		int posicion=0;
		int canditadconsejoporpartido[ci.listaPartidosHabilitados.size()];
		string nombrespartidos [ci.listaPartidosHabilitados.size()];
		//PARA CADA CIUDAD SE SACAN TODOS LOS CANDIDATOS DE ALCALDIA Y CONSEJO (de todos los partidos) y Se meten en el vector provisional correspondiente para tenerlos a todos juntos y generar los votos que no superen el total del censo
		for(const auto& partido: ci.listaPartidosHabilitados){ 
			canditadconsejoporpartido[posicion]=0;
			nombrespartidos[posicion]=partido.nombre;
			candidatosAlcaldiaCiudad.push_back(partido.candidatoAlcaldia);
			for(const auto& persona: partido.listaCandidatosConsejo){
				candidatosConsejoCiudad.push_back(persona);
				canditadconsejoporpartido[posicion]++;
			}
			posicion++;
		}
		
		Persona p("Blanco", "", 0, 'M', "", "", "", "");
		Persona p1("Anulado", "", 1, 'M', "", "", "", "");
		Persona p2("Abstinencia", "", 2, 'M', "", "", "", "");//Se agregan las 3 opciones obligatorias para cada elecci�n como si fuesen un candidato m�s con su atributo votos
		candidatosAlcaldiaCiudad.push_back(p);
		candidatosAlcaldiaCiudad.push_back(p1);
		candidatosAlcaldiaCiudad.push_back(p2);
		
		candidatosConsejoCiudad.push_back(p);
		candidatosConsejoCiudad.push_back(p1);
		candidatosConsejoCiudad.push_back(p2);
		
		// GENERA LOS VOTOS PARA CONSEJO Y ALCALDIA
    	int votantesRestantes = votantes;
		for(auto& persona : candidatosAlcaldiaCiudad){//Genera numeros aleatorios para cada "persona"(candidato) tomando como max los votantes restantes y los asigna al candidato
			if (votantesRestantes == 0) { //Si por casualidad se genera el maximo asigna 0 votos a todos los que falten
            	persona.votos = 0;
        	} else {
            	int voto = std::rand() % (votantesRestantes + 1);
            	persona.votos = voto;
            	votantesRestantes -= voto;
        	}
		}
		if (!candidatosAlcaldiaCiudad.empty()) { //Si sobra algun voto se los asigna al ultimo candidato
    		candidatosAlcaldiaCiudad.back().votos += votantesRestantes;
		}
		
		votantesRestantes = votantes; // reinicia la cuenta de los votos restantes y hace el mismo proceso pero para consejo
		for(auto& persona : candidatosConsejoCiudad){
			if (votantesRestantes == 0) {
            	persona.votos = 0;
        	} else {
            	int voto = std::rand() % (votantesRestantes + 1);
            	persona.votos = voto;
            	votantesRestantes -= voto;
        	}
		}
		if (!candidatosConsejoCiudad.empty()) {
    		candidatosConsejoCiudad.back().votos += votantesRestantes;
		}

		// SE IMPRIMEN LOS REPORTES
    	cout <<"\n"<< "-------- Reporte por: " << ci.nombre << endl << endl << " ALCALDIA:" << endl; 

		int fr=0;
    	for(const auto& persona : candidatosAlcaldiaCiudad){
			if(persona.nombre!="Blanco"&&persona.nombre!="Anulado"&&persona.nombre!="Abstinencia"){
    			cout << "   " << persona.nombre << ", Votos:" << persona.votos << ", Porcentaje: " << (static_cast<float>(persona.votos) * 100) / votantes << "%"<<"-----partido : "<< nombrespartidos[fr]<<endl;
				fr++;
				if (ganador == nullptr || persona.votos > ganador->votos) {
            		ganador = const_cast<Persona*>(&persona);  // Asignar la direcci�n de memoria de persona al puntero ganador
        		}
			}
			else{
				cout << "   " << persona.nombre << ", Votos:" << persona.votos << ", Porcentaje: " << (static_cast<float>(persona.votos) * 100) / votantes << "%"<<endl;
			}
		} 
		cout << "   GANADOR: " << ganador->nombre << " " << ganador->apellido << ", Votos:" << ganador->votos << ", Porcentaje: " << (static_cast<float>(ganador->votos) * 100)/votantes << "%";

		ganador = nullptr;
		cout << endl; 
		cout << " CONSEJO:" << endl; 
		int posicionpartido=0;
		int cantidad=0;
		for(const auto& persona : candidatosConsejoCiudad){
			if(persona.nombre!="Blanco"&&persona.nombre!="Anulado"&&persona.nombre!="Abstinencia"){
    			cout << "   " << persona.nombre << ", Votos:" << persona.votos << ", Porcentaje: " << (static_cast<float>(persona.votos) * 100) / votantes << "%" <<"-----partido : "<< nombrespartidos[posicionpartido]<<endl;
    			if (ganador == nullptr || persona.votos > ganador->votos) {
            		ganador = const_cast<Persona*>(&persona);  // Asignar la direcci�n de memoria de persona al puntero ganador
        		}
				cantidad++;
				if(cantidad>=canditadconsejoporpartido[posicionpartido]){
					posicionpartido++;
					cantidad=0;
				}
			}
			else{
				cout << "   " << persona.nombre << ", Votos:" << persona.votos << ", Porcentaje: " << (static_cast<float>(persona.votos) * 100) / votantes << "%" <<endl;
			}
		}
		cout << "   GANADOR: " << ganador->nombre << " " << ganador->apellido << ", Votos:" << ganador->votos << ", Porcentaje: " << (static_cast<float>(ganador->votos) * 100)/votantes << "%";
		cout << endl;
		int counter = 0;
		int i = 0;
		for(auto& partido: ci.listaPartidosHabilitados){// ASIGNA los votos a cada candidato en la lista original
			if(partido.candidatoAlcaldia.identificacion == candidatosAlcaldiaCiudad[counter].identificacion){
				partido.candidatoAlcaldia.votos = candidatosAlcaldiaCiudad[counter].votos;
			}
			for(auto& persona: partido.listaCandidatosConsejo){
				if(persona.identificacion == candidatosConsejoCiudad[i].identificacion){
					persona.votos = candidatosConsejoCiudad[i].votos;
				}
				i++;
			}
			counter++;
		}
	}
	estadisticas(data);
	guardar(data);	
}


#endif


