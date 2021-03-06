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
    void SetVisto(Usuario* _user);
    bool getBorrado(Usuario* _user);
    void serBorrado(Usuario* _user);
    void ImprimeVisto();
    string tipo;

    // Constructores y Destructores
    Mensaje(int _id, string _texto, Usuario* _autor);
    Mensaje(int _id, string _texto, Usuario* _autor, string tipo);
    Mensaje();
    ~Mensaje();
private:
    Fecha* fecha;
    int id;
    string texto;
    bool borrado;
    IDictionary* MVisto;
    Usuario* autor;
};

#endif /* MENSAJE_H */

