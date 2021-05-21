#include "Interaccion.h"
#include "freeglut.h"
bool interaccion::colision(personaje& h, cubo c)
{
	Vector velocidad_inicial=h.getVel();
	Vector distancia;
	distancia.x = h.getPos().x - c.getPos().x+1;
	distancia.y = h.getPos().y - c.getPos().y ;
	if (distancia.x <= h.getAltura() )
	{
		h.setPos(h.getPos().x, h.getPos().y);
		h.setVel(0, velocidad_inicial.x);
	}
	if (distancia.y <= h.getAltura())
	{
		h.setPos(h.getPos().x, h.getPos().y);
		h.setVel(velocidad_inicial.x, 0);
	}
	return true;
}


bool interaccion::colision(disparo& d, cubo c)
{
	return true;
	/*
	Vector dir;
	float dif = p.distancia(d.posicion, &dir) - d.radio;
	if (dif <= 0.0f)
	{
		return true;
	}
	return false;
	*/
}

bool interaccion::colision(personaje& p, Moneda m)
{

	float distancia = (m.posicion - p.getPos()).modulo();
	if (distancia <= m.radio + p.getAltura())
	{
		return true;
	}
	return false;
}