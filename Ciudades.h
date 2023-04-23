#ifndef CIUDADES_H
#include <iostream>
#define CIUDADES_H
#include <Candidatos.h>
using namespace std;

struct Ciudades
{
    /* data */
    string nombre;
    string departamento;
    int tamaño_consejo;
    lista_candidatos consejo;
    lista_candidatos alcaldia;
    Candidatos alcalde;
    Ciudades *sig;
    
};
class lista_ciudades{
    private:
    Ciudades *ciudad_inicial;

    public:
    lista_ciudades();
    ~lista_ciudades();
    void agregar_ciudad();
    void mostrar();
};

#endif
