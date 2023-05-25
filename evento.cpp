/*
    Autor:
    Mario Álvarez Gracia
*/
#include "evento.h"

void crearEv(string nom, string lugar, string fecha, string hora, int precio, evento &e){
    e.nombre = nom;
    e.lugar = lugar;
    e.fecha = fecha;
    e.hora = hora;
    e.precio = precio;

}

string listarDatos(const evento &e){
    ostringstream pre;
    pre << "Concierto: " << e.nombre << endl;
    pre << "Lugar: " << e.lugar << endl;
    pre << "Fecha: " << e.fecha << endl;
    pre << "Hora: " << e.hora << endl;
    pre << "Precio: " << e.precio << " $" << endl;

    return pre.str();
}
string mostrarNombre(const evento &e){
    return e.nombre;
}
string mostrarLugar(const evento &e){
    return e.lugar;
}
string mostrarFecha(const evento &e){
    return e.fecha;
}
string mostrarHora(const evento &e){
    return e.hora;
}
int mostrarPrecio(const evento &e){
    return e.precio;
}
