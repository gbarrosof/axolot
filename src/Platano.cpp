#include "Platano.h"
#include "freeglut.h"

Platano::Platano() :personaje()
{
	sprite.setSize(2, 2);
}

void Platano::dibuja()
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
