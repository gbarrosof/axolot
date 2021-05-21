#pragma once
#include "Vector.h"
class disparo
{
private:

	float radio;
	Vector posicion, velocidad, aceleracion, origen;

public:
	disparo();
	void dibuja();
	void mueve(float t);
	void setPos(float ix, float iy);
	void setVel(float vx, float vy);
	float getRadio() { return radio; }
	Vector getPos();
	friend class Interaccion;
};