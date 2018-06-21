

#ifndef FACTORY_H
#define FACTORY_H

#include "ISistema.h"
#include "Sistema.h"


class factory {
public:
    static ISistema* CrearSistema();
    factory();
    factory(const factory& orig);
    virtual ~factory();
private:

};

#endif /* FACTORY_H */

