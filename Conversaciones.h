#ifndef CONVERSACIONES_H
#define CONVERSACIONES_H

#include "iostream"
#include "string"
#include "string.h"

using namespace std;

#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/IIterator.h"
#include "ICollection/interfaces/IKey.h"
#include "ICollection/collections/List.h"

class Usuario;

class Conversaciones : public ICollectible {
public:
    IDictionary* getIntegrantes();
    void setIntegrantes(IDictionary* _integrantes);
    IDictionary* getMensaejs();
    void setMensaejs(IDictionary* _mensaejs);
    int getId();
    void setId(int _id);
    virtual string tipo();
    
    void commit();
    void addContacto(Usuario* user);
    void removeContacto(Usuario* user);
    bool isEmpty();
    void SolicitaListaContactos();
    void SolicitaListaContactosDetallada();
    void HacerAdministradores(IKey* k);
    bool getAdministradores(IKey* k);
    void setAdmin(Usuario* _user);
    IDictionary* getVistos();
    void setVistos(IDictionary* _vistos);
    
    Conversaciones(IDictionary* _integrantes, IDictionary* _mensaejs);
    Conversaciones(IDictionary* _integrantes);
    Conversaciones(Usuario* _user);
    Conversaciones();
    ~Conversaciones();
private:
    IDictionary* integrantes;
    IDictionary* mensaejs;
    IDictionary* visto;
    int id;
};


#include "Usuario.h"

#endif /* CONVERSACIONES_H */

