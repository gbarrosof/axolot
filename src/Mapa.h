#pragma once
#include "ETSIDI.h"
#include"freeglut.h"
#include"suelo.h"
#include"listamonedas.h"
#include"listacuadrados.h"
#include "Plataforma.h"
#include "listaplataformas.h"
#include "listaPowerUps.h"
#include "Score.h"
#include "listapinchos.h"
#include"Vidas.h"
#include"ListaEnemigos.h"
#include "ListaDisparos.h"
#include "ListaEnemigosVisibles.h"
#include "Platano.h"
#include "Pina.h"
#include "Aguacate.h"
#include "Icono.h"

using namespace ETSIDI;

class Mapa
{
private:
	bool Tpowerup= false;
	int a = 0;
	int lvl;
	int vid;
	int altura = 21;
	int largo = 300;
	int posicionz = 17;
	void inicializamapa();
	char mapa[21][300];
	
public:
	listamonedas monedas;
	listacuadrados cuadraditos;
	personaje fruta;
	listaplataformas plataformas;
	listaPowerUps PowerUps;
	cubo cuadrado;
	Plataforma plataforma;
	Score score;
	listapinchos pinchos;
	Bandera bandera;
	Vidas Vida, *vida1, *vida2;
	ListaEnemigos enemigos;
	ListaDisparos disparos;
	ListaEnemigosVisibles visibles;
	Disparo disparo;
	Icono icono;

	void setnivel(int z) { lvl = z; }
	int getnivel() { return lvl; }
	Vector ojo, posiocioncamara, posicion_personaje;

	Mapa();

	void inicializa(char nivel);
	void pinta();
	void fondos(const char *fondo);
	void teclado(unsigned char key);
	void teclamovimiento(unsigned char key);
	void mueve();
	Vector getPosOjo();
	int getNivel() { return lvl; }
	bool getpowerup() { return Tpowerup; }
	void setpowerup(bool a) { Tpowerup = a; }

};

