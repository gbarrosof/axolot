#pragma once
#include"Enemigo.h"
#include"personaje.h"
#include "Enemigo10.h"
#include "Enemigo11.h"
#include "Enemigo12.h"
#include "interaccion.h"

#define MAX_ENEMIGOS 100 

class ListaEnemigos
{

public:
	ListaEnemigos();
	~ListaEnemigos();
	bool agregar(Enemigo* e);
	void dibuja();
	void mueve(float t);
	void destruirContenido();
	void eliminar(int index);
	int getNumero() { return numero; }
	Enemigo* colision(personaje f);
	Enemigo* operator [](int i);
	bool eliminar(Disparo d);
	Enemigo* disparo(personaje, int);

private:
	Enemigo* lista[MAX_ENEMIGOS];
	int numero;

};

