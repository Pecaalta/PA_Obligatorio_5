#include "Conversaciones.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "ICollection/String.h"
#include "ICollection/interfaces/IKey.h"

#include "InterfazGrafica.h"
#include "Usuario.h"
#include "Miembro.h"
#include "Visto.h"
#include "Miembro_Conversacion.h"
int id = 0;
// Funciones de mensaejs

IDictionary* Conversaciones::getMensaejs() {
    return this->mensaejs;
};

void Conversaciones::setMensaejs(IDictionary* _mensaejs) {
    this->mensaejs = _mensaejs;
};

void Conversaciones::addMensaje(Mensaje* mens, string Numero) {
    IKey* k = new String(to_string(mens->getId()).c_str());
    this->mensaejs->add(k, mens);
    if (Numero.compare(this->user1->getNumeroUsuario()) != 0) {
        Visto* v = (Visto*)this->user1;
        v->setIdmensaje(mens->getId());
        v->setFecha();
    } else {
        Visto* v = (Visto*)this->user2;
        v->setIdmensaje(mens->getId());
        v->setFecha();

    }
}
// Funciones de user

Usuario* Conversaciones::getUser1() {
    return this->user1->getUsuario();
};

void Conversaciones::setUser1(Usuario* _user) {
    Visto* v = new Visto(_user);
    this->user1 = v;
};

Usuario* Conversaciones::getUser2() {
    return this->user2->getUsuario();
};

void Conversaciones::setUser2(Usuario* _user) {
    Visto* v = new Visto(_user);
    this->user2 = v;
};

string Conversaciones::tipo() {
    return "Conversaciones";
};

string Conversaciones::getId() {
    this->id;
};

void Conversaciones::impresionSimple() {
    li("Nombre: " + this->user1->getUsuario()->getNumero());
    li("Imagen: " + this->user2->getUsuario()->getNumero());
};

void Conversaciones::impresionSimple(Usuario* _user) {
    if ((_user->getNumero()).compare(this->user1->getNumeroUsuario()) == 0) {
        li("Nombre: " + this->user2->getUsuario()->getNombre());
        li("Numero: " + this->user2->getUsuario()->getNumero());
    } else {
        li("Nombre: " + this->user1->getUsuario()->getNombre());
        li("Numero: " + this->user1->getUsuario()->getNumero());
    }
};

void Conversaciones::impresionSimple(string _user) {
    if ((_user).compare(this->user1->getUsuario()->getNumero()) == 0) {
        li("Imagen: " + this->user2->getUsuario()->getNumero());
    } else {
        li("Nombre: " + this->user1->getUsuario()->getNumero());
    }
};

void Conversaciones::ImprimeMensajes() {
    Mensaje* m;
    int id = this->user1->getIdmensaje();
    li();
    if (!this->mensaejs->isEmpty()) {
        IIterator* it = this->mensaejs->getIterator();
        while (it->hasCurrent()) {
            m = (Mensaje*) it->getCurrent();
            if (id < m->getId() ) {
                li("-");
                li("Autor: " + m->getAutor()->getNombre());
                li("Contenido: " + m->getTexto());
                li("-");
            }
            it->next();
        }
        delete it;
    } else {
        li("-");
        li("No tines Contactos");
        li("-");
    }
    li();
};
// Constructores y Destructores

/*
Conversaciones::Conversaciones(Usuario* _user_1, Usuario* _user_2, IDictionary* _mensaejs) {
    this->user1 = new Visto(_user_1);
    this->user2 = new Visto(_user_2);
    this->mensaejs = _mensaejs;
}*/
Conversaciones::Conversaciones(Usuario* _user_1) {
    this->user1 = new Visto(_user_1);
    this->user2 = NULL;
    this->mensaejs = new OrderedDictionary();
}

Conversaciones::Conversaciones(Miembro_Conversacion* mimbro) {
    this->user1 = new Visto(mimbro->getUsuario());
    this->user2 = NULL;
    this->mensaejs = new OrderedDictionary();
}

Conversaciones::Conversaciones(Usuario* _user_1, Usuario* _user_2) {
    this->user1 = new Visto(_user_1);
    this->user2 = new Visto(_user_2);
    this->mensaejs = new OrderedDictionary();
    _user_1->addConversacion(_user_2, this);
    _user_2->addConversacion(_user_1, this);
}

Conversaciones::Conversaciones(Miembro_Conversacion* mimbro, Usuario* _user_2) {
    this->user1 = new Visto(mimbro->getUsuario());
    this->user2 = new Visto(_user_2);
    this->mensaejs = new OrderedDictionary();
    _user_2->addConversacion(mimbro->getUsuario(), this);
}

Conversaciones::Conversaciones() {
    this->user1 = NULL;
    this->user2 = NULL;
    this->mensaejs = new OrderedDictionary();
}

Conversaciones::~Conversaciones() {
};