#pragma once
#include "ETSIDI.h"
#include"Vector.h"

class Bandera
{
	Vector posicion;
	ETSIDI::SpriteSequence SpriteS1{ "imagenes/bandera.png", 2, 1, 200, true, 0, 0, 2,2,1 };
public:
	void dibuja();
	Vector getPos();
	void setPos(float x, float y);
	Bandera();
	void mueve();

	
};

