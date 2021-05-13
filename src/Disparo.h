#pragma once
#include "Vector2D.h"
class Disparo
{
private:

	float radio;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	Vector2D origen;
public:
	Disparo();
	void dibuja();
	void mueve(float t);
	void setPos(float ix, float iy);
	void setVel(float vx, float vy);
	float getRadio() { return radio; }
	Vector2D getPos();
	friend class Interaccion;
};