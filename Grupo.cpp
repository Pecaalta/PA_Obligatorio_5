#include "Grupo.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "Miembro.h"
#include "Visto.h"

// Funciones de nombre

string Grupo::getNombre() {
    return this->nombre;
};

void Grupo::setNombre(string _nombre) {
    this->nombre = _nombre;
};

// Funciones de imagen

string Grupo::getImagen() {
    return this->imagen;
};

void Grupo::setImagen(string _imagen) {
    this->imagen = _imagen;
};

string Grupo::tipo() {
    return "Grupo";
};

// Funciones de imprecion

void Grupo::impresionSimple() {
    cout << "----------------------------------------------" << endl;
    cout << "\t Nombre: " << this->nombre << endl;
    cout << "\t Numero: " << this->imagen << endl;
    cout << "----------------------------------------------" << endl;
}

void Grupo::impresionSuperSimple() {
    cout << "----------------------------------------------" << endl;
    cout << "\t Nombre: " << this->nombre << endl;
    cout << "----------------------------------------------" << endl;
}

// Constructores y Destructores

Grupo::Grupo(string _nombre, string _imagen) : Conversaciones() {
    this->nombre = _nombre;
    this->imagen = _imagen;
}

Grupo::Grupo() : Conversaciones() {
}

Grupo::~Grupo() {
};
