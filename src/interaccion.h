#pragma once
#include "personaje.h"
#include "disparo.h"
#include "cubo.h"
#include "Moneda.h"
class interaccion
{
public:

	static bool colision(personaje& h, cubo c);
	static bool colision(disparo& d, cubo c);
	static bool colision(personaje& p, Moneda m);

};

