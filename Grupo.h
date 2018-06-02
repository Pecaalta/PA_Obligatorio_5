/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grupo.h
 * Author: mauro
 *
 * Created on 2 de junio de 2018, 14:20
 */

#ifndef GRUPO_H
#define GRUPO_H

#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/IIterator.h"
#include "ICollection/collections/List.h"
#include "ICollection/String.h"
#include "Fecha.h"

#include "iostream"
#include "string"
#include "string.h"
using namespace std;

class Usuario;

class Grupo : public ICollectible {
public:
    IDictionary* getIntegrantes();
    void setIntegrantes(IDictionary* _integrantes);
    IDictionary* getMensaejs();
    void setMensaejs(IDictionary* _mensaejs);

    void commit();
    void addContacto(Usuario* user);
    void removeContacto(Usuario* user);
    bool isEmpty();
    void SolicitaListaContactos();
    void SolicitaListaContactosDetallada();
    void HacerAdministradores(IKey* k);
    bool getAdministradores(IKey* k);
    void setAdmin(Usuario* _user);

    string getNombre();
    void setNombre(string _nombre);
    string getImagen();
    void setImagen(string _imagen);
    Fecha* getCreacion();
    void setCreacion(Fecha* _creacion);
    IDictionary* getVistos();
    void setVistos(IDictionary* _vistos);
    void impresionSimple();
    // Constructores y Destructores
    Grupo(string _nombre, string _imagen);
    Grupo(Usuario* _user);
    Grupo();
    ~Grupo();
private:
    IDictionary* integrantes;
    IDictionary* mensaejs;
    IDictionary* visto;
    string nombre;
    string imagen;
    Fecha* creacion;
};

#include "Usuario.h"

#endif /* GRUPO_H */

