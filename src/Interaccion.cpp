#include "Interaccion.h"
#include "freeglut.h"
void Interaccion::rebote(Hombre& h, Caja c)
{
	float xmax = c.suelo.limite2.x;
	float xmin = c.suelo.limite1.x;
	float ymin = c.suelo.limite1.y;

	if (h.posicion.x > xmax)h.posicion.x = xmax;
	if (h.posicion.x < xmin)h.posicion.x = xmin;
	if (h.posicion.y < ymin)h.posicion.y = ymin;
}

bool Interaccion::contacto(Hombre& h, Pared p)
{
	Vector2D dir;
	float dif = p.distancia(h.posicion, &dir);
	if (dif == 0.0f)
	{
		return true;
	}
	else 
	return false;
}

bool Interaccion::contacto(Hombre& h, Caja c)
{	
	return (Interaccion::contacto(h, c.suelo));
}

bool Interaccion::colision(Disparo d, Pared p)
{
	Vector2D dir;
	float dif = p.distancia(d.posicion, &dir) - d.radio;
	if (dif <= 0.0f)
	{
		return true;
	}
	return false;
}
