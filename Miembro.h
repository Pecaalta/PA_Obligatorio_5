/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Miembro.h
 * Author: mauro
 *
 * Created on 2 de junio de 2018, 8:55
 */

#ifndef MIEMBRO_H
#define MIEMBRO_H

#include "Fecha.h"

#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IIterator.h"
#include "ICollection/collections/List.h"
#include "ICollection/String.h"
#include "Usuario.h"

class Miembro : public ICollectible {
public:
    bool getArchivado();
    void setArchivado(bool _archivado);
    Fecha* getFecha();
    void setFecha(Fecha* _fecha);
    Usuario* getUsuario();
    void setUsuario(Usuario* user);
    bool getAdministrador();
    void setAdministrador(bool _admin);
    void addConversacion(Grupo* con);
    void ImprimeUsuario();
    void ImprimeUsuarioDetallada();

    // Constructores y Destructores
    Miembro(bool _archivado, Fecha* _fecha);
    Miembro();
    ~Miembro();
private:
    Usuario* user;
    bool archivado;
    bool administrador;
    Fecha* fecha;
};

#endif /* MIEMBRO_H */

