#pragma once
#include "Disparo.h"
//#include "ETSIDI.h"

class Disparo12 :public Disparo
{
public:
	Disparo12(float x, float y);
	~Disparo12();
	void dibuja();
	void mueve(float t);

private:
	ETSIDI::Sprite spriteD12{"imagenes/enemigos/disparo12.png"};
};

