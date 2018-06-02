/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conversaciones.h
 * Author: mauro
 *
 * Created on 2 de junio de 2018, 9:13
 */

#ifndef CONVERSACIONES_H
#define CONVERSACIONES_H

#include "iostream"
#include "string"
#include "string.h"

using namespace std;

#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/IIterator.h"
#include "ICollection/interfaces/IKey.h"
#include "ICollection/collections/List.h"

class Usuario;

class Conversaciones : public ICollectible {
public:
    IDictionary* getIntegrantes();
    void setIntegrantes(IDictionary* _integrantes);
    IDictionary* getMensaejs();
    void setMensaejs(IDictionary* _mensaejs);
    int getId();
    void setId(int _id);

    // Constructores y Destructores
    Conversaciones(IDictionary* _integrantes, IDictionary* _mensaejs);
    Conversaciones(IDictionary* _integrantes);
    Conversaciones(Usuario* _user);
    Conversaciones();
    ~Conversaciones();
private:
    IDictionary* integrantes;
    IDictionary* mensaejs;
    IDictionary* visto;
    int id;
};


#include "Usuario.h"

#endif /* CONVERSACIONES_H */

