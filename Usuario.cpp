#include "Usuario.h"
#include "string"
#include "string.h"

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
void Usuario::addConversacion(Miembro* con) {
    this->conversaciones->add(new String(con->getNumero().c_str()),con);
}
// Imprimir
void Usuario::impresionSimple() {
    cout << "\t Nombre: " << this->nombre << endl;
    cout << "\t Numero: " << this->numero << endl;
    cout << "\t Imagen: " << this->imagen << endl;
}
void Usuario::impresionSuperSimple() {
    cout << "\t Nombre: " << this->nombre << endl;
    cout << "\t Numero: " << this->numero << endl;
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

    cout << "-----------------------------------------" << endl;
    cout << " Tus Grupos" << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
    Miembro* n;
    if (!this->grupos->isEmpty()) {
        IIterator* it = this->grupos->getIterator();
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
        cout << "\t No tines Grupos" << endl;
        cout << endl;
    }
}
bool Usuario::ListarMisGrupoas() {
    system("cls");
    cout << "-----------------------------------------" << endl;
    cout << " Tus Grupos" << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
    Grupo* n;
    if (!this->grupos->isEmpty()) {
        IIterator* it = this->grupos->getIterator();
        while (it->hasCurrent()) {
            n = (Grupo*) it->getCurrent();
            cout << endl;
            n->impresionSimple();
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
    cout << "-----------------------------------------" << endl;
    cout << " Tus Conversaciones Archivadas" << endl;
    cout << "-----------------------------------------" << endl;
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
    cout << "-----------------------------------------" << endl;
    cout << " Tus Conversaciones Activas" << endl;
    cout << "-----------------------------------------" << endl;
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
    cout << "-----------------------------------------" << endl;
    cout << " Tus Contactos" << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
    Usuario* n;
    if (!this->contactos->isEmpty()) {
        IIterator* it = this->contactos->getIterator();
        while (it->hasCurrent()) {
            n = (Usuario*) it->getCurrent();
            cout << endl;
            cout << "----------------------------------------------" << endl;
            cout << "\t Nombre: " << n->getNombre() << endl;
            cout << "\t Numero: " << n->getNumero() << endl;
            cout << "\t Imagen: " << n->getImagen() << endl;
            it->next();
        }
        delete it;
    } else {
        cout << endl;
        cout << "\t No tines Contactos" << endl;
        cout << endl;
    }
};
bool Usuario::ModificarUsuario() {
    system("cls");
    cout << "-----------------------------------------" << endl;
    cout << " Modificar Usuario" << endl;
    cout << "-----------------------------------------" << endl;
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
    
    return false;//No sale de la aplicacion
}
// Mensajes
bool Usuario::EnviarMensaje() {
    system("cls");
    cout << "-----------------------------------------" << endl;
    cout << " Enviar Mensaje" << endl;
    cout << "-----------------------------------------" << endl;
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
    system("pause");
    /*
        1. Seleccionar una conversación activa
                2. Ver las conversaciones archivadas
                3. Enviar un mensaje a un contacto con el cuál aún no ha iniciado
                una conversación
     */
};
bool Usuario::EliminarMensaje() {
    system("cls");
    cout << "-----------------------------------------" << endl;
    cout << " Eliminar Mensaje" << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
};
bool Usuario::VerMensajes() {
    system("cls");
    cout << "-----------------------------------------" << endl;
    cout << " Ver Mensajes" << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
};

// Conversaciones
bool Usuario::ArchivarConversaciones() {
    system("cls");
    cout << "-----------------------------------------" << endl;
    cout << " Archivar Conversaciones" << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
};
bool Usuario::AgregarParticipantes() {
    system("cls");
    cout << "-----------------------------------------" << endl;
    cout << " Agregar Participantes" << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
};
bool Usuario::EliminarParticipantes() {
    system("cls");
    cout << "-----------------------------------------" << endl;
    cout << " Eliminar Participantes" << endl;
    cout << "-----------------------------------------" << endl;
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
    do {
        cout << "----------------------------------------------" << endl;
        cout << " Agregar Administradores" << endl;
        cout << "----------------------------------------------" << endl;
        cout << endl;
        if (this->ListarMisGrupoas()) {
            cout << "----------------------------------------------" << endl;
            cout << "\t Selecciona Grupo: ";
            fflush(stdin);
            getline(cin, Nombre);
            k = new String(Nombre.c_str());
            while (!this->grupos->member(k)) {
                cout << "\t No hay grupos con ese nombre";
                cout << "\t 1 - Reintentar";
                cout << "\t 2 - Salir";
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
            Grupo* gurpo = (Grupo*) this->grupos->find(k);
            gurpo->SolicitaListaContactosDetallada();
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
                cout << "-----------------------------------------" << endl;
                cout << " Agregar Administradores" << endl;
                cout << "-----------------------------------------" << endl;
                cout << endl;
                cout << "\t 1 - Agregar Administrador" << endl;
                cout << "\t 2 - Salir" << endl;
            } while (Opciones != 1 and Opciones != 2);
        } else {
            Opciones = 2;
        }
    } while (Opciones == 2);
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

