

#ifndef CONTACTO_H
#define CONTACTO_H

#include "Mensaje.h"


class Contacto:public Mensaje {
  public:
	Usuario* getContenido();
	void  setContenido(Usuario* _Contenido);

	// Constructores y Destructores
	Contacto(Usuario* _Contenido, int _id, string _texto, Usuario* _autor);
	Contacto();
	~Contacto();
  private:
	Usuario* Contenido;
}
;

#endif /* CONTACTO_H */

