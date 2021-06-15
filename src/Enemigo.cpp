#include "Enemigo.h"
#include "freeglut.h"

Enemigo::Enemigo()
{
	altura = 0.5f;
	posicion.x = 0;
	posicion.y = 0;
}

Enemigo::~Enemigo() {}

void Enemigo::setPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}

void Enemigo::dibuja()
{
	/*glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(altura, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);*/
}

void Enemigo::mueve(float t)
{
	/*posicion.x = posicion.x + velocidad.x * t + 0.5f * aceleracion.x * t * t;
	posicion.y = posicion.y + velocidad.y * t + 0.5f * aceleracion.y * t * t;
	velocidad.x = velocidad.x + aceleracion.x * t;
	velocidad.y = velocidad.y + aceleracion.y * t;*/
}

void Enemigo::dispara(float x, float y)
{

	/*disp.posicion.x = x;
	disp.posicion.y = y;*/

	/*glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(altura, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);*/
}