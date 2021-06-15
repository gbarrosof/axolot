#pragma once
#include "Disparo.h"
//#include "ETSIDI.h"

class Disparo11 :public Disparo
{
private:
	Vector personaje;
	bool a;
	ETSIDI::Sprite spriteD11{ "imagenes/enemigos/disparo11.png" };
public:
	Disparo11(float x, float y, float, float);
	~Disparo11();
	void dibuja();
	void mueve(float t);

};

