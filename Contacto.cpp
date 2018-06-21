
#include "Contacto.h"

// Funciones de Contenido
Usuario* Contacto::getContenido() {
	return this->Contenido;
};
void Contacto::setContenido(Usuario* _Contenido) { 
	this->Contenido = _Contenido;
};

// Constructores y Destructores
Contacto::Contacto( Usuario* _Contenido, int _id, string _texto, Usuario* _autor) : Mensaje(_id, _texto, _autor,"Contacto") {
	this->Contenido = _Contenido;
}
Contacto::~Contacto(){};
