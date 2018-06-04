#include "Grupo.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "Miembro.h"
#include "Visto.h"

#include "InterfazGrafica.h"

//Administradores

void Grupo::HacerAdministradores(IKey* k) {
    if (this->integrantes->member(k)) {
        Miembro* mim = (Miembro*)this->integrantes->find(k);
        mim->setAdministrador(true);
    }
}

bool Grupo::getAdministradores(IKey* k) {
    return this->integrantes->member(k) and ((Miembro*)this->integrantes->find(k))->getAdministrador();
}


//Agrego visto

IDictionary* Grupo::getVistos() {
    return this->visto;
};

void Grupo::setVistos(IDictionary* _vistos) {
    this->visto = _vistos;
};

//Añade contacto como administrador

void Grupo::setAdmin(Usuario* _user) {
    IKey* k = new String(_user->getNumero().c_str());
    Miembro* mim = new Miembro(_user, this);
    Visto* vis = new Visto(_user);
    mim->setAdministrador(true);
    this->integrantes->add(k, mim);
    this->visto->add(k, vis);
    _user->addGrupo(mim);
}

//Contactos

void Grupo::addContacto(Usuario* user) {
    IKey* k = new String(user->getNumero().c_str());
    if (!this->integrantes->member(k)) {
        Miembro* mim = new Miembro(user);
        Visto* v = new Visto(user);
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
    if (!this->integrantes->isEmpty() and this->integrantes->member(k)) {
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

bool Grupo::isEmpty() {
    return this->integrantes->isEmpty();
}

// Relaciona los mimbros con el usuario al q apunta

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
    header("Contactos de " + this->nombre);
    Miembro* n;
    if (!this->integrantes->isEmpty()) {
        IIterator* it = this->integrantes->getIterator();
        li();
        while (it->hasCurrent()) {
            li("-");
            n = (Miembro*) it->getCurrent();
            n->ImprimeUsuario();
            li("-");
            it->next();
        }
        li();
        delete it;
    } else {
        alarm("No tines Contactos");
    }
};

void Grupo::SolicitaListaContactosDetallada() {
    cout << endl;
    cout << "-----------------------------------------" << endl;
    cout << " Contactos del Grupo" << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
    Usuario* n;
    if (!this->integrantes->isEmpty()) {
        IIterator* it = this->integrantes->getIterator();
        while (it->hasCurrent()) {
            n = (Usuario*) it->getCurrent();
            n->impresionSimple();
            it->next();
        }
        delete it;
    } else {
        cout << endl;
        cout << "\t No tines Contactos" << endl;
        cout << endl;
    }
}

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
    li("Nombre: " + this->nombre);
    li("Imagen: " + this->imagen);
}

void Grupo::impresionSuperSimple() {
    li("Nombre: " + this->nombre);
}

// Constructores y Destructores

Grupo::Grupo(string _nombre, string _imagen) {
    this->nombre = _nombre;
    this->imagen = _imagen;
    this->integrantes = new OrderedDictionary();
    this->mensaejs = new OrderedDictionary();
    this->visto = new OrderedDictionary();
}

Grupo::Grupo(string _nombre, string _imagen, IDictionary* contactos) {
    this->nombre = _nombre;
    this->imagen = _imagen;
    this->mensaejs = new OrderedDictionary();
    this->visto = new OrderedDictionary();
    this->integrantes = new OrderedDictionary();
    Usuario* user;
    IIterator* it = contactos->getIterator();
    Miembro* miembro;
    Visto* visto;
    IKey* k;
    while (it->hasCurrent()) {
        user = (Usuario*) it->getCurrent();
        miembro = new Miembro(user, this);
        visto = new Visto(user);
        user->addGrupo(miembro);
        k = new String(user->getNumero().c_str());
        this->visto->add(k, visto);
        this->integrantes->add(k, miembro);
        it->next();
    }
    delete it;
}

Grupo::Grupo() {
    this->integrantes = new OrderedDictionary();
    this->mensaejs = new OrderedDictionary();
    this->visto = new OrderedDictionary();
}

Grupo::~Grupo() {
};
