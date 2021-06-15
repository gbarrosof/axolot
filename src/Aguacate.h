#pragma once
#include "personaje.h"

class Aguacate : public personaje
{
public:
	Aguacate();
	void dibuja();
	void mueve(float t);
	void setAc(float x, float y);
private:
	ETSIDI::SpriteSequence sprite{ "imagenes/aguacate.png", 5, 1, 300 };
};

