#pragma once
#include"Vector.h"
//#include "Disparo.h"

class Enemigo
{
public:
	Enemigo();
	~Enemigo();
	virtual void dibuja();
	virtual void mueve(float tiempo);
	void setPos(float x, float y);
	float getRadio() { return altura; }
	Vector getPos() { return posicion; }
	void dispara(float, float);
	virtual int getnumer() { return numer; }
	void setderecha(bool x) { derecha = x; }

protected:
	float altura;
	Vector posicion;
	int numer;
	bool derecha=false;
};
