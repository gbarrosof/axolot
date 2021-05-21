#pragma once
#include "cubo.h"
#include "personaje.h"
#include "interaccion.h"

#define max_elem 150

class listacuadrados
{

public:
	//friend Moneda;
	listacuadrados();
	cubo* lista[max_elem];
	int numero;
	bool agregar(cubo* c);
	void dibuja();
	void colision(personaje& h);
	friend class interaccion;


};

