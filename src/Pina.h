#pragma once
#include "personaje.h"

class Pina : public personaje
{
public:
	Pina();
	void dibuja();
	ETSIDI::SpriteSequence sprite{ "imagenes/pina.png", 3, 1, 300 }; //MODIFICAR
};

