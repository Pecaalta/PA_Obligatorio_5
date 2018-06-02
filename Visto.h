/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Visto.h
 * Author: mauro
 *
 * Created on 2 de junio de 2018, 9:13
 */

#ifndef VISTO_H
#define VISTO_H
#include "Usuario.h"
#include "Fecha.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IIterator.h"
#include "ICollection/collections/List.h"
#include "ICollection/String.h"

class Visto : public ICollectible{
  public:
	Usuario* getUsuario();
	void  setUsuario(Usuario* _usuario);
	Fecha* getFecha();
	void  setFecha(Fecha* _fecha);
	int getIdmensaje();
	void  setIdmensaje(int _idmensaje);

	// Constructores y Destructores
	Visto(Usuario* _usuario, Fecha* _fecha, int _idmensaje );
	Visto(Usuario* _usuario);
	Visto();
	~Visto();
  private:
	Usuario* usuario;
	Fecha* fecha;
	int idmensaje;
};


#endif /* VISTO_H */

