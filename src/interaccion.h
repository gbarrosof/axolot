#pragma once
#include "personaje.h"
#include "disparo.h"
#include "Suelo.h"
#include "Moneda.h"
#include "Plataforma.h"
#include "PowerUp.h"
#include "Pincho.h"
#include "Bandera.h"
#include "Vidas.h"
#include "Enemigo.h"
#include "Disparo.h"

class interaccion
{
	
public:

	static bool colision(personaje& h, cubo c);
	static bool colision(personaje p, Enemigo& e);
	static bool colision(personaje& p, Moneda m);
	static bool colision(personaje& p, Plataforma pl);
	static bool colision(personaje& p, PowerUp PU);
	static bool vacio(personaje p);
	static bool colision(personaje p, Pincho pi);
	static bool colision(personaje p, Bandera b);
	static bool colision(personaje p, Vidas *v);
	static bool disparo(personaje p, Enemigo e);
	static bool disparoeliminar(Disparo d);
	static bool colision(personaje p, Disparo d);
	static bool colision(Disparo d, Enemigo e);
	static bool colision(Disparo d, cubo c);
	static bool rango(Disparo d, int rang);
};

