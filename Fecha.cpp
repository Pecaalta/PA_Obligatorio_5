/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fecha.cpp
 * Author: mauro
 * 
 * Created on 2 de junio de 2018, 8:58
 */

#include <stdio.h>
#include <time.h>

#include "Fecha.h"

// Funciones de s

int Fecha::gets() {
    return this->s;
};

void Fecha::sets(int _s) {
    this->s = _s;
};

// Funciones de m

int Fecha::getm() {
    return this->m;
};

void Fecha::setm(int _m) {
    this->m = _m;
};

// Funciones de h

int Fecha::geth() {
    return this->h;
};

void Fecha::seth(int _h) {
    this->h = _h;
};

// Funciones de D

int Fecha::getD() {
    return this->D;
};

void Fecha::setD(int _D) {
    this->D = _D;
};

// Funciones de M

int Fecha::getM() {
    return this->M;
};

void Fecha::setM(int _M) {
    this->M = _M;
};

// Funciones de A

int Fecha::getA() {
    return this->A;
};

void Fecha::setA(int _A) {
    this->A = _A;
};

// Constructores y Destructores

Fecha::Fecha(int _s, int _m, int _h, int _D, int _M, int _A) {
    this->s = _s;
    this->m = _m;
    this->h = _h;
    this->D = _D;
    this->M = _M;
    this->A = _A;
}

void Fecha::Actual() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    this->s = 1 + ltm->tm_sec;
    this->m = 1 + ltm->tm_min;
    this->h = 1 + ltm->tm_hour;
    this->D = ltm->tm_mday;
    this->M = 1 + ltm->tm_mon;
    this->A = 1970 + ltm->tm_year;

}

Fecha::Fecha() {
    this->Actual();
};

Fecha::~Fecha() {
};
