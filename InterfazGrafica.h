
#ifndef INTERFAZGRAFICA_H
#define INTERFAZGRAFICA_H

#include "string"
#include "Usuario.h"
using namespace std;

void gotoxy(int x, int y);
void Color();
void Color(int col);
void Console(int ancho, int largo);
void log(string texto);
void log();

bool Rango(bool sent, bool exepcion);
bool Rango(bool sent);

void Subheader(string texto);
void header(string texto);
void header(bool limpiarPantalla, string texto);
string CinString();
string CinString(string texto);
int CinInt();
int CinInt(string texto);
void li();
void li(string texto);
void ol(string texto);
void ol();
int olNum();
void p(string texto);
bool olBool(int numero);
void alarm(string text);

bool MenuDual(string titule,string OpcionFalsa,string OpcionVerdadera);
bool MenuDual(bool limpia, string titule, string OpcionFalsa, string OpcionVerdadera);

int PantallaSeleccionModificarUsuario();

int PantallaSeleccionConversacionEnviarMensaje(Usuario* user);
int PantallaSeleccionTipomensajeEnviarMensaje();
bool PantallaEnviarOtroEnviarMensaje(int tipo);
bool PantallaSeleccionarOtraConversacionEnviarMensaje();
int PantallaSeleccionConversacionVerMensaje(Usuario* user);

bool PantallaSeleccionDetalladoEliminarMensaje();
bool PantallaSeleccionDetalladoVerMensaje();
bool PantallaSeleccionMasMensajesDetalladoVerMensaje();

bool PantallaSegirArchivandoConversacion();

bool PantallaSeleccionAgregarAdministradores();
bool PantallaSeleccionSeleccionGrupoAgregarAdministradores();
bool PantallaSeleccionAgregarParticipantes();
bool PantallaSeleccionEliminarParticipantes();


void PantallaImprimeArchivada();
void PantallaImprimeArchivada(Usuario* user);
int PantallaImprimeAltagrupo(Usuario* user, IDictionary* contactos );
bool PantallaConformeContactos();
bool PantallaOtroGrupos();

bool PantallaNoHayUsuario();
int PantallaUsuarioNoExiste();
int PantallaUsuarioEquivocado();
bool PantallaUsuarioCerrar();
bool PantallaAgregarContacto(Usuario* user);
bool PantallaConfirmaContacto();


bool PantallaSeleccionEnviarEstado();

    void GuardaUsuarioLocal(Usuario*);
    void ActualizaUsuarioLocal(Usuario* user);

#endif /* INTERFAZGRAFICA_H */

