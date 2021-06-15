#pragma once
#include"ETSIDI.h"
#include "freeglut.h"
#include "Vector.h"

class Pincho
{
	//int x, y;
	Vector posicion;
	ETSIDI::Sprite SpriteS1{ "imagenes/pinchos.png", 0, 0, 1, 1 };
public:
	void dibuja();
	Vector getPos();
	Pincho(float x, float y);
	void setPos(float x, float y);
	Pincho();

	
};