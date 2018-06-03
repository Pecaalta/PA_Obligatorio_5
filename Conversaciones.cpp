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
string Conversaciones::tipo() {
    return "Conversaciones";
};

//Agrego visto
IDictionary* Conversaciones::getVistos() {
    return this->visto;
};
void Conversaciones::setVistos(IDictionary* _vistos) {
    this->visto = _vistos;
};

//Añade contacto como administrador
void Conversaciones::setAdmin(Usuario* _user) {
    IKey* k = new String(_user->getNumero().c_str()) ;
    Miembro* mim = new Miembro();
    Visto* vis = new Visto(_user);
    mim->setUsuario(_user);
    mim->addConversacion(this);
    mim->setAdministrador(true);
    this->integrantes->add( k , mim );
    this->visto->add( k , vis );
}

//Contactos
void Conversaciones::addContacto(Usuario* user) {
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
void Conversaciones::removeContacto(Usuario* user) {
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

//Retorna si la conversacion tine integrantes
bool Conversaciones::isEmpty() {
    return this->integrantes->isEmpty();
}

// Relaciona los mimbros con el usuario al q apunta
void Conversaciones::commit() {
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

void Conversaciones::SolicitaListaContactos() {
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
void Conversaciones::SolicitaListaContactosDetallada(){
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

//Administradores
void Conversaciones::HacerAdministradores(IKey* k){
    if (this->integrantes->member(k)){
        Miembro* mim = (Miembro*)this->integrantes->find(k);
        mim->setAdministrador(true);
    }
}
bool Conversaciones::getAdministradores(IKey* k){
    return this->integrantes->member(k) and ((Miembro*)this->integrantes->find(k))->getAdministrador();
}
    

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