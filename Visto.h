#ifndef VISTO_H
#define VISTO_H
#include "Fecha.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IIterator.h"
#include "ICollection/collections/List.h"
#include "ICollection/String.h"
#include "Usuario.h"

class Visto : public ICollectible{
  public:
	Usuario* getUsuario();
	void  setUsuario(Usuario* _usuario);
	Fecha* getFecha();
	void  setFecha(Fecha* _fecha);
	int getIdmensaje();
	void  setIdmensaje(int _idmensaje);

	// Constructores y Destructores
	Visto(Usuario* _usuario);
	Visto();
	~Visto();
  private:
	Usuario* usuario;
	Fecha* fecha;
	int idmensaje;
};


#endif /* VISTO_H */

