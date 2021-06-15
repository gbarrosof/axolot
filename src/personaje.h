#pragma once
#include "ETSIDI.h"
#include "Vector.h"

class personaje
{

protected:
	bool death;
	float altura;
	Vector posicion, velocidad, aceleracion;
	int vidas, tipo=0;

	bool direccionderecha = true, dispar=false;
	
public:

	void setdireccionderecha(bool x) { direccionderecha = x; }
	bool getdireccionderecha() { return direccionderecha; }
	void setTipo(int x);
	int getTipo() { return tipo; }
	void setDisparos(bool x) { dispar = x; };
	bool getDisparos() { return dispar; };
	personaje();
	virtual void dibuja();
	void mueve(float t);
	void setVel(float vx, float vy);
	void setPos(float x, float y) { posicion.x = x; posicion.y = y; }
	float getAltura();
	Vector getPos();
	Vector getVel() { return velocidad; }
	Vector getAc() { return aceleracion; }

	virtual void setAc(float x , float y);

	void setdeath(bool a) { death = a; }
	bool getdeath() { return death; }
	
	//int getVidas() { return vidas; }
	//void setVidas(int a) { vidas = a; }


	friend class Interaccion; 

	bool salto;

	ETSIDI::SpriteSequence aguacate{ "imagenes/aguacate.png", 6, 1 ,100, true, 0, 0, 1, 1, 0 };
	ETSIDI::SpriteSequence pina{ "imagenes/pina.png", 3, 1 ,100, true, 0, 0, 1, 1, 0 };
	ETSIDI::SpriteSequence platano{ "imagenes/platano.png", 4, 1 ,100, true, 0, 0, 1, 1, 0 };


	//ETSIDI::SpriteSequence sprite{ "imagenes/zanahoria.png", 3, 1, 300 };
};

