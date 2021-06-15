#pragma once
#include "Enemigo.h"
#include "ETSIDI.h"

class Enemigo12 :public Enemigo
{
public:
	Enemigo12(float, float);
	~Enemigo12();
	void dibuja();
	void mueve(float t);
	int getnumer() { return numer; }
	
private:
	ETSIDI::SpriteSequence spriteE12{ "imagenes/enemigos/enemigo12.png", 6, 1, 300, true, 0, 0, 2, 2, 0 };
protected:
	Vector origen;
};

