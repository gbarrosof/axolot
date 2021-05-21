#include "Disparo.h"
#include "freeglut.h"
#include <math.h>

disparo::disparo()
{
	radio = 0.25f;
	velocidad.x = 10.0f;
	aceleracion.y = 0.0f;
}

void disparo::dibuja()
{
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();
}

void disparo::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}

void disparo::setPos(float ix, float iy)
{
	posicion.x = ix;
	posicion.y = iy;
}

void disparo::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}

Vector disparo::getPos()
{
	return (posicion);
}