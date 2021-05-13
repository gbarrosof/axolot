#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;
class Hombre
{
private:
	
	float altura;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
public:
	Hombre();
	void dibuja();
	void mueve(float t);
	void setVel(float vx, float vy);
	void setPos(float x, float y) { posicion.x = x; posicion.y = y; }
	float getAltura();
	Vector2D getPos();
	Vector2D getVel() { return velocidad; }
	friend class Interaccion;
	SpriteSequence sprite{ "imagenes/pangplayer.png", 5 };
};