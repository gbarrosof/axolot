#pragma once
#include"ETSIDI.h"
#include "freeglut.h"
#include "Vector.h"
class cubo
{
	int x, y;
	Vector posicion;
public:
	void dibuja();
	Vector getPos();
	cubo(float x, float y);
};

