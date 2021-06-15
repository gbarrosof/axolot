#pragma once
#include "Vector.h"
#include "ETSIDI.h"
#include"freeglut.h"

using namespace ETSIDI;

class PowerUp
{
	//bool Tpowerup = false;
	public:
		
		PowerUp(float posx = 0, float posy = 0);
		Vector posicion;
		PowerUp();
		//Sprite* PU;
		float radio;
		void dibuja();
		Vector getPos();
		float getRadio();
	//bool getPowerup() { return Tpowerup;}
		//void setPowerup(bool);
		ETSIDI::Sprite sprite{ "imagenes/powerup.png", posicion.x, posicion.y, 0.5, 0.5 };
};

