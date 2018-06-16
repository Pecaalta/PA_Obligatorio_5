

#include<fstream>
#include<windows.h>

#include "Sistema.h"
#include "Usuario.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "ICollection/interfaces/IIterator.h"
#include "ICollection/collections/List.h"
#include "ICollection/interfaces/IKey.h"
#include "ICollection/String.h"
#include "Grupo.h"
#include "ICollection/Integer.h"
#include "InterfazGrafica.h"

#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <cstdlib>

using namespace std;

// Funciones de activo

Usuario* Sistema::getActivo() {
    return this->activo;
};

void Sistema::setActivo(Usuario* _activo) {
    this->activo = _activo;
};

// Funciones de usuarios

IDictionary* Sistema::getUsuarios() {
    return this->usuarios;
};

void Sistema::setUsuarios(IDictionary* _usuarios) {
    this->usuarios = _usuarios;
};

// Funciones de conversaciones

IDictionary* Sistema::getConversaciones() {
    return this->conversaciones;
};

void Sistema::setConversaciones(IDictionary* _conversaciones) {
    this->conversaciones = _conversaciones;
};


//Funciones Usuarios

void Sistema::NuevoUsuario(string Numero) {
    this->activo = new Usuario();
    IKey* k = new String(Numero.c_str());
    this->usuarios->add(k, this->activo);
    this->activo->setNumero(Numero);

    header("Nuevo Usuario");
    this->activo->setNombre(CinString("Ingrese su Nombre"));
    this->activo->setDireccion(CinString("Ingrese su Descripcion"));
    this->activo->setImagen(CinString("Ingrese url Imagen"));
    GuardaUsuarioLocal(this->activo);
};

/*
string cod(string texto){
  for (int i = 0;i < texto.size()-1; i++) {
        if (texto[i] == ' ') texto[i] = '_';
    }
}
string decod(string texto){
  for (int i = 0;i < texto.size(); i++) {
        if (texto[i] == '_') texto[i] = ' ';
    }
}
void Sistema::CargarUsuarioLocal() {
    ifstream lectura;
    string nombre, numero, imagen, dir;
    IKey* k;
    lectura.open("fichero.csv", ios::in);
    while (lectura.good()) {
        lectura >> nombre >> numero >> imagen>>dir;
        k = new String(numero.c_str());
        if (!this->usuarios->member(k)) {
            this->usuarios->add(k, new Usuario(decod(nombre), decod(numero), decod(imagen), decod(dir)));
        }
    }
    lectura.close();
}
 */

void Sistema::ActualizaUsuarioLocal() {
    FILE * pFile;
    pFile = fopen("fichero.txt", "w");
    Usuario* user;
    IIterator* it = this->usuarios->getIterator();
    fprintf(pFile, "Nombre,Descripcion,Numero,Imagen\n");
    while (it->hasCurrent()) {
        user = (Usuario*) it->getCurrent();
        fprintf(pFile, "%s,%s,%s,%s\n", user->getNombre().c_str(), user->getDireccion().c_str(), user->getNumero().c_str(), user->getImagen().c_str());
        it->next();
    }
    fclose(pFile);
}
void Sistema::CargarUsuario() {
   /*
    char getNombre[21], getDireccion[21], getNumero[101], getImagen[101];
    FILE * pFile;
    pFile = fopen("fichero.txt", "r");
    if (pFile != NULL) {
        fscanf(pFile, "%20[^,],%20[^,],%100[^,],%100[^,]", getNombre, getDireccion, getNumero, getImagen);
        for (; fscanf(pFile, "\n%20[^,]", getNombre) != EOF;) {
            fscanf(pFile, ",%20[^,]", getDireccion);
            fscanf(pFile, ",%100[^,]", getNumero);
            fscanf(pFile, ",%100[^\n]", getImagen);
            Usuario* usuario_1 = new Usuario(getNombre, getNumero, getImagen, getDireccion);
            this->usuarios->add(new String(getNumero), usuario_1);
        }
        fclose(pFile);
    }

    */
    Usuario* usuario_1  = new Usuario("Mauro >_< "   , "0", "Url 0", "Direccion 0");
    Usuario* usuario_2  = new Usuario("Lucas"   , "1", "Url 1", "Direccion 1");
    Usuario* usuario_3  = new Usuario("Maxi"    , "2", "Url 2", "Direccion 2");
    Usuario* usuario_4  = new Usuario("Seva"    , "3", "Url 3", "Direccion 3");
    Usuario* usuario_5  = new Usuario("Putin"   , "4", "Url 4", "Direccion 4");
    Usuario* usuario_6  = new Usuario("Maia"    , "5", "Url 5", "Direccion 5");
    Usuario* usuario_7  = new Usuario("Andres"  , "6", "Url 6", "Direccion 6");
    Usuario* usuario_8  = new Usuario("Agustina", "7", "Url 7", "Direccion 7");
    Usuario* usuario_9  = new Usuario("Diejo"   , "8", "Url 8", "Direccion 8");
    Usuario* usuario_10 = new Usuario("Pedro"   , "9", "Url 9", "Direccion 9");

    usuario_1->addContacto(usuario_2);
    usuario_1->addContacto(usuario_3);
    usuario_1->addContacto(usuario_4);
    usuario_1->addContacto(usuario_5);
    usuario_1->addContacto(usuario_6);
    usuario_1->addContacto(usuario_7);
    usuario_1->addContacto(usuario_8);
    usuario_1->addContacto(usuario_9);
    usuario_1->addContacto(usuario_10);

    usuario_2->addContacto(usuario_1);
    usuario_2->addContacto(usuario_3);
    usuario_2->addContacto(usuario_4);
    usuario_2->addContacto(usuario_5);

    usuario_3->addContacto(usuario_1);
    usuario_3->addContacto(usuario_2);

    usuario_4->addContacto(usuario_1);

    usuario_5->addContacto(usuario_1);
    usuario_5->addContacto(usuario_2);

    usuario_6->addContacto(usuario_1);
    usuario_6->addContacto(usuario_2);

    usuario_7->addContacto(usuario_1);
    usuario_7->addContacto(usuario_2);

    usuario_8->addContacto(usuario_1);
    usuario_8->addContacto(usuario_2);

    usuario_9->addContacto(usuario_1);
    usuario_9->addContacto(usuario_2);

    usuario_10->addContacto(usuario_1);
    usuario_10->addContacto(usuario_2);

    this->usuarios->add(new String(usuario_1->getNumero().c_str())  , usuario_1);
    this->usuarios->add(new String(usuario_2->getNumero().c_str())  , usuario_2);
    this->usuarios->add(new String(usuario_3->getNumero().c_str())  , usuario_3);
    this->usuarios->add(new String(usuario_4->getNumero().c_str())  , usuario_4);
    this->usuarios->add(new String(usuario_5->getNumero().c_str())  , usuario_5);
    this->usuarios->add(new String(usuario_6->getNumero().c_str())  , usuario_6);
    this->usuarios->add(new String(usuario_7->getNumero().c_str())  , usuario_7);
    this->usuarios->add(new String(usuario_8->getNumero().c_str())  , usuario_8);
    this->usuarios->add(new String(usuario_9->getNumero().c_str())  , usuario_9);
    this->usuarios->add(new String(usuario_10->getNumero().c_str()) , usuario_10);

};

//Pantallas

void Sistema::SolicitaListaContactos() {
    header("Contactos del Sistema");
    Usuario* n;
    li();
    if (!this->usuarios->isEmpty()) {
        IIterator* it = this->usuarios->getIterator();
        while (it->hasCurrent()) {
            n = (Usuario*) it->getCurrent();
            li("-");
            n->impresionSimple();
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

// Constructores y Destructores
Sistema * Sistema::instance = 0;

Sistema * Sistema::getInstance() {
    if (instance == 0) {
        instance = new Sistema();
    }
    return instance;
}

Sistema::Sistema(Usuario* _activo, IDictionary* _usuarios, IDictionary* _conversaciones) {
    this->IDMensaje = 0;
    this->activo = _activo;
    this->usuarios = _usuarios;
    this->conversaciones = _conversaciones;
    this->grupos = new OrderedDictionary();
    this->log = false;
};

Sistema::Sistema() {
    this->IDMensaje = 0;
    this->activo = NULL;
    this->usuarios = new OrderedDictionary();
    this->conversaciones = new OrderedDictionary();
    this->grupos = new OrderedDictionary();
    this->log = false;
};

Sistema::~Sistema() {
};

bool Sistema::ListarOpciones() {
    int Opciones = 0;
    bool ok;
    try {
        do {
            header(" Opciones del Sistema");
            ol();
            ol("AbrirGuasapTECNO");
            ol("CerrarGuasapTECNO");
            ol("AgregarContactos");
            ol("AltaGrupo");
            ol("AgregarAdministradores");
            ol("EnviarMensaje");
            ol("VerMensajes");
            ol("ArchivarConversaciones");
            ol("AgregarParticipantes");
            ol("EliminarParticipantes");
            ol("ModificarUsuario");
            ol("EliminarMensaje");
            ol("Cerrar Applicacion");
            Opciones = CinInt();
        } while (olBool(Opciones));
        if (Opciones != 1 and Opciones != 13 and !this->log) {
            alarm("¡No hay usuario en sesion!");
        } else {
            switch (Opciones) {
                case 1:
                    return AbrirGuasapTECNO(); // Test
                case 2:
                    return CerrarGuasapTECNO(); // Test
                case 3:
                    return AgregarContactos(); // Test
                case 4:
                    return AltaGrupo(); // Test
                case 5:
                    return AgregarAdministradores(); // Test
                case 6:
                    return EnviarMensaje(); // Test
                case 7:
                    return VerMensajes(); // Test
                case 8:
                    return ArchivarConversaciones(); // Test
                case 9:
                    return AgregarParticipantes(); // Test
                case 10:
                    return EliminarParticipantes(); // seba
                case 11:
                    ok = ModificarUsuario(); // Test
                    ActualizaUsuarioLocal();
                    return ok;
                case 12:
                    return EliminarMensaje(); //
                case 13:
                    return true;
            }
        }
    } catch (int e) {
        alarm("Error " + e);
        return false;
    }
};

//DSS

bool Sistema::AbrirGuasapTECNO() {
    string Numero;
    do {
        header("Abrir GuasapTECNO");
        Numero = CinString("Ingrese su Numero");
        IKey* k = new String(Numero.c_str());
        if (this->activo == NULL) {
            if (this->usuarios->isEmpty()) {
                if (PantallaNoHayUsuario()) {
                    this->NuevoUsuario(Numero);
                    this->log = true;
                    return false;
                } else {
                    return true;
                }
            } else {
                if (!this->usuarios->member(k)) {
                    switch (PantallaUsuarioNoExiste()) {
                        case 1:
                            this->NuevoUsuario(Numero);
                            this->log = true;
                            return false;
                            break;
                        case 3:
                            return true;
                    }
                } else {
                    this->activo = (Usuario*) this->usuarios->find(k);
                    this->log = true;
                    return false;
                }
            }
        } else {
            if (Numero.compare(this->activo->getNumero()) != 0) {
                switch (PantallaUsuarioEquivocado()) {
                    case 1:
                        this->CerrarGuasapTECNO();
                        return false;
                        break;
                    case 3:
                        return true;
                }
            } else {
                return false;
            }
        }
    } while (true);
    return false;
};

bool Sistema::CerrarGuasapTECNO() {
    if (this->log) {
        if (PantallaUsuarioCerrar()) {
            this->activo = NULL;
        }
        return false;
    } else {
        alarm("No hay usuario logeado");
    }
};

bool Sistema::AgregarContactos() {
    /*
            El caso de uso comienza cuando un usuario, que previamente ha iniciado
        sesión, desea agregar a otros usuarios de la aplicación como sus contactos.
            Para ello, para cada contacto que desee agregar, primero el sistema lista los
        contactos que el usuario posee. De cada uno se muestra el número de
        celular, el nombre y la URL de la imagen de perfil.
            Luego el usuario puede agregar un nuevo contacto, ingresando el número
        de celular del mismo o finalizar el caso de uso.
            En la primera opción, el usuario indica el número de celular y el sistema le
        muestra todos sus datos. El usuario confirma si desea agregarlo y en caso
        afirmativo, el sistema lo agrega como contacto del usuario. Acto seguido,
        el usuario puede elegir finalizar el caso de uso o continuar agregando
        contactos como se describió anteriormente.
        En caso que el usuario a agregar como contacto no exista o corresponda a
        un contacto que ya posee, el sistema muestra un mensaje acorde sin
        finalizar el caso de uso.
     */
    string Numero;
    IKey* k;
    do {
        if (PantallaAgregarContacto(this->activo)) {
            header("Seleccionar Contacto");
            Numero = CinString("Ingrese el numero");
            k = new String(Numero.c_str());
            header("Datos de Contacto Seleccionado");
            if (this->usuarios->isEmpty()) {
                alarm("¡Hay usuarios en el sistema!");
            } else if (!this->usuarios->member(k)) {
                alarm("¡El Usuario no existe!");
            } else if (this->activo->getNumero().compare(Numero) == 0) {
                alarm("¡No te puedes agregar como contacto!");
            } else if (this->activo->member(k)) {
                alarm("¡El Usuario ya es un contacto!");
            } else {
                Usuario* n = (Usuario*) this->usuarios->find(k);
                li();
                n->impresion();
                li();
                if (PantallaConfirmaContacto()) {
                    this->activo->addContacto(n);
                };
            }
        } else {
            return false;
        }
    } while (true);
};

bool Sistema::AltaGrupo() {
    /*
            El caso de uso comienza cuando un usuario, que previamente ha iniciado
        sesión, desea dar de alta un grupo. Este caso se realiza en dos grandes
        pasos.
            El primer paso consiste en la elección de los participantes del grupo que
        debe ser al menos uno (además del usuario que da de alta al grupo). Para
        este paso, mientras el usuario lo desee se procede de la siguiente forma.
        El sistema lista por un lado los datos de los contactos elegidos hasta el
        momento como participantes del grupo y por otro de los contactos del
        usuario restantes. Luego, el usuario puede quitar algún contacto elegido
        previamente o elegir un nuevo participante. Para cualquiera de estas dos
        opciones utiliza el número de celular. Si no elige a ningún participante,
        el sistema le avisa que debe seleccionar al menos 1 y el usuario elige entre
        repetir este primer paso o cancelar el caso de uso.
        Una vez elegidos los participantes del grupo, el paso dos consiste en el
        ingreso por parte del usuario del nombre del grupo y la URL de la imagen.
        El sistema termina dando de alta el grupo usando además la fecha y hora
        actual como fecha y hora de creación del grupo y al usuario con sesión
        como el administrador del grupo.
        En caso que el usuario no posea contactos, el sistema muestra un aviso y
        se finaliza el caso de uso. En situaciones análogas se procede de la misma
        manera.
     */
    if (this->activo->isEmptyContactos()) {
        alarm("No tienes contactos como para aser un grupo");
        return false;
    }
    int Opciones = 0;
    string Numero, Nombre;
    IDictionary* contactos = new OrderedDictionary();
    IKey* k;
    do {
        do {
            header("Alta Grupo");
            Opciones = PantallaImprimeAltagrupo(this->activo, contactos);
            if (Opciones == 3) {
                if (contactos->isEmpty()) {
                    alarm("El Grupo esta vacio");
                } else if (PantallaConformeContactos()) {
                    header("Datos de grupo");
                    Nombre = CinString("Ingrese un Nombre");
                    k = new String(Nombre.c_str());
                    Grupo* g = new Grupo(Nombre, CinString("Ingrese un Imagen"), contactos);
                    g->setAdmin(this->activo);
                    this->grupos->add(k, g);
                } else {
                    delete contactos;
                    return false;
                }
            } else {
                Numero = CinString("Ingrese el numero");
                k = new String(Numero.c_str());
                if (this->activo->memberContactos(k)) {
                    if (Numero.compare(this->activo->getNumero()) != 0) {
                        if (Opciones == 1) {
                            if (!contactos->member(k)) {
                                contactos->add(k, this->activo->findContactos(k));
                            } else {
                                alarm("Ya pertenece al grupo");
                            }
                        } else if (Opciones == 2) {
                            if (contactos->member(k)) {
                                contactos->remove(k);
                            } else {
                                alarm("No pertenece al grupo");
                            }
                        }
                    } else {
                        alarm("Imposible es tu numero");
                    }
                } else {
                    alarm("El numero no es tu contacto");
                }
            }
        } while (Opciones != 3);
    } while (PantallaOtroGrupos());
    return false;
};

bool Sistema::AgregarAdministradores() {
    /*
            El caso de uso comienza cuando un usuario, que previamente ha iniciado
        sesión, desea agregar a otros participantes como administradores de un
        grupo.
            Para ello el sistema lista el nombre de cada grupo en el que el usuario
        participa. Luego el usuario selecciona un grupo del listado indicando su
        nombre.
            El sistema lista datos de los participantes del grupo indicando además
        para cada uno si es administrador o no.
            Si el usuario es administrador del grupo, selecciona a uno de los
        participantes que no sea administrador para agregarlo como tal. Luego el
        sistema agrega al participante elegido como administrador del grupo.
            Este proceso se repite mientras hayan participantes que no sean
        administradores y el usuario desee agregar administradores al grupo. Al
        terminar este proceso, finaliza el caso de uso.
            En caso que el usuario no sea administrador del grupo o que el
        participante elegido ya sea administrador, el sistema muestra un mensaje
        acorde a la situación, sin finalizar el caso de uso.
            En caso que el usuario no participe en ningún grupo, el sistema muestra
        un mensaje y finaliza el caso de uso.
     */
    return this->activo->AgregarAdministradores();
};

bool Sistema::EnviarMensaje() {
    /*
            El caso de uso comienza cuando un usuario, que previamente ha
        iniciado sesión, desea enviar un mensaje.
            Primero, el sistema lista las conversaciones del usuario. Para cada
        conversación activa, si se corresponde a un grupo se muestra el
        nombre del grupo. Si es una conversación simple, se muestra
        nombre y número de celular del contacto con el cual se mantiene la
        misma. Para el caso de las conversaciones archivadas, se muestra
        una sola entrada con la etiqueta “Archivadas” y la cantidad de
        conversaciones archivadas.
        A continuación, el usuario puede elegir entre las siguientes
        opciones:
        1. Seleccionar una conversación activa
        2. Ver las conversaciones archivadas
        3. Enviar un mensaje a un contacto con el cuál aún no ha iniciado
        una conversación
        Si el usuario elige la primera opción, luego ingresa el identificador
        de la conversación activa que quiere seleccionar.
        En caso de elegir la segunda opción, el sistema lista las
        conversaciones archivadas de igual forma a la que se listan las
        conversaciones activas. Luego el usuario ingresa el identificador de
        la conversación archivada que quiere seleccionar.
            Si elige la tercera opción, el sistema lista todos los contactos del
        usuario, mostrando para cada uno su número de celular y nombre.
        Luego el usuario indica el contacto con el cual quiere iniciar la
        conversación individual, ingresando el número de celular del
        mismo.
            Posteriormente, el usuario elige el tipo de mensaje que desea enviar
        entre las opciones simple, imagen, video o contacto. En caso de
        elegir un mensaje simple debe ingresar el texto a enviar. En el caso
        de una imagen, debe ingresar su URL, formato, tamaño y de forma
        opcional un texto descriptivo de la imagen. En caso de elegir un
        video debe ingresar la URL del mismo y la duración. Por último, si
        elige un contacto, el sistema lista el nombre y número de celular de
        todos los contactos del usuario. Luego el usuario selecciona el
        contacto que desea compartir ingresando el número de celular del
        mismo.
        Finalmente, el sistema crea el mensaje con un código identificatorio
        autogenerado por el sistema y la fecha y hora de envío con la fecha
        y hora actual del sistema. Adicionalmente, en caso que el mensaje
        sea enviado en una conversación archivada, la misma se convierte
        en activa. Por último, el mensaje se agrega como no visto.
        En caso que el usuario no participe en ninguna conversación, el
        sistema muestra un mensaje apropiado y se finaliza el caso de uso.
        Este comportamiento se repite para situaciones análogas.
     */
    this->IDMensaje = this->activo->EnviarMensaje(this->IDMensaje);
    return false;

};

bool Sistema::VerMensajes() {
    /*
            El caso de uso comienza cuando un usuario, que previamente ha iniciado
        sesión, desea ver los mensajes de una conversación.
        Primero, el sistema lista las conversaciones del usuario. Para cada
        conversación activa, si se corresponde a un grupo se muestra el nombre
        del grupo. Si es una conversación simple, se muestra nombre y número
        de celular del contacto con el cual se mantiene la misma. Para el caso de
        las conversaciones archivadas, se muestra una sola entrada con la etiqueta
        “Archivadas” y la cantidad de conversaciones archivadas.
        A continuación, el usuario puede elegir entre las siguientes opciones:
        1. Seleccionar una conversación activa
        2. Ver las conversaciones archivadas
        Si el usuario elige la primera opción, luego ingresa el identificador de la
        conversación activa que quiere seleccionar.
        En caso de elegir la segunda opción, el sistema lista las conversaciones
        archivadas de igual forma a la que se listan las conversaciones activas.
        Luego el usuario ingresa el identificador de la conversación archivada que
        quiere seleccionar.
        A continuación, el sistema muestra todos los datos de los mensajes de esa
        conversación. En caso de que sea de un grupo, sólo muestra los mensajes
        cuya fecha y hora de envío sea mayor o igual a la fecha y hora en que el
        usuario fue añadido al grupo. Además, marca aquellos mensajes
        mostrados en el cual el usuario es receptor como mensaje visto
        registrando la fecha y hora de visto con la fecha y hora actual del sistema.
        Finalmente, el usuario puede elegir ver información adicional de sus
        mensajes enviados. Seleccionando un mensaje enviado, el sistema
        muestra el nombre y número de celular de los receptores que lo han visto
        junto con la fecha y hora en que lo hicieron. Esto lo repite para los
        mensajes que desee.
        Luego, finaliza el caso de uso.
        En caso que el usuario no participe en ninguna conversación, el sistema
        muestra un aviso y se finaliza el caso de uso. En situaciones análogas se
        procede de la misma manera.
     */
    this->activo->VerMensajes();
};

bool Sistema::ArchivarConversaciones() {
    /*
            El caso de uso comienza cuando un usuario, que previamente ha iniciado
        sesión, desea archivar una o más conversaciones.
        Para ello el sistema lista las conversaciones activas del usuario. Si la
        conversación corresponde a un grupo, se muestra el nombre del grupo. Si
        corresponde a una conversación simple, se muestra nombre y número de
        celular del contacto con el cual se mantiene la conversación.
        Luego el usuario selecciona una conversación proporcionando su
        identificador y finalmente el sistema cambiará dicha conversación a
        archivada.
        Este proceso se repite mientras el usuario desee archivar conversaciones.
        Luego finaliza el casos de uso.
        En caso que el usuario no tenga conversaciones activas, el sistema
        muestra un mensaje acorde y se finaliza el caso de uso.
     */
    this->activo->ArchivarConversaciones();
};

bool Sistema::AgregarParticipantes() {
    /*
            El caso de uso comienza cuando un usuario, que previamente ha iniciado
        sesión, desea agregar participantes a un grupo.
        Para ello el sistema lista el nombre de cada grupo en el cual el usuario
        participa y este selecciona uno indicando su nombre. Acto seguido el
        sistema lista los datos de los participantes del grupo, indicando además
        para cada uno si es administrador y la fecha y hora en que fue añadido al
        grupo.
        Luego el sistema lista los contactos del usuario. El usuario selecciona uno
        y en caso que este no forme parte del grupo, el sistema lo agrega.
        Esto se repite mientras el usuario desee agregar contactos a un grupo. Al
        finalizar este proceso termina el caso de uso.
        En caso que el usuario no sea administrador del grupo o que el número de
        celular no sea contacto del usuario, el sistema muestra un mensaje
        apropiado, sin finalizar el caso de uso.
        En caso que el usuario no participe en ningún grupo, el sistema muestra
        un aviso y se finaliza el caso de uso.
     */
    this->activo->AgregarParticipantes();
};

bool Sistema::EliminarParticipantes() {
    /*
            El caso de uso comienza cuando un usuario, que previamente ha iniciado
        sesión, desea eliminar participantes de un grupo.
        Para ello el sistema lista el nombre de cada grupo en el cual el usuario
        participa y este selecciona uno indicando su nombre.
        El sistema lista los datos de los participantes del grupo, indicando además
        para cada uno si es administrador.
        Si el usuario es administrador del grupo, selecciona uno de los
        participantes indicando su número de celular y el sistema lo elimina del
        grupo. Los mensajes del participante dentro del grupo NO son eliminados.
        A su vez, de aquí en adelante el participante eliminado no puede ver la
        conversación del grupo (por tanto no ve ningún mensaje del grupo ni
        puede enviar mensajes al mismo).
        Esto se repite mientras el usuario desee eliminar participantes del grupo.
        Luego finaliza el caso de uso.
        En caso que el usuario no sea administrador del grupo o que el número de
        celular del participante seleccionado, no forme parte del grupo, el sistema
        muestra un mensaje apropiado sin finalizar el caso de uso.
        En caso que el usuario no participe en ningún grupo, el sistema muestra
        un aviso y se finaliza el caso de uso.
     */
    this->activo->EliminarParticipantes();
};

bool Sistema::ModificarUsuario() {
    /*
            El caso de uso comienza cuando un usuario, que previamente ha iniciado
        sesión, desea modificar su información personal con excepción de su
        número de celular y la fecha y hora de registro.
        Para ello el usuario ingresa los nuevos valores de la información personal
        que desea actualizar, pudiendo elegir entre el nombre de usuario, la URL
        de la imagen de perfil y su descripción personal.
        Luego el sistema actualiza la información personal del usuario con los
        nuevos valores ingresados y finaliza el caso de uso.
     */
    this->activo->ModificarUsuario();
};

bool Sistema::EliminarMensaje() {
    /*
            El caso de uso comienza cuando un usuario, que previamente ha iniciado
        sesión, desea eliminar un mensaje.
            Primero, el sistema lista las conversaciones del usuario. Para cada
        conversación activa, si se corresponde a un grupo se muestra el nombre
        del grupo. Si es una conversación simple, se muestra nombre y número
        de celular del contacto con el cual se mantiene la misma. Para el caso de
        las conversaciones archivadas, se muestra una sola entrada con la etiqueta
        “Archivadas” y la cantidad de conversaciones archivadas.
        A continuación, el usuario puede elegir entre las siguientes opciones:
        1. Seleccionar una conversación activa
        2. Ver las conversaciones archivadas
        Si el usuario elige la primera opción, luego ingresa el identificador de la
        conversación activa que quiere seleccionar.
        En caso de elegir la segunda opción, el sistema lista las conversaciones
        archivadas de igual forma a la que se listan las conversaciones activas.
        Luego el usuario ingresa el identificador de la conversación archivada que
        quiere seleccionar.
        A continuación, el sistema muestra todos los datos de los mensajes de esa
        conversación. En caso de que sea de un grupo, sólo muestra los mensajes
        cuya fecha y hora de envío sea mayor o igual a la fecha y hora en que el
        usuario fue añadido al grupo.
        Finalmente el usuario selecciona el mensaje que desea eliminar. Si el
        usuario es el emisor del mensaje, el sistema elimina el mensaje
        desvinculándolo incluso de la conversación y de manera que no pueda ser
        visto ni por su emisor ni por sus receptores en el futuro. Si el usuario es
        receptor del mensaje se lo elimina de manera que pueda ser visto por el
        emisor y los otros receptores. Dicho de otra forma, el primer caso
        corresponde a una eliminación física y en el segundo caso a una
        eliminación lógica para el usuario.
        En caso que el usuario no participe en ninguna conversación, el sistema
        muestra un aviso y se finaliza el caso de uso. En situaciones análogas se
        procede de la misma manera.
     */
    this->activo->EliminarMensaje();
};
