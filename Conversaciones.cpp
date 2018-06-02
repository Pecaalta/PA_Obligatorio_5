/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conversaciones.cpp
 * Author: mauro
 * 
 * Created on 2 de junio de 2018, 9:13
 */

#include "Conversaciones.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "ICollection/String.h"
#include "ICollection/interfaces/IKey.h"

#include "Usuario.h"
#include "Miembro.h"
#include "Visto.h"

// Funciones de integrantes

IDictionary* Conversaciones::getIntegrantes() {
    return this->integrantes;
};

void Conversaciones::setIntegrantes(IDictionary* _integrantes) {
    this->integrantes = _integrantes;
};

// Funciones de mensaejs

IDictionary* Conversaciones::getMensaejs() {
    return this->mensaejs;
};

void Conversaciones::setMensaejs(IDictionary* _mensaejs) {
    this->mensaejs = _mensaejs;
};
// Funciones de id

int Conversaciones::getId() {
    return this->id;
};

void Conversaciones::setId(int _id) {
    this->id = _id;
};

// Constructores y Destructores

Conversaciones::Conversaciones(IDictionary* _integrantes, IDictionary* _mensaejs) {
    this->integrantes = _integrantes;
    this->mensaejs = _mensaejs;
    this->visto = new OrderedDictionary();
}

Conversaciones::Conversaciones(Usuario* _user) {
    this->integrantes = new OrderedDictionary();
    this->mensaejs = new OrderedDictionary();
    this->visto = new OrderedDictionary();
    
    IKey* k = new String(_user->getNumero().c_str()) ;
    Miembro* mim = new Miembro();
    Visto* vis = new Visto(_user);
    mim->setUsuario(_user);
    
    this->integrantes->add( k , mim );
    this->visto->add( k , vis );
}

Conversaciones::Conversaciones(IDictionary* _integrantes) {
    this->integrantes = _integrantes;
    this->mensaejs = new OrderedDictionary();
    this->visto = new OrderedDictionary();
}

Conversaciones::Conversaciones() {
    this->integrantes = new OrderedDictionary();
    this->mensaejs = new OrderedDictionary();
    this->visto = new OrderedDictionary();
}

Conversaciones::~Conversaciones() {
};
