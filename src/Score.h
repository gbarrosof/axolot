#pragma once
#include "ETSIDI.h"
#include "Vector.h"

class Score
{
	int unidades=0, decenas=0, centenas=0, millares=0;
public:
	Score ();
	Vector posicion;
	void dibuja();
	void setScore(int, int, int, int);
	void setPos(float px, float py);

	ETSIDI::SpriteSequence a{ "imagenes/numero.png", 10, 1 , 50, false, 0,0, 0.3, 0.3, 0 };
	ETSIDI::SpriteSequence b{ "imagenes/numero.png", 10, 1 , 50, false, 0,0, 0.3, 0.3, 0 };
	ETSIDI::SpriteSequence c{ "imagenes/numero.png", 10, 1 , 50, false, 0,0, 0.3, 0.3, 0 };
	ETSIDI::SpriteSequence d{ "imagenes/numero.png", 10, 1 , 50, false, 0,0, 0.3, 0.3, 0 };
};

