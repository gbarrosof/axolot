#pragma once
#include"ETSIDI.h"
#include "freeglut.h"
#include "Vector.h"

class cubo
{
	int x, y;
	Vector posicion;
public:
	void dibuja( char, char, int, int);
	Vector getPos();
	cubo(float x, float y);
	void setPos(float x, float y);
	cubo();

};

