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

class Usuario;
class Visto;

class Conversaciones : public ICollectible {
public:
    IDictionary* getMensaejs();
    void setMensaejs(IDictionary* _mensaejs);
    Usuario* getUser1();
    void setUser1(Usuario* user1);
    Usuario* getUser2();
    void setUser2(Usuario* user2);
    virtual string tipo();
      
    Conversaciones(Usuario* _user_1, Usuario* _user_2, IDictionary* _mensaejs);
    Conversaciones(Usuario* _user_1, Usuario* _user_2);
    Conversaciones();
    ~Conversaciones();
private:
    IDictionary* mensaejs;
    Visto* user1;
    Visto* user2;
};


#include "Visto.h"
#include "Usuario.h"

#endif /* CONVERSACIONES_H */

