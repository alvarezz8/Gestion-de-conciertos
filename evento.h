/*
    Autor:
    Mario Álvarez Gracia
*/
#ifndef evento_H_INCLUDED
#define evento_H_INCLUDED
#include <iostream>

using namespace std;

struct evento;
void crearEv(string nom, string lugar, string dia, string hora, int precio, evento &e);
string listarDatos(const evento &e);
string mostrarNombre(const evento &e);
string mostrarLugar(const evento &e);
string mostrarFecha(const evento &e);
string mostrarHora(const evento &e);
int mostrarPrecio(const evento &e);


struct evento{
    friend void crearEv(string nom, string lugar, string dia, string hora, int precio, evento &e);
    friend string listarDatos(const evento &e);
    friend string mostrarNombre(const evento &e);
    friend string mostrarLugar(const evento &e);
    friend string mostrarFecha(const evento &e);
    friend string mostrarHora(const evento &e);
    friend int mostrarPrecio(const evento &e);

    private:
        string nombre;
        string lugar;
        string fecha;
        string hora;
        int precio;

};




#endif // evento_H_INCLUDED
