/*
    Autor:
    Mario Álvarez Gracia
*/

#ifndef ESTUDIANTES_H_INCLUDED
#define ESTUDIANTES_H_INCLUDED

//#ifndef _ESTUDIANTES_
//#define _ESTUDIANTES_
#include <iostream>
#include <sstream>
#include "unizar.h"

using namespace std;

template<typename V> struct estudiantes;

template<typename V> void crear(estudiantes<V>& est);
template<typename V> int cardinal(const estudiantes<V>& est);
template<typename V> bool esVacia(const estudiantes<V>& est);
template<typename V> void anyadir(estudiantes<V>& est,const V& v);
template<typename V> int actualizarCandidato(estudiantes<V>& est, const V& v);

template<typename V> void obtenerCandidatoSuValoryClave(const estudiantes<V>& est, V& v);

template<typename V> struct estudiantes {

    friend void crear<V>(estudiantes<V>& est);
    friend int cardinal<V>(const estudiantes<V>& est);
    friend bool esVacia<V>(const estudiantes<V>& est);
    friend void anyadir<V>(estudiantes<V>& est, const V& v);
    friend int actualizarCandidato<V>(estudiantes<V>& est, const V& v);
    friend void obtenerCandidatoSuValoryClave<V>(const estudiantes<V>& est, V& v);

private:
    bool inscripcion;
    bool matricula;
    int total;

    struct estudiante{
        V valor;
        estudiante* sig;
    };
    estudiante* iterador;
    estudiante* primerEstudiante;
};

//{Devuelve una “agrupación de estudiantes” de selección vacía, sin elementos (pares), y en estado de Inscripción.}
template<typename V> void crear(estudiantes<V>& est){
    est.primerEstudiante = nullptr;
    est.total = 0;
    est.matricula = false;
    est.inscripcion = true;
};

//{Devuelve el nº de elementos (de pares) en la “agrupación de estudiantes” est}
template<typename V> int cardinal(const estudiantes<V>& est){
    return est.total;
};

//{Devuelve verdad si y sólo si est no tiene elementos}
template<typename V> bool esVacia(const estudiantes<V>& est){
    return est.total == 0;
};

template<typename V> void anyadir(estudiantes<V>& est, const V& v){

        est.primerEstudiante = new typename estudiantes<V>::estudiante;
        est.primerEstudiante->valor = v;
        est.total++;
}

template<typename V> void obtenerCandidatoSuValoryClave(const estudiantes<V>& est, V& v){
  //  c = est.primerEstudiante->clave;
    v = est.primerEstudiante->valor;
}

template<typename V> int actualizarCandidato(estudiantes<V>& est, const V& v){
        est.primerEstudiante->valor = v;
        return 1;
}

#endif // ESTUDIANTES_H_INCLUDED
