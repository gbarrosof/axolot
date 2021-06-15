#pragma once
#include "ETSIDI.h"
#include "Vector.h"
class Icono
{	
public:
	Icono();
	~Icono();
	void dibuja(int a, float x, float y);

private:
	Vector posicion;
	int tipo;
	ETSIDI::SpriteSequence aguacate{ "imagenes/aguacate.png", 6, 1 ,50, false, 0, 0, 1, 1, 0 };
	ETSIDI::SpriteSequence pina{ "imagenes/pina.png", 3, 1 ,50, false, 0, 0, 1, 1, 0 };
	ETSIDI::SpriteSequence platano{ "imagenes/platano.png", 4, 1 ,50, false, 0, 0, 1, 1, 0 };
};

