#include "Grupo.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "Miembro.h"
#include "Visto.h"

#include "InterfazGrafica.h"
#include "Contacto.h"
#include "Video.h"
#include "Foto.h"

IDictionary* Grupo::getIntegrantes() {
    return this->integrantes;
};

void Grupo::setIntegrantes(IDictionary* _integrantes) {
    this->integrantes = _integrantes;
};
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

void Grupo::addMensaje(Mensaje* mens, string Numero) {
    IKey* k = new String(to_string(mens->getId()).c_str());
    this->mensaejs->add(k, mens);
    Miembro* n;
    IIterator* it = this->integrantes->getIterator();
    while (it->hasCurrent()) {
        n = (Miembro*) it->getCurrent();
        n->setArchivado(false);
        mens->SetVisto(n->getUsuario());
        it->next();
    }
    delete it;
    k = new String(Numero.c_str());
    Visto* v = (Visto*)this->visto->find(k);
    v->setIdmensaje(mens->getId());
    v->setFecha();
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
        Miembro* miembro = new Miembro(user, this);
        Visto* v = new Visto(user);
        user->addGrupo(miembro);
        this->visto->add(k, v);
        this->integrantes->add(k, miembro);
    } else {
        alarm("Imposible ya esta agregado");
    }
}

void Grupo::removeContacto(IKey* k) {
    if (this->integrantes->member(k)) {
        Usuario* user = ((Miembro*)this->integrantes->find(k))->getUsuario();
        user->removeGrupo(new String(this->getNombre().c_str()));
        if (this->integrantes->member(k))
            this->integrantes->remove(k);
/*        if (this->visto->member(k))
            this->visto->remove(k);*/
    } else {
        alarm("El usuario no pertenece");
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
        cout << "\t No tienes Contactos" << endl;
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
        alarm("No tienes Contactos");
    }
};

void Grupo::SolicitaListaContactos(string name) {
    header("Contactos de " + this->nombre);
    Miembro* n;
    if (!this->integrantes->isEmpty()) {
        IIterator* it = this->integrantes->getIterator();
        li();
        while (it->hasCurrent()) {
            n = (Miembro*) it->getCurrent();
            if (name.compare(n->getNumero()) != 0) {
                li("-");
                n->ImprimeUsuario();
                li("-");
            }
            it->next();
        }
        li();
        delete it;
    } else {
        alarm("No tienes Contactos");
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
        cout << "\t No tienes Contactos" << endl;
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

void Grupo::ImprimeMensajes(Usuario* user, Fecha* f) {
    Mensaje* m;
    li();
    if (!this->mensaejs->isEmpty()) {
        IIterator* it = this->mensaejs->getIterator();
        while (it->hasCurrent()) {
            m = (Mensaje*) it->getCurrent();
            if (f <= m->getFecha()) {
                if (!m->getBorrado(user)) {
                    m->SetVisto(user);
                    li("-");
                    li("Id: " + to_string(m->getId()));
                    li("Autor: " + m->getAutor()->getNombre());
                    li("Texto: " + m->getTexto());
                    if (m->tipo.compare("Contacto") == 0) {
                        li("Nombre Contacto: " + ((Contacto*) m) ->getContenido()->getNombre());
                        li("Numero Contacto: " + ((Contacto*) m) ->getContenido()->getNumero());
                    } else if (m->tipo.compare("Video") == 0) {
                        li("Duracion de Video: " + ((Video*) m) ->getDuracion());
                        li("Url: " + ((Video*) m) ->getURL());
                    } else if (m->tipo.compare("Foto") == 0) {
                        li("Descripcion : " + ((Foto*) m) ->getDesc());
                        li("Formato : " + ((Foto*) m) ->getForm());
                        li("Tamaño : " + ((Foto*) m) ->getTama());
                        li("Ur : " + ((Foto*) m) ->getURL());
                    }
                    li("-");
                }
            }
            it->next();
        }
        delete it;
    } else {
        li("-");
        li("No tienes Contactos");
        li("-");
    }
    li();
};

void Grupo::EliminarMensaje(string numbre, Usuario* user) {
    IKey* k = new String(numbre.c_str());
    if (this->mensaejs->member(k)) {
        Mensaje* m = (Mensaje*)this->mensaejs->find(k);
        m->serBorrado(user);
    } else {
        alarm("No se encontro mensaje con ese identificador");
    }
}

void Grupo::ImprimeMensajeDetallado(string numbre) {
    header("Mensajes");
    IKey* k = new String(numbre.c_str());
    bool ok;
    if (this->mensaejs->member(k)) {
        Mensaje* m = (Mensaje*)this->mensaejs->find(k);
        li();
        li("Id: " + to_string(m->getId()));
        li("Autor: " + m->getAutor()->getNombre());
        li("Texto: " + m->getTexto());
        li("");
        li("Vistos");
        if (m->tipo.compare("Contacto") == 0) {
            li("Nombre Contacto: " + ((Contacto*) m) ->getContenido()->getNombre());
            li("Numero Contacto: " + ((Contacto*) m) ->getContenido()->getNumero());
        } else if (m->tipo.compare("Video") == 0) {
            li("Duracion de Video: " + ((Video*) m) ->getDuracion());
            li("Url: " + ((Video*) m) ->getURL());
        } else if (m->tipo.compare("Foto") == 0) {
            li("Descripcion : " + ((Foto*) m) ->getDesc());
            li("Formato : " + ((Foto*) m) ->getForm());
            li("Tamaño : " + ((Foto*) m) ->getTama());
            li("Ur : " + ((Foto*) m) ->getURL());
        }
        m->ImprimeVisto();
        li();
    } else {
        alarm("No se encontro mensaje con ese identificador");
    }
}


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
        this->addContacto(user);
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
