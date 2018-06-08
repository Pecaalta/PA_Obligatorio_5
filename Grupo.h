#ifndef GRUPO_H
#define GRUPO_H

#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/IIterator.h"
#include "ICollection/collections/List.h"
#include "ICollection/String.h"

#include "Conversaciones.h"

#include "iostream"
#include "string"
#include "string.h"

using namespace std;

class Grupo : public ICollectible {
public:
    string getNombre();
    void setNombre(string _nombre);

    string getImagen();
    void setImagen(string _imagen);

    void impresionSimple();
    void impresionSuperSimple();

    IDictionary* getMensaejs();
    void setMensaejs(IDictionary* _mensaejs);

    IDictionary* getIntegrantes();
    void setIntegrantes(IDictionary* _integrantes);

    void addMensaje(Mensaje* mens, string Numero);
    string tipo();
    
    void ImprimeMensajes(Usuario* user);
    void ImprimeMensajeDetallado(string numbre);

    // Constructores y Destructores
    Grupo(string _nombre, string _imagen);
    Grupo(string _nombre, string _imagen, IDictionary* contactos);
    Grupo();
    ~Grupo();

    bool isEmpty();
    void addContacto(Usuario* user);
    void removeContacto(Usuario* user);
    int getId();
    void setId(int _id);
    void commit();
    void SolicitaListaContactos();
    void SolicitaListaContactosDetallada();
    void HacerAdministradores(IKey* k);
    bool getAdministradores(IKey* k);
    void setAdmin(Usuario* _user);
    IDictionary* getVistos();
    void setVistos(IDictionary* _vistos);


private:
    IDictionary* integrantes;
    IDictionary* mensaejs;
    IDictionary* visto;
    string nombre;
    string imagen;
};

#include "Usuario.h"
#endif /* GRUPO_H */

