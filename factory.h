/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   factory.h
 * Author: Mauro
 *
 * Created on 8 de junio de 2018, 7:40
 */

#ifndef FACTORY_H
#define FACTORY_H

#include "ISistema.h"
#include "Sistema.h"


class factory {
public:
    static ISistema* CrearSistema();
    factory();
    factory(const factory& orig);
    virtual ~factory();
private:

};

#endif /* FACTORY_H */

