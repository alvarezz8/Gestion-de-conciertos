/*
    Autor:
    Mario Álvarez Gracia
*/
#ifndef CONCIERTOS_H_INCLUDED
#define CONCIERTOS_H_INCLUDED

#include <iostream>
#include <sstream>
#include "piladinamica.h"
#include "unizar.h"
#include "evento.h"
using namespace std;

template<typename K, typename V> struct conciertos;
template<typename K, typename V> void crearConcierto(conciertos<K,V>& c);
template<typename K, typename V> bool esVacio(const conciertos<K,V>& c);
template<typename K, typename V> bool existeClave(const conciertos<K,V>& c, const K& k, V& v);
template<typename K, typename V> void insertar(conciertos<K,V>& c, const K& k, const V& v);
template<typename K, typename V> bool obtenerDato(const conciertos<K,V>& c, const K& k, V& v);
template<typename K, typename V> void borrar(conciertos<K,V>& c, const K& k);
template<typename K, typename V> int tamanyo(const conciertos<K,V>& c);
template<typename K, typename V> string listar(conciertos<K,V>& c);
template<typename K, typename V> void iniciarIterador(conciertos<K,V>& c);
template<typename K, typename V> bool existeSiguiente(const conciertos<K,V>& c);
template<typename K, typename V> bool siguiente(conciertos<K,V>& c, K& k, V& v);
template<typename K, typename V> bool mayorClave(conciertos<K,V>& c, K& mayor);
template<typename K, typename V> void avanza(conciertos<K,V>& c);

template<typename K, typename V> void insertarRec(typename conciertos<K,V>::NodoBinario*& nodo, const K& k, const
V& v, bool& metido);

template<typename K, typename V> void borrarRec(typename conciertos<K,V>::NodoBinario*& nodo, const K& k, bool&
borrado);
template<typename K, typename V> void BorrarMaximo(typename conciertos<K,V>::NodoBinario* nodo, K& k, V& v);

template<typename K, typename V> void buscarRec(typename conciertos<K,V>::NodoBinario* nodo, const K& k, V& v, bool& exito);

template<typename K, typename V>
struct conciertos {
    friend void crearConcierto<K,V>(conciertos<K,V>& c);
    friend bool esVacio<K,V>(const conciertos<K,V>& c);
    friend bool existeClave<K,V>(const conciertos<K,V>& c, const K& k, V& v);
    friend void insertar<K,V>(conciertos<K,V>& c, const K& k, const V& v);
    friend bool obtenerDato<K,V>(const conciertos<K,V>& c, const K& k, V& v);
    friend void borrar<K,V>(conciertos<K,V>& c, const K& k);
    friend int tamanyo<K,V>(const conciertos<K,V>& c);
    friend string listar<K,V>(conciertos<K,V>& c);
    friend void iniciarIterador<K,V>(conciertos<K,V>& c);
    friend bool existeSiguiente<K,V>(const conciertos<K,V>& c);
    friend bool siguiente<K,V>(conciertos<K,V>& c, K& k, V& v);
    friend bool mayorClave<K,V>(conciertos<K,V>& c, K& mayor);
    friend void avanza<K,V>(conciertos<K,V>& c);

private:

    struct NodoBinario {
        K clave;
        V valor;
        NodoBinario* izqda;
        NodoBinario* drcha;
    };

    NodoBinario* raiz = nullptr;
    int total;
    PilaDinamica<NodoBinario*> itrPila;

    PilaDinamica<NodoBinario*> primero;

    /*OPERACIONES INTERNAS*/
    friend void insertarRec<K,V>(NodoBinario*& nodo, const K& k, const V& v, bool& metido);
    friend void borrarRec<K,V>(typename conciertos<K,V>::NodoBinario*& nodo, const K& k, bool& borrado);
    friend void BorrarMaximo<K,V>(typename conciertos<K,V>::NodoBinario* nodo, K& k, V& v);
    friend void buscarRec<K,V>(typename conciertos<K,V>::NodoBinario* nodo, const K& k, V& v, bool& exito);

};

template<typename K, typename V> void crearConcierto(conciertos<K,V>& c){
    c.total = 0;
    c.raiz = nullptr;
}

template<typename K, typename V> bool esVacio(const conciertos<K,V>& c){
    return c.raiz = nullptr;
}

template<typename K, typename V> void buscarRec(typename conciertos<K,V>::NodoBinario* nodo, const K& k, V& v, bool& exito){
    if(nodo == nullptr){
        exito = false;
        return;
    }
    else{
        if(k < nodo->clave){
            buscarRec(nodo->izqda,k,v,exito);
        }else if(k == nodo->clave){
            exito = true;
            v = nodo->valor;
            return;
        }else if(k > nodo->clave){
            buscarRec(nodo->drcha,k,v,exito);
            return;
        }
    }
}


//{Devuelve verdad si y sólo si en c existe un par con clave k.}
template<typename K, typename V> bool existeClave(const conciertos<K,V>& c, const K& k, V& v){
   bool exito;
    buscarRec(c.raiz,k,v,exito);
    if(exito) return true;

    return false;
}

template<typename K, typename V> void insertarRec(typename conciertos<K,V>::NodoBinario*& nodo,
const K& k, const V& v, bool& metido){
    if (nodo == nullptr) {
        nodo = new typename conciertos<K,V>::NodoBinario;
        nodo->clave = k;
        nodo->valor = v;
        nodo->izqda = nullptr;
        nodo->drcha = nullptr;
        metido = true;
    }else{
        if (k < nodo->clave) {
            insertarRec<K,V>(nodo->izqda, k, v, metido);
        }else if (k > nodo->clave) {
            insertarRec<K,V>(nodo->drcha, k, v, metido);
        }else{
            nodo->valor = v;
            metido = false;
        }

    }

}

template<typename K, typename V> void insertar(conciertos<K,V>& c, const K& k, const V& v){
    bool metido = false;
    insertarRec<K,V>(c.raiz, k, v, metido);
    if (metido) {
        c.total++;
    }
}

/*{Si en c existe un par (k,v), devuelve su dato v.
Parcial: la operación no está definida si not existeClave?(c,k).} */
template<typename K, typename V> bool obtenerDato(const conciertos<K,V>& c, const K& k, V& v){
    bool exito;
    if(!existeClave(c,k,v)){
        return false;
    }else{
       buscarRec(c.raiz,k,v,exito);
       return true;
    }
}

template<typename K, typename V> void BorrarMaximo(typename conciertos<K,V>::NodoBinario* nodo, K& k, V& v){
    typename conciertos<K,V>::NodoBinario* nodoAuxi;
    if(nodo->drcha == nullptr){
        k = nodo->clave;
        v = nodo->valor;
        nodoAuxi = nodo;
        nodo = nodo->izqda;
        delete(nodoAuxi);
    }else{
        BorrarMaximo<K,V>(nodo->drcha, k, v);
    }
}

template<typename K, typename V> void borrarRec(typename
conciertos<K,V>::NodoBinario*& nodo, const K& k, bool& borrado){

typename conciertos<K,V>::NodoBinario* nodoAuxi;
    if(nodo == nullptr){
        borrado = false;
    }else{
        if(k < nodo->clave){
            borrarRec<K,V>(nodo->izqda, k, borrado);
        }else if(k > nodo->clave){
            borrarRec<K,V>(nodo->drcha, k, borrado);
        }else{
            if(nodo->izqda == nullptr){
                nodoAuxi = nodo;
                nodo = nodo->drcha;
                delete(nodoAuxi);
                borrado = true;
            }else{
                BorrarMaximo<K,V>(nodo->izqda,nodo->clave, nodo->valor);
            }
        }
    }

}


/* {Si en c existe un par con clave k, entonces devuelve una colección igual a la resultante de
eliminar de c el par con clave k. Si not existeClave?(c,k), devuelve una colección igual a c.} */
template<typename K, typename V> void borrar(conciertos<K,V>& c, const K& k){

    bool borrado;
    borrarRec<K,V>(c.raiz, k, borrado);
    if(borrado){
        c.total--;
    }
}
template<typename K, typename V> int tamanyo(const conciertos<K,V>& c){
    return c.total;
}


template<typename K, typename V> string listar(conciertos<K,V>& c){
    ostringstream out;
    K clave;
    V valor;
    iniciarIterador(c);
   // siguiente(c, clave, valor);

   // while(siguiente(c, clave, valor)){
    while(existeSiguiente(c)){
        siguiente(c,clave,valor);
            out << "clave: " << clave << endl;
            out << listarDatos(valor) << endl;
        }
    return out.str();
}
/* {Inicializa el iterador para recorrer los pares de la colección c, de forma que el siguiente
par a visitar sea el primero (situación de no haber visitado ningún par).} */
template<typename K, typename V> void iniciarIterador(conciertos<K,V>& c){
    typename conciertos<K,V>::NodoBinario* nodoAuxi;
    crear(c.itrPila);
    nodoAuxi = c.raiz;
    while(nodoAuxi != nullptr){
        push(c.itrPila, nodoAuxi);
        nodoAuxi = nodoAuxi->izqda;
    }
}
/* pag 121 de los apuntes {Prepara el iterador para visitar del siguiente par de la colección c.
Parcial: la operación no está definida si ya se ha visitado el último par.} */
template<typename K, typename V> void avanza(conciertos<K,V>& c){
    typename conciertos<K,V>::NodoBinario* nodoAuxi;

    while(!esVacia(c.itrPila)){
        nodoAuxi = cima(c.itrPila);
        pop(c.itrPila);
     //   push(c.itrPila,nodoAuxi.clave);  esto es añadir
        nodoAuxi = nodoAuxi.drcha;

        while(nodoAuxi =! nullptr){
            push(c.itrPila,nodoAuxi);
            nodoAuxi = nodoAuxi.izqda;
        }
    }

}
template<typename K, typename V> bool existeSiguiente(const conciertos<K,V>& c){
    return(!esVacia(c.itrPila));
}

template<typename K, typename V> bool siguiente(conciertos<K,V>& c, K& k, V& v){
    typename conciertos<K,V>::NodoBinario* ptrAux;
    if(existeSiguiente(c)) {
		ptrAux = pop(c.itrPila);
		k = ptrAux->clave;
		v = ptrAux->valor;
		ptrAux = ptrAux->drcha;
		while(ptrAux != nullptr) {

			push(c.itrPila, ptrAux);
			ptrAux = ptrAux->izqda;
		}
		return true;
	} else {
		return false;
	}

}
template<typename K, typename V> bool mayorClave(conciertos<K,V>& c, K& mayor){
    return false;

}

#endif // CONCIERTOS_H_INCLUDED
