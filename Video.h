/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Video.h
 * Author: Mauro
 *
 * Created on 7 de junio de 2018, 8:04
 */

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

