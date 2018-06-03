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


class Grupo : public Conversaciones {
public:
    string getNombre();
    void setNombre(string _nombre);
    string getImagen();
    void setImagen(string _imagen);
    virtual string tipo();

    void impresionSimple();
    void impresionSuperSimple();
    // Constructores y Destructores
    Grupo(string _nombre, string _imagen);
    Grupo();
    ~Grupo();
private:
    string nombre;
    string imagen;
};

#include "Usuario.h"
#endif /* GRUPO_H */

