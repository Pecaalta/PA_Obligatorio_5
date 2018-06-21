

#include "generadorId.h"


int generadorId::getid() {
    int temp = id;
    id++;
    return temp;
}

