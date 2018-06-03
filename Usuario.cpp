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

    header("Tus Grupos");
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
    system("cls");
    header("Tus Grupos");
    cout << endl;
    Miembro* n;
    if (!this->grupos->isEmpty()) {
        IIterator* it = this->grupos->getIterator();
        while (it->hasCurrent()) {
            n = (Miembro*) it->getCurrent();
            cout << endl;
            n->ImprimeGrupo();
            it->next();
        }
        delete it;
        return true;
    } else {
        cout << endl;
        cout << "\t No tines Grupos" << endl;
        cout << endl;
        system("pause");
        return false;
    }
}

void Usuario::ListarMisConversacionesArchivadas() {
    system("cls");
    header("Tus Conversaciones Archivadas");
    cout << endl;
    Miembro* n;
    if (!this->conversaciones->isEmpty()) {
        IIterator* it = this->conversaciones->getIterator();
        while (it->hasCurrent()) {
            n = (Miembro*) it->getCurrent();
            cout << endl;
            if (n->getArchivado()) {
                n->impresionSuperSimple();
            }
            it->next();
        }
        delete it;
    } else {
        cout << endl;
        cout << "\t No tines Conversaciones Archivadas" << endl;
        cout << endl;
    }
};

void Usuario::ListarNombreDeGrupos() {
};

void Usuario::ListarMisConversaciones() {
    header("Tus Conversaciones Activas");
    cout << endl;
    Miembro* n;
    if (!this->conversaciones->isEmpty()) {
        IIterator* it = this->conversaciones->getIterator();
        while (it->hasCurrent()) {
            n = (Miembro*) it->getCurrent();
            cout << endl;
            if (!n->getArchivado()) {
                n->impresionSuperSimple();
            }
            it->next();
        }
        delete it;
    } else {
        cout << endl;
        cout << "\t No tines Conversaciones Activas" << endl;
        cout << endl;
    }
}

void Usuario::SolicitaListaContactos() {
    system("cls");
    header("Tus Contactos");
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
    system("cls");
    header("Enviar Mensaje");
    cout << endl;

    this->ListarMisConversaciones();
    cout << endl;
    this->ListarMisGruposSimple();
    cout << endl;
    int cant = this->CuentaArchivadas();
    if (cant > 0) {
        cout << "-----------------------------------------" << endl;
        cout << " Archivadas " << cant << endl;
        cout << "-----------------------------------------" << endl;
    }
    int opcion;
    {
        cout << "\t 1 - Seleccionar una conversación activa" << endl;
        cout << "\t 2 - Ver las conversaciones archivadas" << endl;
        cout << "\t 3 - Enviar un mensaje a un contacto sin conversacion" << endl;
        cout << "\t 4 - Volver" << endl;
        cin >> opcion;
    }
    while (opcion < 1 || opcion > 4);
    switch (opcion) {
        case 1:

            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
    }

    system("pause");

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
            cout << "----------------------------------------------" << endl;
            cout << "\t Selecciona Grupo: ";
            fflush(stdin);
            getline(cin, Nombre);
            k = new String(Nombre.c_str());
            while (!this->grupos->member(k)) {
                cout << "\t No hay grupos con ese nombre" << endl;
                cout << "\t 1 - Reintentar" << endl;
                cout << "\t 2 - Salir" << endl;
                cin >> Opciones;
                if (Opciones == 2) {
                    return false;
                }
                cout << "\t Selecciona Grupo: ";
                fflush(stdin);
                getline(cin, Nombre);
                delete k;
                k = new String(Nombre.c_str());
            }
            gurpo = ((Miembro*) this->grupos->find(k))->getConversacion();
            gurpo->SolicitaListaContactos();
            cout << "\t Selecciona Usuario: ";
            fflush(stdin);
            getline(cin, Nombre);
            k = new String(Nombre.c_str());
            if (!gurpo->getAdministradores(new String(this->numero.c_str()))) {
                system("cls");
                cout << "-----------------------------------------" << endl;
                cout << " No tines permisos" << endl;
                cout << "-----------------------------------------" << endl;
                system("pause");
            } else if (!gurpo->getAdministradores(k)) {
                gurpo->HacerAdministradores(k);
            } else {
                system("cls");
                cout << "-----------------------------------------" << endl;
                cout << " No tines permisos" << endl;
                cout << "-----------------------------------------" << endl;
                system("pause");
            }
            do {
                system("cls");
                header("Agregar Administradores");

                cout << "\t 1 - Agregar Administrador" << endl;
                cout << "\t 2 - Salir" << endl;
                cin >> Opciones;
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

