#pragma once
#include "Vector.h"
#include "ETSIDI.h"
#include"freeglut.h"

using namespace ETSIDI;

class Moneda
{
public:
	Moneda(float posx=0, float posy=0);
	Vector posicion;
	Sprite* mon;
	float radio;
	void dibuja();
	Vector getPos();
	float getRadio();
};
