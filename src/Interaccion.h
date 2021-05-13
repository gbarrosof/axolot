#pragma once
#include "Hombre.h"
#include "Caja.h"
#include "Disparo.h"
class Interaccion
{
public:
	static void rebote(Hombre& h, Caja c);

	static bool contacto(Hombre& h, Pared p);
	static bool contacto(Hombre& h, Caja c);
	static bool colision(Disparo d, Pared p);
	static bool colision(Disparo d, Caja c);
};

