#include "Mensaje.h"
#include "Fecha.h"

#include "InterfazGrafica.h"
#include "string.h"

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

// Constructores y Destructores
Mensaje::Mensaje(Fecha* _fecha, int _id, string _texto, bool _borrado, Usuario* _autor ) {
	this->fecha = _fecha;
	this->id = _id;
	this->texto = _texto;
	this->borrado = _borrado;
	this->autor = _autor;
}
Mensaje::~Mensaje(){};
