#include "Conversaciones.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "ICollection/String.h"
#include "ICollection/interfaces/IKey.h"

#include "InterfazGrafica.h"
#include "Usuario.h"
#include "Miembro.h"
#include "Visto.h"

// Funciones de mensaejs
IDictionary* Conversaciones::getMensaejs() {
    return this->mensaejs;
};
void Conversaciones::setMensaejs(IDictionary* _mensaejs) {
    this->mensaejs = _mensaejs;
};

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

// Constructores y Destructores

Conversaciones::Conversaciones(Usuario* _user_1, Usuario* _user_2, IDictionary* _mensaejs) {
    this->user1 = new Visto(_user_1);
    this->user2 = new Visto(_user_2);
    this->mensaejs = _mensaejs;
}

Conversaciones::Conversaciones(Usuario* _user_1, Usuario* _user_2) {
    this->user1 = new Visto(_user_1);
    this->user2 = new Visto(_user_2);
    this->mensaejs = new OrderedDictionary();

}

Conversaciones::Conversaciones() {
    this->user1 = NULL;
    this->user2 = NULL;
    this->mensaejs = new OrderedDictionary();
}

Conversaciones::~Conversaciones() {
};