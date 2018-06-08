/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Foto.h
 * Author: Mauro
 *
 * Created on 7 de junio de 2018, 8:01
 */

#ifndef FOTO_H
#define FOTO_H

#include "string"
#include "string.h"
#include "Mensaje.h"
using namespace std;

class Foto: public Mensaje {
  public:
	string getURL();
	void  setURL(string _URL);
	string getForm();
	void  setForm(string _form);
	string getTama();
	void  setTama(string _tama);
	string getDesc();
	void  setDesc(string _desc);

	// Constructores y Destructores
	Foto(string _URL, string _form, string _tama, string _desc,int _id,string _texto,Usuario* _autor);
	Foto();
	~Foto();
  private:
	string URL;
	string form;
	string tama;
	string desc;
};


#endif /* FOTO_H */

