#include "EnemigoV.h"
#include "freeglut.h"

EnemigoV::EnemigoV(float x, float y, int z)
{
	altura = 0.5f;
	posicion.x = x;
	posicion.y = y;
	numero = z;
}

EnemigoV::~EnemigoV() {}

void EnemigoV::setPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}

void EnemigoV::dibuja()
{
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(altura, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
}

void EnemigoV::mueve(float t)
{
	/*posicion.x = posicion.x + velocidad.x * t + 0.5f * aceleracion.x * t * t;
	posicion.y = posicion.y + velocidad.y * t + 0.5f * aceleracion.y * t * t;
	velocidad.x = velocidad.x + aceleracion.x * t;
	velocidad.y = velocidad.y + aceleracion.y * t;*/
}

void EnemigoV::dispara(float x, float y)
{

	/*disp.posicion.x = x;
	disp.posicion.y = y;*/

	/*glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(altura, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);*/
}