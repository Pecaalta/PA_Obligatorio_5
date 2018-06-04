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
class Grupo;

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
    Grupo* getConversacion();
    
    void ImprimeGrupo();
    void ImprimeUsuario();
    void impresionSuperSimple();
    void ImprimeUsuarioDetallada();
    string getNumero();
    
    void MenuAgragaAdministrador();
    void SolicitaListaContactosDetallada();

    // Constructores y Destructores
    Miembro(Usuario* _user,Grupo* _grupo );
    Miembro(Usuario* _user);
    Miembro();
    ~Miembro();
private:
    Usuario* user;
    bool archivado;
    bool administrador;
    Grupo* Conversacion;
    Fecha* fecha;
};

#include "Grupo.h"
#include "Usuario.h"
#endif /* MIEMBRO_H */

