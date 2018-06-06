#ifndef USUARIO_H
#define USUARIO_H
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/IIterator.h"
#include "ICollection/interfaces/IKey.h"
#include "ICollection/collections/List.h"
#include "ICollection/String.h"
#include "Conversaciones.h"
#include "Miembro.h"
#include "Fecha.h"

#include "string"
#include "string.h"
#include "Grupo.h"
#include "Mensaje.h"
using namespace std;

class Usuario : public ICollectible {
public:
    string getNombre();
    void setNombre(string _nombre);
    string getNumero();
    void setNumero(string _numero);
    string getImagen();
    void setImagen(string _imagen);
    string getDireccion();
    void setDireccion(string _direccion);
    Fecha* getCreacion();
    void setCreacion(Fecha* _creacion);
    Fecha* getUltima();
    void setUltima(Fecha* _ultima);
    IDictionary* getConversaciones();
    void setConversaciones(IDictionary* _conversaciones);
    bool memberContactos(IKey* k);
    bool isEmptyContactos();
    Usuario* findContactos(IKey* k);
    IDictionary* getEstados();
    void setEstados(IDictionary* _estados);
    IDictionary* getMensajes();
    void setMensajes(IDictionary* _mensajes);
    void addConversacion(Usuario* user, Conversaciones* con);
    void addConversacion(Usuario* user, Miembro_Conversacion* miembro);
    
    
    void addGrupo(Miembro* con);
    void impresionSimple();
    void impresionSuperSimple();
    bool ListarMisGrupoas();
    void ListarMisGruposSimple();
    void ListarMisGruposSimpleArchivadas();
    
    bool AgregarAdministradores();

    void ListarMisConversaciones();
    void ListarMisConversacionesArchivadas();
    void ListarNombreDeGrupos();
    int CuentaArchivadas();
    int CuentaNoArchivadas();

    bool AltaGrupo();
    bool ModificarUsuario();
    int EnviarMensaje(int idMensaje);
    bool EliminarMensaje();
    bool VerMensajes();
    bool ArchivarConversaciones();
    bool AgregarParticipantes();
    bool EliminarParticipantes();

    bool member(IKey* k);
    void addContacto(Usuario* user);
    void SolicitaListaContactos();
    void ActualisarConeccion();

    // Constructores y Destructores
    Usuario(string _nombre, string _numero, string _imagen, string _direccion, Fecha* _creacion, Fecha* _ultima);
    Usuario();
    ~Usuario();
private:
    string nombre;
    string numero;
    string imagen;
    string direccion;
    Fecha* creacion;
    Fecha* ultima;
    IDictionary* grupos;
    IDictionary* conversaciones;
    IDictionary* contactos;
    IDictionary* estados;
    IDictionary* mensajes;
};


#endif /* USUARIO_H */