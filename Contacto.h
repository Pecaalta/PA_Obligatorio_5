/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Contacto.h
 * Author: Mauro
 *
 * Created on 7 de junio de 2018, 8:06
 */

#ifndef CONTACTO_H
#define CONTACTO_H

#include "Mensaje.h"


class Contacto:public Mensaje {
  public:
	Usuario* getContenido();
	void  setContenido(Usuario* _Contenido);

	// Constructores y Destructores
	Contacto(Usuario* _Contenido, int _id, string _texto, Usuario* _autor);
	Contacto();
	~Contacto();
  private:
	Usuario* Contenido;
}
;

#endif /* CONTACTO_H */

