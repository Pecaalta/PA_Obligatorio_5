/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mauro
 *
 * Created on 2 de junio de 2018, 8:46
 */

#include <cstdlib>

#include "ISistema.h"
#include "Sistema.h"
#include "iostream"
#include "string"
using namespace std;

int main(int argc, char** argv) {
    ISistema* sis = Sistema::getInstance();
    sis->CargarUsuario();
    while(!sis->ListarOpciones());
    return 0;
}

