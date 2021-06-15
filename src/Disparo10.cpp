#include"Disparo10.h"
#include "freeglut.h"

Disparo10::Disparo10(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
	alcance = 15;
	numer = 10;
	origen.x = x;
	origen.y = y;
	velocidad.x = 0;
	velocidad.y = 0;
	aceleracion.x = 0;
	aceleracion.y = 0;
	radio = 0.6;
}

Disparo10::~Disparo10() {}

void Disparo10::dibuja()
{
	/*glColor3f(0, 0, 255);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);*/

	//spriteD10.setCenter(posicion.x, posicion.y);
	spriteD10.setSize(2.25, 2.25);


	if (velocidad.x < 0)
	{
		spriteD10.setPos(posicion.x-1.7, posicion.y - 1.7);
		
	}
	else
	{
		
		spriteD10.setPos(posicion.x+ 1.7, posicion.y - 1.7);
		spriteD10.flip(true, false);
	}
	spriteD10.draw();
	//ETSIDI::SpriteSequence sprite("imagenes/disparo10", 9, 1, 50, true, 0, 0, 1, 1, 0);
}
void Disparo10::mueve(float t)
{
	posicion.x = posicion.x + velocidad.x * t + 0.5f * aceleracion.x * t * t;
	posicion.y = posicion.y + velocidad.y * t + 0.5f * aceleracion.y * t * t;
	velocidad.x = velocidad.x + aceleracion.x * t;
	velocidad.y = velocidad.y + aceleracion.y * t;
}
