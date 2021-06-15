#pragma once
#include "Vector.h"
#include "ETSIDI.h"
#include"freeglut.h"

using namespace ETSIDI;

class Vidas
{
private:
	Vector posicion;
	int vidas;
public:
	Vidas(float posx = 0, float posy = 0);
	
	//Sprite* mon;
	float radio;
	void dibuja();
	Vector getPos();
	float getRadio();

	
	void setVidas(int a) { vidas = a; }
	int getVidas() { return vidas; }
	


};

