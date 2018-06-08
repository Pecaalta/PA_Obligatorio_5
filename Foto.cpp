/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Foto.cpp
 * Author: Mauro
 * 
 * Created on 7 de junio de 2018, 8:01
 */

#include "Foto.h"

// Funciones de URL
string Foto::getURL() {
	return this->URL;
};
void Foto::setURL(string _URL) { 
	this->URL = _URL;
};

// Funciones de form
string Foto::getForm() {
	return this->form;
};
void Foto::setForm(string _form) { 
	this->form = _form;
};

// Funciones de tama
string Foto::getTama() {
	return this->tama;
};
void Foto::setTama(string _tama) { 
	this->tama = _tama;
};

// Funciones de desc
string Foto::getDesc() {
	return this->desc;
};
void Foto::setDesc(string _desc) { 
	this->desc = _desc;
};

// Constructores y Destructores
Foto::Foto(string _URL, string _form, string _tama, string _desc,int _id,string _texto,Usuario* _autor ):Mensaje( _id, _texto, _autor,"Foto") {
	this->URL = _URL;
	this->form = _form;
	this->tama = _tama;
	this->desc = _desc;
}
Foto::~Foto(){};
