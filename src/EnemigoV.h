#pragma once
#include"Vector.h"
#include "Disparo.h"

class EnemigoV
{
public:
	EnemigoV(float , float, int);
	~EnemigoV();
	virtual void dibuja();
	void mueve(float tiempo);
	void setPos(float x, float y);
	float getRadio() { return altura; }
	Vector getPos() { return posicion; }
	int getNum() { return numero; }
	virtual void dispara(float, float);


protected:
	float altura;
	Vector posicion;
	int numero;
};
