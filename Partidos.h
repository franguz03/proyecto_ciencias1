#ifndef PARTIDOS_H
#include <iostream>
#define PARTIDOS_H
#include <Ciudades.h>
using namespace std;

struct Partidos{
    string nombre;
    string representante_legal;
    lista_ciudades ciudades_activas;
    Partidos *sig;
};

class lista_partidos{
        private:
    Ciudades *ciudad_inicial;

    public:
    lista_partidos();
    ~lista_partidos();
    void agregar_partido();
    void mostrar();
};





#endif