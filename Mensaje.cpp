#include "Mensaje.h"
#include "Fecha.h"

#include "InterfazGrafica.h"
#include "Visto.h"
#include "string.h"
#include "ICollection/collections/OrderedDictionary.h"

using namespace std;

// Funciones de fecha

Fecha* Mensaje::getFecha() {
    return this->fecha;
};

void Mensaje::setFecha(Fecha* _fecha) {
    this->fecha = _fecha;
};

// Funciones de id

int Mensaje::getId() {
    return this->id;
};

void Mensaje::setId(int _id) {
    this->id = _id;
};

// Funciones de texto

string Mensaje::getTexto() {
    return this->texto;
};

void Mensaje::setTexto(string _texto) {
    this->texto = _texto;
};

// Funciones de borrado

bool Mensaje::getBorrado() {
    return this->borrado;
};

void Mensaje::setBorrado(bool _borrado) {
    this->borrado = _borrado;
};

// Funciones de autor

Usuario* Mensaje::getAutor() {
    return this->autor;
};

void Mensaje::setAutor(Usuario* _autor) {
    this->autor = _autor;
};

   void Mensaje::SetVisto(Usuario* _user){
       IKey* k = new String(_user->getNumero().c_str());
       Visto* v;
       if (!this->MVisto->member(k)){
           v = new Visto(_user);
           this->MVisto->add(k, v);
       }else{
           v  = (Visto*)this->MVisto->find(k);
           v->setFecha();
       }
   }
// Constructores y Destructores

Mensaje::Mensaje(int _id, string _texto, Usuario* _autor) {
    this->fecha = new Fecha();
    this->id = _id;
    this->texto = _texto;
    this->borrado = false;
    this->autor = _autor;
    this->MVisto = new OrderedDictionary;
}

Mensaje::~Mensaje() {
};

Mensaje::Mensaje() {
    this->borrado = false;
    this->fecha = new Fecha();
    this->MVisto = new OrderedDictionary;
};
