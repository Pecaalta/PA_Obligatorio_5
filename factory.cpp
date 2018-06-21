

#include "factory.h"

#include "Sistema.h"

ISistema* factory::CrearSistema() {
    return Sistema::getInstance();
}

factory::factory() {
}

factory::factory(const factory& orig) {
}

factory::~factory() {
}

