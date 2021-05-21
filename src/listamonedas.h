#pragma once
#include "Moneda.h"
#include "personaje.h"
#include "interaccion.h"

#define max_elem 50

class listamonedas
{
public:
	//friend Moneda;
	listamonedas();
	Moneda* lista[max_elem];
	int numero;
	bool agregar(Moneda* m);
	void dibuja();
	void eliminar(Moneda* m);
	void eliminar(int index);
	Moneda* colision(personaje& h);
	friend class interaccion;
};

