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

vector<Persona> generarVotos(vector<Persona> listaCandidatos, int votantes){
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

void simulacion(){
	srand(time(0));
	list<Ciudad> data = leer(); // SE LEE EL ARCHIVO ANTES DE INICIAR LA SIMULACIÓN, POR TANTO CUALQUIER EDICIÓN DEBE GUARDARSE EN EL ARCHIVO PLANO ANTES DE INICIAR LA SIMULACION
	for(const auto& ci : data){
		//POR CADA CIUDAD...
		vector<Persona> candidatosAlcaldiaCiudad, candidatosConsejoCiudad;
		int votantes = censoParticular(ci);
		
		//PARA CADA CIUDAD SE SACAN TODOS LOS CANDIDATOS DE ALCALDIA Y CONSEJO (de todos los partidos) y Se meten en el vector provisional correspondiente para tenerlos a todos juntos y generar los votos que no superen el total del censo
		for(const auto& partido: ci.listaPartidosHabilitados){ 
			candidatosAlcaldiaCiudad.push_back(partido.candidatoAlcaldia);
			for(const auto& persona: partido.listaCandidatosConsejo){
				candidatosConsejoCiudad.push_back(persona);
			}
		}
		
		Persona p("Blanco", "", 0, 'M', "", "", "", "");
		Persona p1("Anulado", "", 1, 'M', "", "", "", "");
		Persona p2("Abstinencia", "", 2, 'M', "", "", "", "");//Se agregan las 3 opciones obligatorias para cada elección como si fuesen un candidato más con su atributo votos
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
    	cout << "-------- Reporte por: " << ci.nombre << endl << endl << " ALCALDIA:" << endl; 
    	for(const auto& persona : candidatosAlcaldiaCiudad){
    		cout << "   " << persona.nombre << ", Votos:" << persona.votos << ", Porcentaje: " << (static_cast<float>(persona.votos) * 100) / votantes << "%" <<endl;
		} 
		
		cout << endl; 
		cout << " CONSEJO:" << endl; 
		for(const auto& persona : candidatosConsejoCiudad){
    		cout << "   " << persona.nombre << ", Votos:" << persona.votos << ", Porcentaje: " << (static_cast<float>(persona.votos) * 100) / votantes << "%" <<endl;
		}
		cout << endl;
		
		
	}
	//guardar(data);
}



