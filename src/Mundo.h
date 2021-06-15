#pragma once
#include"Mapa.h"
#include "ETSIDI.h"
#include "Vector.h"
#include "moneda.h"
#include"listamonedas.h"
#include "personaje.h"
#include "interaccion.h"

using namespace ETSIDI;

class Mundo
{

private:
	Mapa nivel;
	float ojo=20;
	int score;
	int flecha;
	bool historia = true;
	
public:
	Mundo();
	void mueve();
	void inicializa();
	void dibuja();
	void teclado(unsigned char key);
	void teclaespecial(unsigned char key);
	void teclamovimiento(unsigned char key);

private:
	enum Estado { start, controls, play, pause, gameover, credits, loading, dormido, powerup, loose, story};
	ETSIDI::SpriteSequence sprite1{ "imagenes/aguacate.png", 6, 1, 50, false, -2, 0, 1, 1, 0 };
	ETSIDI::SpriteSequence sprite2{ "imagenes/pina.png", 3, 1, 50, false, -1, 0, 1, 1, 0 };
	ETSIDI::SpriteSequence sprite3{ "imagenes/zanahoria.png", 3, 1, 50, false, 1, 0, 1, 1, 0 };
	ETSIDI::SpriteSequence sprite4{ "imagenes/platano.png", 4, 1, 50, false, 2, 0, 1, 1, 0 };
	ETSIDI::Sprite vidas{ "imagenes/vidas.png" };
	ETSIDI::SpriteSequence cambio{ "imagenes/cambio.png", 5, 5, 75, true, 0, 0, 2, 2, 0 };
	Estado estado;
};

