#include "InterfazGrafica.h"
#include "iostream"
#include "Sistema.h"
#include <stdio.h>
#include <windows.h>
#include <time.h>

#include <fstream>
using namespace std;


int ancho = 120;
int largo = 30;
string tab = "    ";
bool Contli = true;
int ContOl = 0;

void GuardaUsuarioLocal(Usuario* user) {
    FILE * pFile;
    pFile = fopen("fichero.txt", "a");
    fprintf(pFile, "%s,%s,%s,%s\n", user->getNombre().c_str(), user->getDireccion().c_str(), user->getNumero().c_str(), user->getImagen().c_str());
    fclose(pFile);
}

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void Color(int col) {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    FlushConsoleInputBuffer(hConsole);
    SetConsoleTextAttribute(hConsole, col);
}

void Color() {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);
}

void log(string text) {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    ofstream fs("log.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    fs << (1900 + ltm->tm_year) << "-" << (1 + ltm->tm_mon) << "-" << (ltm->tm_mday) << " " << (ltm->tm_hour) << ":" << (1 + ltm->tm_min) << ":" << (1 + ltm->tm_sec) << " " << text << endl;
    fs.close();
}

void log(int text) {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    ofstream fs("log.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    fs << (1900 + ltm->tm_year) << "-" << (1 + ltm->tm_mon) << "-" << (ltm->tm_mday) << " " << (ltm->tm_hour) << ":" << (1 + ltm->tm_min) << ":" << (1 + ltm->tm_sec) << " " << text << endl;
    fs.close();
}

void Console(int ancho, int largo) {
    SMALL_RECT r;
    COORD c;
    HANDLE hConOut = GetStdHandle(STD_OUTPUT_HANDLE);
    r.Right = ancho - 1;
    r.Bottom = largo - 1;
    SetConsoleWindowInfo(hConOut, TRUE, &r);
    c.X = ancho;
    c.Y = largo + 999;
    SetConsoleScreenBufferSize(hConOut, c);

}

bool Rango(bool sent) {
    if (sent) {
        alarm("Opcion no valida");
    }
    return sent;
}

bool Rango(bool sent, bool exepcion) {
    if (sent) {
        alarm("Opcion no valida");
    }
    if (exepcion)
        return true;
    else
        return sent;
}

int CinInt() {
    cout << endl << "\t>";
    string texto;
    fflush(stdin);
    getline(cin, texto);
    int ret = 0, aux = 0, pow = 1;
    for (int i = texto.size() - 1; i >= 0; i--) {
        aux = ((int) texto[i] - 48);
        if (aux <= 9 and aux >= 0) {
            ret += pow * aux;
            pow *= 10;
        } else {
            return -1;
        }
    }
    log(ret);
    return ret;
};

int CinInt(string texto) {
    cout << "\t " << texto << ": ";
    fflush(stdin);
    getline(cin, texto);
    int ret = 0, aux = 0, pow = 1;
    for (int i = texto.size() - 1; i >= 0; i--) {
        aux = ((int) texto[i] - 48);
        if (aux <= 9 and aux >= 0) {
            ret += pow * aux;
            pow *= 10;
        } else {
            return -1;
        }
    }
    log(ret);
    return ret;
};

string CinString() {
    string texto;
    cout << endl << "\t>";
    fflush(stdin);
    getline(cin, texto);
    log(texto);
    return texto;
};

string CinString(string texto) {
    cout << "\t " << texto << ": ";
    fflush(stdin);
    getline(cin, texto);
    log(texto);
    return texto;
};

void header(string texto) {
    system("cls");
    char ASCII[] = {(char) 205, (char) 186, (char) 201, (char) 187, (char) 188, (char) 200, (char) 196};
    int anchoImprimible = (ancho - 10);
    int spacio = (anchoImprimible - texto.size()) / 2;
    int var1 = (spacio * 2);
    int var2 = anchoImprimible - texto.size();
    cout << endl;
    cout << tab << ASCII[2];
    for (int i = 0; i < anchoImprimible; i++) {
        cout << ASCII[0];
    }
    cout << ASCII[3] << endl;

    cout << tab << ASCII[1];
    for (int i = 0; i < spacio; i++) {
        cout << " ";
    }
    cout << texto;
    if (var1 != var2) {
        cout << " ";
    }
    for (int i = 0; i < spacio; i++) {
        cout << " ";
    }
    cout << ASCII[1] << endl;

    cout << tab << ASCII[5];
    for (int i = 0; i < anchoImprimible; i++) {
        cout << ASCII[0];
    }
    cout << ASCII[4] << endl;
    cout << endl;
};

void p(string texto) {
    int anchoImprimible = ancho - (tab.size() * 4) - 3;
    anchoImprimible -= 4;
    int i = 0;
    cout << tab;
    for (i; i < anchoImprimible && i < texto.size(); i++) {
        cout << texto[i];
    }
    if (i == anchoImprimible) {
        cout << "... ";
    }

    cout << endl;
};

void header(bool limpiarPantalla, string texto) {
    if (limpiarPantalla) {
        system("cls");
    }
    char ASCII[] = {(char) 205, (char) 186, (char) 201, (char) 187, (char) 188, (char) 200, (char) 196};
    int anchoImprimible = (ancho - 10);
    int spacio = (anchoImprimible - texto.size()) / 2;
    int var1 = (spacio * 2);
    int var2 = anchoImprimible - texto.size();
    cout << endl;
    cout << tab << ASCII[2];
    for (int i = 0; i < anchoImprimible; i++) {
        cout << ASCII[0];
    }
    cout << ASCII[3] << endl;

    cout << tab << ASCII[1];
    for (int i = 0; i < spacio; i++) {
        cout << " ";
    }
    cout << texto;
    if (var1 != var2) {
        cout << " ";
    }
    for (int i = 0; i < spacio; i++) {
        cout << " ";
    }
    cout << ASCII[1] << endl;

    cout << tab << ASCII[5];
    for (int i = 0; i < anchoImprimible; i++) {
        cout << ASCII[0];
    }
    cout << ASCII[4] << endl;
    cout << endl;
};

void Subheader(string texto) {
    int anchoImprimible = (ancho - 20);
    int spacio = (anchoImprimible - texto.size()) / 2;
    int var1 = (spacio * 2);
    int var2 = anchoImprimible - texto.size();
    cout << tab << tab << "  ";
    for (int i = 0; i < spacio; i++) {
        cout << " ";
    }

    cout << " " << texto << " " << endl;

    cout << tab << tab << "  ";
    for (int i = 0; i < anchoImprimible; i++) {
        cout << (char) 205;
    }
    cout << endl;
};

void li() {
    int anchoImprimible = ancho - (tab.size() * 4) - 2;
    cout << tab << tab;
    if (Contli) {
        cout << (char) 218;
        for (int i = 0; i < anchoImprimible; i++) {
            cout << (char) 196;
        }
        cout << (char) 191;
    } else {
        cout << (char) 192;
        for (int i = 0; i < anchoImprimible; i++) {
            cout << (char) 196;
        }
        cout << (char) 217;
    }
    cout << endl;
    Contli = !Contli;
}

void li(string texto) {
    int anchoImprimible = ancho - (tab.size() * 4) - 3;
    if (texto.compare("-") != 0) {
        cout << tab << tab << (char) 179 << " ";
        if (anchoImprimible > texto.size()) {
            cout << texto;
            anchoImprimible -= texto.size();
            for (int i = 0; i < anchoImprimible; i++) {
                cout << " ";
            }
        } else {
            anchoImprimible -= 4;
            for (int i = 0; i < anchoImprimible; i++) {
                cout << texto[i];
            }
            cout << "... ";
        }
        cout << (char) 179 << endl;
    } else {
        anchoImprimible += 1;
        cout << tab << tab << (char) 195;
        for (int i = 0; i < anchoImprimible; i++) {
            cout << (char) 196;
        }
        cout << (char) 180;
        cout << endl;
    }
}

void li(string texto, bool left) {
    int anchoImprimible = ancho - (tab.size() * 4) - 3;
    if (texto.compare("-") != 0) {
        cout << tab << tab << (char) 179 << " ";
        if (anchoImprimible > texto.size()) {
            anchoImprimible -= texto.size();
            if (left) {
                cout << texto;
                for (int i = 0; i < anchoImprimible; i++) {
                    cout << " ";
                }
            } else {
                for (int i = 0; i < anchoImprimible; i++) {
                    cout << " ";
                }
                cout << texto;
            }
        } else {
            anchoImprimible -= 4;
            for (int i = 0; i < anchoImprimible; i++) {
                cout << texto[i];
            }
            cout << "... ";
        }
        cout << (char) 179 << endl;
    } else {
        anchoImprimible += 1;
        cout << tab << tab << (char) 195;
        for (int i = 0; i < anchoImprimible; i++) {
            cout << (char) 196;
        }
        cout << (char) 180;
        cout << endl;
    }
}

void ol(string texto) {
    ContOl++;
    int anchoImprimible = ancho - (tab.size() * 4) - 5;
    cout << tab << tab;
    printf("%-3d", ContOl);
    cout << " - ";
    if (anchoImprimible > texto.size()) {
        cout << texto;
        anchoImprimible -= texto.size();
    } else {
        anchoImprimible -= 4;
        for (int i = 0; i < anchoImprimible; i++) {
            cout << texto[i];
        }
        cout << "... ";
    }
    cout << endl;
}

void ol() {
    ContOl = 0;
}

int olNum() {
    return ContOl;
}

bool olBool(int numero) {//Retorna verdadero para ser usado en while
    if (numero < 1 || numero > ContOl) {
        alarm("Opcion invalida");
        return true;
    } else {
        return false;
    }
}

void alarm(string text) {
    int margenDerechoIzquierdo = 10;
    int margenArribaAbajo = 6;

    int anchoImprimible = (ancho - (margenDerechoIzquierdo * 2) - 2);
    int largoImprimible = (largo - (margenArribaAbajo * 2) - 2);
    gotoxy(margenDerechoIzquierdo, margenArribaAbajo);
    cout << (char) 201;
    for (int i = 0; i < anchoImprimible; i++) {
        cout << (char) 205;
    }
    cout << (char) 187;

    for (int i = 0; i < largoImprimible; i++) {
        margenArribaAbajo++;
        gotoxy(margenDerechoIzquierdo, margenArribaAbajo);
        cout << (char) 186;
        for (int i = 0; i < anchoImprimible; i++) {
            cout << " ";
        }
        cout << (char) 186;
    }
    margenArribaAbajo++;
    gotoxy(margenDerechoIzquierdo, margenArribaAbajo);
    cout << (char) 200;
    for (int i = 0; i < anchoImprimible; i++) {
        cout << (char) 205;
    }
    cout << (char) 188;

    gotoxy((ancho / 2 - (text.size() / 2) + 1), largo / 2);
    cout << text;
    system("pause>nul");
    system("cls");
}

/*Pantallas*/

/*
 * Modificar Usuario
 */

int PantallaSeleccionModificarUsuario() {
    int Opciones = -1;
    do {
        if (Opciones != -1) {
            alarm("Opciones incorrecta");
        }
        header("Modificar Usuario");
        ol();
        ol("Modificar Nombre");
        ol("Modificar Descripcion");
        ol("Modificar Imagen de Perfil");
        ol("Cancelar");
        Opciones = CinInt();
    } while (Opciones < 1 || Opciones > 4);
    return Opciones;
};

/*
 * Enviar Mensajes
 */

int PantallaSeleccionConversacionEnviarMensaje(Usuario* user) {
    int Opciones = -1;
    do {
        if (Opciones != -1) {
            alarm("Opciones incorrecta");
        }
        cout << endl;
        user->ListarMisConversaciones();
        cout << endl;
        user->ListarMisGruposSimple();
        cout << endl;
        li();
        li(" Archivadas " + to_string(user->CuentaArchivadas()));
        li();
        cout << endl;
        ol();
        ol("Seleccionar una conversacion activa");
        ol("Ver las conversaciones archivadas");
        ol("Enviar un mensaje a un contacto sin conversacion");
        ol("Volver");
        Opciones = CinInt();
    } while (Rango(Opciones < 1 || Opciones > 4));
    return Opciones;
}

int PantallaSeleccionTipomensajeEnviarMensaje() {
    int Opciones = -1;
    do {
        if (Opciones != -1) {
            alarm("Opciones incorrecta");
        }
        header("Seleccionar Tipo de mensaje");
        ol();
        ol("Simple");
        ol("Imagen");
        ol("Video");
        ol("Contacto");
        Opciones = CinInt();
    } while (Opciones < 1 || Opciones > 4);
    return Opciones;
}

bool PantallaEnviarOtroEnviarMensaje(int tipo) {
    int Opciones = -1;
    do {
        if (Opciones != -1) {
            alarm("Opciones incorrecta");
        }
        switch (tipo) {
            case 1:case 2:
                header("Crear otro Mensaje");
                break;
            default:
                header("Algo a intentar mandar un mensaje");
                break;
        }
        ol();
        ol("Enviar mensajes");
        ol("Cancelar");
        Opciones = CinInt();
    } while (Opciones < 1 || Opciones > 2);
    return Opciones == 2;
}

bool PantallaSeleccionarOtraConversacionEnviarMensaje() {
    int Opciones = -1;
    do {
        header("Elegir otra conversacion");
        ol();
        ol("Elegir conversacion");
        ol("Menu Principal");
        Opciones = CinInt();
    } while (Opciones < 1 || Opciones > 2);
    return Opciones == 1;
}

void PantallaImprimeArchivada(Usuario* user) {
    header("Selecciona Conversacion archivada");
    user->ListarMisConversacionesArchivadas();
    cout << endl;
    user->ListarMisGruposSimpleArchivadas();
    cout << endl;
}

int PantallaImprimeAltagrupo(Usuario* user, IDictionary* contactos) {
    Usuario* n;
    int Opciones = -1;
    do {
        if (Opciones != -1) {
            alarm("Opciones incorrecta");
        }
        Subheader("Contactos del grupo al momento");
        li();
        if (contactos->isEmpty()) {
            li("El grupo esta vacio por el momento.");
        } else {
            IIterator* it = contactos->getIterator();
            while (it->hasCurrent()) {
                n = (Usuario*) it->getCurrent();
                li("-");
                n->impresionSimple();
                li("-");
                it->next();
            }
            delete it;
        }
        li();
        user->SolicitaListaContactos(contactos);
        ol();
        ol("Agregar contactos");
        ol("Quitar contactos");
        ol("Finalizar");
        Opciones = CinInt();
    } while (Opciones < 1 || Opciones > 3);
    return Opciones;
}

bool PantallaConformeContactos() {
    return MenuDual("Confirma grupo", "Si", "No");
}

bool PantallaOtroGrupos() {
    return MenuDual("Crear otro grupo", "Si", "Volver");
}

bool PantallaNoHayUsuario() {
    return MenuDual("No hay usaurio en el sistema", "Registrarse", "Volver a menu");
}

int PantallaUsuarioNoExiste() {
    int Opciones = -1;
    do {
        if (Opciones != -1) {
            alarm("Opcion Incorrecta");
        }
        header("El usaurio no existe");
        ol();
        ol("Registrarse");
        ol("Reintentar");
        ol("Volver a menu");
        Opciones = CinInt();
    } while (Opciones < 1 || Opciones > 3);
    return Opciones;
}

int PantallaUsuarioEquivocado() {
    int Opciones = -1;
    do {
        if (Opciones != -1) {
            alarm("Opcion Incorrecta");
        }
        header("Hay otro usuario logeado");
        ol();
        ol("Cerrar sesion");
        ol("Reintentar");
        ol("Volver al menu");
        Opciones = CinInt();
    } while (Opciones < 1 || Opciones > 3);
    return Opciones;
}

bool PantallaUsuarioCerrar() {
    return MenuDual("Cerrar GuasapTECNO", "Cerrar sesion", "Volver");
}

bool PantallaAgregarContacto(Usuario* user) {
    int Opciones = -1;
    do {
        if (Opciones != -1) {
            alarm("Opciones incorrecta");
        }
        header("Agregar contacto");
        user->SolicitaListaContactos();

        cout << endl;
        ol();
        ol("Si");
        ol("Volver");
        Opciones = CinInt();
    } while (Opciones < 1 || Opciones > 2);
    return Opciones == 1;
}

bool PantallaConfirmaContacto() {
    return MenuDual(true,"Añadir a mis contactos", "Si", "Volver");
}

/*
 * Ver Mensajes
 */

int PantallaSeleccionConversacionVerMensaje(Usuario* user) {
    int Opciones = -1;
    do {
        if (Opciones != -1) {
            alarm("Opciones incorrecta");
        }
        system("cls");
        cout << endl;
        user->ListarMisConversaciones();
        cout << endl;
        user->ListarMisGruposSimple();
        cout << endl;
        li();
        li(" Archivadas " + to_string(user->CuentaArchivadas()));
        li();

        cout << endl;
        ol();
        ol("Seleccionar una conversacion activa");
        ol("Ver las conversaciones archivadas");
        ol("Volver");
        Opciones = CinInt();
    } while (Opciones < 1 || Opciones > 3);
    return Opciones;
}

bool PantallaSeleccionDetalladoVerMensaje() {
    return MenuDual(true,"Seleccionar un Mensaje", "Si", "Volver");
}
bool PantallaSeleccionDetalladoEliminarMensaje() {
    return MenuDual("Seleccionar un Mensaje", "Si", "Volver");
}

bool PantallaSeleccionMasMensajesDetalladoVerMensaje() {
    return MenuDual("Seguir viendo mensajes", "Si", "Volver");
}

/*
 * Archivar Conversaciones
 */


bool PantallaSegirArchivandoConversacion() {
    return MenuDual("Seguir archivando?", "Si", "Volver");
}

/*
 * Agregar Participantes
 */

bool PantallaSeleccionAgregarAdministradores() {
    return MenuDual("Agregar Administradores", "Agregar Administrador", "Volver");
}

bool PantallaSeleccionAgregarParticipantes() {
    return MenuDual("Agregar Mas Participantes", "Si", "Volver");
}
bool PantallaSeleccionEliminarParticipantes() {
    return MenuDual("Eliminar Mas Participantes", "Si, Eliminar mas participantes", "No, Volver a menu");
}

bool MenuDual(string titule, string OpcionFalsa, string OpcionVerdadera) {
    int Opciones = -1;
    do {
        if (Opciones != -1) {
            alarm("Opciones incorrecta");
        }
        header(titule);
        ol();
        ol(OpcionFalsa);
        ol(OpcionVerdadera);
        Opciones = CinInt();
    } while (Opciones < 1 || Opciones > olNum());
    return Opciones == 1;
}
/*
 * Estados
 */

bool PantallaSeleccionEnviarEstado() {
    return MenuDual(true,"Segir mandadno estados", "Si", "Volver");
}
bool MenuDual(bool limpia, string titule, string OpcionFalsa, string OpcionVerdadera) {
    int Opciones = -1;
    do {
        if (Opciones != -1) {
            alarm("Opciones incorrecta");
        }
        if (limpia) {
            Subheader(titule);
        } else {
            header(titule);
        }
        ol();
        ol(OpcionFalsa);
        ol(OpcionVerdadera);
        Opciones = CinInt();
    } while (Opciones < 1 || Opciones > olNum());
    return Opciones == 1;
}

int MenuTriple(string titule, string Opcion_1, string Opcion_2, string Opcion_3) {
    int Opciones = -1;
    do {
        if (Opciones != -1) {
            alarm("Opciones incorrecta");
        }
        header(titule);
        ol();
        ol(Opcion_1);
        ol(Opcion_2);
        ol(Opcion_3);
        Opciones = CinInt();
    } while (Opciones < 1 || Opciones > olNum());
    return Opciones;
}
