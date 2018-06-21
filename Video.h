

#ifndef VIDEO_H
#define VIDEO_H

#include "Mensaje.h"


class Video:public Mensaje {
  public:
	string getURL();
	void  setURL(string _URL);
	string getDuracion();
	void  setDuracion(string _Duracion);

	// Constructores y Destructores
	Video(string _Duracion,string _URL,int _id,string _texto,Usuario* _autor  );
	Video();
	~Video();
  private:
	string URL;
	string Duracion;
};

#endif /* VIDEO_H */

