/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Miembro.cpp
 * Author: mauro
 * 
 * Created on 2 de junio de 2018, 8:55
 */

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

void Miembro::setAdministrador(bool _admin) {
    this->administrador = _admin;
};
bool Miembro::getAdministrador() {
    return this->administrador;
};

void Miembro::addConversacion(Grupo* con) {
    this->user->addConversacion(con);
};

void Miembro::ImprimeUsuario() {
    cout << "----------------------------------------------" << endl;
    this->user->impresionSimple();
    cout << "----------------------------------------------" << endl;
};
void Miembro::ImprimeUsuarioDetallada() {
    cout << "----------------------------------------------" << endl;
    this->user->impresionSimple();
    cout << (this->administrador? "\t Privilegios administrador" : "\t Privilegios estandar") << endl;
    cout << "----------------------------------------------" << endl;
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

