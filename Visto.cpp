/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Visto.cpp
 * Author: mauro
 * 
 * Created on 2 de junio de 2018, 9:13
 */

#include "Visto.h"
#include "Usuario.h"
#include "Fecha.h"
#include "ICollection/collections/OrderedDictionary.h"


// Funciones de usuario
Usuario* Visto::getUsuario() {
	return this->usuario;
};
void Visto::setUsuario(Usuario* _usuario) { 
	this->usuario = _usuario;
};

// Funciones de fecha
Fecha* Visto::getFecha() {
	return this->fecha;
};
void Visto::setFecha(Fecha* _fecha) { 
	this->fecha = _fecha;
};

// Funciones de idmensaje
int Visto::getIdmensaje() {
	return this->idmensaje;
};
void Visto::setIdmensaje(int _idmensaje) { 
	this->idmensaje = _idmensaje;
};

// Constructores y Destructores
Visto::Visto(Usuario* _usuario, Fecha* _fecha, int _idmensaje ) {
	this->usuario = _usuario;
	this->fecha = _fecha;
	this->idmensaje = _idmensaje;
}
Visto::Visto(Usuario* _usuario) {
	this->usuario = _usuario;
	this->fecha = new Fecha();
	this->idmensaje = -1;
}
Visto::Visto() {
	this->usuario = NULL;
	this->fecha = new Fecha();
	this->idmensaje = -1;
}
Visto::~Visto(){};
