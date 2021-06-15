#pragma once
#include "Disparo.h"
//#include "ETSIDI.h"

class Disparo10 :public Disparo
{
public:
	Disparo10(float x, float y);
	~Disparo10();
	void dibuja();
	void mueve(float t);

private:
	ETSIDI::Sprite spriteD10{ "imagenes/enemigos/disparo10.png" };
};

