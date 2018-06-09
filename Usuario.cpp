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

// Funciones de estados

IDictionary* Usuario::getEstados() {
    return this->estados;
};

void Usuario::setEstados(IDictionary* _estados) {
    this->estados = _estados;
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
    this->grupos->add(new String(con->getConversacion()->getNombre().c_str()), con);
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
            } else {
                cont++;
            }
            it->next();
        }
        if (cont == 0) {
            li("-");
            li("No tines Grupos");
            li("-");
        }
        delete it;
    } else {
        li("-");
        li("No tines Grupos");
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
            li("No tines Grupos");
            li("-");
        }
        delete it;
    } else {
        li("-");
        li("No tines Grupos");
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
        alarm("No tines Grupos");
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
            } else {
                cont++;
            }
            it->next();
        }
        if (cont == 0) {
            li("-");
            li("No tines Conversaciones");
            li("-");
        }
        delete it;
    } else {
        li("-");
        li("No tines Conversaciones Activas");
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
            } else {
                cont++;
            }
            it->next();
        }
        if (cont == 0) {
            li("-");
            li("No tines Conversaciones");
            li("-");
        }
        delete it;
    } else {
        li("-");
        li("No tines Conversaciones Activas");
        li("-");
    }
    li();
}

void Usuario::SolicitaListaContactos() {
    Subheader("Tus Contactos");
    cout << endl;
    Usuario* n;
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
        li("No tines Contactos");
        li("-");
    }
    li();
};

bool Usuario::ModificarUsuario() {
    int Opciones = -1;
    string aux;

    do {

        if (Opciones != -1) {
            alarm("Opciones incorecta");
        }
        header("Modificar Usuario");
        ol();
        ol("Modificar Nombre");
        ol("Modificar Descripcion");
        ol("Modificar Imagen de Perfil");
        ol("Cancelar");
        Opciones = CinInt();
    } while (Opciones < 1 || Opciones > 4);

    switch (Opciones) {
        case 1:
            aux = CinString("Ingrese su Nombre");
            this->setNombre(aux);
            break;

        case 2:
            aux = CinString("Ingrese su Descripcion");
            this->setDireccion(aux);
            break;

        case 3:
            aux = CinString("Ingrese su Imagen");
            this->setImagen(aux);
            break;

        case 5:
            return 0;
    }

    return false; //No sale de la aplicacion
}
// Mensajes

int Usuario::EnviarMensaje(int idMensaje) {
    bool exit = false;
    int opcion, cant;
    string Numero;
    string texto, URL, form, tama, desc, dura;
    Mensaje* mens = NULL;
    IKey* k;
    Miembro* mim = NULL;
    Miembro_Conversacion* mimcon;
    int cerarMensaje = 0;

    do {
        do {//Mintras quiera seleccionar conversacion
            system("cls");

            do {
                //Selecciona conversacion
                cout << endl;
                this->ListarMisConversaciones();
                cout << endl;
                this->ListarMisGruposSimple();
                cout << endl;
                cant = this->CuentaArchivadas();
                li();
                li(" Archivadas " + to_string(this->CuentaArchivadas()));
                li();

                cout << endl;
                ol();
                ol("Seleccionar una conversacion activa");
                ol("Ver las conversaciones archivadas");
                ol("Enviar un mensaje a un contacto sin conversacion");
                ol("Volver");
                opcion = CinInt();
            } while (Rango(opcion < 1 || opcion > 4));
            switch (opcion) {
                case 1:
                    if (!this->conversaciones->isEmpty() || !this->grupos->isEmpty()) {
                        Numero = CinString("Seleccionar una Conversacion");
                        k = new String(Numero.c_str());
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
                    if (this->CuentaArchivadas() > 0) {
                        header("Selecciona Conversacion archivada");
                        this->ListarMisConversacionesArchivadas();
                        cout << endl;
                        this->ListarMisGruposSimpleArchivadas();
                        cout << endl;
                        Numero = CinString("Seleccionar una Conversacion");
                        k = new String(Numero.c_str());
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
                    } else {
                        alarm("No posee ese Conversacion Archivadas");
                    }
                    break;
                case 3:
                    if (this->contactos->isEmpty()) {
                        alarm("No tines contactos");
                    } else {
                        system("cls");
                        cout << endl;
                        this->SolicitaListaContactos();
                        Numero = CinString("Seleccionar una Contacto");
                        k = new String(Numero.c_str());
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
                    }
                    break;
                case 4:
                    return false;
                    break;
            }
        } while (opcion != 4 and cerarMensaje == 0);

        //Crea mensaje
        do {
            if (cerarMensaje != 0) {
                do {
                    header("Seleccionar Tipo de mensaje");
                    ol();
                    ol("Simple");
                    ol("Imagen");
                    ol("Video");
                    ol("Contacto");
                    opcion = CinInt();
                } while (opcion < 1 || opcion > 4);
                switch (opcion) {
                    case 1:
                        header("Redacta mensaje");
                        texto = CinString("Texto");
                        mens = new Mensaje(idMensaje, texto, this);
                        idMensaje++;
                        break;
                    case 2:
                        URL = CinString("Url imagen");
                        form = CinString("Formato");
                        tama = CinString("tamaño");
                        desc = CinString("Descripcion");
                        texto = CinString("Texto");
                        mens = new Foto(URL, form, tama, desc, idMensaje, texto, this);
                        idMensaje++;
                        break;
                    case 3:
                        URL = CinString("Url video");
                        dura = CinString("Duracion");
                        texto = CinString("Texto");
                        mens = new Video(URL, dura, idMensaje, texto, this);
                        idMensaje++;
                        break;
                    case 4:
                        this->SolicitaListaContactos();
                        numero = CinString("Ingrese el numero a mandar");
                        k = new String(numero.c_str());
                        if (this->contactos->member(k)) {
                            texto = CinString("Texto");
                            mens = new Contacto((Usuario*)this->contactos->find(k), idMensaje, texto, this);
                            idMensaje++;
                        } else {
                            alarm("El contacto no se encontro");
                        }
                        break;
                }
            }

            //Envia mensaje
            if (cerarMensaje == 2) {
                mim->addMensaje(mens, this->getNumero());
                header("Crear otro Mensaje");
            } else if (cerarMensaje == 1) {
                mimcon->addMensaje(mens, this->getNumero());
                header("Crear otro Mensaje");
            } else {
                header("Volver a intentar crear Mensaje");
            }
            ol();
            ol("Enviar mensajes");
            ol("Volver");
            opcion = CinInt();
            exit = opcion != 2;
            if (opcion < 1 || opcion > 2) {
                alarm("Fera de rango o caracter invalido");
            }
        } while (exit);
    } while (exit);
    return idMensaje;
};

bool Usuario::EliminarMensaje() {
    system("cls");
    header("Eliminar Mensaje");
};

bool Usuario::VerMensajes() {
    bool exit = false;
    int opcion, cant;
    string Numero;
    string texto, URL, form, tama, desc, dura;
    Mensaje* mens = NULL;
    IKey* k;
    Miembro* mim = NULL;
    Miembro_Conversacion* mimcon;
    int cerarMensaje = 0;


    if (this->conversaciones->isEmpty() and this->grupos->isEmpty()) {
        alarm("No tines conversaciones para poder ver mensajes");
        return FALSE;
    }

    system("cls");
    cout << endl;
    this->ListarMisConversaciones();
    cout << endl;
    this->ListarMisGruposSimple();
    cout << endl;
    cant = this->CuentaArchivadas();
    li();
    li(" Archivadas " + to_string(this->CuentaArchivadas()));
    li();
    do {
        cout << endl;
        ol();
        ol("Seleccionar una conversacion activa");
        ol("Ver las conversaciones archivadas");
        ol("Volver");
        opcion = CinInt();
    } while (opcion < 1 || opcion > 3);
    switch (opcion) {
        case 1:
            if (!this->conversaciones->isEmpty() || !this->grupos->isEmpty()) {
                Numero = CinString("Seleccionar una Conversacion");
                k = new String(Numero.c_str());
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
            header("Selecciona Conversacion archivada");
            this->ListarMisConversacionesArchivadas();
            cout << endl;
            this->ListarMisGruposSimpleArchivadas();
            cout << endl;
            Numero = CinString("Seleccionar una Conversacion");
            k = new String(Numero.c_str());
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
            break;
        case 3:
            return false;
            break;
    }
    opcion = -1;
    do {
        if (opcion != -1) {
            alarm("Opcion invalida");
        }
        if (cerarMensaje == 1) {
            mimcon->ImprimeMensajes(this);
        } else if (cerarMensaje == 2) {
            mim->ImprimeMensajes(this);

        }
        if (cerarMensaje == 1 || cerarMensaje == 2) {
            cout << endl;
            ol();
            ol("Seleccionar una Mensaje");
            ol("Volver");
            opcion = CinInt();
            if (opcion == 1) {
                if (cerarMensaje == 1) {
                    Numero = CinString("Cual es el identificador");
                    mimcon->ImprimeMensajeDetallado(Numero);
                } else if (cerarMensaje == 2) {
                    Numero = CinString("Cual es el identificador");
                    mim->ImprimeMensajeDetallado(Numero);
                }
            }
        }
    } while (opcion != 2);


};

// Conversaciones

bool Usuario::ArchivarConversaciones() {
    int opcion;
    string Numero;
    bool exit = true;
    do {
        if (this->CuentaNoArchivadas() != 0) {
            system("cls");
            header("Archivar Conversaciones");
            this->ListarMisConversaciones();
            cout << endl;
            this->ListarMisGruposSimple();
            Numero = CinString("Ingrese el Numero/Nombre");
            IKey* k = new String(Numero.c_str());

            if (this->conversaciones->member(k) || this->grupos->member(k)) {
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
                }
            } else {
                alarm("No se encontro la Conversacion");
            }
            do {
                header("Segir archivando?");
                ol();
                ol("Si");
                ol("Volver");
                opcion = CinInt();
            } while (opcion < 1 || opcion > 2);
            exit = opcion == 1;
        } else {
            alarm("No tines conversaciones para archivadas");
        }
    } while (exit && this->CuentaNoArchivadas() != 0);
};

bool Usuario::AgregarParticipantes() {
    system("cls");
    int Opciones;
    string Numero;
    string Nombre;
    IKey* k;
    Grupo* grupo = NULL;
    do {
        header("Agregar Participantes");
        if (this->ListarMisGrupoas()) {
            Nombre = CinString("Selecciona Grupo");
            k = new String(Nombre.c_str());
            while (!this->grupos->member(k)) {
                header("No hay grupos con ese nombre");
                ol();
                ol("Reintentar");
                ol("Salir");
                Opciones = CinInt();
                if (Opciones == 2) {
                    return false;
                }
                header("Agregar Participantes");
                this->ListarMisGrupoas();
                Nombre = CinString("Selecciona Grupo");
                delete k;
                k = new String(Nombre.c_str());
            }
            grupo = ((Miembro*) this->grupos->find(k))->getConversacion();
            Subheader("Miembros del grupo");
            grupo->SolicitaListaContactos();
            Subheader("Tus contactos");
            this->SolicitaListaContactos();
            Numero = CinInt("Selecciona el numero de uno de tus contactos para agregarlo al grupo");
            k = new String(Numero.c_str());
            if (this->contactos->member(k)) {
                if (!grupo->getIntegrantes()->member(k)) {
                    grupo->addContacto((Usuario*)this->contactos->find(k));
                } else {
                    cout << "El nuemero ingresado ya es un miembro del grupo\n";
                }
            } else {
                cout << "El numero ingresado no corresponde a uno de tus contactos\n";
            }
            cout << "Desea seguir agregando contactos al grupo?";
            cout << "1 - Si\n 2 - No\n";
            cin >> Opciones;
        }
    } while (Opciones != 2);
    return false;
};

bool Usuario::EliminarParticipantes() {
    system("cls");
    header("Eliminar Participantes");
    cout << endl;
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

bool Usuario::AgregarAdministradores() {
    int Opciones;
    string Nombre;
    IKey* k;

    Grupo* gurpo = NULL;
    do {
        header("Agregar Administradores");
        if (this->ListarMisGrupoas()) {
            Nombre = CinString("Selecciona Grupo");
            k = new String(Nombre.c_str());
            while (!this->grupos->member(k)) {
                header("No hay grupos con ese nombre");
                ol();
                ol("Reintentar");
                ol("Salir");
                Opciones = CinInt();
                if (Opciones == 2) {
                    return false;
                }
                header("Agregar Administradores");
                this->ListarMisGrupoas();
                Nombre = CinString("Selecciona Grupo");
                delete k;
                k = new String(Nombre.c_str());
            }
            gurpo = ((Miembro*) this->grupos->find(k))->getConversacion();
            gurpo->SolicitaListaContactos();
            Nombre = CinString("Selecciona Usuario");
            k = new String(Nombre.c_str());
            if (!gurpo->getAdministradores(new String(this->numero.c_str()))) {
                alarm("No tines permisos");
            } else if (!gurpo->getAdministradores(k)) {
                gurpo->HacerAdministradores(k);
            } else {
                alarm("No tines permisos");
            }
            do {
                system("cls");
                header("Agregar Administradores");
                ol();
                ol("Agregar Administrador");
                ol("Salir");
                Opciones = CinInt();
            } while (Opciones != 1 and Opciones != 2);
        } else {
            Opciones = 2;
        }
    } while (Opciones != 2);
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
    this->estados = new OrderedDictionary();
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
    this->estados = new OrderedDictionary();
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
    this->estados = new OrderedDictionary();
    this->mensajes = new OrderedDictionary();
    this->grupos = new OrderedDictionary();
};

Usuario::~Usuario() {
};
