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
public:
	Mapa nivel;
	
	//listamonedas monedas;
	//Vector ojo, posiocioncamara, posicion_personaje, bala;

	int score;
	int flecha;
	


	Mundo();

	//SpriteSequence* avocado, * platano, * piña, * granada, * zanahoria;

	void mueve();
	void inicializa();
	void dibuja();
	void teclado(unsigned char key);
	void teclaespecial(unsigned char key);
	enum Estado { start, controls, play, pause, gameover, credits, loading, dormido};

	ETSIDI::SpriteSequence sprite1{ "imagenes/aguacate.png", 6, 1, 50, true, -2, 0, 1, 1, 0 };
	ETSIDI::SpriteSequence sprite2{ "imagenes/piña.png", 3, 1, 50, true, -1, 0, 1, 1, 0 };
	ETSIDI::SpriteSequence sprite3{ "imagenes/zanahoria.png", 3, 1, 50, true, 1, 0, 1, 1, 0 };
	ETSIDI::SpriteSequence sprite4{ "imagenes/platano.png", 4, 1, 50, true, 2, 0, 1, 1, 0 };
	ETSIDI::Sprite vidas{ "imagenes/vidas.png" };

	Estado estado;
};

