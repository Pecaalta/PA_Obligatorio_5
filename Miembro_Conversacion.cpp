#include "Miembro.h"
#include "Fecha.h"
#include "Grupo.h"

#include "InterfazGrafica.h"
// Funciones de archivado

bool Miembro_Conversacion::getArchivado() {
    return this->archivado;
};

void Miembro_Conversacion::setArchivado(bool _archivado) {
    this->archivado = _archivado;
};

// Funciones de fecha

Fecha* Miembro_Conversacion::getFecha() {
    return this->fecha;
};

void Miembro_Conversacion::setFecha(Fecha* _fecha) {
    this->fecha = _fecha;
};

// Funciones de Usuario

Usuario* Miembro_Conversacion::getUsuario() {
    return this->user;
};


void Miembro_Conversacion::addMensaje(Mensaje* mens, string Numero) {
    this->Conversacion->addMensaje(mens, Numero);
}


void Miembro_Conversacion::setUsuario(Usuario* user) {
    this->user = user;
};

// conecto miembrio con conversacion y usuario

void Miembro_Conversacion::addConversacion(Usuario* user, Conversaciones* con) {
    this->user->addConversacion(user, this);
    this->Conversacion = con;
};

Conversaciones* Miembro_Conversacion::getConversacion() {
    return this->Conversacion;
};

// Imprimir

void Miembro_Conversacion::ImprimeConversacion(Usuario* user) {
    this->Conversacion->impresionSimple(user);
};

void Miembro_Conversacion::ImprimeConversacion() {
    this->Conversacion->impresionSimple();
};

void Miembro_Conversacion::impresionSuperSimple() {
    this->user->impresionSuperSimple();
};

void Miembro_Conversacion::ImprimeUsuarioDetallada() {
    this->user->impresionSimple();
};
void Miembro_Conversacion::ImprimeMensajes() {
    header("Mensajes");
    this->Conversacion->ImprimeMensajes();
   
};

string Miembro_Conversacion::getNumero() {
    return this->user->getNumero();
};


// Constructores y Destructores

Miembro_Conversacion::Miembro_Conversacion(Usuario* _yo, Usuario* _user) {
    this->user = _yo;
    this->fecha = new Fecha();
    this->archivado = false;
    this->Conversacion = new Conversaciones(this);
}

Miembro_Conversacion::Miembro_Conversacion(Usuario* _user) {
    this->archivado = false;
    this->user = _user;
    this->fecha = new Fecha();
    this->Conversacion = new Conversaciones(this);
}

Miembro_Conversacion::Miembro_Conversacion(Usuario* _yo, Conversaciones* _con) {
    _con->setUser2(_yo);
    this->Conversacion = _con;
    this->archivado = false;
    this->user = _yo;
    this->fecha = new Fecha();
}

Miembro_Conversacion::Miembro_Conversacion() {
    this->archivado = false;
    this->user = NULL;
    this->Conversacion = NULL;
    this->fecha = new Fecha();
}

Miembro_Conversacion::~Miembro_Conversacion() {
}

