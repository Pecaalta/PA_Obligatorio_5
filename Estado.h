/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estado.h
 * Author: mauro
 *
 * Created on 2 de junio de 2018, 9:13
 */

#ifndef ESTADO_H
#define ESTADO_H

#include "string.h"
#include <string>
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/IIterator.h"
#include "ICollection/collections/List.h"
#include "ICollection/String.h"
using namespace std;

class Estado : public ICollectible {
public:
    string getTexto();
    void setTexto(string _texto);
    IDictionary* getDestinatarios();
    void setDestinatarios(IDictionary* _destinatarios);

    // Constructores y Destructores
    Estado(string _texto, IDictionary* _destinatarios);
    Estado();
    ~Estado();
private:
    string texto;
    IDictionary* destinatarios;
};


#endif /* ESTADO_H */

