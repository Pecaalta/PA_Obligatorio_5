
#include "Video.h"

// Funciones de URL

string Video::getURL() {
    return this->URL;
};

void Video::setURL(string _URL) {
    this->URL = _URL;
};

// Funciones de Duracion

string Video::getDuracion() {
    return this->Duracion;
};

void Video::setDuracion(string _Duracion) {
    this->Duracion = _Duracion;
};

// Constructores y Destructores

Video::Video(string _Duracion, string _URL, int _id, string _texto, Usuario* _autor) : Mensaje(_id, _texto, _autor,"Video") {
    this->URL = _URL;
    this->Duracion = _Duracion;
}

Video::~Video() {
};


