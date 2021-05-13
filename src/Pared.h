#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
class Pared
{
private:
	
	ColorRGB color;
	Vector2D limite1;
	Vector2D limite2;
public:
	
	Pared();
	void setColor(Byte r, Byte g, Byte b);
	void dibuja();
	void setPos(float x1, float y1, float x2, float y2);
	float distancia(Vector2D punto, Vector2D* direccion = 0);
	friend class Interaccion;
};