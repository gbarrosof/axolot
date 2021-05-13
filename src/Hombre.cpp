#include "Hombre.h"
#include "freeglut.h"
#include <math.h>

Hombre::Hombre()
{
	altura = 1.8f;
	aceleracion.y = -40.0f;
	sprite.setCenter(1,0);
	sprite.setSize(2, 2);
}

void Hombre::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 1);

	//glutSolidSphere(altura, 20, 20);
	//gestion de direccion y animacion
	if (velocidad.x > 0.01)sprite.flip(false, false);
	if (velocidad.x < -0.01)sprite.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		sprite.setState(0);
	else if (sprite.getState() == 0)
		sprite.setState(1, false);
	sprite.draw();

	glPopMatrix();

}

void Hombre::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	sprite.loop();
}

void Hombre::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}

float Hombre::getAltura()
{
	return altura;
}

Vector2D Hombre::getPos()
{
	return posicion;
}
