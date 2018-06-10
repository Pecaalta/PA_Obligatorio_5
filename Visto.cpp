#include "Visto.h"
#include "Usuario.h"
#include "Fecha.h"
#include "ICollection/collections/OrderedDictionary.h"

#include "InterfazGrafica.h"
// Funciones de usuario

Usuario* Visto::getUsuario() {
    return this->usuario;
};

void Visto::setUsuario(Usuario* _usuario) {
    this->usuario = _usuario;
};

string Visto::getNumeroUsuario() {
    return this->usuario->getNumero();
};

void Visto::Imprimir() {
    if (this->check) {
        li(this->usuario->getNombre() + " " + this->fecha->imprimeFecha() + "  Visto");
    } else {
        li(this->usuario->getNombre() + " " + this->fecha->imprimeFecha() + " Recivido");

    }
}
// Funciones de fecha

Fecha* Visto::getFecha() {
    return this->fecha;
};

void Visto::setFecha(Fecha* _fecha) {
    this->fecha = _fecha;
};

void Visto::setFecha() {
    this->check = true;
    this->fecha->Actual();
};
void Visto::setBorrado() {
    this->borrar = true;
};
bool Visto::getBorrado() {
    return this->borrar;
};

// Funciones de idmensaje

int Visto::getIdmensaje() {
    return this->idmensaje;
};

void Visto::setIdmensaje(int _idmensaje) {
    this->idmensaje = _idmensaje;
};

// Constructores y Destructores

Visto::Visto(Usuario* _usuario) {
    this->usuario = _usuario;
    this->fecha = new Fecha();
    this->idmensaje = -1;
    this->check = false;
    this->borrar = false;
}

Visto::Visto() {
    this->check = false;
    this->borrar = false;
    this->usuario = NULL;
    this->fecha = new Fecha();
    this->idmensaje = -1;
}

Visto::~Visto() {
};
