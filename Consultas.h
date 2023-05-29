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
#include "Archivos.h"
#include "funcionesAdicionales.h"

using namespace std;
// consulta 0 lista de ciudades 
void listciudad(list<Ciudad> multilistaCiudad){
	for (const auto& ciudad : multilistaCiudad) {
		cout<< ciudad.nombre << "\n ";
	}
	}
//

void partidosporciudad(list<Ciudad> multilistaCiudad){
	for (const auto& ciudad : multilistaCiudad) {
		cout<< ciudad.nombre << "\n ";
		for (const auto& PARTIDO : ciudad.listaPartidosHabilitados) {
			cout<<"---" <<PARTIDO.nombre << "\n ";
	}

	}
	}

// ------------ CONSULTA #1 DADO UN PARTIDO Y UNA CIUDAD MOSTRAR LA LISTA DE SUS CANDIDATOS AL CONSEJO Y EL CANDIDATO A LA ALCALDIA
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

// ------------ CONSULTA #2 DADO UN PARTIDO MOSTRAR LA LISTA DE CANDIDATOS A ALCALDIAS DE CADA UNA DE LAS DIFERENTES CIUDADES
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

// ------------ CONSULTA #3 DADO UN PARTIDO MOSTRAR LAS LISTAS DE CANDIDATOS A CADA UNO DE DIFERENTES LOS CONSEJOS
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

// ------------ CONSULTA #4 DADA UNA CIUDAD MOSTRAR POR CADA PARTIDO EL CANDIDATO A LA ALCALDIA Y LOS CANDIDATOS AL CONSEJO
void alcaldia_consejo_ciudad(list<Ciudad> multilistaCiudad, string nombreCiudad){
	bool existe = false;
	for(const auto& ciudad : multilistaCiudad){
		if(ciudad.nombre == nombreCiudad){
			cout << ciudad.nombre << endl;
			for(const auto& partido : ciudad.listaPartidosHabilitados){
				cout << "Candidato por el partido " << partido.nombre << " a Alcaldia: " << partido.candidatoAlcaldia << endl;
				cout<<"	lista de consejo: "<<"\n";
				for(const auto& persona: partido.listaCandidatosConsejo){
					cout << "-" << persona << endl;
				}
			}	
			existe = true;
		}	
	}
	if(!existe){
		cout << "la ciudad " << nombreCiudad << " no esta registrada" << endl;
	}
}

// ------------ CONSULTA #5 DADA UNA CIUDAD MOSTRAR EL TARJETON DE CANDIDATOS A LA ALCALDIA INCLUYENDO EL VOTO EN BLANCO
void tarjeton_Ciudad_Alcaldia(list<Ciudad> multilistaCiudad, string nombreCiudad){
	bool existe = false;
	int num = 1;
	for(const auto& ciudad : multilistaCiudad){
		if(ciudad.nombre == nombreCiudad){
			cout << "Tarjeton a alcaldia de "<< ciudad.nombre << endl;
			cout << "0. Voto en Blanco" << endl; 	
			for(const auto& partido : ciudad.listaPartidosHabilitados){
				
				cout << num++ << ". Candidato por el partido " << partido.nombre << endl;
				cout << "  " << partido.candidatoAlcaldia.nombre << " "<< partido.candidatoAlcaldia.apellido <<endl;
				
			}
			existe = true;
		}	
	}
	if(!existe){
		cout << "la ciudad " << nombreCiudad << " no esta registrada para la simulaci�n" << endl;
	}
}

// ------------ CONSULTA #6 DADA UNA CIUDAD MOSTRAR EL TARJETON DE CANDIDATOS AL CONSEJO INCLUYENDO EL VOTO EN BLANCO
void tarjeton_Ciudad_Consejo(list<Ciudad> multilistaCiudad, string nombreCiudad){
	bool existe = false;
	int num = 1;
	for(const auto& ciudad : multilistaCiudad){
		if(ciudad.nombre == nombreCiudad){
			cout << "Tarjeton al consejo de "<< ciudad.nombre << endl;
			cout << "0. Voto en Blanco" << endl; 	
			for(const auto& partido : ciudad.listaPartidosHabilitados){
				int num2 = 1;
				cout << num << ". Candidatos por el partido " << partido.nombre << endl;
				for(const auto& persona: partido.listaCandidatosConsejo){
					cout << "  " <<num << "."<< num2++ << " "<< persona.nombre << " "<< persona.apellido <<endl;
				}
				num++;
			}	
			existe = true;
		}	
	}
	if(!existe){
		cout << "la ciudad " << nombreCiudad << " no esta registrada para la simulaci�n" << endl;
	}
}

// ------------ CONSULTA #7 POR CADA CIUDAD MOSTRAR LA CANTIDAD DE PERSONAS HABILITADAS PARA VOTAR
int censo_Electoral(list<Ciudad> multilistaCiudad){ // Por cada ciudad, mostrara la cantidad de personas habilitadas para votar 
	int votantes = 0;
	
	for(const auto& ciudad : multilistaCiudad){
		cout << "Censo para " << ciudad.nombre << endl;
		int votantes_ciudad=0;
		for(const auto& persona : ciudad.listaHabitantes){
			cout << persona.nombre << " " << persona.apellido <<", fecha de nacimiento: " << persona.fechaNacimiento <<", Edad: " << calcularEdad(persona.fechaNacimiento) << endl;
			if(calcularEdad(persona.fechaNacimiento)>18){
				votantes++;
				votantes_ciudad++;
			}

		}	
		cout<<"cantidad por "<<ciudad.nombre<<" : "<<votantes_ciudad;
		cout << endl;
	}
	cout << "Cantidad de personas habilitadas para votar: " << votantes;
	return votantes;	
}


#endif
