#pragma once
#include "Caja.h"
#include "Hombre.h"
#include "Disparo.h"
#include "Interaccion.h"
#include "ListaDisparos.h"

class Mundo
{
private:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	Disparo disparo;
	Hombre hombre;
	Caja caja;
	Pared plataforma;
	ListaDisparos disparos;
public:

	void inicializa();
	void rotarOjo();
	void mover();
	void dibuja();
	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	~Mundo();
};
