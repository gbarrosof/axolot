#pragma once
#include "personaje.h"

class Platano :public personaje
{
public:
	Platano();
	void dibuja();
	ETSIDI::SpriteSequence sprite{ "imagenes/platano.png", 3, 1, 300 }; //MODIFICAR
};

