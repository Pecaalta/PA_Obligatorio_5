#ifndef SISTEMA_H
#define SISTEMA_H
#include "Usuario.h"
#include "ICollection/interfaces/IDictionary.h"

class Sistema {
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

    // Pantallas
    bool ListarOpciones();
    // Constructores y Destructores
    Sistema(Usuario* _activo, IDictionary* _usuarios, IDictionary* _conversaciones, IDictionary* _estados);
    Sistema();
    ~Sistema();
private:
    bool log;
    int IndexConversacion;
    Usuario* activo;
    IDictionary* usuarios;
    IDictionary* conversaciones;
    IDictionary* grupos;
    IDictionary* estados;
};



#endif /* SISTEMA_H */

