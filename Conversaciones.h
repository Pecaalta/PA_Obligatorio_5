#ifndef CONVERSACIONES_H
#define CONVERSACIONES_H

#include "iostream"
#include "string"
#include "string.h"

using namespace std;

#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/IIterator.h"
#include "ICollection/interfaces/IKey.h"
#include "ICollection/collections/List.h"
#include "Miembro_Conversacion.h"
class Usuario;
class Visto;

class Conversaciones : public ICollectible {
public:
    IDictionary* getMensaejs();
    void setMensaejs(IDictionary* _mensaejs);
    void addMensaje(Mensaje* mens, string Numero);
    Usuario* getUser1();
    void setUser1(Usuario* user1);
    Usuario* getUser2();
    void setUser2(Usuario* user2);
    string getId();
    virtual string tipo();

    void impresionSimple();
    void impresionSimple(Usuario* _user);
    void impresionSimple(string _user);
void ImprimeMensajes();

    Conversaciones(Usuario* _user_1, Usuario* _user_2, IDictionary* _mensaejs);
    Conversaciones(Miembro_Conversacion* mimbro, Usuario* _user_1);
    Conversaciones(Usuario* _user_1, Usuario* _user_2);
    Conversaciones(Usuario* _user_1);
    Conversaciones(Miembro_Conversacion* mimbro);
    Conversaciones();
    ~Conversaciones();
private:
    IDictionary* mensaejs;
    Visto* user1;
    Visto* user2;
    string id;
};


#include "Visto.h"
#include "Usuario.h"

#endif /* CONVERSACIONES_H */

