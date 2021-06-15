#pragma once
#include "Pincho.h"
#include "personaje.h"
#include "interaccion.h"

#define max_elem 50

class listapinchos
{
	int numero;

public:
	listapinchos();
	Pincho* lista[max_elem];
	bool agregar(Pincho* p);
	void dibuja();
	bool colision(personaje& h);
	void destruirContenido();

	friend class interaccion;


};
