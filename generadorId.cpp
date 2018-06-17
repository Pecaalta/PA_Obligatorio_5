/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   generadorId.cpp
 * Author: Mauro
 * 
 * Created on 17 de junio de 2018, 17:42
 */

#include "generadorId.h"


int generadorId::getid() {
    int temp = id;
    id++;
    return temp;
}

