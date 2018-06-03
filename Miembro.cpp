#include "Miembro.h"
#include "Fecha.h"
#include "Grupo.h"

// Funciones de archivado

bool Miembro::getArchivado() {
    return this->archivado;
};

void Miembro::setArchivado(bool _archivado) {
    this->archivado = _archivado;
};

// Funciones de fecha

Fecha* Miembro::getFecha() {
    return this->fecha;
};

void Miembro::setFecha(Fecha* _fecha) {
    this->fecha = _fecha;
};

// Funciones de Usuario

Usuario* Miembro::getUsuario() {
    return this->user;
};

void Miembro::setUsuario(Usuario* user) {
    this->user = user;
};

// Funciones de Administrador

void Miembro::setAdministrador(bool _admin) {
    this->administrador = _admin;
};

bool Miembro::getAdministrador() {
    return this->administrador;
};

// conecto miembrio con conversacion y usuario

void Miembro::addConversacion(Conversaciones* con) {
    this->user->addConversacion(this);
    this->Conversacion = con;
};

// Imprimir

void Miembro::ImprimeUsuario() {
    cout << "----------------------------------------------" << endl;
    this->user->impresionSimple();
    cout << "----------------------------------------------" << endl;
};

void Miembro::impresionSuperSimple() {
    cout << "----------------------------------------------" << endl;
    this->user->impresionSuperSimple();
    cout << "----------------------------------------------" << endl;
};

void Miembro::ImprimeUsuarioDetallada() {
    cout << "----------------------------------------------" << endl;
    this->user->impresionSimple();
    cout << (this->administrador ? "\t Privilegios administrador" : "\t Privilegios estandar") << endl;
    cout << "----------------------------------------------" << endl;
};

string Miembro::getNumero() {
    return this->user->getNumero();
};

// Constructores y Destructores

Miembro::Miembro(bool _archivado, Fecha* _fecha) {
    this->archivado = _archivado;
    this->user = NULL;
    this->fecha = _fecha;
    this->administrador = false;
}

Miembro::Miembro() {
    this->administrador = false;
    this->archivado = false;
    this->user = NULL;
    this->fecha = new Fecha();
}

Miembro::~Miembro() {
}

