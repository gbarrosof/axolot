#pragma once
#include "PowerUp.h"
#include "interaccion.h"
#include "personaje.h"
#define max_elem 10

class listaPowerUps
{

	int numero;
	

public:
	listaPowerUps();
	PowerUp* lista[max_elem];
	bool agregar(PowerUp* PU);
	void dibuja();	
	void eliminar(PowerUp* PU);
	void eliminar(int index);
	PowerUp* colision(personaje& h);
	void destruirContenido();

	friend class interaccion;
	

};

