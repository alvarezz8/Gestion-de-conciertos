/*
    Autor:
    Mario Álvarez Gracia
*/
#ifndef UNIZAR_H_INCLUDED
#define UNIZAR_H_INCLUDED
#include <iostream>
#include "conciertos.h"
using namespace std;

// Interfaz del TAD estudiante. Pre-declaraciones
struct estudiante;
void crearEstudiante(string nom, string tit, estudiante& e);
string nombre(const estudiante& e);
string tit(const estudiante& e);

string mostrarAsignaturas(const estudiante& e);
void asignarConcierto(int id, int precio, estudiante& e);

string mostrarConciertos(const estudiante& e);


string infoEstudiante(const estudiante& e);
const int MAX_CONCIERTOS = 40;


// Declaración:
struct estudiante {
    friend void crearEstudiante(string nom, string tit, estudiante& e);
    friend string nombre(const estudiante& e);
    friend string tit(const estudiante& e);

    friend void asignarConcierto(int id, int precio, estudiante& e);
    friend string mostrarAsignaturas(const estudiante& e);

    friend string infoEstudiante(const estudiante& e);
    friend string mostrarConciertos(const estudiante& e);
    private: // Declaración interna del tipo
        string nombre;
        string titulacion;
        struct concierto{
            int id;
            int precio;
        };
        concierto conciertoss[MAX_CONCIERTOS];
        int numConciertos;
        int sumaPrecio;

};





#endif
