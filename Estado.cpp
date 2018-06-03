#include "Estado.h"
#include "string.h"
#include "ICollection/interfaces/IDictionary.h"

#include "InterfazGrafica.h"
using namespace std;

// Funciones de texto
string Estado::getTexto() {
	return this->texto;
};
void Estado::setTexto(string _texto) { 
	this->texto = _texto;
};

// Funciones de destinatarios
IDictionary* Estado::getDestinatarios() {
	return this->destinatarios;
};
void Estado::setDestinatarios(IDictionary* _destinatarios) { 
	this->destinatarios = _destinatarios;
};

// Constructores y Destructores
Estado::Estado(string _texto, IDictionary* _destinatarios ) {
	this->texto = _texto;
	this->destinatarios = _destinatarios;
}
Estado::~Estado(){};