/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grupo.cpp
 * Author: mauro
 * 
 * Created on 2 de junio de 2018, 14:20
 */

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

// Funciones de creacion

Fecha* Grupo::getCreacion() {
    return this->creacion;
};

void Grupo::setCreacion(Fecha* _creacion) {
    this->creacion = _creacion;
};

// Funciones de vistos

IDictionary* Grupo::getVistos() {
    return this->visto;
};

void Grupo::setVistos(IDictionary* _vistos) {
    this->visto = _vistos;
};
void Grupo::impresionSimple(){
    cout << "----------------------------------------------" << endl;
    cout << "\t Nombre: " << this->nombre << endl;
    cout << "\t Numero: " << this->imagen << endl;
    cout << "----------------------------------------------" << endl;
}

// Constructores y Destructores


void Grupo::setAdmin(Usuario* _user) {
    IKey* k = new String(_user->getNumero().c_str()) ;
    Miembro* mim = new Miembro();
    Visto* vis = new Visto(_user);
    mim->setUsuario(_user);
    mim->addConversacion(this);
    mim->setAdministrador(true);
    this->integrantes->add( k , mim );
    this->visto->add( k , vis );
}

Grupo::Grupo(string _nombre, string _imagen) {
    this->integrantes = new OrderedDictionary();
    this->mensaejs = new OrderedDictionary();
    this->visto = new OrderedDictionary();
    this->nombre = _nombre;
    this->imagen = _imagen;
    this->creacion = new Fecha();
}

Grupo::Grupo() {
    this->integrantes = new OrderedDictionary();
    this->mensaejs = new OrderedDictionary();
    this->visto = new OrderedDictionary();
    this->creacion = new Fecha();
    
}

Grupo::~Grupo() {
};



// Funciones de integrantes

IDictionary* Grupo::getIntegrantes() {
    return this->integrantes;
};

void Grupo::setIntegrantes(IDictionary* _integrantes) {
    this->integrantes = _integrantes;
};

// Funciones de mensaejs

IDictionary* Grupo::getMensaejs() {
    return this->mensaejs;
};

void Grupo::setMensaejs(IDictionary* _mensaejs) {
    this->mensaejs = _mensaejs;
};

void Grupo::addContacto(Usuario* user) {
    IKey* k = new String(user->getNumero().c_str());
    if (!this->integrantes->member(k)) {
        Miembro* mim = new Miembro();
        Visto* v = new Visto(user);
        mim->setUsuario(user);
        this->integrantes->add(k, mim);
        this->visto->add(k, v);
    } else {
        system("cls");
        cout << "-----------------------------------------" << endl;
        cout << " Imposivle ya esta agregado" << endl;
        cout << "-----------------------------------------" << endl;
        cout << endl;
        system("pause");
    }
}

void Grupo::removeContacto(Usuario* user) {
    IKey* k = new String(user->getNumero().c_str());
    if (!this->integrantes->isEmpty()) {
        this->integrantes->remove(k);
        this->visto->remove(k);
    } else {
        system("cls");
        cout << "-----------------------------------------" << endl;
        cout << " Imposivle el Grupo esta vacio" << endl;
        cout << "-----------------------------------------" << endl;
        cout << endl;
        system("pause");
    }
}

bool Grupo::isEmpty() {
    return this->integrantes->isEmpty();
}

void Grupo::commit() {
    Miembro* n;
    if (!this->integrantes->isEmpty()) {
        IIterator* it = this->integrantes->getIterator();
        while (it->hasCurrent()) {
            n = (Miembro*) it->getCurrent();
            n->addConversacion(this);
            it->next();
        }
        delete it;
    } else {
        cout << endl;
        cout << "\t No tines Contactos" << endl;
        cout << endl;
    }
}
void Grupo::SolicitaListaContactos() {
    cout << endl;
    cout << "-----------------------------------------" << endl;
    cout << " Contactos del Grupo" << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
    Miembro* n;
    if (!this->integrantes->isEmpty()) {
        IIterator* it = this->integrantes->getIterator();
        while (it->hasCurrent()) {
            n = (Miembro*) it->getCurrent();
            n->ImprimeUsuario();
            it->next();
        }
        delete it;
    } else {
        cout << endl;
        cout << "\t No tines Contactos" << endl;
        cout << endl;
    }
};
void Grupo::SolicitaListaContactosDetallada(){
    cout << endl;
    cout << "-----------------------------------------" << endl;
    cout << " Contactos del Grupo" << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
    Miembro* n;
    if (!this->integrantes->isEmpty()) {
        IIterator* it = this->integrantes->getIterator();
        while (it->hasCurrent()) {
            n = (Miembro*) it->getCurrent();
            n->ImprimeUsuarioDetallada();
            it->next();
        }
        delete it;
    } else {
        cout << endl;
        cout << "\t No tines Contactos" << endl;
        cout << endl;
    }
}
void Grupo::HacerAdministradores(IKey* k){
    if (this->integrantes->member(k)){
        Miembro* mim = (Miembro*)this->integrantes->find(k);
        mim->setAdministrador(true);
    }
}
bool Grupo::getAdministradores(IKey* k){
    return this->integrantes->member(k) and ((Miembro*)this->integrantes->find(k))->getAdministrador();
}
