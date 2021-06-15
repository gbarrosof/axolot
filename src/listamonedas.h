#pragma once
#include "Moneda.h"
#include "personaje.h"
#include "interaccion.h"

#define max_elem 100

class listamonedas
{
	int numero;

public:
	listamonedas();
	Moneda* lista[max_elem];
	bool agregar(Moneda* m);
	void dibuja();
	void eliminar(Moneda* m);
	void eliminar(int index);
	Moneda* colision(personaje& h);
	void destruirContenido();

	friend class interaccion;
};

