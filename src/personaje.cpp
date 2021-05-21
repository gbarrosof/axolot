#include "personaje.h"
#include "freeglut.h"
#include <math.h>

personaje::personaje()
{
	altura = 0.5f;
	aceleracion.y = -40.0f;
	posicion.x = 5;
	posicion.y = -17;
	sprite.setCenter(1, 0.25);
	sprite.setSize(2, 2);
}


void personaje::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, -5);
	glutSolidSphere(altura, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 5);
	sprite.setPos(posicion.x, posicion.y);
	//sprite.setState(1);

	if (velocidad.x > 0.01)sprite.flip(false, false);
	if (velocidad.x < -0.01)sprite.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		sprite.setState(0);
	else if (sprite.getState() == 2)
		sprite.setState(0, false);
	if (posicion.y > -10)
	{
		sprite.setState(2, false);
	}


	sprite.draw();

	glPopMatrix();
	glTranslatef(0, 0, -1);

}

void personaje::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	sprite.loop();
	if (posicion.y  <= -17 )
	{
		posicion.y = -17;
		velocidad.y = 0;
	}

	
}

void personaje::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}

float personaje::getAltura()
{
	return altura;
}

Vector personaje::getPos()
{
	return posicion;
}
