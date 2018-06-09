
#include "ISistema.h"
#include "factory.h"
#include "InterfazGrafica.h"

using namespace std;
int main(int argc, char** argv) {
    system("TITLE GuasapTECNO");
    Console(120,30);
    
    ISistema* sis = factory::CrearSistema();
    sis->CargarUsuario();
    while (!sis->ListarOpciones());
    return 0;
}

