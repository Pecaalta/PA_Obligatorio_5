/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   factory.cpp
 * Author: Mauro
 * 
 * Created on 8 de junio de 2018, 7:40
 */

#include "factory.h"

#include "Sistema.h"

ISistema* factory::CrearSistema() {
    return Sistema::getInstance();
}

factory::factory() {
}

factory::factory(const factory& orig) {
}

factory::~factory() {
}

