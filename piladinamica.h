/*
    Autor:
    Mario Álvarez Gracia
*/
#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED

#include <iostream>
#include <sstream>

template<typename T> struct PilaDinamica;
template<typename T> void crear(PilaDinamica<T>& l);
template<typename T> void push(PilaDinamica<T>& l, const T& e);
template<typename T> T pop(PilaDinamica<T>& l);
template<typename T> bool esVacia(const PilaDinamica<T>& l);
template<typename T> int tamanyoP(const PilaDinamica<T>& l);
template<typename T> void liberar(PilaDinamica<T>& l);
template<typename T> int cima(PilaDinamica<T>& l);

template<typename T>
struct PilaDinamica {
    friend void crear<T>(PilaDinamica<T>& l);
    friend void push<T>(PilaDinamica<T>& l, const T& e);
    friend T pop<T>(PilaDinamica<T>& l);
    friend bool esVacia<T>(const PilaDinamica<T>& l);
 	friend int tamanyoP<T>(const PilaDinamica<T>& l);
	friend void liberar<T>(PilaDinamica<T>& l);
	friend int cima<T>(PilaDinamica<T>& l);

    private:
    struct Nodo {
        T valor;
        Nodo* siguiente;
    };

    Nodo* elPrimero;
    int numDatos;
};
// Inicializa los variables de PilaDinamica
template<typename T> void crear(PilaDinamica<T>& l) {
	l.elPrimero = nullptr;
	l.numDatos = 0;
}


template<typename T> int cima(PilaDinamica<T>& l) {
    return l.elPrimero;
}

// Apila un nodo
template<typename T> void push(PilaDinamica<T>& l, const T& e) {
	typename PilaDinamica<T>::Nodo* ptrAux;
	ptrAux = new typename PilaDinamica<T>::Nodo;
	ptrAux->valor = e;
	ptrAux->siguiente = l.elPrimero;
	l.elPrimero = ptrAux;
	l.numDatos++;
}
// si es vacia devuelve true
template<typename T> bool esVacia(const PilaDinamica<T>& l) {
	return (l.numDatos == 0);
}
// Desapila un nodo
template<typename T> T pop(PilaDinamica<T>& l) {
	typename PilaDinamica<T>::Nodo* ptrAux;
	T dato;
	if(!esVacia(l)) {
		dato = l.elPrimero->valor;
		ptrAux = l.elPrimero;
		l.elPrimero = l.elPrimero->siguiente;
		delete(ptrAux);
		l.numDatos--;
		return dato;
	} else {
		return nullptr;
	}
}
// Devuelve el numero total de nodos en la pila
template<typename T> int tamanyoP(const PilaDinamica<T>& l) {
	return l.numDatos;
}
// Desapila todos los nodos
template<typename T> void liberar(PilaDinamica<T>& l) {
	typename PilaDinamica<T>::Nodo* ptrAux;
	ptrAux = l.elPrimero;
	while(ptrAux != nullptr) {
		l.elPrimero = l.elPrimero->siguiente;
		delete(ptrAux);
		ptrAux = l.elPrimero;
	}
	l.numDatos = 0;
}

#endif
