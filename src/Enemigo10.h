#pragma once
#include "Enemigo.h"
#include "ETSIDI.h"

class Enemigo10 :public Enemigo
{
public:
	Enemigo10(float, float);
	~Enemigo10();
	void dibuja();
	void mueve(float t);
	int getnumer() { return numer; }

private:
	ETSIDI::SpriteSequence spriteE10{ "imagenes/enemigos/enemigo10.png", 9, 1, 200, true, 0, 0, 1.5, 1.5 };
};

