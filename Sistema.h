#ifndef SISTEMA_H
#define SISTEMA_H
#include "Usuario.h"
#include "ISistema.h"
#include "ICollection/interfaces/IDictionary.h"

class Sistema : public ISistema {
public:
    Usuario* getActivo();
    void setActivo(Usuario* _activo);
    IDictionary* getUsuarios();
    void setUsuarios(IDictionary* _usuarios);
    IDictionary* getConversaciones();
    void setConversaciones(IDictionary* _conversaciones);
    IDictionary* getEstados();
    void setEstados(IDictionary* _estados);

    bool AbrirGuasapTECNO();
    bool CerrarGuasapTECNO();
    bool AgregarContactos();
    bool AltaGrupo();
    bool AgregarAdministradores();
    bool EnviarMensaje();
    bool VerMensajes();
    bool ArchivarConversaciones();
    bool AgregarParticipantes();
    bool EliminarParticipantes();
    bool ModificarUsuario();
    bool EliminarMensaje();

    //Funciones Internas
    void NuevoUsuario(string Numero);
    void CargarUsuario();
    void SolicitaListaContactos();
    void CargarUsuarioLocal();
    void ActualizaUsuarioLocal();

    // Pantallas
    bool ListarOpciones();
    // Constructores y Destructores
    ~Sistema();
    static Sistema* getInstance();
private:
    static Sistema* instance;
    Sistema(Usuario* _activo, IDictionary* _usuarios, IDictionary* _conversaciones);
    Sistema();
    bool log;
    int IDMensaje;
    Usuario* activo;
    IDictionary* usuarios;
    IDictionary* conversaciones;
    IDictionary* grupos;
    ICollection* estados;
};



#endif /* SISTEMA_H */

