#pragma once
#include "ETSIDI.h"
#include "Vector.h"

class personaje
{

private:

	float altura;
	Vector posicion, velocidad, aceleracion;
public:
	personaje();
	void dibuja();
	void mueve(float t);
	void setVel(float vx, float vy);
	void setPos(float x, float y) { posicion.x = x; posicion.y = y; }
	float getAltura();
	Vector getPos();
	Vector getVel() { return velocidad; }
	friend class Interaccion; 

	ETSIDI::SpriteSequence sprite{ "imagenes/piña.png", 3, 1, 300 };
};

