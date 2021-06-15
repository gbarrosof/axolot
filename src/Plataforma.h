#pragma once
#include "Vector.h"
#include "ETSIDI.h"

class Plataforma
{
public:
	Vector posicion;
	
	Plataforma();
	Vector getPos();
	Plataforma(float x, float y);
	void setPos(float x, float y);
	void dibuja(char lvl, char m, int px, int py);
};

