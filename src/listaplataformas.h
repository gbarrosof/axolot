#pragma once
#include "Plataforma.h"
#include "personaje.h"
#include "interaccion.h"

#define max_elem 300

class listaplataformas
{
	int numero;

public:
	listaplataformas();
	Plataforma* lista[max_elem];
	bool agregar(Plataforma* p);
	void destruirContenido();
	void colision(personaje& h);

	friend class interaccion;


};

