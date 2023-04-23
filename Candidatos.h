#ifndef CANDIDATOS_H
#include <iostream>
#define CANDIDATOS_H
using namespace std;
#include <time.h>


struct Candidatos
{
    /* data */
    string nombre;
    string apellido;
    long int identificacion;
    string estado_civil;
    struct tm fecha;
    /*
    Establecer la fecha deseada
    fecha.tm_year = 123; // Año 2023 (1900 + 123)
    fecha.tm_mon = 3; // Mes abril (0-11)
    fecha.tm_mday = 23; // Día 23
    */
    string ciudad_nacimiento;
    string ciudad_residencia; // solo pueden postularse donde habitan
    Candidatos *sig;
};


class lista_candidatos
{
private:
Candidatos *inicial;

public:
    lista_candidatos(/* args */);
    ~lista_candidatos();
    void agregar_candidato();
    void mostrar_candidatos();
};

#endif