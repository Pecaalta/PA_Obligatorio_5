/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InterfazGrafica.h
 * Author: mauro
 *
 * Created on 3 de junio de 2018, 16:17
 */

#ifndef INTERFAZGRAFICA_H
#define INTERFAZGRAFICA_H

#include "string"
using namespace std;

void gotoxy(int x, int y);
void Color();
void Color(int col);
void Console(int ancho,int largo);

bool Rango(bool sent, bool exepcion);
bool Rango(bool sent);

void Subheader(string texto);
void header(string texto);
void header(bool limpiarPantalla, string texto);
string CinString();
string CinString(string texto);
int CinInt();
int CinInt(string texto);
void li();
void li(string texto);
void ol(string texto);
void ol();
int olNum();
void p(string texto);
bool olBool(int numero);
void alarm(string text);
#endif /* INTERFAZGRAFICA_H */

