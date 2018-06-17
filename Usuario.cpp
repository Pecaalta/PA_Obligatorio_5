#include <windef.h>

#include "Usuario.h"
#include "string"
#include "string.h"

#include "InterfazGrafica.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "ICollection/Integer.h"
#include "Conversaciones.h"
#include "Grupo.h"
#include "Miembro.h"
#include "Mensaje.h"
#include "Miembro_Conversacion.h"
#include "Foto.h"
#include "Video.h"
#include "Contacto.h"
#include "Estado.h"

using namespace std;

// Funciones de nombre

string Usuario::getNombre() {
    return this->nombre;
};

void Usuario::setNombre(string _nombre) {
    this->nombre = _nombre;
};

// Funciones de numero

string Usuario::getNumero() {
    return this->numero;
};

void Usuario::setNumero(string _numero) {
    this->numero = _numero;
};

// Funciones de imagen

string Usuario::getImagen() {
    return this->imagen;
};

void Usuario::setImagen(string _imagen) {
    this->imagen = _imagen;
};

// Funciones de direccion

string Usuario::getDireccion() {
    return this->direccion;
};

void Usuario::setDireccion(string _direccion) {
    this->direccion = _direccion;
};

// Funciones de creacion

Fecha* Usuario::getCreacion() {
    return this->creacion;
};

void Usuario::setCreacion(Fecha* _creacion) {
    this->creacion = _creacion;
};

// Funciones de ultima

Fecha* Usuario::getUltima() {
    return this->ultima;
};

void Usuario::setUltima(Fecha* _ultima) {
    this->ultima = _ultima;
};

// Funciones de conversaciones

IDictionary* Usuario::getConversaciones() {
    return this->conversaciones;
};

void Usuario::setConversaciones(IDictionary* _conversaciones) {
    this->conversaciones = _conversaciones;
};

bool Usuario::memberContactos(IKey* k) {
    return (!this->contactos->isEmpty() and this->contactos->member(k));
}

bool Usuario::isEmptyContactos() {
    return this->contactos->isEmpty();
}

Usuario* Usuario::findContactos(IKey* k) {
    return (Usuario*) this->contactos->find(k);
};

bool Usuario::member(IKey * k) {
    return !this->contactos->isEmpty() and this->contactos->member(k);
};

void Usuario::addContacto(Usuario * user) {
    IKey* k = new String(user->getNumero().c_str());
    this->contactos->add(k, user);
};

void Usuario::ActualisarConeccion() {
    this->ultima->Actual();
};

// Funciones de mensajes

IDictionary* Usuario::getMensajes() {
    return this->mensajes;
};

void Usuario::setMensajes(IDictionary* _mensajes) {
    this->mensajes = _mensajes;
};

// Conversacion

void Usuario::addGrupo(Miembro* con) {
    IKey* k = new String(con->getConversacion()->getNombre().c_str());
    if (this->grupos->member(k)) {
        alarm("El contacto ya pertenece al grupo");
    } else {
        this->grupos->add(k, con);
    }
}

void Usuario::removeGrupo(IKey* k) {
    if (this->grupos->member(k)) {
        this->grupos->remove(k);
    } else {
        alarm("El contacto no pertenece al grupo");
    }

}

void Usuario::addConversacion(Usuario* user, Conversaciones* con) {
    IKey* k = new String(user->getNumero().c_str());
    Miembro_Conversacion* MIM = new Miembro_Conversacion(this, con);
    this->conversaciones->add(k, MIM);
}

void Usuario::addConversacion(Usuario* user, Miembro_Conversacion* miembro) {
    IKey* k = new String(user->getNumero().c_str());
    this->conversaciones->add(k, miembro);
}
// Imprimir

void Usuario::impresion() {
    li("Nombre: " + this->nombre);
    li("Numero: " + this->numero);
    li("Imagen: " + this->imagen);
    li("Descripcion: " + this->direccion);
}

void Usuario::impresionSimple() {
    li("Nombre: " + this->nombre);
    li("Numero: " + this->numero);
    li("Imagen: " + this->imagen);
}

void Usuario::impresionSuperSimple() {
    li("Nombre: " + this->nombre);
    li("Numero: " + this->numero);
}




//Cuenta Archivadas

int Usuario::CuentaNoArchivadas() {
    int count = 0;
    Miembro* n;
    Miembro_Conversacion* m;
    if (!this->grupos->isEmpty()) {
        IIterator* it = this->grupos->getIterator();
        while (it->hasCurrent()) {
            n = (Miembro*) it->getCurrent();
            if (!n->getArchivado()) {
                count++;
            }
            it->next();
        }
        delete it;
    }
    if (!this->conversaciones->isEmpty()) {
        IIterator* it2 = this->conversaciones->getIterator();
        while (it2->hasCurrent()) {
            m = (Miembro_Conversacion*) it2->getCurrent();
            if (!m->getArchivado()) {
                count++;
            }
            it2->next();
        }
        delete it2;
    }
    return count;
}

int Usuario::CuentaArchivadas() {
    int count = 0;
    Miembro* n;
    Miembro_Conversacion* m;
    if (!this->grupos->isEmpty()) {
        IIterator* it = this->grupos->getIterator();
        while (it->hasCurrent()) {
            n = (Miembro*) it->getCurrent();
            if (n->getArchivado()) {
                count++;
            }
            it->next();
        }
        delete it;
    }
    if (!this->conversaciones->isEmpty()) {
        IIterator* it2 = this->conversaciones->getIterator();
        while (it2->hasCurrent()) {
            m = (Miembro_Conversacion*) it2->getCurrent();
            if (m->getArchivado()) {
                count++;
            }
            it2->next();
        }
        delete it2;
    }
    return count;
}

// Listados

void Usuario::ListarMisGruposSimple() {
    Subheader("Tus Grupos");
    Miembro* n;
    int cont = 0;
    li();
    if (!this->grupos->isEmpty()) {
        IIterator* it = this->grupos->getIterator();
        while (it->hasCurrent()) {
            n = (Miembro*) it->getCurrent();
            if (!n->getArchivado()) {
                li("-");
                n->impresionNombreGrupo();
                li("-");
                cont++;
            }
            it->next();
        }
        if (cont == 0) {
            li("-");
            li("No tienes Grupos");
            li("-");
        }
        delete it;
    } else {
        li("-");
        li("No tienes Grupos");
        li("-");
    }
    li();
}

void Usuario::ListarMisGruposSimpleArchivadas() {
    Subheader("Tus Grupos Archivados");
    Miembro* n;
    int cont = 0;
    li();
    if (!this->grupos->isEmpty()) {
        IIterator* it = this->grupos->getIterator();
        while (it->hasCurrent()) {
            n = (Miembro*) it->getCurrent();
            if (n->getArchivado()) {
                li("-");
                n->impresionNombreGrupo();
                li("-");
            } else {
                cont++;
            }
            it->next();
        }
        if (cont == 0) {
            li("-");
            li("No tienes Grupos");
            li("-");
        }
        delete it;
    } else {
        li("-");
        li("No tienes Grupos");
        li("-");
    }
    li();
}

bool Usuario::ListarMisGrupoas() {
    if (!this->grupos->isEmpty()) {
        Subheader("Tus Grupos");
        Miembro* n;
        int cont = 0;
        li();
        IIterator* it = this->grupos->getIterator();
        while (it->hasCurrent()) {
            n = (Miembro*) it->getCurrent();
            li("-");
            n->ImprimeGrupo();
            li("-");
            it->next();
        }
        delete it;
        li();
        return true;
    } else {
        alarm("No tienes Grupos");
        return false;
    }
}

void Usuario::ListarMisConversacionesArchivadas() {
    Subheader("Tus Conversaciones Archivadas");
    Miembro_Conversacion* n;
    int cont = 0;
    li();
    if (!this->conversaciones->isEmpty()) {
        IIterator* it = this->conversaciones->getIterator();
        while (it->hasCurrent()) {
            n = (Miembro_Conversacion*) it->getCurrent();
            if (n->getArchivado()) {
                li("-");
                n->ImprimeConversacion(this);
                li("-");
                cont++;
            }
            it->next();
        }
        if (cont == 0) {
            li("-");
            li("No tienes Conversaciones");
            li("-");
        }
        delete it;
    } else {
        li("-");
        li("No tienes Conversaciones");
        li("-");
    }
    li();
};

void Usuario::ListarMisConversaciones() {
    Subheader("Tus Conversaciones Activas");
    Miembro_Conversacion* n;
    li();
    int cont = 0;
    if (!this->conversaciones->isEmpty()) {
        IIterator* it = this->conversaciones->getIterator();
        while (it->hasCurrent()) {
            n = (Miembro_Conversacion*) it->getCurrent();
            if (!n->getArchivado()) {
                li("-");
                n->ImprimeConversacion(this);
                li("-");
                cont++;
            }
            it->next();
        }
        if (cont == 0) {
            li("-");
            li("No tienes Conversaciones");
            li("-");
        }
        delete it;
    } else {
        li("-");
        li("No tienes Conversaciones Activas");
        li("-");
    }
    li();
}

void Usuario::SolicitaListaContactos() {
    Usuario* n;
    Subheader("Tus Contactos");
    cout << endl;
    li();
    if (!this->contactos->isEmpty()) {
        IIterator* it = this->contactos->getIterator();
        while (it->hasCurrent()) {
            n = (Usuario*) it->getCurrent();
            li("-");
            li("Nombre " + n->getNombre());
            li("Numero " + n->getNumero());
            li("Imagen " + n->getImagen());
            li("Descripcion " + n->getDireccion());
            li("-");
            it->next();
        }
        delete it;
    } else {
        li("-");
        li("No tienes Contactos");
        li("-");
    }
    li();
};

void Usuario::SolicitaListaContactos(IDictionary* cont) {
    Usuario* n;
    Subheader("Tus Contactos");
    int contar = 0;
    cout << endl;
    li();
    if (!this->contactos->isEmpty()) {
        IIterator* it = this->contactos->getIterator();
        while (it->hasCurrent()) {
            n = (Usuario*) it->getCurrent();
            if (!cont->member(new String(n->getNumero().c_str()))) {
                li("-");
                li("Nombre " + n->getNombre());
                li("Numero " + n->getNumero());
                li("Imagen " + n->getImagen());
                li("Descripcion " + n->getDireccion());
                li("-");
                contar++;
            }
            it->next();
        }
        delete it;
        if (contar == 0) {
            li("-");
            li("No quedan contactos");
            li("-");
        }
    } else {
        li("-");
        li("No tienes Contactos");
        li("-");
    }
    li();
};


/*
 *
 * DSS
 *
 */

// Usuario

bool Usuario::ModificarUsuario() {
    switch (PantallaSeleccionModificarUsuario()) {
        case 1:
            this->setNombre(CinString("Ingrese su Nombre"));
            break;
        case 2:
            this->setDireccion(CinString("Ingrese su Descripcion"));
            break;
        case 3:
            this->setImagen(CinString("Ingrese su Imagen"));
            break;
        case 5:
            return 0;
    }
    return false; //No sale de la aplicacion
}

// Mensajes

bool Usuario::EliminarMensaje() {
    string Numero;
    IKey* k;
    Miembro* mim = NULL;
    Miembro_Conversacion* mimcon;
    int cerarMensaje = 0;
    if (this->conversaciones->isEmpty() and this->grupos->isEmpty()) {
        alarm("No tienes conversaciones para poder ver mensajes");
        return FALSE;
    }
    switch (PantallaSeleccionConversacionVerMensaje(this)) {
        case 1:
            if (!this->conversaciones->isEmpty() || !this->grupos->isEmpty()) {
                k = new String(CinString("Seleccionar una Conversacion").c_str());
                if (this->conversaciones->member(k)) {
                    mimcon = (Miembro_Conversacion*) this->conversaciones->find(k);
                    cerarMensaje = 1;
                } else if (this->grupos->member(k)) {
                    mim = (Miembro*) this->grupos->find(k);
                    cerarMensaje = 2;
                } else {
                    alarm("No posee ese Conversacion con ese numero");
                }
            } else {
                alarm("No posees Conversaciones");
            }
            break;
        case 2:
            if (this->CuentaArchivadas() == 0) {
                alarm("No tiene Conversaciones archivadas");
            } else {
                PantallaImprimeArchivada(this);
                k = new String(CinString("Seleccionar una Conversacion").c_str());
                if (this->conversaciones->member(k)) {
                    mimcon = (Miembro_Conversacion*) this->conversaciones->find(k);
                    mimcon->setArchivado(false);
                    cerarMensaje = 1;
                } else if (this->grupos->member(k)) {
                    mim = (Miembro*) this->grupos->find(k);
                    mim->setArchivado(false);
                    cerarMensaje = 2;
                } else {
                    alarm("No posee ese Conversacion con ese numero");
                }
            }
            break;
        case 3:
            return false;
            break;
    }
    if (cerarMensaje == 1 || cerarMensaje == 2) {
        do {
            if (cerarMensaje == 1) {
                mimcon->ImprimeMensajes(this);
            } else if (cerarMensaje == 2) {
                mim->ImprimeMensajes(this);
            }
            Numero = CinString("Cual es el identificador");
            if (cerarMensaje == 1) {
                mimcon->EliminarMensaje(Numero, this);
            } else if (cerarMensaje == 2) {
                mim->EliminarMensaje(Numero, this);
            }
        } while (PantallaSeleccionMasMensajesDetalladoVerMensaje());
    }
};

int Usuario::EnviarMensaje(int idMensaje) {
    IKey* k;
    Mensaje* mens = NULL;
    Miembro* mim = NULL;
    Miembro_Conversacion* mimcon;
    int cerarMensaje = 0;
    if (this->contactos->isEmpty()) {
        alarm("No tienes contactos a quien mandar mensajes");
    } else {
        do {
            // Seleccionar conversacion
            do {
                system("cls");
                switch (PantallaSeleccionConversacionEnviarMensaje(this)) {
                    case 1:
                        if (!this->conversaciones->isEmpty() || !this->grupos->isEmpty()) {
                            k = new String(CinString("Seleccionar una Conversacion").c_str());
                            if (this->conversaciones->member(k)) {
                                mimcon = (Miembro_Conversacion*) this->conversaciones->find(k);
                                cerarMensaje = 1;
                            } else if (this->grupos->member(k)) {
                                mim = (Miembro*) this->grupos->find(k);
                                cerarMensaje = 2;
                            } else {
                                alarm("No posee esa Conversacion con ese numero");
                            }
                        } else {
                            alarm("No posees Conversaciones");
                        }
                        break;
                    case 2:
                        if (this->CuentaArchivadas() > 0) {
                            PantallaImprimeArchivada(this);
                            k = new String(CinString("Seleccionar una Conversacion").c_str());
                            if (this->conversaciones->member(k)) {
                                mimcon = (Miembro_Conversacion*) this->conversaciones->find(k);
                                mimcon->setArchivado(false);
                                cerarMensaje = 1;
                            } else if (this->grupos->member(k)) {
                                mim = (Miembro*) this->grupos->find(k);
                                mim->setArchivado(false);
                                cerarMensaje = 2;
                            } else {
                                alarm("No posee esa Conversacion con ese numero");
                            }
                        } else {
                            alarm("No posee esa Conversacion Archivadas");
                        }
                        break;
                    case 3:
                        if (!this->contactos->isEmpty()) {
                            system("cls");
                            cout << endl;
                            this->SolicitaListaContactos();
                            k = new String(CinString("Seleccionar una Contacto").c_str());
                            if (this->contactos->member(k)) {
                                if (this->conversaciones->member(k)) {
                                    alarm("Ya posees una conversacion con ese usuario");
                                } else {
                                    mimcon = new Miembro_Conversacion(this);
                                    this->conversaciones->add(k, mimcon);
                                    ((Usuario*)this->contactos->find(k))->addConversacion(this, mimcon->getConversacion());
                                    cerarMensaje = 1;
                                }
                            } else {
                                alarm("No posee ese numero como contacto");
                            }
                        } else {
                            alarm("No tienes contactos");
                        }
                        break;
                    case 4:
                        return false;
                        break;
                }
            } while (cerarMensaje == 0);

            //Crea mensaje
            do {
                switch (PantallaSeleccionTipomensajeEnviarMensaje()) {
                    case 1:
                        header("Redacta mensaje");
                        mens = new Mensaje(idMensaje, CinString("Texto"), this);
                        idMensaje++;
                        break;
                    case 2:
                        header("Redacta mensaje");
                        mens = new Foto(CinString("Url imagen"), CinString("Formato"), CinString("tamaño"), CinString("Descripcion"), idMensaje, CinString("Texto"), this);
                        idMensaje++;
                        break;
                    case 3:
                        header("Redacta mensaje");
                        mens = new Video(CinString("Url video"), CinString("Duracion"), idMensaje, CinString("Texto"), this);
                        idMensaje++;
                        break;
                    case 4:
                        header("Redacta mensaje");
                        this->SolicitaListaContactos();
                        k = new String(CinString("Ingrese el numero a mandar").c_str());
                        if (this->contactos->member(k)) {
                            mens = new Contacto((Usuario*)this->contactos->find(k), idMensaje, CinString("Texto"), this);
                            idMensaje++;
                        } else {
                            alarm("El contacto no se encontro");
                        }
                        break;
                }
                //Envia mensaje
                if (cerarMensaje == 2) {
                    mim->setArchivado(false);
                    mim->addMensaje(mens, this->getNumero());
                } else if (cerarMensaje == 1) {
                    mimcon->addMensaje(mens, this->getNumero());
                    mimcon->setArchivado(false);
                }
            } while (PantallaEnviarOtroEnviarMensaje(cerarMensaje));
        } while (PantallaSeleccionarOtraConversacionEnviarMensaje());
    }
    return idMensaje;
};

bool Usuario::VerMensajes() {
    string Numero;
    IKey* k;
    Miembro* mim = NULL;
    Miembro_Conversacion* mimcon;
    int cerarMensaje = 0;
    if (this->conversaciones->isEmpty() and this->grupos->isEmpty()) {
        alarm("No tienes conversaciones para poder ver mensajes");
        return FALSE;
    }
    switch (PantallaSeleccionConversacionVerMensaje(this)) {
        case 1:
            if (!this->conversaciones->isEmpty() || !this->grupos->isEmpty()) {
                k = new String(CinString("Seleccionar una Conversacion").c_str());
                if (this->conversaciones->member(k)) {
                    mimcon = (Miembro_Conversacion*) this->conversaciones->find(k);
                    cerarMensaje = 1;
                } else if (this->grupos->member(k)) {
                    mim = (Miembro*) this->grupos->find(k);
                    cerarMensaje = 2;
                } else {
                    alarm("No posee ese Conversacion con ese numero");
                }
            } else {
                alarm("No posees Conversaciones");
            }
            break;
        case 2:
            if (this->CuentaArchivadas() == 0) {
                alarm("No tiene Conversaciones archivadas");
            } else {
                PantallaImprimeArchivada(this);
                k = new String(CinString("Seleccionar una Conversacion").c_str());
                if (this->conversaciones->member(k)) {
                    mimcon = (Miembro_Conversacion*) this->conversaciones->find(k);
//                    mimcon->setArchivado(false);
                    cerarMensaje = 1;
                } else if (this->grupos->member(k)) {
                    mim = (Miembro*) this->grupos->find(k);
  //                  mim->setArchivado(false);
                    cerarMensaje = 2;
                } else {
                    alarm("No posee ese Conversacion con ese numero");
                }
            }
            break;
        case 3:
            return false;
            break;
    }
    if (cerarMensaje == 1 || cerarMensaje == 2) {
        do {
            if (cerarMensaje == 1) {
                mimcon->ImprimeMensajes(this);
            } else if (cerarMensaje == 2) {
                mim->ImprimeMensajes(this);
            }
            if (PantallaSeleccionDetalladoVerMensaje()) {
                Numero = CinString("Cual es el identificador");
                if (cerarMensaje == 1) {
                    mimcon->ImprimeMensajeDetallado(Numero);
                } else if (cerarMensaje == 2) {
                    mim->ImprimeMensajeDetallado(Numero);
                }
                system("pause");
            }
        } while (PantallaSeleccionMasMensajesDetalladoVerMensaje());
    }
};

// Conversaciones

bool Usuario::ArchivarConversaciones() {
    if (this->CuentaNoArchivadas() == 0) {
        alarm("No tienes conversaciones para archivar");
    } else {
        do {
            system("cls");
            header("Archivar Conversaciones");
            this->ListarMisConversaciones();
            cout << endl;
            this->ListarMisGruposSimple();
            IKey* k = new String(CinString("Ingrese el Numero/Nombre").c_str());
            if (this->conversaciones->member(k)) {
                if (((Miembro_Conversacion*) this->conversaciones->find(k))->getArchivado()) {
                    alarm("Esta Conversacion ya esta archivada");
                } else {
                    ((Miembro_Conversacion*) this->conversaciones->find(k))->setArchivado(true);
                }
            } else if (this->grupos->member(k)) {
                if (((Miembro*) this->grupos->find(k))->getArchivado()) {
                    alarm("Esta Conversacion ya esta archivada");
                } else {
                    ((Miembro*) this->grupos->find(k))->setArchivado(true);
                }
            } else {
                alarm("No se encontro la Conversacion");
            }
        } while (PantallaSegirArchivandoConversacion());
    }
    return false;
};

bool Usuario::AgregarParticipantes() {
    IKey* k;
    Grupo* grupo = NULL;
    if (this->grupos->isEmpty()) {
        alarm("No tienes conversaciones para archivadar");
    } else {
        do {
            header("Agregar Participantes");
            if (this->ListarMisGrupoas()) {
                k = new String(CinString("Selecciona Grupo").c_str());
                if (!this->grupos->member(k)) {
                    alarm("No hay grupos con ese nombre");
                } else if (!((Miembro*) this->grupos->find(k))->getAdministrador()) {
                    alarm("No tienes permisos para agregar participantes a este grupo");
                } else {
                    grupo = ((Miembro*) this->grupos->find(k))->getConversacion();
                    header("Miembros del grupo");
                    grupo->SolicitaListaContactos(this->numero);
                    this->SolicitaListaContactos();
                    k = new String(CinString("Selecciona el numero de uno de tus contactos para agregarlo al grupo").c_str());
                    if (this->contactos->member(k)) {
                        if (!grupo->getIntegrantes()->member(k)) {
                            grupo->addContacto((Usuario*)this->contactos->find(k));
                        } else {
                            alarm("El numero ingresado ya es un miembro del grupo");
                        }
                    } else {
                        alarm("El numero ingresado no corresponde a uno de tus contactos");
                    }
                }
            }
        } while (PantallaSeleccionAgregarParticipantes());
    }
    return false;
};

bool Usuario::EliminarParticipantes() {
    IKey* k;
    Grupo* grupo = NULL;
    if (this->grupos->isEmpty()) {
        alarm("No tienes conversaciones para archivadas");
    } else {
        do {
            header("Eliminar Participantes");
            if (this->ListarMisGrupoas()) {
                k = new String(CinString("Selecciona Grupo").c_str());
                if (!this->grupos->member(k)) {
                    alarm("No hay grupos con ese nombre");
                } else if (!((Miembro*) this->grupos->find(k))->getAdministrador()) {
                    alarm("No tienes permisos para agregar participantes a este grupo");
                } else {
                    grupo = ((Miembro*) this->grupos->find(k))->getConversacion();
                    header("Miembros del grupo");
                    grupo->SolicitaListaContactos(this->numero);
                    k = new String(CinString("Selecciona el numero de uno de los contactos para quitar del grupo").c_str());
                    grupo->removeContacto(k);
                }
            }
        } while (PantallaSeleccionEliminarParticipantes());
    }
    return false;
};

bool Usuario::AgregarAdministradores() {
    IKey* k;
    Grupo* gurpo = NULL;
    if (this->grupos->isEmpty()) {
        alarm("No tienes conversaciones para archivadas");
    } else {
        do {
            header("Agregar Administradores");
            if (this->ListarMisGrupoas()) {
                k = new String(CinString("Selecciona Grupo").c_str());
                if (this->grupos->member(k)) {
                    gurpo = ((Miembro*) this->grupos->find(k))->getConversacion();
                    do {
                        header("Agregar Administradores");
                        gurpo->SolicitaListaContactos();
                        k = new String(CinString("Selecciona Usuario").c_str());
                        if (!gurpo->getIntegrantes()->member(k)) {
                            alarm("No se encontro el usuario");
                        } else if (!gurpo->getAdministradores(new String(this->numero.c_str()))) {
                            alarm("No tienes permisos");
                        } else if (gurpo->getAdministradores(k)) {
                            alarm("Ya tienes permisos");
                        } else {
                            gurpo->HacerAdministradores(k);
                        }
                    } while (PantallaSeleccionAgregarAdministradores());
                } else {
                    alarm("No hay grupos con ese nombre");
                }
            } else {
                alarm("No tienes grupoes");
            }
        } while (PantallaSeleccionSeleccionGrupoAgregarAdministradores());
    }
    return false;
};

// Constructores y Destructores

Usuario::Usuario(string _nombre, string _numero, string _imagen, string _direccion, Fecha* _creacion, Fecha * _ultima) {
    this->nombre = _nombre;
    this->numero = _numero;
    this->imagen = _imagen;
    this->direccion = _direccion;
    this->ultima = _ultima;
    this->creacion = _creacion;
    this->contactos = new OrderedDictionary();
    this->conversaciones = new OrderedDictionary();
    this->mensajes = new OrderedDictionary();
    this->grupos = new OrderedDictionary();
}

Usuario::Usuario(string _nombre, string _numero, string _imagen, string _direccion) {
    this->nombre = _nombre;
    this->numero = _numero;
    this->imagen = _imagen;
    this->direccion = _direccion;
    this->ultima = new Fecha();
    this->creacion = new Fecha();
    this->contactos = new OrderedDictionary();
    this->conversaciones = new OrderedDictionary();
    this->mensajes = new OrderedDictionary();
    this->grupos = new OrderedDictionary();
}

Usuario::Usuario() {
    this->nombre = "";
    this->numero = "";
    this->imagen = "";
    this->direccion = "";
    this->ultima = new Fecha();
    this->creacion = new Fecha();
    this->conversaciones = new OrderedDictionary();
    this->contactos = new OrderedDictionary();
    this->mensajes = new OrderedDictionary();
    this->grupos = new OrderedDictionary();
};

Usuario::~Usuario() {
};
