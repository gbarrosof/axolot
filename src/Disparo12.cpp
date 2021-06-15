#include "Disparo12.h"
#include "freeglut.h"

Disparo12::Disparo12(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
	origen.x = x;
	origen.y = y;
	alcance = 20;
	numer = 12;
	velocidad.x = 0;
	velocidad.y = 0;
	aceleracion.x = 0;
	aceleracion.y = 0;
	radio = 0.25;
}

Disparo12::~Disparo12() {}

void Disparo12::dibuja()
{
	/*glColor3f(120, 120, 0);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);*/

	spriteD12.setPos(posicion.x+1, posicion.y -1);
	spriteD12.setSize(1.25, 1.25);
	spriteD12.setAngle(90);

	if (velocidad.x < 0)
	{
		spriteD12.flip(true, false);
		spriteD12.setPos(posicion.x - 1.1, posicion.y - 1.25);
	}
	else
	{
		spriteD12.setPos(posicion.x + 1.1, posicion.y - 1.25);
	}
	spriteD12.draw();
	//ETSIDI::SpriteSequence sprite("imagenes/disparo12", 9, 1, 50, true, 0, 0, 1, 1, 0);
}
void Disparo12::mueve(float t)
{
	posicion.x = posicion.x + velocidad.x * t + 0.5f * aceleracion.x * t * t;
	posicion.y = posicion.y + velocidad.y * t + 0.5f * aceleracion.y * t * t;
	velocidad.x = velocidad.x + aceleracion.x * t;
	velocidad.y = velocidad.y + aceleracion.y * t;
}