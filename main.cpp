#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <list>

#include "Ciudad.h"
#include "Persona.h"
#include "Archivos.h"
#include "Simulacion.h"
#include "funcionesAdicionales.h"

using namespace std;

void menu_consultas(list<Ciudad> multilistaCiudad);
void menu_principal();
void menu_modificacioines(list<Ciudad> multilistaCiudad);

int main(int argc, char *argv[]){
	menu_principal();
	//simulacion();
    return 0;
}



void menu_principal(){
    list<Ciudad> listaLecturaCiudades = leer();
    cout<<"programa de simulacion"<<"\n";
    cout<<"\n"<<"1. modificar datos"<<"\n"<<"2. consultar datos"<<"\n"<<"3. simular votaciones"<<"\n"<<"\n";
    int opcion;
    cout<<"ingrese su opcion: ";
    cin>>opcion;
    switch (opcion) {

        case 1:
            menu_modificacioines(listaLecturaCiudades);
            menu_principal();
        case 2:
            menu_consultas(listaLecturaCiudades);
            menu_principal();
        case 3:
            simulacion();
            menu_principal();
        default:
            std::cout << "OpciÃ³n invÃ¡lida" << std::endl;
            menu_principal();
       


    }
}

void menu_consultas(list<Ciudad> multilistaCiudad){
    cout<<"\n"<<"1. DADO UN PARTIDO Y UNA CIUDAD MOSTRAR LA LISTA DE SUS CANDIDATOS AL CONSEJO Y EL CANDIDATO A LA ALCALDIA"<<"\n"<<"2. DADO UN PARTIDO MOSTRAR LA LISTA DE CANDIDATOS A ALCALDIAS DE CADA UNA DE LAS DIFERENTES CIUDADES"<<"\n"<<"3. DADO UN PARTIDO MOSTRAR LAS LISTAS DE CANDIDATOS A CADA UNO DE DIFERENTES LOS CONSEJOS"<<"\n"<<"4. DADA UNA CIUDAD MOSTRAR POR CADA PARTIDO EL CANDIDATO A LA ALCALDIA Y LOS CANDIDATOS AL CONSEJO"<<"\n"<<"5. DADA UNA CIUDAD MOSTRAR EL TARJETON DE CANDIDATOS A LA ALCALDIA INCLUYENDO EL VOTO EN BLANCO"<<"\n"<<"6. DADA UNA CIUDAD MOSTRAR EL TARJETON DE CANDIDATOS AL CONSEJO INCLUYENDO EL VOTO EN BLANCO"<<"\n"<<"7. POR CADA CIUDAD MOSTRAR LA CANTIDAD DE PERSONAS HABILITADAS PARA VOTAR"<<"\n"<<"8. Volver atras"<<"\n"<<"\n";
    int opcion;
    cin>>opcion;
    string ciudad;
    string partido;
    switch (opcion)
    {
    case 1:
        cout << "Introduce la partido: ";
        cin>> partido;
        cout << "Introduce la ciudad: ";
        cin>>ciudad;
        candidatos_ciudad_partido(multilistaCiudad,ciudad,partido);
        menu_consultas(multilistaCiudad);

    case 2:
        cout << "Introduce la partido: ";
        cin>> partido;
        alcaldia_ciudad(multilistaCiudad,partido);
        menu_consultas(multilistaCiudad);

    case 3:
        cout << "Introduce la partido: ";
        cin>> partido;
        consejo_ciudad(multilistaCiudad,partido);
        menu_consultas(multilistaCiudad);
    
    case 4:
        cout << "Introduce la ciudad: ";
        cin>>ciudad;
        alcaldia_consejo_ciudad(multilistaCiudad,ciudad);
        menu_consultas(multilistaCiudad);

    case 5:
        cout << "Introduce la ciudad: ";
        cin>>ciudad;
        tarjeton_Ciudad_Alcaldia(multilistaCiudad,ciudad);
        menu_consultas(multilistaCiudad);

    case 6:
        cout << "Introduce la ciudad: ";
        cin>>ciudad;
        tarjeton_Ciudad_Consejo(multilistaCiudad,ciudad);
        menu_consultas(multilistaCiudad);

    case 7:
        censo_Electoral(multilistaCiudad);
        menu_consultas(multilistaCiudad);

    case 8:
        menu_principal();

    default:
        cout<<"opcioin no valida";
        menu_consultas(multilistaCiudad);
        
    }
}
void menu_modificacioines(list<Ciudad> multilistaCiudad){

    cout<<"\n"<<"1. AGREGAR UN CANDIDATO-ALCALDIA SEGUN CIUDAD Y PARTIDO"<<"\n"<<"2. AGREGAR UN CANDIDATO-CONSEJO SEGUN CIUDAD Y PARTIDO"<<"\n"<<"3. AGREGAR UN PARTIDO SEGUN CIUDAD"<<"\n"<<"4. AGREGAR CIUDAD"<<"\n"<<"5. ELIMINAR UN CANDIDATO-CONSEJO SEGUN CIUDAD Y PARTIDO"<<"\n"<<"6. ELIMINAR UN PARTIDO SEGUN CIUDAD"<<"\n"<<"7. ELIMINAR CIUDAD"<<"\n"<<"8. VOLVER ATRAS"<<"\n";
    int opcion;
    cin>>opcion;
    string ciudad;
    string partido;
    string candidato;
    switch (opcion)
    {
    case 1:
        cout << "Introduce el partido: ";
        cin>>partido;
        cout << "Introduce la ciudad: ";
        cin>>ciudad;
        agregar_candidato_alcaldia(multilistaCiudad,ciudad,partido);
        menu_modificacioines(multilistaCiudad);
    case 2:
        cout << "Introduce el partido: ";
        cin>>partido;
        cout << "Introduce la ciudad: ";
        cin>>ciudad;
        agregar_candidato_consejo(multilistaCiudad,ciudad,partido);
        menu_modificacioines(multilistaCiudad);
    case 3:
        cout << "Introduce la ciudad: ";
        cin>>ciudad;
        agregar_partido(multilistaCiudad,ciudad);
        menu_modificacioines(multilistaCiudad);
    case 4:
        agregar_ciudad(multilistaCiudad);
        menu_modificacioines(multilistaCiudad);
    case 5:
        cout<< "Introduce el nombre del candidato: ";
        cin>>candidato;
        cout << "Introduce el partido: ";
        cin>>partido;
        cout << "Introduce la ciudad: ";
        cin>>ciudad;
        eliminar_candidato_consejo(multilistaCiudad,ciudad,partido,candidato);
        menu_modificacioines(multilistaCiudad);
    case 6:
        cout << "Introduce la ciudad: ";
        cin>>ciudad;
        cout << "Introduce la partido: ";
        cin>>partido;
        eliminar_partido(multilistaCiudad,ciudad,partido);
        menu_modificacioines(multilistaCiudad);
    case 7:
        cout << "Introduce la ciudad: ";
        cin>>ciudad;
        eliminar_ciudad(multilistaCiudad,ciudad);
        menu_modificacioines(multilistaCiudad);
    case 8:
        menu_principal();
    
    
    default:
        cout<<"opcion no valida";
        menu_modificacioines(multilistaCiudad);
    }


}

	

