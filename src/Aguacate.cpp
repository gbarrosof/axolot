#include "Aguacate.h"
#include "freeglut.h"



Aguacate::Aguacate() :personaje()
{
	/*posicion.x = 5;
	posicion.y = -17;*/
	sprite.setSize(2, 2);
}

void Aguacate::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, -5);
	glutSolidSphere(altura, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 5);
	sprite.setPos(posicion.x, posicion.y - altura);

	if (velocidad.x > 0.01)
	{
		sprite.flip(false, false);
	}
	else if (velocidad.x < -0.01)
	{
		sprite.flip(true, false);
	}
	else
	{
		sprite.setState(2, false);
	}
	if (velocidad.y != 0 && salto == 0)
	{
		sprite.setState(1, false);
	}
	sprite.draw();
	glPopMatrix();
}

void Aguacate::setAc(float x, float y)
{
	aceleracion.x = x;
	aceleracion.y = y;
}
void Aguacate::mueve(float t)
{
	personaje::mueve(t);
}


