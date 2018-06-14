#ifndef ISISTEMA_H
#define ISISTEMA_H
#include "Usuario.h"
#include "ICollection/interfaces/IDictionary.h"

class ISistema {
public:
    virtual bool AbrirGuasapTECNO() = 0;
    virtual bool CerrarGuasapTECNO() = 0;
    virtual bool AgregarContactos() = 0;
    virtual bool AltaGrupo() = 0;
    virtual bool AgregarAdministradores() = 0;
    virtual bool EnviarMensaje() = 0;
    virtual bool VerMensajes() = 0;
    virtual bool ArchivarConversaciones() = 0;
    virtual bool AgregarParticipantes() = 0;
    virtual bool EliminarParticipantes() = 0;
    virtual bool ModificarUsuario() = 0;
    virtual bool EliminarMensaje() = 0;

    virtual void CargarUsuario() = 0;
    virtual bool ListarOpciones() = 0;

    virtual ~ISistema() {
    };
};



#endif /* ISISTEMA_H */

