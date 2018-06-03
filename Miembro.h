#ifndef MIEMBRO_H
#define MIEMBRO_H

#include "Fecha.h"

#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IIterator.h"
#include "ICollection/collections/List.h"
#include "ICollection/String.h"

#include "string"
#include "string.h"
using namespace std;

class Usuario;
class Conversaciones;

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
    void addConversacion(Conversaciones* con);
    void ImprimeUsuario();
    void impresionSuperSimple();
    void ImprimeUsuarioDetallada();
    string getNumero();

    // Constructores y Destructores
    Miembro(bool _archivado, Fecha* _fecha);
    Miembro();
    ~Miembro();
private:
    Usuario* user;
    bool archivado;
    bool administrador;
    Conversaciones* Conversacion;
    Fecha* fecha;
};

#include "Conversaciones.h"
#include "Usuario.h"
#endif /* MIEMBRO_H */

