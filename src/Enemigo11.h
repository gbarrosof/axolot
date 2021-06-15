#pragma once
#include"Enemigo.h"
#include "ETSIDI.h"

class Enemigo11 :public Enemigo
{
public:
	Enemigo11(float, float);
	~Enemigo11();
	void dibuja();
	void mueve(float t);
	int getnumer() { return numer; }

private:
	ETSIDI::SpriteSequence spriteE11{ "imagenes/enemigos/enemigo11.png", 4, 1, 500, true, 0, 0, 1.5, 1.5, 0 };
};

