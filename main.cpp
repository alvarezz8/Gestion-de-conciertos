/*
    Autor:
    Mario Álvarez Gracia
*/
#include <iostream>
#include "conciertos.h"
#include "piladinamica.h"
#include "unizar.h"
#include "evento.h"
#include "estudiantes.h"
#include "unizar.cpp"
#include "evento.cpp"

#include <sstream>

using namespace std;


const int INTRODUCIR_CONCIERTO = 1;
const int MOSTRAR_CONCIERTO = 2;
const int BORRAR_CONCIERTO = 3;
const int LISTAR_CONCIERTOS = 4;
const int INSCRIBIR_CLIENTE = 5;
const int MOSTRAR_CLIENTE = 6;
const int COMPRAR_TICKET = 7;

const int MAX_DINERO = 300;
const int MAX_TICKETS = 40;

void menu();
void introducir_concierto(conciertos<int, evento> &c);
void mostrar_concierto(conciertos<int, evento> &c);
void borrar_concierto(conciertos<int, evento> &c);
string listar_conciertos(conciertos<int, evento> &c);
//void inscribir_cliente(estudiante &e);
void inscribir_cliente(estudiantes<estudiante> &est);
void mostrar_cliente(estudiantes<estudiante> &est);
void crearTicket(conciertos<int, evento> &c, estudiantes<estudiante> &est);
void asignarConcierto(int id, int precio, estudiante& e);
int main()
{
    int opcion = 0;
    conciertos<int, evento>Misconciertos;
    estudiantes<estudiante>Misestudiantes;
    crearConcierto(Misconciertos);
    menu();
    cout << "Elige una opción: " << endl;
    cin >> opcion;
     while(opcion != 0){

        switch(opcion){
            case INTRODUCIR_CONCIERTO:
                introducir_concierto(Misconciertos);
                break;
            case MOSTRAR_CONCIERTO:
                mostrar_concierto(Misconciertos);
                break;
            case BORRAR_CONCIERTO:
                borrar_concierto(Misconciertos);
                break;
            case LISTAR_CONCIERTOS:
                cout << listar_conciertos(Misconciertos);
                break;
            case INSCRIBIR_CLIENTE:
                inscribir_cliente(Misestudiantes);
                break;
            case MOSTRAR_CLIENTE:
                mostrar_cliente(Misestudiantes);
                break;
            case COMPRAR_TICKET:
                crearTicket(Misconciertos, Misestudiantes);
                break;

        }
        menu();
        cout << "Elige una opción: " << endl;
        cin >> opcion;
    }

    return 0;

}

void menu(){
        cout << "**  Menu  **" << endl;
        cout << "** Elige una opción:  **" << endl;
        cout << "1. introducir concierto " << endl;
        cout << "2. mostrar concierto " << endl;
        cout << "3. borrar concierto" << endl;
        cout << "4. listar conciertos" << endl;
        cout << "5. inscribir cliente" << endl;
        cout << "6. mostrar cliente " << endl;
        cout << "7. comprar ticket" << endl;
        cout << "0. SALIR" << endl;
}

void introducir_concierto(conciertos<int, evento> &c){
    evento e;
    string nombre;
    string lugar;
    string fecha;
    string hora;
    int precio;
    int cod;

    cout << "Introduzca el codigo del evento: " << endl;
    cin >> cod;
    cout << "Introduzca el nombre del evento: " << endl;
    cin >> nombre;
    cout << "Introduzca el lugar del evento: " << endl;
    cin >> lugar;
    cout << "Introduzca la fecha del evento: " << endl;
    cin >> fecha;
    cout << "Introduzca la hora del evento: " << endl;
    cin >> hora;
    cout << "Introduzca el precio del evento: " << endl;
    cin >> precio;

    crearEv(nombre, lugar, fecha, hora, precio, e);

    if(existeClave(c,cod,e)){
        insertar(c,cod,e);
        cout << "Actualizacion realizada" << endl;
    }else if(!existeClave(c,cod,e)){
        insertar(c, cod, e);
        cout << "Insercion realizada" << endl;
    }else {
        cout << "Insercion descartada" << endl;
    }
   // cout << tamanyo(c) << endl;
 /*   if(insertar(c, cod, e)){
            cout << "ERROR / EL concierto ya existe" << endl;
    }else{
        cout << "concierto INSCRITO" << endl;
    } */
}

void mostrar_concierto(conciertos<int, evento> &c){
    int cod;
//    bool exito;
    evento e;
    cout << "introduzca el codigo del concierto" << endl;
    cin >> cod;
    if(existeClave(c,cod,e)){
        cout << "Concierto encontrado" << endl;
        obtenerDato(c,cod,e);
        cout << listarDatos(e);
    }else{
        cout << "Concierto desconocido" << endl;
    }
}

void borrar_concierto(conciertos<int, evento> &c){
    int cod;
    evento e;
    cout << "introduzca el codigo del concierto que desea borrar: " << endl;
    cin >> cod;
    if(existeClave(c,cod,e)){
        cout << "Concierto borrado" << endl;
        borrar(c, cod);
    }
    else{
        cout << "El concierto no existe" << endl;
    }
}

string listar_conciertos(conciertos<int, evento> &c){
    ostringstream lista;
  //  string cod;
 //   evento e;

    lista << "CONCIERTOS" << endl;
    lista << "Numero de conciertos: " << tamanyo(c)<< endl;
    lista << " " << endl;
    lista << listar(c) << endl;

    return lista.str();

}

void inscribir_cliente(estudiantes<estudiante> &est){
    estudiante e;
    string nombre;
    string titulacion;

    if (cardinal(est) < 1){
    cout << "Introduzca el nombre del estudiante: " << endl;
    cin >> nombre;
    cout << "Introduzca la titulacion del estudiante: " << endl;
    cin >> titulacion;

    crearEstudiante(nombre,titulacion,e);
    anyadir(est,e);
    cout << "estudiante inscrito" << endl;
    }
    else {
        cout << "No se puede añadir nigun cliente mas" << endl;
    }
}

void mostrar_cliente(estudiantes<estudiante> &est){

    estudiante e;
    if(cardinal(est) > 0){
        obtenerCandidatoSuValoryClave(est,e);
        cout << infoEstudiante(e) << endl;
    }
}

void crearTicket(conciertos<int, evento> &c, estudiantes<estudiante> &est){
    estudiante e;
    evento ev;
    int cod;

    string nip;
    if(tamanyo(c) > 0 && cardinal(est) > 0){
        cout << listar_conciertos(c);
        cout << "INtroduzca el codigo del concierto al que quieras asistir: " << endl;
        cin >> cod;

        if(existeClave(c,cod,ev)){
            obtenerCandidatoSuValoryClave(est, e);
            obtenerDato(c,cod,ev);
            int precio = mostrarPrecio(ev);
            cout << "ESTUDIANTE ACTUALIZADO" << endl;
            asignarConcierto(cod, precio, e);
            actualizarCandidato(est,e);
            cout <<  infoEstudiante(e);
        }else{
            cout << "no existe ese concierto" <<endl;

        }
    }
    else if(tamanyo(c) == 0){
        cout << "No hay conciertos" << endl;
    }
    else if(cardinal(est) < 1){
        cout << "NO HAY CLIENTES" << endl;
    }

}

void asignarConcierto(int id, int precio, estudiante& e){
    /*
    if((e.sumaPrecio + precio) <= MAX_DINERO ) && (e.numConciertos)){
        e.conciertoss[e.numConciertos].id = id;
        e.conciertoss[e.numConciertos].precio = precio;
        e.numConciertos++;
        e.sumaPrecio = e.sumaPrecio + precio;
        cout << "Concierto adquirido " << e.numConciertos << endl;
        cout << "Suma total del precio de todos los tickets: " << e.sumaPrecio << " $ \n" << endl;

    }else{
        cout << "Has alcanzado el precio maximo de dinero " << endl;
    }
    */
    if ((e.sumaPrecio + precio) > MAX_DINERO){
        cout << "Has alcanzado el precio maximo de dinero, no se ha podido realizar la operación " << endl;
    }
    else if ((e.numConciertos + 1) > MAX_TICKETS){
        cout << "Has alcanzado el máximo de tickets permitido, no se ha podido realizar la operación " << endl;
    }
    else {
        e.conciertoss[e.numConciertos].id = id;
        e.conciertoss[e.numConciertos].precio = precio;
        e.numConciertos++;
        e.sumaPrecio = e.sumaPrecio + precio;

        cout << "Concierto adquirido " << e.numConciertos << endl;
        cout << "Suma total del precio de todos los tickets: " << e.sumaPrecio << " $ \n" << endl;
    }
}

