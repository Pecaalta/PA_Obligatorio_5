#include <stdio.h>
#include <time.h>

#include "InterfazGrafica.h"
#include "Fecha.h"

// Funciones de segundo

int Fecha::gets() {
    return this->s;
};

void Fecha::sets(int _s) {
    this->s = _s;
};

// Funciones de minuto

int Fecha::getm() {
    return this->m;
};

void Fecha::setm(int _m) {
    this->m = _m;
};

// Funciones de hora

int Fecha::geth() {
    return this->h;
};

void Fecha::seth(int _h) {
    this->h = _h;
};

// Funciones de Dia

int Fecha::getD() {
    return this->D;
};

void Fecha::setD(int _D) {
    this->D = _D;
};

// Funciones de Mes

int Fecha::getM() {
    return this->M;
};

void Fecha::setM(int _M) {
    this->M = _M;
};

// Funciones de Año

int Fecha::getA() {
    return this->A;
};

void Fecha::setA(int _A) {
    this->A = _A;
};

string Fecha::imprimeFecha() {
    return to_string(this->A) + "-" + to_string(this->M) + "-" + to_string(this->D) + " " + to_string(this->h) + ":" + to_string(this->m) + ":" + to_string(this->s);
};


// Funciones Actualiza Hora actual

void Fecha::Actual() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    this->s = 1 + ltm->tm_sec;
    this->m = 1 + ltm->tm_min;
    this->h = ltm->tm_hour;
    this->D = ltm->tm_mday;
    this->M = 1 + ltm->tm_mon;
    this->A = 1900 + ltm->tm_year;

}

// Constructores y Destructores

Fecha::Fecha(int _s, int _m, int _h, int _D, int _M, int _A) {
    this->s = _s;
    this->m = _m;
    this->h = _h;
    this->D = _D;
    this->M = _M;
    this->A = _A;
}

Fecha::Fecha() {
    this->Actual();
};

Fecha::~Fecha() {
};

bool Fecha::operator<(Fecha* rhs) {
    if (this->getA() == rhs->getA()) {
        if (this->getM() == rhs->getM()) {
            if (this->getD() == rhs->getD()) {
                if (this->geth() == rhs->geth()) {
                    if (this->getm() == rhs->getm()) {
                        if (this->gets() == rhs->gets()) {
                            return false;
                        } else {
                            return this->getA() < rhs->getA();
                        }
                    } else {
                        return this->getM() < rhs->getM();
                    }
                } else {
                    return this->getD() < rhs->getD();
                }
            } else {
                return this->geth() < rhs->geth();
            }
        } else {
            return this->getm() < rhs->getm();
        }
    } else {
        return this->gets() < rhs->gets();
    }
}
bool Fecha::operator<=(Fecha* rhs) {
    if (this->getA() == rhs->getA()) {
        if (this->getM() == rhs->getM()) {
            if (this->getD() == rhs->getD()) {
                if (this->geth() == rhs->geth()) {
                    if (this->getm() == rhs->getm()) {
                        if (this->gets() == rhs->gets()) {
                            return true;
                        } else {
                            return this->getA() < rhs->getA();
                        }
                    } else {
                        return this->getM() < rhs->getM();
                    }
                } else {
                    return this->getD() < rhs->getD();
                }
            } else {
                return this->geth() < rhs->geth();
            }
        } else {
            return this->getm() < rhs->getm();
        }
    } else {
        return this->gets() < rhs->gets();
    }
}