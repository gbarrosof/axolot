#pragma once
#include"Vector.h"
#include "ETSIDI.h"


class Disparo
{
public:
	Disparo();
	Disparo(float x, float y, float alc, int t);
	~Disparo();
	virtual void dibuja();
	virtual void mueve(float t);
	void setRadio(float radio);
	float getAltura() { return radio; }
	Vector getPos() { return posicion; }
	void setOri(Vector);
	void setPos(Vector pos);
	float getAlc() { return alcance; }
	float getRadio() { return radio; }
	int getnumer() { return numer; }
	void setVel(float x, float y);
	Vector getOri();

	friend class interaccion;

protected:
	Vector posicion;
	Vector origen;
	Vector velocidad;
	Vector aceleracion;
	float radio;
	float alcance;
	int numer;
	int tipo;

private:
	ETSIDI::SpriteSequence DisparoPL{ "imagenes/personajes/disparoPlatano.png", 3, 1, 100, true, 0, 0, 2, 2, 0 };
	ETSIDI::Sprite DisparoPi{ "imagenes/personajes/disparoPina.png"};
	ETSIDI::Sprite DisparoAg{ "imagenes/personajes/disparoAguacate.png" };
};