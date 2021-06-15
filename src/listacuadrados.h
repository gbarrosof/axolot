#pragma once
#include "Suelo.h"
#include "personaje.h"
#include "interaccion.h"

#define max_elem 500

class listacuadrados
{
	int numero;
public:

	listacuadrados();
	cubo* lista[max_elem];
	bool agregar(cubo* c);
	void dibuja( char , char, int, int);
	void colision(personaje& h);
	bool colision(Disparo* d);
	friend class interaccion;
	void destruirContenido();


};

