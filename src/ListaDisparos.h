#pragma once
#include "Disparo.h"
#include "Disparo10.h"
#include "Disparo11.h"
#include "Disparo12.h"
#include "personaje.h"
#include "interaccion.h"

#define MAX_DISPAROS 50

class ListaDisparos
{

public:
	ListaDisparos();
	~ListaDisparos();
	bool agregar(Disparo* d);
	void mueve(float t);
	void dibuja();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(personaje& );
	Disparo* operator [](int i);
	int getNumero() { return numero; }
	void chocar(Disparo* d, personaje& p);
	void eliminar(Disparo* e);
	bool personajeagregar();
	Disparo* colision(personaje f);

private:
	Disparo* lista[MAX_DISPAROS];
	int numero;
};
