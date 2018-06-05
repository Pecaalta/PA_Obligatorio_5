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

int Usuario::CuentaArchivadas() {
    int count = 0;
    Miembro* n;
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
            n = (Miembro*) it2->getCurrent();
            if (n->getArchivado()) {
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
    li();
    if (!this->grupos->isEmpty()) {
        IIterator* it = this->grupos->getIterator();
        while (it->hasCurrent()) {
            n = (Miembro*) it->getCurrent();
            cout << endl;
            if (!n->getArchivado()) {
                li("-");
                n->impresionSuperSimple();
                li("-");
            }
            it->next();
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
    Miembro* n;
    li();
    if (!this->conversaciones->isEmpty()) {
        IIterator* it = this->conversaciones->getIterator();
        while (it->hasCurrent()) {
            n = (Miembro*) it->getCurrent();
            if (n->getArchivado()) {
                n->impresionSuperSimple();
            }
            it->next();
        }
        delete it;
    } else {
        li("No tines Conversaciones Archivadas");
    }
    li();
};

void Usuario::ListarNombreDeGrupos() {
};

void Usuario::ListarMisConversaciones() {
    Subheader("Tus Conversaciones Activas");
    Miembro* n;
    li();
    if (!this->conversaciones->isEmpty()) {
        IIterator* it = this->conversaciones->getIterator();
        while (it->hasCurrent()) {
            n = (Miembro*) it->getCurrent();
            if (!n->getArchivado()) {
                li("-");
                n->impresionSuperSimple();

                li("-");
            }
            it->next();
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
    system("cls");
    header("Modificar Usuario");
    cout << endl;
    /*
     * 1 - editar Nombre
     * 2 - editar imagen
     * 3 - editar descripcion
     * 4 - salir
     * 
     * do {
     *  escanear en variable
     * }while(opcion > 0 || < 4);
     * switch 
     *  case 1:
     *  this->getNombre(usar variable)
     */

    return false; //No sale de la aplicacion
}
// Mensajes

bool Usuario::EnviarMensaje() {
    header("Enviar Mensaje");
    this->ListarMisConversaciones();
    cout << endl;
    this->ListarMisGruposSimple();
    cout << endl;
    int cant = this->CuentaArchivadas();
    li();
    li(" Archivadas " + to_string(this->CuentaArchivadas()));
    li();
    int opcion;
    string Numero;
    IKey* k;
    do{
        ol();
        ol("Seleccionar una conversación activa");
        ol("Ver las conversaciones archivadas");
        ol("Enviar un mensaje a un contacto sin conversacion");
        ol("Volver");
        opcion = CinInt();
    }
    while (opcion < 1 || opcion > 4);
    switch (opcion) {
        case 1:

            break;
        case 2:
            break;
        case 3:
            this->SolicitaListaContactos();
            Numero = CinString("Seleccionar una Contacto");
            k = new String(Numero.c_str());
            if (this->contactos->member(k)){
                do {
                    cout << "Seleccionar Tipo de mensaje";
                    ol();
                    ol("Ver las conversaciones archivadas");
                    ol("Enviar un mensaje a un contacto sin conversacion");
                    ol("Volver");
                    opcion = CinInt();
                } while (opcion < 1 || opcion > 4);
            }else{
                alarm("No posee ese numero como contacto");
            }
            break;
        case 4:
            return false;
            break;
    }

};

bool Usuario::EliminarMensaje() {
    system("cls");
    header("Eliminar Mensaje");
};

bool Usuario::VerMensajes() {
    system("cls");
    header("Ver Mensaje");
};

// Conversaciones

bool Usuario::ArchivarConversaciones() {
    system("cls");
    header("Archivar Conversaciones");
    cout << endl;
};

bool Usuario::AgregarParticipantes() {
    system("cls");
    header("Agregar Participantes");
    cout << endl;
};

bool Usuario::EliminarParticipantes() {
    system("cls");
    header("Eliminar Participantes");
    cout << endl;
};

bool Usuario::member(IKey* k) {
    return !this->contactos->isEmpty() and this->contactos->member(k);
};

void Usuario::addContacto(Usuario* user) {
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

Usuario::Usuario(string _nombre, string _numero, string _imagen, string _direccion, Fecha* _creacion, Fecha* _ultima) {
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

