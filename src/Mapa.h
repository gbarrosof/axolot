#pragma once
#include "ETSIDI.h"
#include"freeglut.h"
#include"cubo.h"
#include "Moneda.h"
#include"listamonedas.h"
#include"listacuadrados.h"

using namespace ETSIDI;

class Mapa
{
	
	Moneda *mon;
	int a = 0;
public:
	listamonedas monedas;
	listacuadrados cuadraditos;
	personaje fruta;

	int altura = 21;
	int largo = 253;
	char lvl;
	Vector ojo, posiocioncamara, posicion_personaje, bala;
	/*Sprite tierra("imagenes/tierra.png");
	Sprite cesped; 
	Sprite borde;*/
	//cubo cuadradito;
	ETSIDI::Sprite tierra{ "imagenes/tierra.png" };


	int vidas=5;
	char mapa [21][253];
	void inicializa(char nivel);
	void pinta();
	void fondos(const char *fondo);
	void teclado(unsigned char key);
	void mueve();
	Vector getPosOjo();
};

