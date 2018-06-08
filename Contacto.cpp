/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Contacto.cpp
 * Author: Mauro
 * 
 * Created on 7 de junio de 2018, 8:06
 */

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
