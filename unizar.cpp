/*
    Autor:
    Mario Álvarez Gracia
*/
#include "unizar.h"

void crearEstudiante(string nom, string tit, estudiante& e){
    e.nombre = nom;
    e.titulacion = tit;
    e.numConciertos = 0;
}

string nombre(const estudiante& e){
    return e.nombre;
}
string tit(const estudiante& e){
    return e.titulacion;
}

string mostrarConciertos(const estudiante& e){
    string concierto;
    string id;
    string precio;
    string numConciertos;
    int codigo = 0;
    int dinero = 0;
    for (int i = 0; i < e.numConciertos; i++){
        codigo = e.conciertoss[i].id;
        dinero = e.conciertoss[i].precio;
        id = to_string(codigo);
        precio = to_string(dinero);
        numConciertos= to_string(i+1);
        concierto = concierto + ("\n clave: "+ id + " \n precio:" + precio + " $ \n");
    }

    return concierto;
}


string infoEstudiante(const estudiante& e){
    ostringstream inf;
    inf << "Nombre: " << e.nombre << endl;
    inf << "Titulacion: " << e.titulacion << endl;
    inf << "Numero de tikets: " << e.numConciertos << endl;

    if(e.numConciertos> 0){
        inf << "Conciertos adquiridos: " << mostrarConciertos(e) << endl;
    }else{
        inf << "Aun no tiene tickets de conciertos" << endl;
    }

    return inf.str();
}
