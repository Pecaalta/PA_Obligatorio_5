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
#include "Contacto.h"
#include "Video.h"
#include "Foto.h"
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
    mens->SetVisto(this->user1->getUsuario());
    mens->SetVisto(this->user2->getUsuario());
    ((Miembro*)this->user1->getUsuario()->getConversaciones()->find( new String( this->user2->getUsuario()->getNumero().c_str() ) ))->setArchivado(false);
    ((Miembro*)this->user2->getUsuario()->getConversaciones()->find( new String( this->user1->getUsuario()->getNumero().c_str() ) ))->setArchivado(false);
    if (Numero.compare(this->user1->getNumeroUsuario()) != 0) {
        Visto* v = this->user1;
        v->setIdmensaje(mens->getId());
        v->setFecha();
    } else {
        Visto* v = this->user2;
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

void Conversaciones::ImprimeMensajes(Usuario* user) {
    Mensaje* m;
    int id = this->user1->getIdmensaje();
    int cont = 0;
    li();
    if (!this->mensaejs->isEmpty()) {
        IIterator* it = this->mensaejs->getIterator();
        while (it->hasCurrent()) {
            m = (Mensaje*) it->getCurrent();
            //if (id < m->getId()) {
            m->SetVisto(user);
            if (!m->getBorrado(user)) {
                cont++;
                li("-");
                li("Id: " + to_string(m->getId()));
                li("Autor: " + m->getAutor()->getNombre());
                li("Texto: " + m->getTexto());
                if (m->tipo.compare("Contacto") == 0) {
                    li("Nombre Contacto: " + ((Contacto*) m) ->getContenido()->getNombre());
                    li("Numero Contacto: " + ((Contacto*) m) ->getContenido()->getNumero());
                } else if (m->tipo.compare("Video") == 0) {
                    li("Durecion de Video: " + ((Video*) m) ->getDuracion());
                    li("Url: " + ((Video*) m) ->getURL());
                } else if (m->tipo.compare("Foto") == 0) {
                    li("Descripcion : " + ((Foto*) m) ->getDesc());
                    li("Formato : " + ((Foto*) m) ->getForm());
                    li("Tamaño : " + ((Foto*) m) ->getTama());
                    li("Ur : " + ((Foto*) m) ->getURL());
                }
                li("-");
                //}
            }
            it->next();
        }
        delete it;
    }
    if (cont == 0) {
        li("-");
        li("No tines Contactos");
        li("-");
    }
    li();
};

void Conversaciones::ImprimeMensajeDetallado(string numbre) {
    header("Mensajes");
    IKey* k = new String(numbre.c_str());
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
            li("Durecion de Video: " + ((Video*) m) ->getDuracion());
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

void Conversaciones::EliminarMensaje(string numbre, Usuario* user) {
    IKey* k = new String(numbre.c_str());
    if (this->mensaejs->member(k)) {
        Mensaje* m = (Mensaje*)this->mensaejs->find(k);
        if (m->getAutor()->getNumero().compare(user->getNumero()) == 0) {
            this->mensaejs->remove(k);
            delete m;
        } else {
            m->serBorrado(user);
        }
    } else {
        alarm("No se encontro mensaje con ese identificador");
    }
}

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