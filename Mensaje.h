#ifndef MENSAJE_H
#define MENSAJE_H

#include "Fecha.h"
#include "Usuario.h"

#include "string"
#include "string.h"
using namespace std;
// Funciones de fecha

#include "ICollection/interfaces/IIterator.h"
#include "ICollection/collections/List.h"
#include "ICollection/String.h"
class Mensaje : public ICollectible {
public:
    Fecha* getFecha();
    void setFecha(Fecha* _fecha);
    int getId();
    void setId(int _id);
    string getTexto();
    void setTexto(string _texto);
    bool getBorrado();
    void setBorrado(bool _borrado);
    Usuario* getAutor();
    void setAutor(Usuario* _autor);

    // Constructores y Destructores
    Mensaje(int _id, string _texto, Usuario* _autor);
    Mensaje();
    ~Mensaje();
private:
    Fecha* fecha;
    int id;
    string texto;
    bool borrado;
    Usuario* autor;
};

#endif /* MENSAJE_H */

