#ifndef MIEMBRO_CONVERSACION_H
#define MIEMBRO_CONVERSACION_H

#include "Fecha.h"

#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IIterator.h"
#include "ICollection/collections/List.h"
#include "ICollection/String.h"

#include "string"
#include "string.h"
using namespace std;

class Usuario;
class Mensaje;
class Conversaciones;

class Miembro_Conversacion : public ICollectible {
public:
    bool getArchivado();
    void setArchivado(bool _archivado);
    Fecha* getFecha();
    void setFecha(Fecha* _fecha);
    Usuario* getUsuario();
    void setUsuario(Usuario* user);
    void addConversacion(Usuario* user, Conversaciones* con);
    Conversaciones* getConversacion();
    
    void ImprimeConversacion(Usuario* user);
    void ImprimeConversacion();
    void ImprimeUsuario();
    void impresionSuperSimple();
    void ImprimeUsuarioDetallada();
    string getNumero();
    void addMensaje(Mensaje* mens, string Numero);
    
    void MenuAgragaAdministrador();
    void SolicitaListaContactosDetallada();

    // Constructores y Destructores
    Miembro_Conversacion(Usuario* _yo,Usuario* _user );
    Miembro_Conversacion(Usuario* _user);
    Miembro_Conversacion(Usuario* _yo,Conversaciones* _con);
    Miembro_Conversacion();
    ~Miembro_Conversacion();
private:
    Usuario* user;
    bool archivado;
    Conversaciones* Conversacion;
    Fecha* fecha;
};

#include "Mensaje.h"
#include "Conversaciones.h"
#include "Usuario.h"
#endif /* MIEMBRO_CONVERSACION_H */

