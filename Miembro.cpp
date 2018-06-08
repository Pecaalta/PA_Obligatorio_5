#include "Miembro.h"
#include "Fecha.h"
#include "Grupo.h"

#include "InterfazGrafica.h"
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

void Miembro::addMensaje(Mensaje* mens, string Numero) {
    this->Conversacion->addMensaje(mens, Numero);
}

void Miembro::addConversacion(Grupo* con) {
    this->user->addGrupo(this);
    this->Conversacion = con;
};

Grupo* Miembro::getConversacion() {
    return this->Conversacion;
};

// Imprimir

void Miembro::ImprimeGrupo() {
    this->Conversacion->impresionSimple();
};

void Miembro::ImprimeUsuario() {
    this->user->impresionSimple();
    li(this->administrador ? "administrador" : "Comun");
};

void Miembro::impresionSuperSimple() {
    this->user->impresionSuperSimple();
};

void Miembro::impresionNombreGrupo() {
    li("Nombre: " + this->Conversacion->getNombre());
};


void Miembro::ImprimeMensajes(Usuario* user) {//Este numero representa el telefono para poner vistos
    header("Mensajes");
    this->Conversacion->ImprimeMensajes(user);
};
void Miembro::ImprimeMensajeDetallado(string numbre) {//este numero representa el identificador para vuscar el mensaeje
    header("Mensajes");
    this->Conversacion->ImprimeMensajeDetallado(numbre);
};

void Miembro::ImprimeUsuarioDetallada() {
    this->user->impresionSimple();
    li(this->administrador ? "administrador" : "Comun");
};

string Miembro::getNumero() {
    return this->user->getNumero();
};

void Miembro::MenuAgragaAdministrador() {
    this->Conversacion->SolicitaListaContactosDetallada();
}

void Miembro::SolicitaListaContactosDetallada() {
    this->Conversacion->SolicitaListaContactosDetallada();
}

// Constructores y Destructores

Miembro::Miembro(Usuario* _user, Grupo* _grupo) {
    this->Conversacion = _grupo;
    this->user = _user;
    this->fecha = new Fecha();
    this->administrador = false;
    this->archivado = false;
}

Miembro::Miembro(Usuario* _user) {
    this->administrador = false;
    this->Conversacion = NULL;
    this->archivado = false;
    this->user = _user;
    this->fecha = new Fecha();
}

Miembro::Miembro() {
    this->administrador = false;
    this->archivado = false;
    this->user = NULL;
    this->Conversacion = NULL;
    this->fecha = new Fecha();
}

Miembro::~Miembro() {
}

